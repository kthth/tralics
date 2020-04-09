#pragma once
// -*- C++ -*-
// TRALICS, copyright (C) INRIA/apics (Jose' Grimm) 2004, 2007,2008

// This software is governed by the CeCILL license under French law and
// abiding by the rules of distribution of free software.  You can  use,
// modify and/ or redistribute the software under the terms of the CeCILL
// license as circulated by CEA, CNRS and INRIA at the following URL
// "http://www.cecill.info".
// (See the file COPYING in the main directory for details)

#include "tralics/Buffer.h"

// This file holds the hash table, and XML.
class LabelInfo;

// The string_hash table. It is like the hashtable below (Text and Next)
// but it is extensible (maybe, we should make the hashtable extensible)
// Each item has a pointer to a LabelInfo element. If the pointer is not null
// we consider the slot of `foo', that has a \label{foo} or \ref{foo}
// At bootstrap, we fill the table with true, false, spacebefore, center,...
// This uses utf8 encoding. The token can be dumped via its Value
// which can be ascii, utf8 or latin1 (XML syntax)

struct StrHash_record {
    String      name{nullptr};
    std::string value;
    LabelInfo * Labinfo{nullptr};
    size_t      next{0};
};

class StrHash : public std::vector<StrHash_record> {
    size_t hash_last{hash_prime + 1}; // last slot used
public:
    StrHash() : std::vector<StrHash_record>(hash_size) {
        at(0) = {"", "", nullptr, 0};
        at(1) = {"", "", nullptr, 0};
        at(2) = {" ", " ", nullptr, 0};
    }

    [[nodiscard]] auto p_str(size_t k) const -> String { return at(k).value.c_str(); } // \todo remove c_str

    auto        hash_find(const std::string &s) -> size_t;
    auto        find(String s) -> size_t;
    auto        find(const std::string &s) -> size_t;
    auto        find(int s) -> size_t;
    auto        operator[](size_t k) const -> String { return at(k).name; }
    auto        lab_val(Istring k) -> LabelInfo * { return at(k.id).Labinfo; };
    auto        lab_val_check(Istring k) -> LabelInfo *;
    static auto next_label_id() -> Istring; // \todo Move outside
    auto        find_scaled(ScaledInt s) -> Istring;
};
