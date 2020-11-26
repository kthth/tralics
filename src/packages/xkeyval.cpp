#include "../tralics/Dispatcher.h"
#include "../tralics/Logger.h"
#include "../tralics/Symcode.h"
#include "../tralics/XkvSetkeys.h"
#include "../tralics/globals.h"
#include "../tralics/util.h"

// Auto-registering package, see tipa.cpp

namespace classes_ns {
    auto cur_options(bool, TokenList &, bool) -> TokenList;
    void register_key(const std::string &);
} // namespace classes_ns

namespace token_ns {
    auto find_in(TokenList &A, TokenList &B, Token t, bool sw, int &n) -> bool;
} // namespace token_ns

namespace xkv_ns {
    void find_aux(int c);
    auto find_key_of(const TokenList &L, int type) -> std::string;
} // namespace xkv_ns

namespace {
    // Implements ExecuteOptionsX
    void xkv_execute_options() {
        XkvSetkeys data(&the_parser);
        the_parser.xkv_fetch_prefix();
        data.special_fams();
        data.fetch_keys(true);
        data.dump_keys();
        data.set_aux();
        data.finish();
    }

    // Implements ProcessOptionsX
    void xkv_process_options() {
        XkvSetkeys data(&the_parser);
        //  data.no_err = remove_initial_plus(false);
        bool s = the_parser.remove_initial_star(); // we should do something with this
        the_parser.xkv_fetch_prefix();
        data.set_inpox();
        data.special_fams();
        TokenList uo;
        TokenList L = classes_ns::cur_options(s, uo, false);
        L.brace_me();
        the_parser.back_input(L);
        data.fetch_keys(true);
        data.set_aux();
        data.finish();
    }

    // May set \XKV@prefix \XKV@fams \XKV@tfam \XKV@header \XKV@tkey \XKV@na
    void setkeys(bool c) {
        XkvSetkeys data(&the_parser);
        data.run(c);
    }

    // This deletes L from W. Here L is a simple list of keys
    void xkv_ns_remove(TokenList &W, TokenList &L, int type) {
        Buffer  B;
        Buffer &aux = txparser2_local_buf;
        the_parser.list_to_string_c(L, ",", ",", "Invalid key name list", B);
        Token     comma = hash_table.comma_token;
        TokenList tmp;
        TokenList key;
        W.swap(tmp);
        while (!tmp.empty()) {
            token_ns::split_at(comma, tmp, key);
            std::string key_name = xkv_ns::find_key_of(key, type);
            aux                  = "," + key_name + ",";
            if (B.find(aux) == std::string::npos) {
                if (!W.empty()) W.push_back(comma);
                W.splice(W.end(), key);
            }
        }
    }

    // This merges L into W; both lists have the form \global{key}=value
    // or, depenfing on the type, are lists of keys
    void xkv_ns_merge(TokenList &W, TokenList &L, int type) {
        Token     comma = hash_table.comma_token;
        TokenList key;
        TokenList tmp;
        if (W.empty()) {
            while (!L.empty()) {
                token_ns::split_at(comma, L, key);
                token_ns::remove_first_last_space(key);
                if (!W.empty()) W.push_back(comma);
                W.splice(W.end(), key);
            }
            return;
        }
        while (!L.empty()) {
            token_ns::split_at(comma, L, key);
            token_ns::remove_first_last_space(key);
            std::string key_name = xkv_ns::find_key_of(key, type);
            bool        found    = false; // Was key in W ?
            TokenList   z;
            W.swap(tmp);
            while (!tmp.empty()) {
                token_ns::split_at(comma, tmp, z);
                std::string zname = xkv_ns::find_key_of(z, type);
                if (!W.empty()) W.push_back(comma);
                if (key_name == zname) {
                    found = true; // replace in W old value z by new value
                    W.splice(W.end(), key);
                } else
                    W.splice(W.end(), z);
            }
            if (!found) {
                if (!W.empty()) W.push_back(comma);
                W.splice(W.end(), key); // Insert key at the end
            }
        }
    }

