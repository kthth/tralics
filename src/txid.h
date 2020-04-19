#pragma once
// -*- C++ -*-
// TRALICS, copyright (C) INRIA/apics (Jose' Grimm) 2006,2008

// This software is governed by the CeCILL license under French law and
// abiding by the rules of distribution of free software.  You can  use,
// modify and/ or redistribute the software under the terms of the CeCILL
// license as circulated by CEA, CNRS and INRIA at the following URL
// "http://www.cecill.info".
// (See the file COPYING in the main directory for details)

#include "tralics/Istring.h"

class AttList;

// Adress of attribute list of an xml object
// is a wrapper around an int
class Xid {
public:
    long value; // value of the id \todo should this be size_t ?

    Xid(long v = 0) : value(v) {}

    [[nodiscard]] auto get_att() const -> AttList &;
    [[nodiscard]] auto is_font_change() const -> bool;

    void               add_attribute(Istring A, Istring B) const;
    void               add_attribute(const Istring& A, const Istring& B, bool f) const;
    void               add_attribute(name_positions A, name_positions B) const;
    void               add_attribute(name_positions A, name_positions B, bool c) const;
    void               add_attribute(name_positions n, Istring v) const;
    void               add_attribute(const AttList &L, bool f) const;
    void               add_attribute_but_rend(Xid b) const;
    void               add_attribute(Xid b) const;
    void               add_ref(const std::string &s) const;
    void               add_span(long n) const;
    void               add_top_rule() const;
    void               add_bottom_rule() const;
    [[nodiscard]] auto has_attribute(const Istring &n) const -> Istring;
    void               add_special_att(const std::string &S);

    auto operator==(const Xid &X) const -> bool { return value == X.value; }
};
