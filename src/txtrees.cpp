// Tralics, a LaTeX to XML translator.
// Copyright INRIA/apics/marelle (Jose' Grimm) 2006, 2007-2011

// This software is governed by the CeCILL license under French law and
// abiding by the rules of distribution of free software.  You can  use,
// modify and/ or redistribute the software under the terms of the CeCILL
// license as circulated by CEA, CNRS and INRIA at the following URL
// "http://www.cecill.info".
// (See the file COPYING in the main directory for details)

// This file contains a lot of stuff dealing with trees
// It contains also some eTeX extensions.

#include "tralics/AllIndex.h"
#include "tralics/Logger.h"
#include "tralics/MainClass.h"
#include "tralics/OneIndex.h"
#include "tralics/Parser.h"
#include "tralics/globals.h"
#include <fmt/format.h>

namespace trees_ns {
    void normalise_space(TokenList &L);
    auto which_index(std::string) -> int;
} // namespace trees_ns

namespace date_ns {
    auto check_date(long y, size_t m, size_t d) -> bool; // \todo there has to be a system library for that
    auto year_length(long y) -> size_t;
    auto month_length(long y, size_t m) -> size_t;
    void prev_date(long &year, size_t &month, size_t &day);
    void next_date(long &year, size_t &month, size_t &day);
} // namespace date_ns

namespace {
    Buffer                 local_buf;
    std::array<size_t, 13> month_length_table = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Token                  day_ctr, year_ctr, month_ctr;

    // Case \printglossary or \printindex[foo].
    // Marks the place where to insert the index
    void mark_print(OneIndex &g) {
        Xml *mark = new Xml(std::string(), nullptr);
        Xml *Foo  = new Xml(std::string(), mark);
        the_stack.add_last(Foo);
        g.position = mark;
    }
} // namespace

// For \addatttoindex[foo]{bar}{gee}, returns the idx of foo,
// then we can say \XMLaddatt{idx}{bar}{gee}
auto Parser::get_index_value() -> size_t {
    std::string s = sT_optarg_nopar();
    return the_index.find_index(s).AL;
}

// Case of \index{key@value|encap}
// Translates to <index encap='encap' target='x1 x2'>value<index>

// This normalises spaces
void trees_ns::normalise_space(TokenList &L) {
    bool      prev_space = false;
    TokenList res;
    auto      SP = Token(space_token_val);
    auto      C  = L.begin();
    auto      E  = L.end();
    while (C != E) {
        if (C->is_space_token()) {
            if (!prev_space) res.push_back(SP);
            prev_space = true;
        } else {
            res.push_back(*C);
            prev_space = false;
        }
        ++C;
    }
    L.swap(res);
}

auto Parser::index_aux(TokenList &L, std::optional<size_t> father, OneIndex &g) -> size_t {
    static const Token escape_t(other_t_offset, '"');
    static const Token actual_t(other_t_offset, '@');
    static const Token actualb_t(letter_t_offset, '@');
    static const Token encap_t(other_t_offset, '|');
    std::string        key, encap;
    bool               have_key = false;
    TokenList          z;
    if (token_ns::split_at(escape_t, actual_t, actualb_t, L, z, false)) {
        have_key = true;
        token_ns::remove_first_last_space(z);
        key = to_stringE(z);
    }
    if (token_ns::split_at(escape_t, encap_t, encap_t, L, z, false)) {
        token_ns::remove_first_last_space(L);
        encap = to_stringE(L);
        swap(L, z);
    }
    if (!have_key) {
        z = L;
        token_ns::remove_first_last_space(z);
        key = to_stringE(z);
    }
    z               = L;
    std::string aux = to_stringE(z);
    // We have now: key@aux|encap
    std::vector<Indexer> &IR    = g;
    int                   level = 1;
    if (father) level = 1 + IR[*father].level;
    auto n = IR.size();
    for (size_t i = 0; i < n; i++)
        if (IR[i].is_same(level, aux)) return i;
    Buffer &B = local_buf;
    B.clear();
    if (father) B += IR[*father].key + "____";
    B += key;
    B.lowercase();
    for (auto &c : B)
        if (c == '\n') c = ' ';
    Xml *res = translate_list(L);
    Xml *x   = new Xml(the_names["index"], res);
    if (!encap.empty()) x->id.add_attribute(the_names["encap"], std::string(encap));
    x->id.add_attribute(the_names["level"], the_names[std::to_string(level)]);
    auto iid = the_index.last_iid++;
    IR.push_back({B, aux, x, level, iid});
    return n;
}