    // Merges or deletes depending on mg globally if gbl is true
    // the keys in L from the variable depending on type
    // Implements preset or save depending on type
    void xkv_merge(bool gbl, int type, TokenList &L, bool mg) {
        token_ns::sanitize_one(L, '=');
        token_ns::sanitize_one(L, ',');
        xkv_ns::find_aux(type);
        Token     T = hash_table.locate(txparser2_local_buf);
        TokenList W = the_parser.get_mac_value(T);
        if (mg)
            xkv_ns_merge(W, L, type);
        else
            xkv_ns_remove(W, L, type);
        the_parser.new_macro(W, T, gbl);
    }

    // Implements \key@ifundefined
    void key_ifundefined() {
        Buffer &B = txparser2_local_buf;
        the_parser.xkv_fetch_prefix();
        TokenList   fams      = the_parser.read_arg();
        bool        undefined = true;
        TokenList   key       = the_parser.read_arg();
        std::string Key       = the_parser.list_to_string_c(key, "problem scanning key");
        std::string Fams      = the_parser.list_to_string_c(fams, "Problem with the families");
        std::string fam;
        for (const auto &f : split_commas(Fams)) {
            fam = f;
            B   = xkv_prefix + fam;
            if (!fam.empty()) B.push_back('@');
            B.append(Key);
            if (hash_table.is_defined(B)) {
                undefined = false;
                break;
            }
        }
        the_parser.new_macro(fam, hash_table.locate("XKV@tfam"));
        the_parser.one_of_two(undefined);
    }

    void lower_case(TokenList &L) {
        for (auto &a : L) {
            if (a.val < single_offset) {
                auto b  = a.chr_val();
                auto cx = eqtb_int_table[b + lc_code_offset].val;
                if (cx != 0) a = Token(a.val - b + to_unsigned(cx));
            }
        }
    }

    // Implements \XKV@cc
    void internal_choice_key() {
        bool      if_star = the_parser.remove_initial_plus(false);
        bool      if_plus = the_parser.remove_initial_plus(true);
        TokenList bin;
        the_parser.read_optarg_nopar(bin); // \todo std::optional
        TokenList input   = the_parser.read_arg();
        TokenList allowed = the_parser.read_arg();
        TokenList ok_code = the_parser.read_arg();
        TokenList bad_code;
        if (if_plus) bad_code = the_parser.read_arg();
        if (if_star) {
            lower_case(input);
            lower_case(allowed);
        }
        Token relax = hash_table.relax_token;
        Token B1 = relax, B2 = relax;
        if (!bin.empty()) {
            B1 = bin.front();
            bin.pop_front();
        }
        if (!bin.empty()) {
            B2 = bin.front();
            bin.pop_front();
        }
        if (B1.not_a_cmd()) B1 = relax;
        if (B2.not_a_cmd()) B2 = relax;
        if (B1 != relax) {
            TokenList u = input;
            the_parser.new_macro(u, B1);
        }
        TokenList xinput = input;
        int       k      = 0;
        bool      found  = token_ns::find_in(xinput, allowed, hash_table.comma_token, false, k);
        if (B2 != relax) {
            txparser2_local_buf = fmt::format("{}", k);
            TokenList u         = txparser2_local_buf.str_toks(nlt_cr); // Should be irrelevant ?
            the_parser.new_macro(u, B2);
        }
        if (found)
            the_parser.back_input(ok_code);
        else if (if_plus) // invalid, but catched
            the_parser.back_input(bad_code);
        else {
            the_parser.parse_error(the_parser.err_tok, "XKV: value is not allowed");
            log_and_tty << " " << input << "\n";
        }
    }

    // Assume txparser2_local_buf contains the name of T without the extension
    void internal_define_key_default(Token T, TokenList &L) {
        L.brace_me();
        L.push_front(T);
        txparser2_local_buf.append("@default");
        the_parser.cur_tok = hash_table.locate(txparser2_local_buf);
        the_parser.new_macro(L, the_parser.cur_tok);
    }

    // This is like \def\T#1, optimised
    void internal_define_key(Token T) {
        auto *X = new Macro;
        X->set_nbargs(1);
        X->set_type(dt_normal);
        the_parser.read_mac_body(X->body, false, 1);
        X->correct_type();
        the_parser.mac_define(T, X, false, rd_always, user_cmd);
    }

