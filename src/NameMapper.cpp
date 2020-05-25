#include "tralics/NameMapper.h"
#include "tralics/MainClass.h"
#include "tralics/Parser.h"
#include "tralics/globals.h"

auto NameMapper::operator[](const std::string &name) const -> Istring { return dict.contains(name) ? dict.at(name) : Istring(name); }

auto NameMapper::operator[](name_positions i) const -> Istring {
    // spdlog::warn("deprecated : id {} is key {}", i, id_to_name[i]);
    return (*this)[id_to_name[i]];
}

void NameMapper::set(name_positions i, const std::string &s) { dict[id_to_name[i]] = Istring(s); }

void NameMapper::set(const std::string &name, const std::string &value) { dict[name] = Istring(value); };

void NameMapper::def(const std::string &name, name_positions pos, const std::optional<std::string> &value) {
    id_to_name[pos] = name;
    dict[name]      = value ? Istring(*value) : Istring();
}

void NameMapper::def(name_positions i, const std::string &s) { id_to_name[i] = s; }

auto NameMapper::cstf(size_t i) -> Istring {
    static const std::array<std::string, 15> fonts = {"normal",
                                                      "cstf_upright",
                                                      "bold",
                                                      "italic",
                                                      "bold-italic",
                                                      "script",
                                                      "bold-script",
                                                      "fraktur",
                                                      "double-struck",
                                                      "bold-fraktur",
                                                      "sans-serif",
                                                      "bold-sans-serif",
                                                      "sans-serif-italic",
                                                      "sans-serif-bold-italic",
                                                      "monospace"

    };
    return (*this)[fonts[i]];
}

auto NameMapper::mml(size_t i) -> Istring {
    static std::array<std::string, 15> fonts = {"mml@font@normal",
                                                "mml@font@upright",
                                                "mml@font@bold",
                                                "mml@font@italic",
                                                "mml@font@bolditalic",
                                                "mml@font@script",
                                                "mml@font@boldscript",
                                                "mml@font@fraktur",
                                                "mml@font@doublestruck",
                                                "mml@font@boldfraktur",
                                                "mml@font@sansserif",
                                                "mml@font@boldsansserif",
                                                "mml@font@sansserifitalic",
                                                "mml@font@sansserifbolditalic",
                                                "mml@font@monospace"

    };
    return (*this)[fonts[i]];
}

auto NameMapper::mi(size_t i) -> Istring {
    static std::array<std::string, 8> list = {"mi", "mn", "mo", "ci", "cn", "csymbol", "cst_nothing", "mmultiscripts"};
    return (*this)[list[i]];
}