// \index, \makeindex, \printindex, + glossary, and \newindex
void Parser::T_index(subtypes c) {
    if (c == makeindex_code || c == makeglossary_code) return;
    flush_buffer();
    if (c == index_code) remove_initial_star();
    if (c == newindex_code) {
        std::string s     = sT_arg_nopar();
        std::string title = sT_arg_nopar();
        the_index.new_index(s, title);
        return;
    }
    auto &g = (c == printindex_code || c == index_code) ? the_index.find_index(sT_optarg_nopar()) : the_index[0];
    if (c == printindex_code || c == printglossary_code) {
        mark_print(g);
        return;
    }
    TokenList L = read_arg();
    trees_ns::normalise_space(L);
    TokenList          z1, z2;
    static const Token escape_t(other_t_offset, '"');
    static const Token level_t(other_t_offset, '!');
    flush_buffer();
    int level = 1;
    if (token_ns::split_at(escape_t, level_t, level_t, L, z1, true)) {
        if (token_ns::split_at(escape_t, level_t, level_t, L, z2, true))
            level = 3; // z1, z2, L
        else
            level = 2; // z1, L
    }
    // If level != 1, make sure parent exists
    std::optional<size_t> position;
    if (level > 1) position = index_aux(z1, position, g);
    // If level == 3, make sure grand parent exists
    if (level == 3) position = index_aux(z2, position, g);
    // make sure this exists
    auto pposition = index_aux(L, position, g);
    // Now, add a label here
    auto iid = g.at(pposition).iid;
    auto nid = ++the_index.last_index;

    local_buf             = fmt::format("lid{}", nid);
    const std::string &W  = local_buf;
    std::string        id = the_stack.add_anchor(W, false);
    create_label(W, id);
    tralics_ns::add_ref(to_signed(iid), W, true);
}

// -----------------------------------------------
// Commands from tree-dvips.sty
void Parser::T_trees(subtypes c) {
    flush_buffer();
    if (c == node_code)
        T_node();
    else if (c == nodepoint_code)
        T_nodepoint();
    else if (c == nodeconnect_code)
        T_nodeconnect(the_names["nodeconnect"]);
    else if (c == anodeconnect_code)
        T_nodeconnect(the_names["anodeconnect"]);
    else if (c == barnodeconnect_code)
        T_barnodeconnect(the_names["barnodeconnect"]);
    else if (c == abarnodeconnect_code)
        T_barnodeconnect(the_names["abarnodeconnect"]);
    else if (c == nodecurve_code)
        T_nodecurve(the_names["nodecurve"]);
    else if (c == anodecurve_code)
        T_nodecurve(the_names["anodecurve"]);
    else if (c == nodebox_code)
        T_nodebox(the_names["nodebox"]);
    else if (c == nodeoval_code)
        T_nodebox(the_names["nodeoval"]);
    else if (c == nodetriangle_code)
        T_nodetriangle(the_names["nodetriangle"]);
    else if (c == nodecircle_code)
        T_nodecircle(the_names["nodecircle"]);
}

// Something like
// \def\node#1#2{\leavevmode
//  \xbox{node}{\XMLaddatt{name}{#1}#2}}

// Initial code uses nodemargin=2pt (value from \nodemargin)
// and nodemargin=2pt for nodepoint below
void Parser::T_node() {
    std::string A = nT_arg_nopar();
    leave_v_mode();
    the_stack.push1(the_names["node"]);
    AttList &cur           = last_att_list();
    cur[the_names["name"]] = A;
    T_arg();
    the_stack.pop(the_names["node"]);
}

