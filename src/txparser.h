#pragma once
// -*- C++ -*-
// TRALICS, copyright (C)  INRIA/apics (Jose' Grimm) 2003-2004, 2007,2008

// This software is governed by the CeCILL license under French law and
// abiding by the rules of distribution of free software.  You can  use,
// modify and/ or redistribute the software under the terms of the CeCILL
// license as circulated by CEA, CNRS and INRIA at the following URL
// "http://www.cecill.info".
// (See the file COPYING in the main directory for details)

#include "txcond.h"
#include "txhash.h"
#include "tximage.h"
#include "txio.h"
#include "txstack.h"
#include "txstats.h"

// This file holds the definition of the Parser class, which is the main
// data structure of the Tralics translator.

class Parser {
    // Make all tables public
    friend class XkvSetkeys;

public:
    Hashtab                                   hash_table;        // the hash table
    Mactab                                    mac_table;         // the table of macros
    Stack                                     the_stack;         // the stack
    std::array<EqtbString, 10>                eqtb_string_table; // eqtb strings
    std::array<EqtbInt, integer_table_size>   eqtb_int_table;    // EQTB, integers
    std::array<EqtbDim, dimension_table_size> eqtb_dim_table;    // EQTB, dimensions
    std::array<EqtbToken, toks_register_size> toks_registers;    // EQTB, token lists
    std::array<EqtbBox, nb_registers>         box_table;         // EQTB, boxes
    std::array<EqtbGlue, glue_table_size>     glue_table;        // EQTB, glue
    std::array<Token, nb_characters>          verbatim_chars;    // value of a character in verbatim mode
    std::array<int, nb_shortverb_values>      old_catcode;       // catcodes for undefineshortverb
    std::array<int, 9>                        allocation_table;  // values for \newcount etc
    std::array<bool, nb_xspace_values>        ok_for_xspace;     // status of char w.r.t. \xspace
    std::array<Token, 22>                     uclc_list;         // upper, lowert case equivalent of \ij etc
    FontInfo                                  cur_font;          // info for the current font
    std::vector<Image>                        the_images;        // file data for images
    std::vector<Xml *>                        all_heads;
    Stats                                     my_stats; // for the statistics
    Token                                     err_tok;  // in case of error
private:
    bool      unexpected_seen_hi{false}; // check for wrongly placed font changes
    bool      calc_loaded;               // did we see \usepackage{calc} ?
    bool      numbered_verbatim;         // has this verbatim line numbers ?
    bool      restricted;                // are we in restricted mode ?
    bool      force_eof{false};          // did we see \endinput ?
    bool      no_new_file{false};        // can we pop the input stack ?
    bool      file_ended;                //
    bool      chapter_has_star{false};   // true in frontmatter, backmatter
    bool      use_quotes;
    bool      list_files_p;            // Should we list the files at the end ?
    bool      tok_is_defined;          // use by \ifcsname
    int       old_nberrs;              // previous number of errors
    int       cur_line;                // current input line number
    int       begin_env_line{0};       // input line number of
    int       ra_year{1789};           // default year if none given as argument
    int       default_language_num{0}; // default language
    int       cur_level;               // current level on the execution stack
    int       equation_ctr_pos;        // position in the table of the counter equation
    states    state;                   // current state of the scanner
    Token     cur_tok;                 // current token
    Token     after_assignment_token;  // token for \afterassignment
    CmdChr    cur_cmd_chr;             // current command code and modifier
    int       sectionning_offset;      // what is the main section, part, chapter ?
    l_state   long_state;              // Error recovery handling (\long)
    scan_stat scanner_status;          // Error recovery handling (\outer)
    int       cur_in_chan;             // if get_token call get_a_new_line
    int       cur_file_pos{0};         // pos of file in the package list (0= none)

    std::string cur_env_name;  // name of current environment
    std::string the_url_val;   // this may be <URSophia>, raweb only
    std::string the_projetval; // this could be miaou
    std::string year_string;   // the year (effective number)
    std::string job_name;      // the name, without extensions

    Buffer                 input_buffer;                          // input buffer
    Buffer                 mac_buffer;                            // buffer the current macro
    Buffer                 group_buffer;                          // buffer for arg of \begin{...} \end(...)
    Buffer                 unprocessed_xml;                       // chars to be converted into an XML element
    Buffer                 fetch_name_res;                        // used by fetch_name
    LinePtr                lines;                                 // the lines to  be read
    TokenList              TL;                                    // list of tokens to be read again
    Condition              conditions;                            // condition stack for current \if
    SthInternal            cur_val;                               // result of scan_something internal
    TokenList              document_hook;                         // the document-hook
    TokenList              end_document_hook;                     // the end-document-hook
    codepoint              verb_saved_char;                       // Char to use for verb by ShortVewrb
    std::vector<codepoint> input_line;                            // input line converted to chars
    uint                   input_line_pos{0};                     // position in input_line
    Xml *                  the_xmlA{nullptr}, *the_xmlB{nullptr}; // for XML tree manipulations
    // private inline functions
private:
    auto               at_eol() -> bool { return input_line_pos >= input_line.size(); }
    auto               get_next_char() -> codepoint { return input_line[input_line_pos++]; }
    [[nodiscard]] auto get_catcode(int x) const -> symcodes { return symcodes(eqtb_int_table[x].get_val()); }
    void               set_catcode(int x, int v) { // untraced version of catcode modification
        eqtb_int_table[x].set_val(v);
    }
    auto get_after_ass_tok() -> Token {
        Token x = after_assignment_token;
        after_assignment_token.kill();
        return x;
    }
    [[nodiscard]] auto get_def_language_num() const -> int { return default_language_num; }
    [[nodiscard]] auto get_projet_val() const -> std::string { return the_projetval; }
    auto               get_ur_val() -> std::string { return the_url_val; }
    [[nodiscard]] auto is_pos_par(int k) const -> bool { return eqtb_int_table[k].get_val() > 0; }
    void               kill_line() { input_line.clear(); }
    void               see_cs_token() { cur_cmd_chr = hash_table.eqtb[cur_tok.eqtb_loc()].get_cmdchr(); }
    void               see_cs_token(Token T) {
        cur_tok = T;
        see_cs_token();
    }
    void see_char_token(Token t) {
        cur_cmd_chr.set_cmd(t.cmd_val());
        cur_cmd_chr.set_chr(t.chr_val());
    }
    void               set_after_ass_tok(Token x) { after_assignment_token = x; }
    void               set_cat(int c, int v) { eqtb_int_table[c].set_val(v); }
    void               set_def_language_num(int x) { default_language_num = x; }
    [[nodiscard]] auto tracing_io() const -> bool { return is_pos_par(tracingoutput_code); }
    [[nodiscard]] auto tracing_macros() const -> bool { return is_pos_par(tracingmacros_code); }
    // public inline functions
public:
    auto get_cur_env_name() -> std::string & { return cur_env_name; }