    void xkv_makehd(TokenList &L) {
        token_ns::remove_first_last_space(L);
        Buffer &B = txparser2_local_buf;
        B         = xkv_prefix;
        auto k    = B.size();
        if (the_parser.list_to_string(L, B)) {
            the_parser.parse_error(the_parser.err_tok, "Bad command ", the_parser.cur_tok, " in XKV family (more errors may follow)",
                                   "bad kv family");
            B.resize(k);
        }
        if (B.size() != k) B.push_back('@');
        xkv_header = B;
    }

    void xkv_declare_option() {
        // \let\@fileswith@pti@ns\@badrequireerror
        bool star = the_parser.remove_initial_star();
        if (star) {
            the_parser.T_declare_option_star();
            return;
        }
        the_parser.xkv_fetch_prefix();
        TokenList FL = the_parser.XKV_parse_filename();
        xkv_makehd(FL);
        TokenList   key  = the_parser.read_arg();
        TokenList   xkey = key;
        std::string Key  = the_parser.list_to_string_c(xkey, "Invalid option");
        classes_ns::register_key(Key);
        the_parser.list_to_string_c(key, xkv_header, "", "bad option name", txparser2_local_buf);
        Token T   = hash_table.locate(txparser2_local_buf);
        auto  opt = the_parser.read_optarg().value_or(TokenList{});
        internal_define_key_default(T, opt);
        internal_define_key(T);
    }

    void xkv_fetch_prefix_family() {
        the_parser.xkv_fetch_prefix();
        TokenList M = the_parser.read_arg();
        xkv_makehd(M);
    }

    // Find saved or preset keys, depending on c2. If not found:
    // signals a an error if c is true (creates otherwise), return true.
    // Creates cur_tok if needed
    auto xkv_save_keys_aux(bool c, int c2) -> bool {
        xkv_fetch_prefix_family();
        xkv_ns::find_aux(c2);
        Buffer &B   = txparser2_local_buf;
        bool    ret = !hash_table.is_defined(B);
        if (c && ret) {
            B = (c2 != 0 ? "No presets defined for `" : "No save keys defined for `") + xkv_header + "'";
            the_parser.parse_error(the_parser.err_tok, B);
            return true;
        }
        the_parser.cur_tok = hash_table.last_tok;
        return ret;
    }

    void disable_keys() {
        Buffer &B = txparser2_local_buf;
        xkv_fetch_prefix_family(); // read prefix and family
        TokenList   keys = the_parser.read_arg();
        std::string Keys = the_parser.list_to_string_c(keys, "problem scanning keys");
        for (const auto &Key : split_commas(Keys)) {
            B = xkv_header + Key;
            if (hash_table.is_defined(B)) {
                Token T = hash_table.last_tok;
                B.append("@default");
                if (hash_table.is_defined(B)) {
                    TokenList L;
                    L.brace_me();
                    L.push_front(T);
                    the_parser.new_macro(L, hash_table.last_tok);
                }
                B           = "Key `" + Key + "' has been disabled";
                TokenList L = B.str_toks(nlt_space); // should be irrelevant
                L.brace_me();
                L.push_front(hash_table.locate("XKV@warn"));
                auto *X = new Macro(L);
                X->set_nbargs(1);
                X->set_type(dt_normal);
                the_parser.mac_define(T, X, false, rd_always, user_cmd);
            } else
                the_parser.parse_error(the_parser.err_tok, "Undefined key cannot be disabled: ", Key, "");
        }
    }