// A node of 0pt width and height
// \nodepoint{nodename}[horizontal displacement][vertical displacement]

void Parser::T_nodepoint() {
    std::string A = nT_arg_nopar();
    auto        B = nT_optarg_nopar();
    auto        C = nT_optarg_nopar();
    the_stack.push1(the_names["node"]);
    AttList &cur           = last_att_list();
    cur[the_names["name"]] = A;
    if (B) cur[the_names["xpos"]] = *B; // default value is zero
    if (C) cur[the_names["ypos"]] = *C; // default value is zero
    the_stack.pop(the_names["node"]);
}

// \nodeconnect[fromloc]{fromnode}[toloc]{tonode}
void Parser::T_nodeconnect(const std::string &W) {
    auto A = get_trees_opt();
    auto B = nT_arg_nopar();
    auto C = get_trees_opt();
    auto D = nT_arg_nopar();
    if (!A) A = "b";
    if (!C) C = "t";
    the_stack.push1(W);
    AttList &cur            = last_att_list();
    cur[the_names["posB"]]  = the_names[*C];
    cur[the_names["posA"]]  = the_names[*A];
    cur[the_names["nameB"]] = D;
    cur[the_names["nameA"]] = B;
    the_stack.pop(W);
}

// \barnodeconnect[depth]{fromnode}{tonode}
void Parser::T_barnodeconnect(const std::string &W) {
    auto        A = nT_optarg_nopar();
    std::string B = nT_arg_nopar();
    std::string C = nT_arg_nopar();
    the_stack.push1(W);
    AttList &cur = last_att_list();
    if (A) cur[the_names["depth"]] = *A;
    cur[the_names["nameB"]] = C;
    cur[the_names["nameA"]] = B;
    the_stack.pop(W);
}

// \nodecurve[fromloc]{fromnode}[toloc]{tonode}{depthfrom}[depthto]
// \anodecurve[fromloc]{fromnode}[toloc]{tonode}{depth}
void Parser::T_nodecurve(const std::string &W) {
    auto A = get_trees_opt();
    auto B = nT_arg_nopar();
    auto C = get_trees_opt();
    auto D = nT_arg_nopar();
    auto E = nT_arg_nopar();
    auto F = nT_optarg_nopar();
    if (!A) A = "b";
    if (!C) C = "t";
    if (!F || F->empty()) F = E;
    the_stack.push1(W);
    AttList &cur             = last_att_list();
    cur[the_names["depthA"]] = E;
    cur[the_names["depthB"]] = *F;
    cur[the_names["posB"]]   = the_names[*C];
    cur[the_names["posA"]]   = the_names[*A];
    cur[the_names["nameB"]]  = D;
    cur[the_names["nameA"]]  = B;
    the_stack.pop(W);
}

void Parser::T_nodebox(const std::string &W) {
    std::string A = nT_arg_nopar();
    the_stack.push1(W);
    AttList &cur            = last_att_list();
    cur[the_names["nameA"]] = A;
    the_stack.pop(W);
}

void Parser::T_nodetriangle(const std::string &W) {
    std::string A = nT_arg_nopar();
    std::string B = nT_arg_nopar();
    the_stack.push1(W);
    AttList &cur            = last_att_list();
    cur[the_names["nameA"]] = A;
    cur[the_names["nameB"]] = B;
    the_stack.pop(W);
}

// \nodecircle[depth]{nodename}
void Parser::T_nodecircle(const std::string &W) {
    auto        B = nT_optarg_nopar();
    std::string A = nT_arg_nopar();
    the_stack.push1(W);
    AttList &cur = last_att_list();
    if (B) cur[the_names["depth"]] = *B;
    cur[the_names["nameA"]] = A;
    the_stack.pop(W);
}

//  gloss -----------------------------------------------------------------