    void               back_input() { TL.push_front(cur_tok); }
    void               back_input(Token t) { TL.push_front(t); }
    void               back_input(TokenList &L) { TL.splice(TL.begin(), L); }
    void               brace_me(TokenList &L);
    [[nodiscard]] auto cur_centering() const -> int { return eqtb_int_table[incentering_code].get_val(); }
    [[nodiscard]] auto cur_lang_fr() const -> bool { return eqtb_int_table[language_code].get_val() == 1; }
    [[nodiscard]] auto cur_lang_german() const -> bool { return eqtb_int_table[language_code].get_val() == 2; }
    auto               cur_line_to_istring() -> Istring;
    void               decr_cur_level() { cur_level--; }
    auto               get_cur_filename() -> std::string { return lines.get_file_name(); }
    [[nodiscard]] auto get_cur_file_pos() const -> int { return cur_file_pos; }
    auto               get_cur_level() -> int { return cur_level; }
    [[nodiscard]] auto get_cur_line() const -> int { return cur_line; }
    auto               get_cur_val() -> SthInternal & { return cur_val; }
    [[nodiscard]] auto get_job_name() const -> std::string { return job_name; }
    [[nodiscard]] auto get_list_files() const -> bool { return list_files_p; }
    [[nodiscard]] auto get_ra_year() const -> int { return ra_year; }
    [[nodiscard]] auto get_year_string() const -> std::string { return year_string; }
    void               init(LinePtr x) { lines = std::move(x); }
    void               remember_ur(std::string s) { the_url_val = std::move(s); }
    void               set_cur_line(int x) { cur_line = x; }
    void               set_cur_file_pos(int k) { cur_file_pos = k; }
    void               set_cur_env_name(std::string s) {
        cur_env_name   = std::move(s);
        begin_env_line = cur_line;
    }
    void set_cur_env_name(std::string s, int x) {
        cur_env_name   = std::move(s);
        begin_env_line = x;
    }
    void               set_ra_year(int x) { ra_year = x; }
    void               set_job_name(std::string s) { job_name = std::move(s); }
    void               set_projet_val(std::string s) { the_projetval = std::move(s); }
    void               set_year_string(std::string s) { year_string = std::move(s); }
    [[nodiscard]] auto tracing_commands() const -> bool { return is_pos_par(tracingcommands_code); }
    [[nodiscard]] auto tracing_assigns() const -> bool { return is_pos_par(tracingassigns_code); }
    [[nodiscard]] auto tracing_math() const -> bool { return is_pos_par(tracingmath_code); }
    [[nodiscard]] auto tracing_stack() const -> bool { return is_pos_par(tracingrestores_code); }
    void               unexpected_font() { unexpected_seen_hi = true; }
    void               L3_load(bool);
    // public functions
public:
    Parser();

    void               add_buffer_to_document_hook(Buffer &b, const std::string &);
    void               add_language_att();
    void               after_main_text();
    void               boot();
    void               boot_special_names();
    void               box_end(Xml *, int);
    auto               list_to_string0(Buffer &b) -> bool;
    auto               list_to_string(TokenList &L, Buffer &b) -> bool;
    auto               list_to_string_cv(TokenList &L, Buffer &b) -> bool;
    void               list_to_string_c(TokenList &x, String s1, String s2, String msg, Buffer &B);
    auto               list_to_string_c(TokenList &x, String s1, String s2, String msg) -> Token;
    auto               list_to_string_c(TokenList &x, String msg) -> std::string;
    auto               csname_aux(String s1, String s2, TokenList &L, bool cs, Buffer &b) -> bool;
    auto               csname_aux(TokenList &L, bool cs, Buffer &b) -> bool;
    auto               csname_ctr(TokenList &L, Buffer &b) -> bool;
    void               eq_define(int a, CmdChr, bool gbl);
    void               titlepage_evaluate(String s, const std::string &);
    void               final_checks();
    void               finish_images();
    void               flush_buffer();
    void               font_has_changed1();
    auto               fp_read_value() -> FpNum;
    void               fp_send_one_arg(TokenList &res);
    [[nodiscard]] auto get_scanner_status() const -> scan_stat { return scanner_status; }
    [[nodiscard]] auto get_long_state() const -> l_state { return long_state; }
    [[nodiscard]] auto has_letter_catcode(int x) const -> bool { return get_catcode(x) == letter_catcode; }
    void               init_all(std::string doc_elt);
    void               load_latex();
    auto               read_arg() -> TokenList;
    auto               read_arg_nopar() -> TokenList;
    auto               nct_aux(Token, TokenList &) -> int;
    auto               nE_arg_nopar() -> Istring;
    auto               nT_arg_nopar() -> Istring;
    auto               nT_optarg_nopar() -> Istring;
    void               parse_error(Token, const std::string &, TokenList &);
    void               parse_error(Token, const std::string &);
    void               parse_error(Token, String);
    void               parse_error(String);
    void               parse_error(Token, const std::string &, const std::string &);
    void               parse_error(Token, const std::string &, Token, const std::string &, const std::string &);
    void               parse_error(Token, const std::string &, const std::string &, const std::string &);
    void               print_cmd_chr(CmdChr);
    void               remove_junk();
    void               scan_eqno(math_list_type);
    void               scan_glue(internal_type level);
    void               scan_glue(internal_type level, Token T);
    void               scan_glue(internal_type level, Token T, bool);
    void               list_to_glue(internal_type level, Token t, TokenList &L);
    void               set_default_language(int v);
    void               set_scanner_status(scan_stat c) { scanner_status = c; }
    void               set_long_state(l_state c) { long_state = c; }
    void               signal_error(String);
    void               signal_error();
    void               signal_error(Token, String);
    void               signal_ovf(Token, String, int, int);
    auto               special_expand(TokenList *args) -> TokenList;
    auto               special_tpa_arg(String n, String y, bool par, bool env, bool has_q) -> Xml *;
    void               T_titlepage_finish(int v);
    auto               tpa_exec(String) -> Xml *;
    void               M_tracingall();
    void               translate0();
    void               translate_all();
    void               word_define(int a, int c, bool gbl);
    auto               find_a_save_key(const std::string &mykey) -> bool;
    auto               expand_mac_inner(const TokenList &W, TokenList *) -> TokenList;
    void               mu_error(String, int);
    void               expand_nct(TokenList &L);
    void               token_for_show(const CmdChr &);
    void               create_label(const std::string &, Istring S);