    void define_bool_key(subtypes c) {
        Buffer &B = txparser2_local_buf;
        the_parser.remove_initial_plus(false);
        bool if_plus = the_parser.remove_initial_plus(true);
        if (c != define_boolkey_code) if_plus = false;
        xkv_fetch_prefix_family(); // read prefix and family
        TokenList L;
        if (the_parser.read_optarg_nopar(L)) {
            the_parser.list_to_string_c(L, "", "", "Problem scanning macro prefix", B);
        } else
            B = xkv_header;
        std::string mp      = B;
        TokenList   keytoks = the_parser.read_arg();
        TokenList   dft;
        bool        has_dft = the_parser.read_optarg_nopar(dft);
        // construct the key or key list
        std::string Keys = the_parser.list_to_string_c(keytoks, "Problem scanning key");
        for (const auto &Key : split_commas(Keys)) {
            if (Key.empty()) continue;
            B           = mp + Key;
            TokenList u = B.str_toks11(false);
            B           = "if" + mp + Key;
            the_parser.back_input(hash_table.locate(B));
            the_parser.M_newif();
            B           = "true,false";
            TokenList v = B.str_toks11(false);
            B           = xkv_header + Key;
            Token T     = hash_table.locate(txparser2_local_buf);
            if (has_dft) {
                TokenList D = dft;
                internal_define_key_default(T, D);
            }
            u.push_front(hash_table.csname_token);
            u.push_back(hash_table.locate("XKV@resa"));
            u.push_back(hash_table.endcsname_token);
            if (c == define_boolkey_code) {
                TokenList add1 = the_parser.read_arg();
                u.splice(u.end(), add1);
            }
            u.brace_me();
            TokenList LL;
            LL.splice(LL.end(), u);
            if (if_plus) {
                TokenList add2 = the_parser.read_arg();
                add2.brace_me();
                LL.splice(LL.end(), add2);
            }
            v.brace_me();
            LL.splice(LL.begin(), v);
            LL.push_front(hash_table.CB_token);
            LL.push_front(Token(other_t_offset, '1'));
            LL.push_front(make_char_token('#', 6));
            LL.push_front(hash_table.OB_token);
            LL.push_front(Token(other_t_offset, ']'));
            LL.push_front(hash_table.locate("XKV@resa"));
            LL.push_front(Token(other_t_offset, '['));
            if (if_plus) LL.push_front(Token(other_t_offset, '+'));
            LL.push_front(Token(other_t_offset, '*'));
            LL.push_front(hash_table.locate("XKV@cc"));
            LL.brace_me();
            the_parser.back_input(LL);
            auto *X = new Macro;
            X->set_nbargs(1);
            X->set_type(dt_normal);
            the_parser.read_mac_body(X->body, false, 1);
            X->correct_type();
            the_parser.mac_define(T, X, false, rd_always, user_cmd);
        }
    }

    void T_define_key() {
        Buffer &B = txparser2_local_buf;
        xkv_fetch_prefix_family();
        TokenList key = the_parser.read_arg();
        the_parser.list_to_string_c(key, xkv_header, "", "bad key name", B);
        Token T = hash_table.locate(B);
        if (auto opt = the_parser.read_optarg()) internal_define_key_default(T, *opt);
        internal_define_key(T);
    }

    void define_choice_key() {
        bool if_star = the_parser.remove_initial_plus(false);
        bool if_plus = the_parser.remove_initial_plus(true);
        xkv_fetch_prefix_family();
        TokenList keytoks = the_parser.read_arg();
        the_parser.list_to_string_c(keytoks, xkv_header, "", "bad key name", txparser2_local_buf);
        Token     T = hash_table.locate(txparser2_local_buf);
        TokenList storage_bin;
        the_parser.read_optarg_nopar(storage_bin);
        TokenList allowed = the_parser.read_arg();
        if (auto opt = the_parser.read_optarg()) internal_define_key_default(T, *opt);
        TokenList F;
        if (if_plus) {
            TokenList x = the_parser.read_arg();
            TokenList y = the_parser.read_arg();
            x.brace_me();
            y.brace_me();
            F.splice(F.end(), x);
            F.splice(F.end(), y);
        } else {
            F = the_parser.read_arg();
            F.brace_me();
        }
        TokenList body;
        body.push_back(hash_table.locate("XKV@cc"));
        if (if_star) body.push_back(Token(other_t_offset, '*'));
        if (if_plus) body.push_back(Token(other_t_offset, '+'));
        storage_bin.push_front(Token(other_t_offset, '['));
        storage_bin.push_back(Token(other_t_offset, ']'));
        body.splice(body.end(), storage_bin);
        TokenList argument;
        argument.push_back(make_char_token('#', 6));
        argument.push_back(Token(other_t_offset, '1'));
        argument.brace_me();
        body.splice(body.end(), argument);
        allowed.brace_me();
        body.splice(body.end(), allowed);
        body.splice(body.end(), F);
        body.brace_me();
        the_parser.back_input(body);
        internal_define_key(T);
    }

