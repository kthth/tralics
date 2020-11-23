#include "tralics/Dispatcher.h"
#include "tralics/Logger.h"
#include "tralics/MainClass.h"
#include "tralics/NameMapper.h"
#include "tralics/Symcode.h"
#include "tralics/globals.h"
#include <spdlog/spdlog.h>

namespace {
    auto hfill_to_np(subtypes c) -> std::string {
        if (c == hfill_code) return "hfill";
        if (c == hfilneg_code) return "hfilneg";
        if (c == hss_code) return "hss";
        return "hfil";
    }

    auto vfill_to_np(subtypes c) -> std::string {
        if (c == vfill_code) return "vfill";
        if (c == vfilneg_code) return "vfilneg";
        if (c == vss_code) return "vss";
        return "vfil";
    }
} // namespace

void Dispatcher::register_action(symcodes x, const std::function<bool(subtypes)> &f) { Symcode::get(x).action = f; }

void Dispatcher::register_action(symcodes x, const std::function<bool()> &f) {
    Symcode::get(x).action = [=](subtypes /*unused*/) { return f(); };
}

void Dispatcher::register_action(symcodes x, const std::function<void()> &f) {
    Symcode::get(x).action = [=](subtypes /*unused*/) { return f(), true; };
}

void Dispatcher::register_action(symcodes x, const std::function<bool(symcodes)> &f) {
    Symcode::get(x).action = [=](subtypes /*unused*/) { return f(x); };
}

void Dispatcher::register_action(symcodes x, const std::function<void(symcodes)> &f) {
    Symcode::get(x).action = [=](subtypes /*unused*/) { return f(x), true; };
}

void Dispatcher::register_action(symcodes x, const std::function<void(subtypes)> &f) {
    Symcode::get(x).action = [f](subtypes c) { return f(c), true; };
}

void Dispatcher::register_action(symcodes x, const std::function<bool(symcodes, subtypes)> &f) {
    Symcode::get(x).action = [=](subtypes c) { return f(x, c); };
}

void Dispatcher::register_action(symcodes x, const std::function<void(symcodes, subtypes)> &f) {
    Symcode::get(x).action = [=](subtypes c) { return f(x, c), true; };
}

void Dispatcher::register_action(symcodes x, parser_fn f) {
    Symcode::get(x).action = [=](subtypes /*unused*/) { return std::invoke(f, the_parser); };
}

void Dispatcher::register_action(symcodes x, parser_fn_void f) {
    Symcode::get(x).action = [f](subtypes /*unused*/) { return std::invoke(f, the_parser), true; };
}

void Dispatcher::register_action(symcodes x, parser_fn_with_x f) {
    Symcode::get(x).action = [=](subtypes /*unused*/) { return std::invoke(f, the_parser, x); };
}

void Dispatcher::register_action(symcodes x, parser_fn_with_x_void f) {
    Symcode::get(x).action = [=](subtypes /*unused*/) { return std::invoke(f, the_parser, x), true; };
}

void Dispatcher::register_action(symcodes x, parser_fn_with_c f) {
    Symcode::get(x).action = [f](subtypes c) { return std::invoke(f, the_parser, c); };
}

void Dispatcher::register_action(symcodes x, parser_fn_with_c_void f) {
    Symcode::get(x).action = [f](subtypes c) { return std::invoke(f, the_parser, c), true; };
}

void Dispatcher::register_action(symcodes x, parser_fn_with_xc f) {
    Symcode::get(x).action = [=](subtypes c) { return std::invoke(f, the_parser, x, c); };
}

void Dispatcher::register_action(symcodes x, parser_fn_with_xc_void f) {
    Symcode::get(x).action = [=](subtypes c) { return std::invoke(f, the_parser, x, c), true; };
}

void Dispatcher::register_action(symcodes x, parser_fn_with_cmdchr f) {
    Symcode::get(x).action = [=](subtypes c) { return std::invoke(f, the_parser, CmdChr{x, c}); };
}

void Dispatcher::register_action(symcodes x, parser_fn_with_cmdchr_void f) {
    Symcode::get(x).action = [=](subtypes c) { return std::invoke(f, the_parser, CmdChr{x, c}), true; };
}

void Dispatcher::register_name(symcodes x, const std::function<std::string(subtypes)> &f) { Symcode::get(x).name_fn = f; }