    // private functions, alphabetic order
private:
    auto stack_math_in_cell() -> bool;
    void E_accent_a();
    void E_accent();
    void E_user(bool, subtypes, symcodes);
    void E_first_of_two(bool, subtypes);
    void E_first_of_three(bool, subtypes);
    void E_first_of_four(bool, subtypes);
    void E_ignore_n_args(bool, subtypes);
    void accent_err1();
    void accent_err2(Token Y);
    void accent_err3();
    void accent_err4();
    void add_bib_marker(bool);
    void add_math_label(Xml *);
    void tokenize_buffer(Buffer &b, TokenList &L, const std::string &);
    void add_vspace(Token T, ScaledInt, Xid);
    void after_parameter(bool exp, int);
    void after_math(bool);
    void append_glue(Token, ScaledInt, bool);
    void arg_font(subtypes);
    void assign_def_something(bool gbl);
    void assign_toks(Token T, int, bool gbl);
    void back_input_braced(TokenList &);
    void back_input_pt(bool);
    void back_input_unless_space();
    void bad_counter0();
    void bad_counter1(const Buffer &, Equivalent &);
    void bad_csname(bool);
    void bad_definition(Token, int);
    void bad_delimited(int, Token x);
    void bad_end_env(int);
    void bad_group_char();
    void bad_macro_prefix(Token, Token);
    void bad_nbargs(int k);
    void missing_number();
    void bad_number();
    void bad_number1(Buffer &);
    void bad_redefinition(int, Token);
    auto before_mac_arg() -> bool;
    void begin_box(int, subtypes);
    void boot_NAO();
    void boot_fp();
    void boot_time();
    void boot_uclc();
    void boot_verbatim();
    void boot_xspace();
    void box_define(int a, Xml *c, bool gbl);
    void calc_aux(SthInternal &A);
    void calc_main(internal_type type, SthInternal &res, TokenList &B);
    void calc_mul_aux(SthInternal &res);
    void calc_primitive(SthInternal &A);
    void calc_ratio_eval(int num, int den, SthInternal &res);
    void calc_spec_mul(RealNumber, SthInternal &res);
    void call_define_key(TokenList &L, Token cmd, const std::string &arg, const std::string &fam);
    void T_case_shift(int);
    void check_all_ids();
    auto check_brace(int &) -> bool;
    auto check_builtin_pack(const std::string &) -> bool;
    void check_builtin_class(const std::string &);
    auto check_if_redef(const std::string &s) -> bool;
    void check_language();
    void check_module_title(TokenList &L);
    void check_outer_validity();
    void E_if_test(subtypes, bool);
    void E_convert();
    void count_days();
    auto M_counter(bool def) -> bool;
    void E_counter(int);
    auto counter_aux(const std::string &, String, Token T) -> bool;
    void counter_boot(String, String);
    auto counter_check(Buffer &, bool) -> bool;
    auto counter_read_opt(String) -> int;
    void counter_overflow(Token, int, int);
    void close_all();
    void create_aux_file_and_run_pgm();
    void E_csname();
    void csname_arg();
    auto cur_group_type() -> int;
    void date_commands(int);
    void datebynumber();
    void dbl_arg();
    void M_declare_math_operator();
    void declaretopics();
    void default_bp(Buffer &B, Token T, TokenList &val);
    void define_bool_key(subtypes);
    void define_choice_key();
    void define_cmd_key(subtypes);
    void define_something(int chr, bool gbl, symcodes w);
    auto delimiter_for_verb(bool &special_space) -> codepoint;
    auto delimiter_for_saveverb() -> codepoint;
    auto dimen_attrib(ScaledInt) -> Istring;
    auto dimen_from_list(Token, TokenList &) -> ScaledInt;
    void dimen_from_list0(Token, TokenList &);
    void dim_define(int a, ScaledInt c, bool gbl);
    void disable_keys();
    auto do_register_arg(int q, int &p, Token &) -> int;
    void do_register_command(bool gbl);
    void dump_save_stack();
    auto edef_aux(TokenList &L) -> bool;
    void english_quotes(CmdChr);
    void enter_file_in_table(const std::string &, bool);
    auto env_helper(const std::string &s) -> SaveAuxEnv *;
    void examine_token(Token);
    void exec_calc();
    void exec_fp_cmd(subtypes);
    void exec_fpi_cmd(subtypes);
    void expand();
    void E_car(bool);
    void expand_first(TokenList &L);
    auto T_ifthenelse_inner(Token) -> bool;
    void T_ifthenelse();
    auto T_ifthenelse(TokenList &) -> bool;
    auto E_ifx() -> bool;
    void expand_mac(Macro &X);
    void T_mark(subtypes);
    void expand_no_arg0(Token);
    void expand_no_arg(const std::string &);
    void expand_spaces();
    void expand_twoargs();
    void T_verbatim(int, Token, Token, Token);
    void expand_verb(unsigned char t);
    void T_verb(codepoint t);
    void expand_verb1(TokenList &);
    void expand_when_ok(bool);
    auto to_stringE(TokenList &L) -> std::string;
    void extended_chars(unsigned int c);
    void extra_close_brace(int cl);
    void extra_fi_or_else();
    void extract_keys(TokenList, std::vector<std::string> &);
    auto eval_condition(subtypes) -> bool;

