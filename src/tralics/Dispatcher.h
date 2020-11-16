#pragma once
#include "Parser.h"
#include "enums.h"
#include <unordered_map>

class Dispatcher {
public:
    using parser_fn                  = bool (Parser::*)();
    using parser_fn_void             = void (Parser::*)();
    using parser_fn_with_x           = bool (Parser::*)(symcodes x);
    using parser_fn_with_x_void      = void (Parser::*)(symcodes x);
    using parser_fn_with_c           = bool (Parser::*)(subtypes c);
    using parser_fn_with_c_void      = void (Parser::*)(subtypes c);
    using parser_fn_with_xc          = bool (Parser::*)(symcodes x, subtypes c);
    using parser_fn_with_xc_void     = void (Parser::*)(symcodes x, subtypes c);
    using parser_fn_with_cmdchr      = bool (Parser::*)(CmdChr cc);
    using parser_fn_with_cmdchr_void = void (Parser::*)(CmdChr cc);

    Dispatcher();

    auto call(symcodes x, subtypes c) -> std::optional<bool>;
    auto name(symcodes x, subtypes c) -> std::optional<std::string>;

    void register_action(symcodes x, const std::function<bool()> &f);                   // explicit action
    void register_action(symcodes x, const std::function<void()> &f);                   // explicit action, return true
    void register_action(symcodes x, const std::function<bool(symcodes)> &f);           // explicit action
    void register_action(symcodes x, const std::function<void(symcodes)> &f);           // explicit action, return true
    void register_action(symcodes x, const std::function<bool(subtypes)> &f);           // explicit action
    void register_action(symcodes x, const std::function<void(subtypes)> &f);           // explicit action, return true
    void register_action(symcodes x, const std::function<bool(symcodes, subtypes)> &f); // explicit action
    void register_action(symcodes x, const std::function<void(symcodes, subtypes)> &f); // explicit action, return true

    void register_action(symcodes x, parser_fn f);                  // x triggers the_parser.f()
    void register_action(symcodes x, parser_fn_void f);             // x triggers the_parser.f(), return true
    void register_action(symcodes x, parser_fn_with_x f);           // x triggers the_parser.f(x)
    void register_action(symcodes x, parser_fn_with_x_void f);      // x triggers the_parser.f(x), return true
    void register_action(symcodes x, parser_fn_with_c f);           // x triggers the_parser.f(c)
    void register_action(symcodes x, parser_fn_with_c_void f);      // x triggers the_parser.f(c), return true
    void register_action(symcodes x, parser_fn_with_xc f);          // x triggers the_parser.f(x,c)
    void register_action(symcodes x, parser_fn_with_xc_void f);     // x triggers the_parser.f(x,c), return true
    void register_action(symcodes x, parser_fn_with_cmdchr f);      // x triggers the_parser.f({x,c})
    void register_action(symcodes x, parser_fn_with_cmdchr_void f); // x triggers the_parser.f({x,c}), return true

    void register_name(symcodes x, const std::function<std::string(symcodes, subtypes)> &f);
    void register_name(symcodes x, subtypes c, const std::string &s);

private:
    static std::unordered_map<symcodes, std::function<bool(symcodes, subtypes)>> &       the_actions();
    static std::unordered_map<symcodes, std::function<std::string(symcodes, subtypes)>> &the_name_fns();
    static std::unordered_map<symcodes, std::unordered_map<subtypes, std::string>> &     the_names();
};

inline Dispatcher actions;