void Parser::T_gloss(bool c) {
    Token A   = hash_table.locate("eachwordone");
    Token B   = hash_table.locate("eachwordtwo");
    Token C   = hash_table.locate("eachwordthree");
    Token amp = Token(ampersand_t_offset, '&');
    ;
    Token     BS          = hash_table.locate("\\");
    TokenList first_line  = read_until(BS);
    TokenList second_line = read_until(BS);
    TokenList third_line;
    int       n1 = 0, n2 = 0, n3 = 0;
    if (!c) third_line = read_until(BS);
    n1 = token_ns::replace_space(first_line, amp, A);
    first_line.push_front(A);
    first_line.push_back(BS);
    n2 = token_ns::replace_space(second_line, amp, B);
    second_line.push_front(B);
    second_line.push_back(BS);
    if (!c) {
        n3 = token_ns::replace_space(third_line, amp, C);
        third_line.push_front(C);
        third_line.push_back(BS);
    }

    if (n3 > n1) n1 = n3;
    if (n2 > n1) n1 = n2;
    n1++;
    TokenList res;
    res.push_back(hash_table.OB_token);
    while (n1 > 0) {
        --n1;
        res.push_back(Token(other_t_offset, 'l'));
    }
    res.push_back(hash_table.CB_token);
    res.splice(res.end(), first_line);
    res.splice(res.end(), second_line);
    res.splice(res.end(), third_line);
    res.add_env("tabular");
    if (tracing_commands()) {
        Logger::finish_seq();
        the_log << "{Gloss: " << res << "}\n";
    }
    back_input(res);
}

//      eTEX ----------------------------------------------------------

void Parser::T_etex() { parse_error(cur_tok, "Unimplemented e-TeX extension ", cur_tok, "", "unimp"); }

// --------------------------------------------------------------------
// GB4e

auto mk_ensure(const std::string &a, const std::string &b) -> std::string { return a + "{\\ensuremath{" + b + "}}"; }

// We should perhaps do something with this list ??
void gb4eboot() {
    LineList    L;
    std::string matha1       = "{\\mathrm{#1}}";
    std::string open_bra     = "{[}";
    std::string close_bra    = "{]}";
    std::string simple_index = "\\sb" + matha1 + "\\;";
    std::string double_index = "\\sb{" + matha1 + "\\sb{#2}}";
    L.insert("%% Begin bootstrap commands for gb4e", true);
    L.insert(R"(\def\lb#1{\@ifnextchar [{\@glarph{#1}}{\@bl{#1}}})", true);
    L.insert(mk_ensure("\\def\\@glarph#1[#2]", open_bra + double_index), true);
    L.insert(mk_ensure("\\def\\@bl#1", open_bra + simple_index), true);
    L.insert(R"(\def\rb#1{\@ifnextchar [{\@grarph{#1}}{\@br{#1}}})", true);
    L.insert(mk_ensure("\\def\\@grarph#1[#2]", close_bra + double_index), true);
    L.insert(mk_ensure("\\def\\@br#1", close_bra + simple_index), true);
}

// --------------------------------------------------------------------
// DATES

// Dispatcher function
void Parser::date_commands(subtypes c) {
    if (c == 0)
        is_date_valid();
    else if (c == 1)
        count_days();
    else if (c == 2)
        next_date();
    else if (c == 3)
        prev_date();
    else if (c == 4)
        datebynumber();
}

// Stores the value c in the counter T if possible
void Parser::set_counter(Token T, long c) {
    see_cs_token(T);
    if (cur_cmd_chr.cmd != assign_int_cmd) return;
    word_define(cur_cmd_chr.chr, c, false);
}

// Stores the value c in the counter T if possible
auto Parser::get_counter(Token T) -> long { // \todo rewrite properly
    long c = 0;
    see_cs_token(T);
    if (cur_cmd_chr.cmd != assign_int_cmd) return c;
    c = eqtb_int_table[cur_cmd_chr.chr].val;
    return c;
}