    auto false_end_tabular(const std::string &) -> bool;
    void fast_new_macro(TokenList &L, Token name);
    void fetch_box_id(Xml *);
    auto fetch_csname(bool) -> Token;
    auto fetch_name0() -> String;
    auto fetch_name0_nopar() -> String;
    auto fetch_name1(TokenList &L) -> String;
    void fetch_name2();
    auto fetch_name_opt() -> String;
    auto find_env_token(const std::string &name, bool beg) -> Token;
    void E_get_config(int c);
    void finish_a_cell(Token T, Istring a);
    void finish_counter_cmd(Token, TokenList &L);
    void finish_csname(const Buffer &, String);
    void finish_csname(const Buffer &);
    void E_fi_or_else();
    void finish_index();
    void finish_color();
    void finish_pers();
    void finish_kvo_bool(Token, const std::string &, const std::string &);
    void finish_iwhile(TokenList &A, Token D);
    void finish_par_cmd(bool, Istring);
    void finish_trivial_math(Xml *);
    void finish_no_mathml(bool, int);
    auto first_boundary() -> boundary_type;
    void E_all_of_one(Token, int);
    void flush_buffer0();
    void flush_buffer1();
    void fnhack();
    void font_has_changed();
    void formatdate();
    auto scan_double_hat(codepoint cc) -> bool;
    void fp_boolean(bool);
    void fp_calla(Token);
    void fp_callb(Token);
    void fp_callc(Token);
    void fp_calld(Token);
    void fp_calle(Token);
    void fp_e_arcsin(subtypes);
    void fp_e_csolve();
    void fp_e_eval();
    void fp_e_lsolve();
    void fp_e_pascal();
    void fp_e_qsolve();
    void fp_e_qqsolve();
    void fp_e_upn();
    void fp_eval_lt(subtypes);
    void fp_eval_unarytest(subtypes);
    void fp_finish(FpNum X);
    void fp_parse_error(Token, Token);
    void fp_prepare();
    void fp_print();
    auto fp_read_int() -> int;
    void fp_set();
    void fp_setseed();
    void fp_special_expand(TokenList &B);
    void french_punctuation(CmdChr X);
    auto get_a_new_line() -> bool;
    auto get_attval() -> std::string;
    auto get_ctb_opt() -> name_positions;
    auto get_trees_opt() -> name_positions;
    auto get_c_val(Token) -> Istring;
    void get_counter(Token, int &);
    auto get_index_value() -> int;
    void get_date_ctrs(int &, int &, int &);
    void get_def_nbargs(Macro *X, Token name);
    auto get_lrcs_opt() -> name_positions;
    auto cs_from_input() -> Token;
    auto get_mac_value(Token) -> TokenList;
    auto get_mac_value(const std::string &) -> TokenList;
    auto read_mac_nbargs() -> int;
    void M_newcommand(rd_flag redef);
    void get_new_command_aux(const TokenList &);
    void M_new_env(rd_flag redef);
    auto read_latex_macro() -> Macro *;
    auto get_opt_dim(Token) -> Istring;
    auto get_token() -> bool;
    auto get_itoken() -> bool;
    auto get_token_o() -> bool;
    auto get_r_token(bool br = false) -> Token;
    auto get_x_token() -> bool;
    void get_x_token_or_active_char(symcodes &a, subtypes &b);
    void glue_define(int a, Glue c, bool gbl);
    auto grab_env_comma(TokenList &) -> bool;
    void grab_env(TokenList &);
    auto group_to_string() -> std::string;
    auto group_to_string_spec(bool) -> std::string;
    void iexpand();
    void T_ifdefinable();
    void E_ifempty();
    void T_ifnextchar(bool);
    void T_ifstar();
    void E_ifundefined(bool);
    void ignore_arg();
    auto T_raw_env(bool) -> std::string;
    void ignore_optarg();
    auto ileave_v_mode() -> Xid;
    void implicit_par(subtypes);
    void improper_alpha();
    void includegraphics(subtypes);
    auto index_aux(TokenList &L, int father, int) -> int;
    void initialise_font();
    void E_the_traced(Token T, subtypes);
    auto E_the(subtypes) -> TokenList;
    void insert_endline_char();
    void insert_every_bib();
    void insert_relax();
    void insert_hook(int);
    void internal_choice_key();
    void internal_define_key(Token T);
    void internal_define_key_default(Token T, TokenList &L);
    auto internal_makebox() -> Xml *;
    void interpret_genfrac_cmd(int res, subtypes, CmdChr);
    void interpret_mathchoice_cmd(int res, subtypes, CmdChr);
    void interpret_math_cmd(int res, subtypes);
    void interpret_rc();
    void invalid_key(Token T, const std::string &, const TokenList &);
    auto is_delimiter(const TokenList &L) -> bool;
    void is_date_valid();
    auto is_env_on_stack(const std::string &s) -> SaveAuxEnv *;
    auto is_input_open() -> bool;
    auto is_inner_math() -> bool;
    auto is_not_a_math_env(String s) -> bool;
    auto is_verbatim_end() -> bool;
    void E_iwhile(subtypes);
    void key_ifundefined();
    void kvo_bool_key();
    void kvo_bool_opt();
    void kvo_comp_opt();
    void kvo_family(subtypes k);
    void kvo_family_etc(subtypes k);
    auto kvo_getfam() -> std::string;
    void kvo_process();
    void kvo_string_opt();
    void kvo_void_opt();
    void kvo_void_key();
    auto last_att_list() -> AttList &;
    void E_latex_ctr();
    void E_latex_ctr_fnsymbol(int, TokenList &);
    auto latex_input(int) -> std::string;
    void LC();
    void leave_h_mode();
    void leave_v_mode();
    void lost_if(Token T, int);
    void mac_define(Token a, Macro *b, bool gbl, rd_flag redef, symcodes);
    void make_catcodes();
    auto make_cit_ref(Istring, Istring) -> Xml *;
    void make_constants();
    void makelabel();
    void make_token(String);
    void make_uclc_table();
    auto math_argument(int, Token) -> subtypes;
    auto math_dimen_attrib(Token C, String s) -> int;
    auto math_lr_value() -> del_pos;
    void math_only();
    void E_mathversion();
    void minus_sign(CmdChr X);
    void missing_argument();
    void missing_close_brace(int);
    void missing_equals(Token);
    void missing_flush();
    void missing_open_brace();
    void mklcuc(int c, int lc, int uc);
    void mklcuc(int c, int uc);
    void mk_hi(String, char);
    void month_day(subtypes);
    void more_bootstrap();
    void multiple_label(String, int, const std::string &);
    void multiply_dim(RealNumber val, int v);
    void E_multispan();
    auto my_csname(String s1, String s2, TokenList &L, String s) -> bool;
    auto nb_env_on_stack(const std::string &s) -> int;
    auto nb_env_on_stack() -> int;
    void need_array_mode();
    void need_bib_mode();
    auto next_arg_is_project() -> bool;
    void next_date();
    void next_day();
    void next_from_list();
    auto next_from_line() -> bool;
    auto next_from_line0() -> bool;
    void M_newboolean(subtypes);
    void new_constant(subtypes);
    void new_constant(String name, int max_val, subtypes alloc_pos, symcodes c);
    void M_newif();
    void M_newif_aux(Token T, const std::string &s, bool b);
    void new_font();
    auto new_line_for_read(bool) -> bool;
    void new_macro(const std::string &s, Token name);
    void new_macro(TokenList &L, Token name, bool gbl);
    void new_macro(TokenList &L, Token name);
    auto new_math_list(int, math_list_type, subtypes s) -> subtypes;
    void new_prim(String, TokenList &);
    void new_prim(String, String);
    void new_prim(Token, Token);
    void new_primx(String, String);
    void new_prim(Token, TokenList &);
    void new_xref(Xml *val, std::string v, bool err);
    void no_arg_font();
    void no_extension(AttList &, const std::string &);
    auto T_optarg_nopar() -> Istring;
    void numberwithin();
    auto ok_to_define(Token a, rd_flag redef) -> bool;
    void old_font();
    void one_of_two(TokenList &, TokenList &, bool);
    void one_of_two(bool);
    void open_tex_file(bool);
    void opt_to_mandatory();
    auto optional_enumerate(TokenList &L, String) -> bool;
    void out_warning(Buffer &B, msg_type);
    void parshape_aux(subtypes m);
    void pass_text(Token);
    void M_prefixed_aux(bool);
    void M_prefixed();
    void prefix_error(bool b_global, symcodes K);
    void pop_input_stack(bool);
    void pop_level(boundary_type);
    void pop_all_levels();
    void prev_date();
    void print_token(std::ostream &fp, Token x);
    void process_char(uchar c);
    void process_string(String s);
    void process_char(codepoint c);
    void process_char(uint c);
    void process_char(int s);
    void push_input_stack(const std::string &, bool, bool);
    void push_level(boundary_type);
    void push_module();
    void push_module(const std::string &aux);
    auto push_par() -> Xid;
    void push_save_stack(SaveAux *v);
    void push_tpa();
    void ratio_evaluate(TokenList &A, TokenList &B, SthInternal &res);
    auto read_delimited(const TokenList &L) -> TokenList;
    auto read_elt_id(Token T) -> int;
    auto read_for_variable() -> Token;
    auto read_from_file(int, bool) -> TokenList;
    auto read_mac_body(bool exp) -> TokenList;
    void read_mac_body(TokenList &, bool, int);
    void read_one_space();
    auto read_optarg(TokenList &) -> bool;
    auto read_optarg_nopar(TokenList &) -> bool;
    auto read_until(Token x) -> TokenList;
    auto read_until_nopar(Token x) -> TokenList;
    void read_into(TokenList &X);
    auto read_unit() -> int;
    auto make_label_inner(const std::string &name) -> std::string;
    void refstepcounter();
    void refstepcounter(String, bool);
    void refstepcounter(TokenList &, bool);
    void refstepcounter_inner(TokenList &, bool);
    void remove_element(TokenList &A, TokenList &B, Token C);
    auto remove_initial_plus(bool) -> bool;
    void remove_initial_space();
    void remove_initial_space_and_back_input();
    void remove_initial_space_relax();
    auto remove_initial_star() -> bool;
    void restore_the_state(SaveState &x);
    auto rT_arg_nopar() -> std::string;
    auto sE_arg() -> std::string;
    auto sE_optarg_nopar() -> std::string;
    void runaway(int);
    void err_one_arg(const TokenList &);
    void save_font();
    void save_the_state(SaveState &x);
    auto scan_27bit_int() -> int;
    auto scan_alpha() -> int;
    void scan_box(int);
    auto scan_braced_int(Token) -> int;
    auto scan_char_num() -> int;
    auto scan_color(const std::string &opt, const std::string &name) -> Istring;
    auto scan_date_ctrs() -> bool;
    auto scan_dim_helper(bool mu, bool allow_int) -> bool;
    auto scan_dim2(RealNumber &, bool) -> bool;
    void scan_dimen(bool, Token T);
    void scan_dimen(bool mu, bool inf, glue_spec &, bool shortcut);
    auto scan_dimen1(bool mu, bool inf, glue_spec &, bool shortcut) -> bool;
    void scan_double(RealNumber &res);
    void scan_expr(subtypes);
    auto scan_expr(Token, internal_type) -> bool;
    void scan_expr_arg(Token T, internal_type);
    auto scan_expr_next(Token, bool) -> scan_expr_t;
    auto scan_fifteen_bit_int() -> int;
    auto scan_file_name() -> std::string;
    auto scan_font_ident() -> int;
    auto scan_for_eval(Buffer &B, bool in_env) -> bool;
    auto scan_general_text() -> TokenList;
    auto scan_group0(TokenList &, int) -> bool;
    auto scan_group1(TokenList &res, int &b, int cl) -> bool;
    auto scan_group2(TokenList &) -> bool;
    void scan_group3(TokenList &, int, bool, int);
    void scan_group4(TokenList &, int);
    auto scan_group_opt(TokenList &L, bool &) -> bool;
    auto scan_group_del(TokenList &res, const TokenList &) -> bool;
    auto scan_group_del1(TokenList &, Token x) -> bool;
    void scan_hbox(int, subtypes c);
    void scan_ignore_group();
    auto scan_int(TokenList &, Token) -> int;
    auto scan_int(Token) -> int;
    auto scan_int(Token, int, String) -> int;
    auto scan_int_digs() -> int;
    auto scan_int_internal() -> int;
    auto scan_keyword(String s) -> bool;
    void scan_left_brace();
    void scan_left_brace_and_back_input();
    void scan_math(int, math_list_type);
    auto scan_math1(int) -> int;
    void scan_math2(int, math_list_type, boundary_type);
    void scan_math3(int, math_list_type, int);
    auto scan_math_dollar(int, math_list_type) -> bool;
    auto scan_math_endcell(Token t) -> bool;
    void scan_math_endcell_ok(int);
    auto scan_math_env(int, math_list_type) -> bool;
    auto scan_mathfont_ident() -> int;
    auto scan_math_kern(symcodes, subtypes &) -> ScaledInt;
    void scan_math_hbox(int, subtypes c);
    void scan_math_mi(int, subtypes, subtypes, CmdChr);
    void scan_math_rel(subtypes, int);
    void scan_math_tag(subtypes);
    void scan_optional_equals();
    auto scan_pair_ints(Token T, TokenList &L) -> bool;
    void scan_prime();
    auto scan_reg_num() -> int;
    void scan_rule(int);
    void E_sideset();
    void E_split();
    auto scan_sign() -> bool;
    void scan_something_internal(internal_type, bool);
    void scan_something_internal(internal_type);
    auto scan_special_int_d(Token T, int d) -> int;
    auto scan_style() -> Token;
    void read_toks_edef(TokenList &);
    void scan_toks_absorb();
    void scan_toks_absorb_expand();
    auto scan_twenty_seven_bit_int() -> int;
    void E_scan_up_down(TokenList &, TokenList &, TokenList &, TokenList &);
    void E_scan_up_down();
    void scan_unit(RealNumber R);
    void see_font_change(subtypes);
    void M_future_let(bool);
    void M_let(bool);
    void M_let(Token A, bool global, bool redef);
    void M_let(Token, Token, bool, bool);
    void M_let_fast(Token, Token, bool);
    void M_let(int, bool);

