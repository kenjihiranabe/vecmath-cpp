/*
   Copyright (C) 1997,1998,1999
   Kenji Hiranabe, Eiwa System Management, Inc.

   This program is free software.
   Implemented by Kenji Hiranabe(hiranabe@esm.co.jp),
   conforming to the Java(TM) 3D API specification by Sun Microsystems.

   Permission to use, copy, modify, distribute and sell this software
   and its documentation for any purpose is hereby granted without fee,
   provided that the above copyright notice appear in all copies and
   that both that copyright notice and this permission notice appear
   in supporting documentation. Kenji Hiranabe and Eiwa System Management,Inc.
   makes no representations about the suitability of this software for any
   purpose.  It is provided "AS IS" with NO WARRANTY.
*/
#ifndef VMUTIL_H
#define VMUTIL_H

#include "vm_conf.h"
#include <cstddef>
#include <cstdlib>
#include <cassert>
#include <cmath>

#ifdef VM_INCLUDE_IO
#   include <iostream>
#endif
#ifdef VM_INCLUDE_TOSTRING
#   include <string>
#   include <sstream>
#   define VM_TOSTRING std::stringstream s; s << *this; return s.str();
#endif

/**
 * to be defined for exceptions
 */
#define VM_OUT_OF_RANGE

#ifdef abs
#undef abs
#endif

#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

VM_BEGIN_NS

/**
 * VmUtil class.
 * static utility functions are defined here for portability reasons.
 */
template<class T>
struct VmUtil {
    // prefer to cmath for portability
    static T abs(T t) { return t > 0 ? t : -t; }
    static T max(T a, T b) { return a < b ? b : a; }
    static T max(T a, T b, T c) { return max(max(a, b), c); }
    static T max(T a, T b, T c, T d) { return max(max(a, b), max(c, d)); }
    static T min(T a, T b) { return a < b ? a : b; }
    static T min(T a, T b, T c) { return min(min(a, b), c); }
    static T min(T a, T b, T c, T d) { return min(min(a, b), min(c, d)); }
    static T sin(T x) { return T(std::sin(x)); }
    static T cos(T x) { return T(std::cos(x)); }
    static T atan2(T y, T x) { return T(std::atan2(y, x)); }
    static T acos(T x) { return T(std::acos(x)); }
    static T sqrt(T x) { return T(std::sqrt(x)); }
    static T pow(T x, T y) { return T(std::pow(x, y)); }
    static size_t hashCode(size_t size, const void* ptr) {
        // idea is from Bjarne Stroustrup 3rd $17.6.2.3
        size_t res = 0;
        const char* p = (const char*)ptr;  // reinterpret_cast
        while (size--)
            res = (res << 1) ^ *p++;
        return res;
    }
};

/**
 * Helper class useful when you add class T to hash_map
 */
template <class T>
struct VmHash {
    size_t operator()(const T& t) const { return t.hashCode(); }
};

VM_END_NS

#endif /* VMUTIL_H */