void Dispatcher::register_name(symcodes x, subtypes c, const std::string &s) { Symcode::get(x).name_sub[c] = s; }

Dispatcher::Dispatcher() {
    register_name(mathbin_cmd, token_math_name);
    register_name(mathrel_cmd, token_math_name);
    register_name(mathinner_cmd, token_math_name);
    register_name(mathbetween_cmd, token_math_name);
    register_name(mathopen_cmd, token_math_name);
    register_name(mathclose_cmd, token_math_name);
    register_name(mathspace_cmd, token_math_name);
    register_name(mathord_cmd, token_math_name);
    register_name(mathordb_cmd, token_math_name);
    register_name(mathop_cmd, token_math_name);
    register_name(mathopn_cmd, token_math_name);

    register_action(addatt_cmd, &Parser::T_xmladdatt);
    register_action(advance_cmd, &Parser::M_prefixed);
    register_action(aftergroup_cmd, &Parser::T_aftergroup);
    register_action(alignment_catcode, &Parser::T_ampersand);
    register_action(argfont_cmd, &Parser::arg_font);
    register_action(assign_dimen_cmd, &Parser::M_prefixed);
    register_action(assign_enc_char_cmd, &Parser::M_prefixed);
    register_action(assign_font_dimen_cmd, &Parser::M_prefixed);
    register_action(assign_font_int_cmd, &Parser::M_prefixed);
    register_action(assign_glue_cmd, &Parser::M_prefixed);
    register_action(assign_int_cmd, &Parser::M_prefixed);
    register_action(assign_mu_glue_cmd, &Parser::M_prefixed);
    register_action(assign_toks_cmd, &Parser::M_prefixed);
    register_action(at_end_of_class_cmd, &Parser::T_at_end_of_class);
    register_action(atdocument_cmd, &Parser::T_atdocument);
    register_action(begin_cmd, &Parser::T_beginend);
    register_action(bezier_cmd, &Parser::T_bezier);
    register_action(bib_cmd, &Parser::T_bauteursediteurs);
    register_action(biblio_cmd, &Parser::T_biblio);
    register_action(bibliographystyle_cmd, &Parser::T_bibliostyle);
    register_action(box_cmd, &Parser::T_mbox);
    register_action(bpers_cmd, &Parser::T_bpers);
    register_action(calc_cmd, &Parser::exec_calc);
    register_action(case_shift_cmd, &Parser::T_case_shift);
    register_action(change_element_name_cmd, &Parser::T_change_element_name);
    register_action(check_date_cmd, &Parser::date_commands);
    register_action(cite_cmd, &Parser::T_cite);
    register_action(cite_one_cmd, &Parser::T_cite_one);
    register_action(cititem_cmd, &Parser::T_cititem);
    register_action(color_cmd, &Parser::T_color);
    register_action(cons_cmd, &Parser::M_cons);
    register_action(cr_cmd, &Parser::T_cr);
    register_action(cst_cmd, &Parser::T_cst1);
    register_action(cst1_cmd, &Parser::T_cst1);
    register_action(cst2_cmd, &Parser::T_cst2);
    register_action(curves_cmd, &Parser::T_curves);
    register_action(dashline_cmd, &Parser::T_dashline);
    register_action(dblarg_cmd, &Parser::dbl_arg);
    register_action(declare_options_cmd, &Parser::T_declare_options);
    register_action(def_cmd, &Parser::M_prefixed);
    register_action(def_code_cmd, &Parser::M_prefixed);
    register_action(def_family_cmd, &Parser::M_prefixed);
    register_action(def_font_cmd, &Parser::M_prefixed);
    register_action(defineverbatimenv_cmd, &Parser::T_define_verbatim_env);
    register_action(description_cmd, &Parser::T_listenv);
    register_action(ding_cmd, &Parser::T_ding);
    register_action(divide_cmd, &Parser::M_prefixed);
    register_action(document_cmd, &Parser::T_begindocument);
    register_action(end_cmd, &Parser::T_beginend);
    register_action(end_description_cmd, &Parser::T_listenv_end);
    register_action(end_document_cmd, &Parser::T_enddocument);
    register_action(end_enumerate_cmd, &Parser::T_listenv_end);
    register_action(end_glossaire_cmd, &Parser::T_glossaire_end);
    register_action(end_itemize_cmd, &Parser::T_listenv_end);
    register_action(end_list_cmd, &Parser::T_listenv_end);
    register_action(end_tabular_env_cmd, &Parser::T_end_tabular);
    register_action(end_thebibliography_cmd, &Parser::T_end_the_biblio);
    register_action(end_xmlelement_env_cmd, &Parser::T_xmlenv_end);
    register_action(endv_cmd, &Parser::T_endv);
    register_action(enumerate_cmd, &Parser::T_listenv);
    register_action(epsfbox_cmd, &Parser::T_epsfbox);
    register_action(eqno_cmd, &Parser::math_only);
    register_action(error_cmd, &Parser::T_error);
    register_action(etex_cmd, &Parser::T_etex);
    register_action(execute_options_cmd, &Parser::T_execute_options);
    register_action(expandtwoargs_cmd, &Parser::expand_twoargs);
    register_action(extension_cmd, &Parser::M_extension);
    register_action(fancy_cmd, &Parser::T_fancy);
    register_action(file_cmd, &Parser::T_input);
    register_action(filecontents_env_cmd, &Parser::T_filecontents);
    register_action(float_cmd, &Parser::T_float);
    register_action(fnhack_cmd, &Parser::fnhack);
    register_action(fontsize_cmd, &Parser::translate_font_size);
    register_action(for_cmd, &Parser::T_xkv_for);
    register_action(formatdate_cmd, &Parser::formatdate);
    register_action(fp_cmd, &Parser::exec_fp_cmd);
    register_action(fpi_cmd, &Parser::exec_fpi_cmd);
    register_action(fpif_cmd, &Parser::exec_fp_cmd);
    register_action(fvset_cmd, &Parser::special_fvset);
    register_action(GetIdInfo_cmd, &Parser::L3_getid);
    register_action(GetIdInfoLog_cmd, &Parser::L3_logid);
    register_action(glo_cmd, &Parser::T_glo);
    register_action(glossaire_cmd, &Parser::T_glossaire);
    register_action(grabenv_cmd, &Parser::T_grabenv);
    register_action(hanl_cmd, &Parser::T_hanl);
    register_action(hspace_cmd, &Parser::T_hspace);
    register_action(ifdefinable_cmd, &Parser::T_ifdefinable);
    register_action(ifstar_cmd, &Parser::T_ifstar);
    register_action(ifthenelse_cmd, &Parser::T_ifthenelse);
    register_action(ignorep_cmd, &Parser::T_par1);
    register_action(includegraphics_cmd, &Parser::includegraphics);
    register_action(index_cmd, &Parser::T_index);
    register_action(inputclass_cmd, &Parser::T_inputclass);
    register_action(isin_cmd, &Parser::T_isin);
    register_action(item_cmd, &Parser::T_item);
    register_action(itemize_cmd, &Parser::T_listenv);
    register_action(keywords_cmd, &Parser::T_keywords);
    register_action(kvo_family_cmd, &Parser::kvo_family);
    register_action(l3_check_cmd, &Parser::L3_check_cmd);
    register_action(l3_gen_cond_Nnn_cmd, &Parser::L3_new_conditional);
    register_action(l3_gen_cond_Npnn_cmd, &Parser::L3_new_conditional_parm);
    register_action(l3_gen_eq_cond_cmd, &Parser::L3_eq_conditional);
    register_action(l3_gen_from_ac_cmd, &Parser::Tl3_gen_from_ac);
    register_action(l3_gen_from_sig_cmd, &Parser::generate_from_sig);
    register_action(l3_generate_variant_cmd, &Parser::l3_generate_variant);
    register_action(l3_rescan_cmd, &Parser::tl_set_rescan);
    register_action(l3_set_cat_cmd, &Parser::L3_set_cat_code);
    register_action(l3_set_num_cmd, &Parser::L3_set_num_code);
    register_action(latex_error_cmd, &Parser::T_class_error);
    register_action(leave_v_mode_cmd, &Parser::leave_v_mode);
    register_action(left_cmd, &Parser::math_only);
    register_action(let_cmd, &Parser::M_prefixed);
    register_action(letter_catcode, &Parser::translate_char);
    register_action(line_cmd, &Parser::T_line);
    register_action(linebreak_cmd, &Parser::ignore_optarg);
    register_action(list_cmd, &Parser::T_listenv);
    register_action(math_font_cmd, &Parser::math_only);
    register_action(math_list_cmd, &Parser::math_only);
    register_action(math_xml_cmd, &Parser::math_only);
    register_action(mathbetween_cmd, &Parser::math_only);
    register_action(mathbin_cmd, &Parser::math_only);
    register_action(mathclose_cmd, &Parser::math_only);
    register_action(mathfont_cmd, &Parser::math_only);
    register_action(mathop_cmd, &Parser::math_only);
    register_action(mathopen_cmd, &Parser::math_only);
    register_action(mathopn_cmd, &Parser::math_only);
    register_action(mathord_cmd, &Parser::math_only);
    register_action(mathordb_cmd, &Parser::math_only);
    register_action(mathrel_cmd, &Parser::math_only);
    register_action(mathspace_cmd, &Parser::math_only);
    register_action(matter_cmd, &Parser::T_matter);
    register_action(minipage_cmd, &Parser::T_minipage);
    register_action(multiply_cmd, &Parser::M_prefixed);
    register_action(newboolean_cmd, &Parser::M_newboolean);
    register_action(newcolumntype_cmd, &Parser::T_newcolumn_type);
    register_action(newcount_cmd, &Parser::new_constant);
    register_action(newif_cmd, &Parser::M_newif);
    register_action(noargfont_cmd, &Parser::see_font_change);
    register_action(nolinebreak_cmd, &Parser::ignore_optarg);
    register_action(numberwithin_cmd, &Parser::numberwithin);
    register_action(oldfont_cmd, &Parser::old_font);
    register_action(omitcite_cmd, &Parser::T_omitcite);
    register_action(options_not_used_cmd, &Parser::T_option_not_used);
    register_action(other_catcode, &Parser::translate_char);
    register_action(par_cmd, &Parser::T_par1);
    register_action(picture_env_cmd, &Parser::T_picture);
    register_action(pop_stack_cmd, &Parser::pop_all_levels);
    register_action(prefix_cmd, &Parser::M_prefixed);
    register_action(process_options_cmd, &Parser::T_process_options);
    register_action(pushmodule_cmd, &Parser::push_module);
    register_action(put_cmd, &Parser::T_put);
    register_action(read_to_cs_cmd, &Parser::M_prefixed);
    register_action(reevaluate_cmd, &Parser::T_reevaluate);
    register_action(register_cmd, &Parser::M_prefixed);
    register_action(removeelement_cmd, &Parser::T_remove_element);
    register_action(right_cmd, &Parser::math_only);
    register_action(rule_cmd, &Parser::scan_rule);
    register_action(saveverb_cmd, &Parser::T_saveverb);
    register_action(scan_glue_cmd, &Parser::T_scan_glue);
    register_action(section_cmd, &Parser::T_paras);
    register_action(selectfont_cmd, &Parser::font_has_changed);
    register_action(selective_sanitize_cmd, &Parser::selective_sanitize);
    register_action(set_aux_cmd, &Parser::M_prefixed);
    register_action(set_box_cmd, &Parser::M_prefixed);
    register_action(set_box_dimen_cmd, &Parser::M_prefixed);
    register_action(set_font_cmd, &Parser::M_prefixed);
    register_action(set_interaction_cmd, &Parser::M_prefixed);
    register_action(set_mathchar_cmd, &Parser::M_prefixed);
    register_action(set_mathprop_cmd, &Parser::M_prefixed);
    register_action(set_page_dimen_cmd, &Parser::M_prefixed);
    register_action(set_page_int_cmd, &Parser::M_prefixed);
    register_action(set_prev_graf_cmd, &Parser::M_prefixed);
    register_action(set_shape_cmd, &Parser::M_prefixed);
    register_action(setboolean_cmd, &Parser::set_boolean);
    register_action(setmode_cmd, &Parser::T_setmode);
    register_action(shorthand_def_cmd, &Parser::M_prefixed);
    register_action(shortverb_cmd, &Parser::M_shortverb);
    register_action(soul_cmd, &Parser::T_fonts);
    register_action(specimp_cmd, &Parser::T_specimp);
    register_action(start_par_cmd, &Parser::implicit_par);
    register_action(sub_cmd, &Parser::T_fonts);
    register_action(subfigure_cmd, &Parser::T_subfigure);
    register_action(tabular_env_cmd, &Parser::T_start_tabular);
    register_action(tag_cmd, &Parser::math_only);
    register_action(testopt_cmd, &Parser::T_testopt);
    register_action(thebibliography_cmd, &Parser::T_start_the_biblio);
    register_action(thickness_cmd, &Parser::T_linethickness);
    register_action(tl_basic_cmd, &Parser::l3_new_token_list);
    register_action(tl_concat_cmd, &Parser::l3_tl_concat);
    register_action(tl_put_left_cmd, &Parser::l3_tl_put_left);
    register_action(tl_set_cmd, &Parser::l3_tl_set);
    register_action(toks_register_cmd, &Parser::M_prefixed);
    register_action(tracingall_cmd, &Parser::M_tracingall);
    register_action(trees_cmd, &Parser::T_trees);
    register_action(typein_cmd, &Parser::T_typein);
    register_action(un_box_cmd, &Parser::T_un_box);
    register_action(unimp_cmd, &Parser::T_unimp);
    register_action(unimp_font_cmd, &Parser::T_unimplemented_font);
    register_action(url_cmd, &Parser::T_url);
    register_action(usecounter_cmd, &Parser::T_use_counter);
    register_action(usefont_cmd, &Parser::T_usefont);
    register_action(verbatim_env_cmd, &Parser::T_verbatim);
    register_action(whiledo_cmd, &Parser::T_whiledo);
    register_action(xfancy_cmd, &Parser::T_xfancy);
    register_action(xkeyval_cmd, &Parser::T_xkeyval);
    register_action(XML_fetch_cmd, &Parser::user_XML_fetch);
    register_action(XML_modify_cmd, &Parser::user_XML_modify);
    register_action(XML_swap_cmd, &Parser::user_XML_swap);
    register_action(xmlelement_env_cmd, &Parser::T_xmlenv);
    register_action(xmlelt_cmd, &Parser::T_xmlelt);
    register_action(xray_cmd, &Parser::M_xray);

    register_action(add_to_macro_cmd, [](subtypes c) { the_parser.T_addtomacro(c == 1); });
    register_action(arg_font_cmd, [] { the_parser.T_fonts("font_sc"); });
    register_action(bibitem_cmd, [](subtypes c) { c == 1 ? the_parser.T_empty_bibitem() : the_parser.T_bibitem(); });
    register_action(caption_cmd, [] { the_parser.T_cap_or_note(true); });
    register_action(char_given_cmd, [](subtypes c) { the_parser.extended_chars(size_t(c)); });
    register_action(char_num_cmd, [] { the_parser.extended_chars(the_parser.scan_27bit_int()); });
    register_action(close_catcode, [] { the_parser.pop_level(bt_brace); });
    register_action(doc_class_cmd, [] { the_parser.T_documentclass(!the_stack.in_v_mode() || seen_document); });
    register_action(end_center_cmd, [] { the_parser.leave_h_mode(); });
    register_action(end_citation_cmd, [] { the_stack.pop(::the_names["citation"]); });
    register_action(end_figure_cmd, [] { the_parser.T_figure_table_end(true); });
    register_action(end_keywords_cmd, [] { the_stack.pop(::the_names["keywords"]); });
    register_action(end_picture_env_cmd, [] { the_stack.pop(::the_names["picture"]); });
    register_action(end_subequations_cmd, [] { the_parser.T_subequations(false); });
    register_action(end_table_cmd, [] { the_parser.T_figure_table_end(false); });
    register_action(endcsname_cmd, [] { the_parser.parse_error("Extra \\endcsname"); });
    register_action(eqref_cmd, [] { Xid(the_parser.read_elt_id(the_parser.cur_tok)).add_ref(the_parser.sT_arg_nopar()); });
    register_action(figure_cmd, [](symcodes x, subtypes c) { the_parser.T_figure_table(x, c); });
    register_action(footcitepre_cmd, [] { the_parser.unprocessed_xml.push_back_unless_punct(' '); });
    register_action(footnote_cmd, [] { the_parser.T_cap_or_note(false); });
    register_action(gloss_cmd, [](subtypes c) { the_parser.T_gloss(c == 0); });
    register_action(hline_cmd, [](subtypes c) { the_parser.T_hline(c); });
    register_action(if_package_later_cmd, [](subtypes c) { the_parser.T_if_package_later(c == 0); });
    register_action(if_package_loaded_cmd, [](subtypes c) { the_parser.T_if_package_loaded(c == 0); });
    register_action(if_package_with_cmd, [](subtypes c) { the_parser.T_if_package_with(c == 0); });
    register_action(ifnextchar_cmd, [](subtypes c) { the_parser.T_ifnextchar(c == 0); });
    register_action(ignore_content_cmd, [] { the_parser.T_raw_env(false); });
    register_action(ignoreA_cmd, [] { the_parser.T_ignoreA(); });
    register_action(insertbibliohere_cmd, [] { Parser::add_bib_marker(true); });
    register_action(kern_cmd, [](subtypes c) { the_parser.scan_dimen(c == 1, the_parser.cur_tok); });
    register_action(listfiles_cmd, [] { the_parser.list_files_p = true; });
    register_action(load_with_options_cmd, [](subtypes c) { the_parser.T_load_with_options(c == 0); });
    register_action(loadlatex3_cmd, [] { the_parser.L3_load(false); });
    register_action(make_box_cmd, [](subtypes c) { the_parser.begin_box(makebox_location, c); });
    register_action(makeatletter_cmd, [] { the_parser.word_define('@', letter_catcode, false); });
    register_action(makeatother_cmd, [] { the_parser.word_define('@', other_catcode, false); });
    register_action(newcounter_cmd, [] { the_parser.M_counter(true); });
    register_action(nobreakspace_cmd, [] { the_parser.LC(), the_parser.process_char(global_in_url ? '~' : 0xA0); });
    register_action(numberedverbatim_cmd, [] { the_parser.numbered_verbatim = true; });
    register_action(open_catcode, [] { the_parser.push_level(bt_brace); });
    register_action(pass_options_cmd, [](subtypes c) { the_parser.T_pass_options(c == 0); });
    register_action(popmodule_cmd, [] { the_stack.end_module(); });
    register_action(provides_package_cmd, [](subtypes c) { the_parser.T_provides_package(c == 0); });
    register_action(raw_env_cmd, [] { the_stack.add_last(new Xml(std::string(the_parser.T_raw_env(true)))); });
    register_action(save_box_cmd, [](subtypes c) { the_parser.T_save_box(c == 0); });
    register_action(setlanguage_cmd, [] { the_parser.scan_int(the_parser.cur_tok); });
    register_action(solvecite_cmd, [] { the_parser.solve_cite(false); });
    register_action(subequations_cmd, [] { the_parser.T_subequations(true); });
    register_action(table_cmd, [](symcodes x, subtypes c) { the_parser.T_figure_table(x, c); });
    register_action(unnumberedverbatim_cmd, [] { the_parser.numbered_verbatim = false; });
    register_action(verb_cmd, [](subtypes c) { the_parser.T_verb(c != 0U ? the_parser.verb_saved_char : char32_t(0U)); });

    register_action(end_ignore_content_cmd, [] {
        the_parser.parse_error(the_parser.cur_tok, "missing \\begin environment ", the_parser.cur_tok.tok_to_str(), "missing begin");
    });
    register_action(end_math_env_cmd, [] {
        the_parser.parse_error(the_parser.cur_tok, "missing \\begin environment ", the_parser.cur_tok.tok_to_str(), "missing begin");
    });
    register_action(end_raw_env_cmd, [] {
        the_parser.parse_error(the_parser.cur_tok, "missing \\begin environment ", the_parser.cur_tok.tok_to_str(), "missing begin");
    });
    register_action(last_item_cmd,
                    [] { the_parser.parse_error(the_parser.cur_tok, "Read only variable ", the_parser.cur_tok, "", "readonly"); });

    register_action(hfill_cmd, [](subtypes c) {
        the_parser.leave_v_mode();
        the_stack.add_newid0(hfill_to_np(c));
    });
    register_action(vfill_cmd, [](subtypes c) {
        the_parser.leave_h_mode();
        the_stack.add_newid0(vfill_to_np(c));
    });

    register_action(space_catcode, [](subtypes c) {
        if (!the_stack.in_v_mode() && !the_stack.in_no_mode() && !the_stack.in_bib_mode()) the_parser.process_char(char32_t(c));
    });
    register_action(inhibit_xml_cmd, [] {
        the_main.no_xml = true;
        spdlog::warn("syntaxonly: no XML file will be produced");
    });
    register_action(xmllatex_cmd, [] {
        the_parser.LC();
        the_parser.unprocessed_xml += the_parser.T_xmllatex();
    });
    register_action(aparaitre_cmd, [] { // \todo multilingual stuff somewhere
        the_parser.LC();
        if (eqtb_int_table[language_code].val == 1) {
            the_parser.process_char(char32_t(0xE0U));
            the_parser.process_string(" para");
            the_parser.process_char(char32_t(0xEEU));
            the_parser.process_string("tre");
        } else
            the_parser.process_string("to appear");
    });
    register_action(dollar_catcode, [] {
        the_parser.flush_buffer();
        the_parser.T_math(nomathenv_code);
    });
    register_action(begingroup_cmd, [](subtypes c) {
        the_parser.flush_buffer();
        if (c == 0)
            the_parser.push_level(bt_semisimple);
        else if (c == 1)
            the_parser.pop_level(bt_semisimple);
        else {
            the_parser.get_token();
            the_parser.pop_level(bt_env);
        }
    });
    register_action(hat_catcode, [](subtypes c) {
        if (global_in_load || is_pos_par(nomath_code))
            the_parser.translate_char(CmdChr(letter_catcode, c));
        else
            the_parser.parse_error(the_parser.cur_tok, "Missing dollar not inserted, token ignored: ", the_parser.cur_tok.tok_to_str(),
                                   "Missing dollar");
    });
    register_action(underscore_catcode, [](subtypes c) {
        if (global_in_load || is_pos_par(nomath_code))
            the_parser.translate_char(CmdChr(letter_catcode, c));
        else
            the_parser.parse_error(the_parser.cur_tok, "Missing dollar not inserted, token ignored: ", the_parser.cur_tok.tok_to_str(),
                                   "Missing dollar");
    });
    register_action(backslash_cmd, [](subtypes c) {
        if (c == 0)
            the_parser.T_backslash();
        else
            the_parser.T_newline();
    });
    register_action(skip_cmd, [](subtypes c) {
        the_parser.append_glue(the_parser.cur_tok, (c == smallskip_code ? 3 : c == medskip_code ? 6 : 12) << 16, true);
    });

    register_action(special_math_cmd, [](subtypes c) {
        if (c == overline_code || c == underline_code)
            the_parser.T_fonts(c == overline_code ? "overline" : "underline");
        else
            the_parser.math_only();
    });
    register_action(ltfont_cmd, [](subtypes c) {
        the_parser.flush_buffer();
        the_parser.cur_font.ltfont(the_parser.sT_arg_nopar(), c);
    });
    register_action(citation_cmd, [] {
        the_parser.T_citation();
        the_stack.add_nl();
    });
    register_action(ignore_cmd, [](subtypes c) {
        if (c == addnl_code) {
            the_parser.flush_buffer();
            the_stack.add_nl();
        } else if (c == unskip_code) {
            if (the_parser.unprocessed_xml.empty())
                the_stack.remove_last_space();
            else
                the_parser.unprocessed_xml.remove_last_space();
        }
    });
    register_action(relax_cmd, [] {});
    register_action(eof_marker_cmd, [] {});
    register_action(ignore_one_argument_cmd, [](subtypes c) {
        if (c == patterns_code || c == hyphenation_code || c == special_code) the_parser.scan_left_brace_and_back_input();
        the_parser.ignore_arg();
    });
    register_action(ignore_two_argument_cmd, [] {
        the_parser.ignore_arg();
        the_parser.ignore_arg();
    });
    register_action(after_assignment_cmd, [] {
        the_parser.get_token();
        the_parser.set_after_ass_tok(the_parser.cur_tok);
        if (tracing_commands()) {
            Logger::finish_seq();
            the_log << "{\\afterassignment: " << the_parser.cur_tok << "}\n";
        }
    });
    register_action(move_cmd, [] {
        the_parser.scan_dimen(false, the_parser.cur_tok);
        the_parser.scan_box(move_location);
    });
    register_action(leader_ship_cmd, [](subtypes c) {
        the_parser.scan_box(c == shipout_code    ? shipout_location
                            : c == leaders_code  ? leaders_location
                            : c == cleaders_code ? cleaders_location
                                                 : xleaders_location);
    });
    register_action(vglue_cmd, [](subtypes c) {
        if (c == 0)
            the_parser.T_par1();
        else
            the_parser.leave_v_mode();
        the_parser.T_scan_glue(c == 0 ? vskip_code : hskip_code);
    });
    register_action(titlepage_cmd, [](subtypes c) {
        if (!the_stack.in_v_mode()) the_parser.wrong_mode("Bad titlepage command");
        Parser::T_titlepage(c);
    });
    register_action(package_cmd, [] {
        if (!the_stack.in_v_mode() || seen_document) the_parser.wrong_mode("Bad \\usepackage command");
        the_parser.T_usepackage();
    });
    register_action(needs_format_cmd, [] {
        the_parser.ignore_arg();
        the_parser.ignore_optarg();
    });
    register_action(label_cmd, [](subtypes c) {
        the_parser.flush_buffer();
        the_parser.T_label(c);
    });
    register_action(ref_cmd, [](subtypes c) {
        the_parser.leave_v_mode();
        the_parser.T_ref(c == 0);
    });
    register_action(centering_cmd, [](subtypes c) {
        the_parser.word_define(incentering_code, c, false);
        if (c != 0U) the_stack.add_center_to_p();
    });
    register_action(fbox_cmd, [](subtypes c) {
        if (c == dashbox_code)
            the_parser.T_fbox_dash_box();
        else if (c == rotatebox_code)
            the_parser.T_fbox_rotate_box();
        else
            the_parser.T_fbox(c);
    });
    register_action(xthepage_cmd, [] {
        the_parser.flush_buffer();
        the_stack.add_last(the_page_xml);
    });
    register_action(only_preamble_cmd, [] {
        the_parser.get_r_token(true);
        onlypreamble.push_back(hash_table.let_token);
        onlypreamble.push_back(the_parser.cur_tok);
        onlypreamble.push_back(hash_table.notprerr_token);
    });
    register_action(toc_cmd, [](subtypes c) {
        {
            std::string np = "tableofcontents";
            if (c == 1) np = "listoftables";
            if (c == 2) np = "listoffigures";
            the_parser.remove_initial_star();
            the_parser.leave_h_mode();
            the_stack.push1(::the_names[np]);
            if (c == 0) {
                static bool inserted = false;
                if (!inserted) the_stack.top_stack()->id = 4;
                inserted = true;
                auto k   = eqtb_int_table[42 + count_reg_offset].val;
                the_stack.add_att_to_cur(std::string("depth"), std::string(std::to_string(k)));
            }
            the_stack.pop(::the_names[np]);
        }
    });
    register_action(center_cmd, [](subtypes c) {
        the_parser.leave_h_mode();
        the_stack.add_nl();
        the_parser.word_define(incentering_code, c, false);
    });
    register_action(thm_aux_cmd, [](subtypes c) {
        {
            TokenList L = the_parser.read_arg();
            the_parser.token_list_define(c, L, false);
        }
    });

    register_action(start_thm_cmd, [](subtypes c) {
        if (c == 2)
            the_parser.T_end_theorem();
        else
            the_parser.T_start_theorem(c);
    });
    register_action(ignore_env_cmd, [] {});
    register_action(math_env_cmd, [](subtypes c) {
        the_parser.cur_tok.kill();
        the_parser.pop_level(bt_env);
        the_parser.T_math(c);
    });
    register_action(end_ignore_env_cmd, [] {});
    register_action(end_minipage_cmd, [] {
        the_parser.flush_buffer();
        the_stack.pop_if_frame(::the_names["cst_p"]);
        the_stack.pop_if_frame(::the_names["item"]);
        the_stack.pop(::the_names["minipage"]);
    });
    register_action(mathinner_cmd, [](subtypes c) {
        if (math_loc(c) == vdots_code) {
            the_parser.back_input(hash_table.dollar_token);
            the_parser.back_input(the_parser.cur_tok);
            the_parser.back_input(hash_table.dollar_token);
        } else
            the_parser.math_only();
    });
    register_action(self_insert_cmd, [] {
        the_parser.LC();
        the_parser.unprocessed_xml.push_back(the_parser.cur_tok);
    });
}