    void M_new_thm();
    void M_def(bool edef, bool gbl, symcodes, rd_flag);
    void see_new_id_spec(bool);
    void selective_sanitize();
    void select_math_font();
    void E_setlength(int c);
    void set_boolean();
    void set_counter(Token, int);
    void set_date_ctrs(int, int, int);
    void setkeys(bool);
    void M_shorthand_define(int cmd, bool gbl);
    auto shorthand_gdefine(int cmd, String, int) -> Token;
    void M_shortverb(int x);
    void short_verb_error(Token T, Token t, int x);
    void show_box(Xml *);
    void skip_group(TokenList &);
    void skip_group0(TokenList &);
    void skip_initial_space();
    void skip_initial_space_and_back_input();
    void skip_over_parens();
    auto skip_prefix(const TokenList &L) -> bool;
    void solve_cite(bool);
    void special_fvset();
    auto special_next_arg() -> std::string;
    void T_verbatim();
    void T_subequations(bool);
    void start_a_cell(bool);
    void start_a_row(int);
    auto start_scan_math(Math &, subtypes) -> bool;
    void start_paras(int, const std::string &, bool);
    void store_new_line(int, bool);
    void string_define(int a, const std::string &c, bool gbl);
    void strip_pt();
    auto sE_arg_nopar() -> std::string;
    auto sT_arg_nopar() -> std::string;
    auto sT_optarg_nopar() -> std::string;
    auto sT_translate(TokenList &L) -> std::string;