    // We make the assumption that a key does not contain a comma
    void define_cmd_key(subtypes c) {
        Buffer &B = txparser2_local_buf;
        xkv_fetch_prefix_family(); // read prefix and family
        TokenList L;
        if (the_parser.read_optarg_nopar(L)) {
            the_parser.list_to_string_c(L, "", "", "Problem scanning macro prefix", B);
        } else
            B = "cmd" + xkv_header;
        std::string mp      = B;
        TokenList   keytoks = the_parser.read_arg();
        auto        opt     = the_parser.read_optarg();
        // construct the key or key list
        std::string Keys = the_parser.list_to_string_c(keytoks, "problem scanning key");
        for (const auto &Key : split_commas(Keys)) {
            if (Key.empty()) continue;
            B         = mp + Key;
            Token cmd = hash_table.locate(B);
            B         = xkv_header + Key;
            Token T   = hash_table.locate(B);
            if (opt) {
                TokenList D = *opt;
                internal_define_key_default(T, D);
            }
            TokenList LL;
            if (c == define_cmdkey_code) { // case of cmdkey
                TokenList u = the_parser.read_arg();
                LL.splice(LL.end(), u);
            }
            LL.push_front(hash_table.CB_token);
            LL.push_front(Token(other_t_offset, '1'));
            LL.push_front(make_char_token('#', 6));
            LL.push_front(hash_table.OB_token);
            LL.push_front(cmd);
            LL.push_front(hash_table.locate("def"));
            LL.brace_me();
            the_parser.back_input(LL);
            auto *X = new Macro;
            X->set_nbargs(1);
            X->set_type(dt_normal);
            the_parser.read_mac_body(X->body, false, 1);
            X->correct_type();
            the_parser.mac_define(T, X, false, rd_always, user_cmd);
        }
    }

    void T_xkeyval(subtypes c) {
        switch (c) {
        case boot_keyval_code: return;
        case xdefinekey_code: T_define_key(); return;
        case define_cmdkey_code:
        case define_cmdkeys_code: define_cmd_key(c); return;
        case define_boolkey_code:
        case define_boolkeys_code: define_bool_key(c); return;
        case define_choicekey_code: define_choice_key(); return;
        case define_cc_code: internal_choice_key(); return;
        case disable_keys_code: disable_keys(); return;
        case key_ifundefined_code: key_ifundefined(); return;
        case save_keys_code:
        case gsave_keys_code: {
            xkv_save_keys_aux(false, 0);
            TokenList A = the_parser.read_arg();
            xkv_merge(c == gsave_keys_code, 0, A, true);
            return;
        }
        case delsave_keys_code:
        case gdelsave_keys_code: {
            bool      bad = xkv_save_keys_aux(false, 0);
            TokenList A   = the_parser.read_arg();
            if (!bad) xkv_merge(c == gdelsave_keys_code, 0, A, false);
            return;
        }
        case unsave_keys_code:
        case gunsave_keys_code:
            if (xkv_save_keys_aux(true, 0)) return;
            the_parser.M_let_fast(the_parser.cur_tok, hash_table.frozen_undef_token, c == gunsave_keys_code);
            return;
        case preset_keys_code:
        case gpreset_keys_code: {
            xkv_save_keys_aux(false, 1);
            TokenList A = the_parser.read_arg();
            TokenList B = the_parser.read_arg();
            xkv_merge(c == gpreset_keys_code, 1, A, true);
            xkv_merge(c == gpreset_keys_code, 2, B, true);
            return;
        }
        case delpreset_keys_code:
        case gdelpreset_keys_code: {
            bool      bad = xkv_save_keys_aux(true, 1);
            TokenList A   = the_parser.read_arg();
            TokenList B   = the_parser.read_arg();
            if (bad) return;
            xkv_merge(c == gdelpreset_keys_code, 1, A, false);
            xkv_merge(c == gdelpreset_keys_code, 2, B, false);
            return;
        }
        case unpreset_keys_code:
        case gunpreset_keys_code: {
            if (xkv_save_keys_aux(true, 1)) return;
            the_parser.M_let_fast(the_parser.cur_tok, hash_table.frozen_undef_token, c == gunpreset_keys_code);
            xkv_ns::find_aux(2);
            the_parser.cur_tok = hash_table.locate(txparser2_local_buf);
            the_parser.M_let_fast(the_parser.cur_tok, hash_table.frozen_undef_token, c == gunpreset_keys_code);
            return;
        }
        case setrmkeys_code: setkeys(false); return;
        case setkeys_code: setkeys(true); return;
        case declare_optionsX_code: xkv_declare_option(); return;
        case process_optionsX_code: xkv_process_options(); return;
        case execute_optionsX_code: xkv_execute_options(); return;
        default: return;
        }
    }

