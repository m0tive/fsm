// File Info {{{----------------------------------------------------------------
/// \file Def.hpp
/// \date 2010 Dec 1
/// \author 
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _fsm_Def_hpp_
#define _fsm_Def_hpp_
// }}}

#define _USE_MATH_DEFINES
#include <math.h>

#ifdef FSM_USE_LOCAL_STDINT
  #ifdef FSM_USE_MSC_STDINT
      #undef FSM_USE_MSC_STDINT
  #endif
#else
  #ifndef FSM_USE_MSC_STDINT
    #if defined(_MSC_VER) && _MSC_VER < 1600
      #define FSM_USE_MSC_STDINT
    #endif
  #endif
#endif


#ifdef FSM_USE_MSC_STDINT
  #include "fsm/stdint.h"
#else
  #include <stdint.h>
#endif
#include <float.h>
#include <stddef.h>

/// \brief Library namespace
namespace fsm
{
    //---------------------------------------
    /// \brief A real number.
    typedef double Real;

    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/pow.html">cmath pow()</A>
    inline Real pow( const Real r1, const Real r2 ) { return ::pow( r1, r2 ); }
    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/sqrt.html">cmath sqrt()</A>
    inline Real sqrt( const Real r ) { return ::sqrt(r); }

    //---------------------------------------
    /// \brief Not a number value.
    extern const Real g_realNaN;

    //---------------------------------------
    /// \brief Smallest possible real number.
    extern const Real g_realEpsilon;
    //---------------------------------------
    /// \brief Floating point comparison.
    /// Test if two Real numbers are almost equal. If there is a difference of
    /// less than FSM_REAL_EPSILON * 10, they are considered equal.
    /// \param _a - first floating point number.
    /// \param _b - second floating point number.
    /// \return True if the two numbers are almost equal.
    Real realCompare( const Real _a, const Real _b );
    //---------------------------------------
    /// \brief Floating point comparison.
    /// Test if two Real numbers are almost equal. If there is a difference of
    /// less than _delta, they are considered equal.
    /// \param _a - first floating point number.
    /// \param _b - second floating point number.
    /// \param _delta - the difference to consider equal.
    /// \return True if the two numbers are different by less than _delta
    Real realCompare( const Real _a, const Real _b, const Real _delta );

    //---------------------------------------
    /// \brief Convert an angle from degrees to radians
    /// \param _angle - the angle to convert
    /// \return The angle in radians
    Real degreeToRadian( const Real _angle );
    //---------------------------------------
    /// \brief Convert an angle from radians to degrees
    /// \param _angle - the angle to convert
    /// \return The angle in degrees
    Real radianToDegree( const Real _angle );
}

#endif