    void T_addtomacro(bool);
    void E_addtoreset();
    void T_aftergroup();
    void E_afterfi();
    void E_afterelsefi();
    void T_ampersand();
    void T_arg1(name_positions);
    void T_atdocument(subtypes c);
    void T_at_end_of_class();
    void T_backslash();
    void T_bezier(int);
    void T_bauteursediteurs(subtypes c);
    void T_bibitem();
    void T_biblio();
    void T_bibliostyle();
    void T_bpers();
    void T_beginend(symcodes x);
    void T_begindocument();
    void T_begin(const std::string &);
    void T_cap_or_note(bool);
    void T_change_element_name();
    void T_catperso();
    void T_citation();
    void T_cite(subtypes);
    void T_cite(subtypes, TokenList &, Istring &);
    void T_cite_one();
    void T_cite_type();
    void T_cititem();
    void T_class_error(subtypes);
    void T_cline();
    void M_cons();
    void M_cons(Token, TokenList &);
    void T_cr();
    void T_cst1(int c);
    void T_cst2(int c);
    void T_curves(int c);
    void T_dashline(subtypes c);
    void T_declare_options();
    void T_declare_option_star();
    void T_define_verbatim_env();
    void T_define_key(bool xkv);
    void T_ding();
    void T_documentclass(bool bad);
    void T_empty_bibitem();
    void T_end_tabular(subtypes c);
    void T_end(const std::string &s);
    void T_enddocument(subtypes c);
    void T_endv();
    void T_end_the_biblio();
    void T_end_theorem();
    void E_ensuremath();
    void T_epsfbox();
    void T_error();
    void T_etex();
    void T_execute_options();
    void E_expandafter();
    void T_figure_table(symcodes x, subtypes c);
    void T_color(subtypes c);
    void T_figure_table_end(bool is_fig);
    void T_fancy(String s, TokenList &L);
    void T_fancy();
    void T_filecontents(int spec);
    void T_fbox(subtypes cc);
    void T_fbox_dash_box();
    void T_fbox_rotate_box();
    void T_float(subtypes c);
    void T_fonts(name_positions x);
    void T_glo();
    void T_glossaire();
    void T_gloss(bool c);
    void T_glossaire_end();
    void T_grabenv();
    void T_hanl(subtypes c);
    auto T_hanl_text() -> Xml *;
    auto T_hanl_url() -> Xml *;
    void T_hline(subtypes c);
    auto T_hline_parse(subtypes c) -> int;
    void T_hspace(subtypes c);
    void T_if_package_later(bool c);
    void T_if_package_loaded(bool type);
    void T_if_package_with(bool c);
    void T_ignoreA();
    void T_index(subtypes c);
    void T_input(int q);
    void T_inputclass();
    void T_ipa(subtypes c);
    void T_isin();
    void T_item(int c);
    auto T_item_label(int c) -> Istring;
    void T_keywords();
    void T_label(int c);
    void T_line(subtypes c);
    auto scan_anchor(bool &h) -> std::string;
    void T_listenv(symcodes x);
    void T_listenv_end();
    void T_linethickness(int c);
    void E_loop();
    void T_load_with_options(bool c);
    void T_makebox(bool framed, Token C);
    void T_math(subtypes type);
    void T_matter(subtypes c);
    void T_mbox(subtypes c);
    void T_minipage();
    void T_moreinfo_end();
    void T_multicolumn();
    void T_multiput();
    void T_arg_local();
    void T_arg();
    void T_optarg();
    void T_newline();
    void T_newcolumn_type();
    void T_newthheorem();
    void T_node();
    void T_nodepoint();
    void T_nodeconnect(name_positions W);
    void T_nodecurve(name_positions W);
    void T_nodebox(name_positions W);
    void T_nodetriangle(name_positions W);
    void T_nodecircle(name_positions W);
    void T_barnodeconnect(name_positions W);
    void T_omitcite();
    void T_option_not_used();
    void T_par1(Istring u);
    void T_par1();
    void T_paras(subtypes x);
    void E_parse_encoding(bool vb, subtypes what);
    void T_participants(subtypes x);
    void T_participants_end();
    void T_pass_options(bool c);
    void T_pers();
    void T_pers_ra();
    void T_picture();
    void T_process_options();
    void T_process_options_aux(TokenList &);
    void T_provides_package(bool c);
    void T_put(subtypes c);
    void T_raisebox();
    void E_random();
    void T_rasection();
    void T_ra_startdoc();
    void T_rasection_end();
    void T_reevaluate();
    void T_ref(bool is_ref);
    void T_reevaluate0(TokenList &L1, bool in_env);
    void T_remove_element();
    void T_save_box(bool simple);
    void T_saveverb();
    void E_useverb();
    void T_scan_glue(subtypes c);
    void T_setmode();
    void T_specimp(int c);
    void T_subfigure();
    void T_startprojet(String proj, String loc);
    void T_start_tabular(subtypes c);
    void T_start_the_biblio();
    void T_start_theorem(int c);
    void T_testopt();
    void T_titlepage(int v);
    void T_trees(int c);
    void T_translate(TokenList &X);
    void T_typein();
    void T_twodims(Istring &A, Istring &B, Token C);
    void T_twoints(Istring &A, Istring &B, Token C);
    void T_twoints(TokenList &A, TokenList &B);
    void T_un_box(subtypes c);
    void T_unimp(subtypes c);
    void T_unimplemented_font(subtypes c);
    void E_unless();
    void T_url(subtypes c);
    void T_usefont();
    void T_usepackage();
    void T_use_counter(const std::string &s);
    void T_use_counter();
    void T_xmlelt(subtypes w);
    void T_xmlenv(subtypes c);
    void T_xmlenv_end(subtypes c);
    void T_xmladdatt(subtypes c);
    void T_xfancy();
    void T_xkeyval(subtypes c);
    void E_xspace();
    void TM_fonts();
    void TM_math_fonts(Math &x);
    void TM_tabular_arg(Xid id);

