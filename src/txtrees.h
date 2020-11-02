#pragma once
#include "tralics/Indexer.h"
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

class Xml;

// -*- C++ -*-
// Copyright (c)  INRIA/apics (Jose' Grimm) 2002, 2004, 2007, 2008

// This software is governed by the CeCILL license under French law and
// abiding by the rules of distribution of free software.  You can  use,
// modify and/ or redistribute the software under the terms of the CeCILL
// license as circulated by CEA, CNRS and INRIA at the following URL
// "http://www.cecill.info".
// (See the file COPYING in the main directory for details)

namespace tralics_ns {
    void add_ref(long v, const std::string &s, bool idx);
    void find_index_labels(std::vector<std::string> &W);

} // namespace tralics_ns

class OneIndex {
    std::string            name;
    std::string            title;
    Xml *                  position; // Position on the XML of the index
    size_t                 AL;       // The attribute list index
    std::vector<Indexer *> value;

public:
    OneIndex(std::string a, std::string b, size_t c) : name(std::move(a)), title(std::move(b)), position(nullptr), AL(c) {}

    [[nodiscard]] auto size() const { return value.size(); }
    [[nodiscard]] auto get_title() const -> const std::string & { return title; }
    [[nodiscard]] auto get_position() const -> Xml * { return position; }
    [[nodiscard]] auto get_translation(size_t i) const -> Xml * { return value[i]->translation; }
    [[nodiscard]] auto get_iid(size_t i) const -> size_t { return value[i]->iid; }
    [[nodiscard]] auto has_name(const std::string &s) const -> bool { return name == s; }
    [[nodiscard]] auto get_AL() const -> size_t { return AL; }

    void set_position(Xml *x) { position = x; }
    auto get_data() -> std::vector<Indexer *> & { return value; }
    void do_sort() {
        std::sort(value.begin(), value.end(), [](auto A, auto B) { return A->key < B->key; });
    }
};

struct AllIndex : public std::vector<OneIndex *> {
    size_t last_index{0}, last_iid{0};

    AllIndex();

    auto find_index(const std::string &s) -> size_t;
    void mark_print(size_t g);
    void new_index(const std::string &s, const std::string &title);
};
