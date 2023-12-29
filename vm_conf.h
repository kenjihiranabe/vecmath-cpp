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
#ifndef VM_CONF_H
#define VM_CONF_H

/* -----------------------------------------------------------
 *  you can configure these defines.
 * ----------------------------------------------------------- */

/*
 * can do 'cout << vec;'
 */
//#define VM_INCLUDE_IO

/*
 * can do 'vec.toString();'
 * automatically defines VM_INCLUDE_IO
 */
//#define VM_INCLUDE_TOSTRING

/*
 * places this library in 'kh_vecmath' namespace
 * later section can turn this off(earlyer version than egcs1.1.2 ).
 * 
 */
#define VM_INCLUDE_NAMESPACE

/* -----------------------------------------------------------
 *   end user customization section 
 * ----------------------------------------------------------- */
 
#ifdef VM_INCLUDE_NAMESPACE
#  define VM_VECMATH_NS  kh_vecmath
#  define VM_BEGIN_NS namespace kh_vecmath {
#  define VM_END_NS }
#else
#  define VM_VECMATH_NS
#  define VM_BEGIN_NS
#  define VM_END_NS
#endif


#ifdef VM_INCLUDE_TOSTRING
#  ifndef VM_INCLUDE_IO
#    define VM_INCLUDE_IO
#  endif
#endif


#endif /* VM_CONF_H */