    void xkeyval() {
        hash_table.primitive_plain("define@boolkey", xkeyval_cmd, define_boolkey_code);
        hash_table.primitive_plain("define@boolkeys", xkeyval_cmd, define_boolkeys_code);
        hash_table.primitive_plain("define@choicekey", xkeyval_cmd, define_choicekey_code);
        hash_table.primitive_plain("define@cmdkey", xkeyval_cmd, define_cmdkey_code);
        hash_table.primitive_plain("define@cmdkeys", xkeyval_cmd, define_cmdkeys_code);
        hash_table.primitive_plain("define@key", xkeyval_cmd, xdefinekey_code);
        hash_table.primitive_plain("tralics@boot@keyval", xkeyval_cmd, boot_keyval_code);
        hash_table.primitive_plain("XKV@cc", xkeyval_cmd, define_cc_code);
        hash_table.primitive_plain("key@ifundefined", xkeyval_cmd, key_ifundefined_code);
        hash_table.primitive_plain("disable@keys", xkeyval_cmd, disable_keys_code);
        hash_table.primitive_plain("presetkeys", xkeyval_cmd, preset_keys_code);
        hash_table.primitive_plain("gpresetkeys", xkeyval_cmd, gpreset_keys_code);
        hash_table.primitive_plain("unpresetkeys", xkeyval_cmd, unpreset_keys_code);
        hash_table.primitive_plain("gunpresetkeys", xkeyval_cmd, gunpreset_keys_code);
        hash_table.primitive_plain("delpresetkeys", xkeyval_cmd, delpreset_keys_code);
        hash_table.primitive_plain("gdelpresetkeys", xkeyval_cmd, gdelpreset_keys_code);
        hash_table.primitive_plain("savekeys", xkeyval_cmd, save_keys_code);
        hash_table.primitive_plain("gsavekeys", xkeyval_cmd, gsave_keys_code);
        hash_table.primitive_plain("unsavekeys", xkeyval_cmd, unsave_keys_code);
        hash_table.primitive_plain("gunsavekeys", xkeyval_cmd, gunsave_keys_code);
        hash_table.primitive_plain("delsavekeys", xkeyval_cmd, delsave_keys_code);
        hash_table.primitive_plain("gdelsavekeys", xkeyval_cmd, gdelsave_keys_code);
        hash_table.primitive_plain("setkeys", xkeyval_cmd, setkeys_code);
        hash_table.primitive_plain("setrmkeys", xkeyval_cmd, setrmkeys_code);
        hash_table.primitive_plain("DeclareOptionX", xkeyval_cmd, declare_optionsX_code);
        hash_table.primitive_plain("ExecuteOptionsX", xkeyval_cmd, execute_optionsX_code);
        hash_table.primitive_plain("ProcessOptionsX", xkeyval_cmd, process_optionsX_code);
        Dispatcher::register_action_plain(xkeyval_cmd, T_xkeyval);
    }

    bool t = (xkeyval(), true);
} // namespace