// Reads three counter names; return true if OK
auto Parser::scan_date_ctrs() -> bool {
    year_ctr  = hash_table.relax_token;
    month_ctr = hash_table.relax_token;
    day_ctr   = hash_table.relax_token;
    bool bad  = M_counter(false);
    bool res  = true;
    if (!bad) {
        get_token();
        year_ctr = cur_tok;
    } else
        res = false;
    bad = M_counter(false);
    if (!bad) {
        get_token();
        month_ctr = cur_tok;
    } else
        res = false;
    bad = M_counter(false);
    if (!bad) {
        get_token();
        day_ctr = cur_tok;
    } else
        res = false;
    return res;
}

// This sets the three counters
void Parser::set_date_ctrs(long year, size_t month, size_t day) {
    set_counter(year_ctr, year);
    set_counter(month_ctr, to_signed(month));
    set_counter(day_ctr, to_signed(day));
}

// This sets the three counters
void Parser::get_date_ctrs(long &year, size_t &month, size_t &day) {
    year  = get_counter(year_ctr);
    month = to_unsigned(get_counter(month_ctr));
    day   = to_unsigned(get_counter(day_ctr));
}

// True if year Y is a leap year

auto is_leap_year(long y) -> bool {
    if ((y % 4) != 0) return false;
    if (y <= 1500) return true;
    if (y % 100 == 0) return y % 400 == 0;
    return true;
}

// Returns number of days in the year
auto date_ns::year_length(long y) -> size_t {
    if (y == 1582) return 355;
    if (is_leap_year(y)) return 366;
    return 365;
}

// Returns number of days in the month
auto date_ns::month_length(long y, size_t m) -> size_t {
    if (m != 2) return month_length_table[m];
    if (is_leap_year(y)) return 29;
    return 28;
}

// Return true if valid, signals error otherwise
auto date_ns::check_date(long y, size_t m, size_t d) -> bool {
    std::string Bad;
    size_t      ml = 0;
    if (y <= 0)
        Bad = "year<1";
    else if (m <= 0)
        Bad = "month<1";
    else if (m > 12)
        Bad = "month>12";
    else if (d < 1)
        Bad = "day<1";
    else {
        ml = date_ns::month_length(y, m);
        if (d > ml)
            Bad = ".";
        else if (y == 1582 && m == 10 && d > 4 && d < 15)
            Bad = "inexistant day";
    }
    if (Bad.empty()) return true;
    local_buf = "Date error: ";
    if (Bad[0] == '.')
        local_buf.format("day>{}", ml);
    else
        local_buf += Bad;
    local_buf.format(" {}/{}/{}", y, m, d);
    the_parser.parse_error(the_parser.err_tok, local_buf);
    return false;
}

// Returns the number of days between start/01/01 and cur/month/day
void Parser::count_days() {
    Token T   = cur_tok;
    bool  bad = M_counter(false);
    if (!bad) get_token();
    Token ctr   = cur_tok;
    auto  start = scan_braced_int(T);
    auto  cur   = scan_braced_int(T);
    auto  month = to_unsigned(scan_braced_int(T));
    auto  day   = scan_braced_int(T);
    if (bad) return;
    long                       c           = 0;
    static std::array<int, 13> month_table = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    for (auto y = start; y < cur; y++) c += to_signed(date_ns::year_length(y));
    c += month_table[month];
    if (is_leap_year(cur) && month > 2) c++;
    if (cur == 1582 && (month > 10 || (month == 10 && day > 14))) c -= 10;
    c += day;
    set_counter(ctr, c);
}

void Parser::datebynumber() {
    Token T     = cur_tok;
    auto  start = scan_braced_int(T);              // start date
    auto  val   = to_unsigned(scan_braced_int(T)); // value to convert
    scan_date_ctrs();                              // fetch the counters
    auto   year = start;
    size_t c    = 1;
    for (;;) {
        auto n = date_ns::year_length(year);
        if (c + n <= val) {
            c += n;
            ++year;
        } else
            break;
    }
    size_t month = 1;
    for (int i = 1; i <= 12; i++) {
        auto n = date_ns::month_length(year, month);
        if (c + n <= val) {
            c += n;
            ++month;
        } else
            break;
    }
    size_t day = 1 + val - c;
    set_date_ctrs(year, month, day);
}