void NameMapper::boot() {
    // Special cases where name != default value
    def("arc", np_arc, "pic-arc");
    def("bezier", np_bezier, "pic-bezier");
    def("bigcircle", np_bigcircle, "pic-bigcircle");
    def("border_left_width", np_border_leftw, "border-left-width");
    def("border_right_width", np_border_rightw, "border-right-width");
    def("box_scale", np_s_scale, "scale");
    def("box_width", np_box_width, "width");
    def("box", np_box, "pic-framebox");
    def("caption", np_captions, "head");
    def("centering", np_center_etc1, "center");
    def("circle", np_circle, "pic-circle");
    def("citetype", np_cite_type, "type");
    def("closecurve", np_closecurve, "pic-closecurve");
    def("cst_div0", cst_div0, "div0");
    def("cst_div1", cst_div1, "div1");
    def("cst_div2", cst_div2, "div2");
    def("cst_div3", cst_div3, "div3");
    def("cst_div4", cst_div4, "div4");
    def("cst_div5", cst_div5, "div5");
    def("cst_div6", cst_div6, "div6");
    def("cst_empty", cst_empty, "");
    def("cst_invalid", cst_invalid);
    def("cst_nothing", cst_nothing, "");
    def("cst_p", cst_p, "p");
    def("curve_nbpts", np_curve_nbpts, "nbsymb");
    def("curve", np_curve, "pic-curve");
    def("fbox_rend", np_b_rend, "rend");
    def("figure_env", np_float_figure, "figure");
    def("file_extension", np_fileextension, "extension");
    def("flush_left", np_center_etc4, "flushed-left");
    def("flush_right", np_center_etc5, "flushed-right");
    def("font_bold", np_font_bold, "bold");
    def("font_boldextended", np_font_boldextended, "boldextended");
    def("font_condensed", np_font_condensed, "condensed");
    def("font_it", np_font_it, "it");
    def("font_large", np_font_large, "large");
    def("font_large1", np_font_large1, "large1");
    def("font_large2", np_font_large2, "large2");
    def("font_large3", np_font_large3, "large3");
    def("font_large4", np_font_large4, "large4");
    def("font_large5", np_font_large5, "large5");
    def("font_large6", np_font_large6, "large6");
    def("font_medium", np_font_medium, "medium");
    def("font_normalsize", np_font_normalsize, "normalsize");
    def("font_roman", np_font_roman, "roman");
    def("font_sansserif", np_font_sansserif, "sansserif");
    def("font_sc", np_font_sc, "sc");
    def("font_semibold", np_font_semibold, "semibold");
    def("font_slanted", np_font_slanted, "slanted");
    def("font_small", np_font_small, "small");
    def("font_small1", np_font_small1, "small1");
    def("font_small2", np_font_small2, "small2");
    def("font_small3", np_font_small3, "small3");
    def("font_small4", np_font_small4, "small4");
    def("font_small5", np_font_small5, "small5");
    def("font_small6", np_font_small6, "small6");
    def("font_tt", np_font_tt, "tt");
    def("font_upright", np_font_upright, "upright");
    def("foot_position", np_foot, "foot");
    def("footnote", np_footnote, "note");
    def("glo", np_glo_name, "Glossary");
    def("gloitem", np_label_glo, "label");
    def("inner_pos", np_posi, "inner-pos");
    def("line", np_line, "pic-line");
    def("lineC", np_lineC, "line");
    def("linethickness", np_line_thickness, "pic-linethickness");
    def("minipage_width", np_minipage_width, "width");
    def("multiput", np_multiput, "pic-multiput");
    def("natcit", np_natcit, "Cit");
    def("np_center_etc", np_center_etc, "center");
    def("np_linethickness", np_linethickness, "linethickness");
    def("oval", np_oval, "pic-oval");
    def("project", np_projet, "projet");
    def("put", np_put, "pic-put");
    def("quotation", np_center_etc3, "quoted");
    def("quote", np_center_etc2, "quoted");
    def("rotate_angle", np_r_angle, "angle");
    def("rotatebox", np_rotatebox, "pic-rotatebox");
    def("row_spaceafter", np_spaceafter, "spaceafter");
    def("scaleput", np_scaleput, "pic-scaleput");
    def("scaption", np_caption, "caption");
    def("stylesheet", np_stylesheet, "");
    def("stylesheettype", np_stylesheet_type, "text/css");
    def("table_env", np_float_table, "table");
    def("table_width", np_tab_width, "width");
    def("tagcurve", np_tagcurve, "pic-tagcurve");
    def("theorem_head", np_theorem_head, "alt_head");
    def("thicklines", np_thick_lines, "pic-thicklines");
    def("thinlines", np_thin_lines, "pic-thinlines");
    def("unit_length", np_unit_length, "unit-length");
    def("vector", np_vector, "pic-vector");

    // Below, this is a mapping id <-> name = default value
    def(cst_ci, "ci");
    def(cst_cn, "cn");
    def(cst_csymbol, "csymbol");
    def(cst_hanl, "hanl");
    def(cst_hi, "hi");
    def(cst_mi, "mi");
    def(cst_mn, "mn");
    def(cst_mo, "mo");
    def(cst_multiscripts, "mmultiscripts");

    def(np_abarnodeconnect, "abarnodeconnect");
    def(np_allowbreak, "allowbreak");
    def(np_anchor, "anchor");
    def(np_anodeconnect, "anodeconnect");
    def(np_anodecurve, "anodecurve");
    def(np_backmatter, "backmatter");
    def(np_barnodeconnect, "barnodeconnect");
    def(np_bauteurs, "bauteurs");
    def(np_bediteurs, "bediteur");
    def(np_biblio, "biblio");
    def(np_bpers, "bpers");
    def(np_center_etc6, "verse");
    def(np_citation, "citation");
    def(np_dashbox, "pic-dashbox");
    def(np_dashline, "dashline");
    def(np_div0, "div0");
    def(np_div1, "div1");
    def(np_div2, "div2");
    def(np_div3, "div3");
    def(np_div4, "div4");
    def(np_div5, "div5");
    def(np_div6, "div6");
    def(np_dottedline, "dottedline");
    def(np_drawline, "drawline");
    def(np_error, "error");
    def(np_fbox, "fbox");
    def(np_figure, "figure");
    def(np_float, "float");
    def(np_frame, "pic-frame");
    def(np_frontmatter, "frontmatter");
    def(np_head, "head");
    def(np_hfil, "hfil");
    def(np_hfill, "hfill");
    def(np_hfilneg, "hfilneg");
    def(np_hss, "hss");
    def(np_item, "item");
    def(np_keywords, "keywords");
    def(np_mainmatter, "mainmatter");
    def(np_mbox, "mbox");
    def(np_minipage, "minipage");
    def(np_node, "node");
    def(np_nodebox, "nodebox");
    def(np_nodecircle, "nodecircle");
    def(np_nodeconnect, "nodeconnect");
    def(np_nodecurve, "nodecurve");
    def(np_nodeoval, "nodeoval");
    def(np_nodetriangle, "nodetriangle");
    def(np_overline, "overline");
    def(np_pagecolor, "pagecolor");
    def(np_picture, "picture");
    def(np_point, "point");
    def(np_ref, "ref");
    def(np_row, "row");
    def(np_rule, "rule");
    def(np_sbox, "scalebox");
    def(np_sc, "sc");
    def(np_scale, "scale");
    def(np_size, "size");
    def(np_Table, "Table");
    def(np_term, "term");
    def(np_texte, "texte");
    def(np_theglossary, "theglossary");
    def(np_theindex, "theindex");
    def(np_theme, "theme");
    def(np_toc, "tableofcontents");
    def(np_toc1, "listoftables");
    def(np_toc2, "listoffigures");
    def(np_totalwidth, "totalwidth");
    def(np_underline, "underline");
    def(np_unknown, "unknown");
    def(np_url, "url");
    def(np_vfil, "vfil");
    def(np_vfill, "vfill");
    def(np_vfilneg, "vfilneg");
    def(np_vpos, "vpos");
    def(np_vss, "vss");
    def(np_xdir, "xdir");
    def(np_xref, "xref");
    def(np_xscale, "xscale");
    def(np_xscaley, "xscaley");
    def(np_ydir, "ydir");
    def(np_yscale, "yscale");
    def(np_yscalex, "yscalex");

    // Cases without name_position where default value is not the key name
    set("bibkey", "bib-key");
    set("cell_leftborder", "left-border");
    set("cell_rightborder", "right-border");
    set("cell_center", "center");
    set("cell_left", "left");
    set("cell_right", "right");
    set("cst_display", "display");
    set("gloss_type", "gloss");
    set("language", "");
    set("np_center", "center");
    set("np_cst_width", "width");
    set("np_separator", "");
    set("cell_topborder", "top-border");
    set("border_top_width", "border-top-width");
    set("cell_bottomborder", "bottom-border");
    set("border_bottom_width", "border-bottom-width");
    set("mathmlns", "http://www.w3.org/1998/Math/MathML");
    set("np_theorem", "");
    set("box_pos", "position");
    set("user_list", "description");
    set("cstf_upright", "");
    set("space_before", "spacebefore");
    set("nb_rasection", "");
    set("composition_ra", "composition");
    set("full_first", "prenomcomplet");
    set("particule", "part");
    set("labelitem", "label");
    set("warning", "");
    set("rcval", "+UR");
    set("rclist", "UR");
    set("alt_section", "alt_head");
    set("alt_caption", "alt_head");
    set("cstb_language", "language");
    set("cstb_key", "key");
    set("cstb_type", "type");
    set("cstb_unknown", "unknown");
    set("cstb_url", "url");
}