    void Tat_pers();
    void Tat_pers_ra();
    void testoptd(std::string s);
    void M_extension(int cc);
    auto string_to_write(int chan) -> String;
    void tipa_acutemacron();
    void tipa_brevemacro();
    void tipa_circumdot();
    void tipa_colon();
    void tipa_dotacute();
    void tipa_exclam();
    void tipa_gravedot();
    void tipa_normal();
    void tipa_semi();
    void tipa_star();
    void tipa_subumlaut();
    void tipa_subtilde();
    void tipa_subring();
    void tipa_tildedot();
    void tipa_syllabic();
    void token_from_list(Token t);
    void token_list_define(int p, TokenList &c, bool gbl);
    auto token_list_to_dim(TokenList &a, Token C, bool spec) -> ScaledInt;
    auto token_list_to_att(TokenList &a, Token C, bool spec) -> Istring;
    void token_show(int, Buffer &B);
    void token_for_show(bool lg, const CmdChr &, Buffer &B);
    void trace_if(int k);
    void trace_if(String a, int k, String b);
    void trace_if(String a, int k, int b);
    void trace_scan_expr(String s, const SthInternal &v, char t, Token T);
    void translate01();
    void translate02();
    void translate03();
    void translate1();
    void translate_char(CmdChr X);
    void translate_char(uchar c1, uchar c2);
    auto translate_list(TokenList &L) -> Xml *;
    void translate_font_size();
    void umlaut();
    void umlaut_bad();
    void undefined_env(const std::string &s);
    void undefined_mac();
    void unexpected_close_brace();
    void unskip_group(String s);
    void upn_eval(TokenList &l);
    void url_hack(TokenList &L);
    void use_a_package(const std::string &name, bool type, const std::string &date, bool builtin);
    void E_usename(int c, bool vb);
    void user_XML_swap(subtypes c);
    void user_XML_modify(subtypes c);
    void user_XML_fetch();
    auto vb_tokens(codepoint test, TokenList &L, bool before) -> bool;
    void verb_error(Token T, int msg);
    void T_whiledo();
    void E_while(subtypes cc);
    void wrong_mode(String s);
    void wrong_pop(Token T, String a, String b);
    void E_input(int q);
    void xgetfontsize();
    void xkv_checksanitize(Token A, TokenList &B, bool c);
    void xkv_checksanitize(bool c);
    void xkv_fetch_prefix_family();
    void T_xkv_for(subtypes c);
    void xkv_makehd(TokenList &L);
    void xkv_makehd();
    void xkv_merge(bool gbl, int type, TokenList &L, bool mg);
    auto XKV_parse_filename() -> TokenList;
    void XKV_pox();
    auto xkv_save_keys_aux(bool c, int c2) -> bool;
    void xkv_testopta();
    void xkv_unsave_keys(bool c);
    void xkv_fetch_prefix();
    void xkv_class_prefix();
    void XKV_process_execute(bool psw);
    void xkv_declare_option();
    void xkv_process_options();
    void xkv_execute_options();
    void xkv_pass_options(bool c);
    void xml_name(Xml *x, internal_type level);
    auto T_xmllatex() -> std::string;
    void xsetfontsize();
    auto xT_arg_nopar() -> Xml *;
    auto xT_optarg_nopar() -> Xml *;
    void M_xray(subtypes c);
    void E_zapspace();
    auto read_token_arg(Token t) -> bool;
    auto read_token_arg(int cl) -> bool;
    // For latex3
    void E_pdfstrcmp();
    void define_definer(String base, String nsig, String osig);
    void define_definer(String base);
    void l3_after_cond(Token T, bool test, subtypes c);
    void L3_check_cmd(int c);
    void L3_eq_conditional(subtypes s);
    void E_l3expand_aux(subtypes c);
    void E_l3noexpand(subtypes c);
    void E_l3expand_base(subtypes c);
    void l3_expand_N(TokenList &L);
    void l3_expand_o(TokenList &L);
    void l3_reexpand_o(TokenList &L);
    void l3_expand_f(TokenList &L);
    void l3_expand_x(TokenList &L);
    void l3_expand_Vv(TokenList &L, bool spec);
    void L3_generate_form(subtypes c, TokenList parms, TokenList body, subtypes s);
    void generate_from_sig();
    void Tl3_gen_from_ac(int c);
    void l3_generate_variant();
    void l3_generate_variant(String orig, String var);
    void l3_generate_variant(const std::string &var, bool prot, Token orig);
    void L3_getid();
    auto l3_get_name(Token T) -> bool;
    void E_cat_ifeq(subtypes c);
    void E_l3_ifx(subtypes c);
    void E_l3str_ifeq(subtypes c);
    void E_l3str_case(subtypes c);
    void L3_logid();
    void L3_new_conditional(subtypes s);
    void L3_new_conditional_aux(TokenList &arg_spec, subtypes s);
    void L3_new_conditional_parm(subtypes s);
    auto l3_parms_from_ac(int n, Token T, bool s) -> TokenList;
    void E_prg_return(int c);
    auto L3_split_next_name() -> bool;
    auto l3_to_string(subtypes c, TokenList &L) -> std::string;
    void L3_user_split_next_name(bool base);
    void tex_string(Buffer &B, Token T, bool esc);
    auto l3_read_int(Token T) -> int;
    void L3_set_cat_code(int c);
    void L3_set_num_code(int c);
    auto l3_get_cat(symcodes &a, subtypes &b, Token caller) -> bool;
    void l3_token_check(subtypes c);
    void l3_new_token_list(int c);
    void l3_tl_concat(int c);
    void l3_tl_set(int c);
    void l3_tl_put_left(int c);
    void tl_set_rescan(int c);
    void T_scantokens(TokenList &L);
};