// gives date of yesterday
void date_ns::prev_date(long &year, size_t &month, size_t &day) {
    --day;
    if (year == 1582 && month == 10 && day == 14) day = 4;
    if (day > 0) return;
    --month;
    if (month == 0) {
        month = 12;
        --year;
    }
    day = date_ns::month_length(year, month);
}

// gives date of tomorrow
void date_ns::next_date(long &year, size_t &month, size_t &day) {
    ++day;
    if (year == 1582 && month == 10 && day == 5) day = 15;
    auto ml = date_ns::month_length(year, month);
    if (day <= ml) return;
    day = 1;
    ++month;
    if (month <= 12) return;
    month = 1;
    ++year;
}

void Parser::next_date() {
    scan_date_ctrs(); // fetch the counters
    long   year  = 0;
    size_t month = 0;
    size_t day   = 0;
    get_date_ctrs(year, month, day);
    date_ns::check_date(year, month, day);
    date_ns::next_date(year, month, day);
    set_date_ctrs(year, month, day);
}

void Parser::prev_date() {
    scan_date_ctrs(); // fetch the counters
    long   year  = 0;
    size_t month = 0;
    size_t day   = 0;
    get_date_ctrs(year, month, day);
    date_ns::check_date(year, month, day);
    date_ns::prev_date(year, month, day);
    set_date_ctrs(year, month, day);
}

void Parser::is_date_valid() {
    Token T = cur_tok;
    auto  y = scan_braced_int(T);
    auto  m = to_unsigned(scan_braced_int(T));
    auto  d = to_unsigned(scan_braced_int(T));
    date_ns::check_date(y, m, d);
}

// C is even for a month, odd for a day
void Parser::month_day(subtypes c) {
    Token T  = cur_tok;
    auto  n0 = scan_braced_int(cur_tok);
    if (n0 <= 0 || n0 > ((int(c) & 1) != 0 ? 7 : 12)) {
        if (tracing_macros())
            the_log << T << "<-"
                    << "\n";
        return;
    }
    auto                               n  = to_unsigned(n0);
    static std::array<std::string, 12> fm = {"janvier", "f\\'evrier", "mars",      "avril",   "mai",      "juin",
                                             "juillet", "ao\\^ut",    "septembre", "octobre", "novembre", "d\\'ecembre"};
    static std::array<std::string, 12> sm = {"enero", "febrero", "marzo",      "abril",   "mayo",      "junio",
                                             "julio", "agosto",  "septiembre", "octubre", "noviembre", "diciembre"};
    static std::array<std::string, 12> gm = {"Januar", "Februar", "M\\\"arz",  "April",   "Mai",      "Juni",
                                             "Juli",   "August",  "September", "Oktober", "November", "Dezember"};
    static std::array<std::string, 12> em = {"January", "February", "March",     "April",   "May",      "June",
                                             "July",    "August",   "September", "October", "November", "December"};

    static std::array<std::string, 7> fd = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};
    static std::array<std::string, 7> sd = {"Lunes", "Martes", "Mi\\'ercoles", "Jueves", "Viernes", "S\\'abado", "Domingo"};
    static std::array<std::string, 7> gd = {"Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag", "Sonntag"};
    static std::array<std::string, 7> ed = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    std::string s;
    switch (c) {
    case md_frenchm_code: s += fm[n - 1]; break;
    case md_frenchd_code: s += fd[n - 1]; break;
    case md_spanishm_code: s += sm[n - 1]; break;
    case md_spanishd_code: s += sd[n - 1]; break;
    case md_germanm_code: s += gm[n - 1]; break;
    case md_germand_code: s += gd[n - 1]; break;
    case md_englishm_code: s += em[n - 1]; break;
    case md_englishd_code: s += ed[n - 1]; break;
    default: break;
    }
    TokenList L = tokenize_buffer(s, "(month and day)");
    if (tracing_macros()) the_log << T << "<-" << L << "\n";
    back_input(L);
}
