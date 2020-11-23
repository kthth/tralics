#include "tralics/Symcode.h"

auto Symcode::get(symcodes v) -> Symcode & {
    static std::unordered_map<symcodes, Symcode> m;
    m.try_emplace(v, Symcode{v});
    return m.at(v);
}

auto Symcode::call(subtypes c) const -> std::optional<bool> {
    if (action) return (*action)(c);
    return {};
}

auto Symcode::name(subtypes c) const -> std::optional<std::string> {
    if (name_fn) return (*name_fn)(c);
    if (auto it = name_sub.find(c); it != name_sub.end()) return it->second;
    return {};
}