void NameMapper::assign(const std::string &sa, const std::string &sb) {
    spdlog::trace("Assigning to `{}` the value \"{}\"", sa, sb);
    auto n = sa.size();

    if (sa.starts_with("elt_")) return the_names.assign_name(sa.substr(4), sb);
    if (sa.starts_with("xml_")) return the_names.assign_name(sa.substr(4, sa.ends_with("_name") ? n - 9 : n - 4), sb);
    if (sa.starts_with("att_")) return set(sa.substr(4), sb);

    if (sa == "lang_fr") { set("french", sb); }
    if (sa == "lang_en") { set("english", sb); }
    if (sa == "distinguish_refer_in_rabib") {
        if ((sb == "true") || (sb == "yes"))
            the_main->distinguish_refer = true;
        else if ((sb == "false") || (sb == "no"))
            the_main->distinguish_refer = false;
        else
            spdlog::warn("distinguish_refer_in_rabib = {} ignored");
    }
    if (sa == "entity_names") { the_main->set_ent_names(sb); }
    if (sa == "default_class") { the_main->default_class = sb; }
    if (sa == "alternate_item") {
        if (sb == "false")
            the_parser.hash_table.eval_let("item", "@@item");
        else if (sb == "true")
            the_parser.hash_table.eval_let("item", "@item");
    }
    if (sa == "url_font") {
        Buffer aux;
        aux << "\\def\\urlfont{" << sb << "}";
        the_main->add_to_from_config(1, aux); // \todo no Buffer
    }
    if (sa == "everyjob") { everyjob_string = fmt::format("\\everyjob={{{}}}", sb); }
    if (sa == "no_footnote_hack") {
        if (sb == "true") the_main->footnote_hack = false;
        if (sb == "false") the_main->footnote_hack = true;
    }
    if (sa == "use_font_elt") {
        if (sb == "true") the_main->use_font_elt = true;
        if (sb == "false") the_main->use_font_elt = false;
    }
    if (sa == "use_all_sizes") {
        if (sb == "true") the_main->use_all_sizes = true;
        if (sb == "false") the_main->use_all_sizes = false;
    }
    if (sa == "bibtex_fields") {
        Buffer(sb).interpret_bibtex_list(); // \todo without Buffer
    }
    if (sa == "bibtex_extensions") { Buffer(sb).interpret_bibtex_extension_list(); }
    if (sa == "mfenced_separator_val") {
        if (sb == "NONE")
            set("np_separator", "");
        else
            set("np_separator", sb);
    }
    if (sa.ends_with("_vals")) {
        Buffer B(sb);
        config_ns::interpret_list(sa.substr(0, n - 5), B); // \todo without Buffer
    }
    if (sa == "mml_font_normal") { set("mml@font@normal", sb); }
    if (sa == "mml_font_upright") { set("mml@font@upright", sb); }
    if (sa == "mml_font_bold") { set("mml@font@bold", sb); }
    if (sa == "mml_font_italic") { set("mml@font@italic", sb); }
    if (sa == "mml_font_bold_italic") { set("mml@font@bolditalic", sb); }
    if (sa == "mml_font_script") { set("mml@font@script", sb); }
    if (sa == "mml_font_bold_script") { set("mml@font@boldscript", sb); }
    if (sa == "mml_font_fraktur") { set("mml@font@fraktur", sb); }
    if (sa == "mml_font_doublestruck") { set("mml@font@doublestruck", sb); }
    if (sa == "mml_font_bold_fraktur") { set("mml@font@boldfraktur", sb); }
    if (sa == "mml_font_sansserif") { set("mml@font@sansserif", sb); }
    if (sa == "mml_font_bold_sansserif") { set("mml@font@boldsansserif", sb); }
    if (sa == "mml_font_sansserif_italic") { set("mml@font@sansserifitalic", sb); }
    if (sa == "mml_font_sansserif_bold_italic") { set("mml@font@sansserifbolditalic", sb); }
    if (sa == "mml_font_monospace") { set("mml@font@monospace", sb); }
}

void NameMapper::assign_name(const std::string &A, const std::string &B) {
    spdlog::trace("Setting XML element name `{}' to \"{}\" (assign_name)", A, B);

    if (A == "pack_font_att") {
        if (B == "true") the_main->pack_font_elt = true;
        if (B == "false") the_main->pack_font_elt = false;
        return;
    }

    if (A == "rasection" && ra_ok) {
        set("nb_rasection", B);
        return;
    }

    if (A == "theorem") {
        if (B[0] == 0) { // reverst to old behavior
            set("np_theorem", B);
            the_parser.hash_table.eval_let("@begintheorem", "@ybegintheorem");
        } else if (B[0] == ' ') { // special case
            set("np_theorem", B.substr(1));
            the_parser.hash_table.eval_let("@begintheorem", "@ybegintheorem");
        } else {
            set("np_theorem", B);
            the_parser.hash_table.eval_let("@begintheorem", "@xbegintheorem");
        }
        return;
    }

    if (A == "use_font_elt") {
        if (B == "true") the_main->use_font_elt = true;
        if (B == "false") the_main->use_font_elt = false;
        return;
    }

    if (A == "xtheorem") {
        set("np_theorem", B);
        return;
    }

    set(A, B);
}