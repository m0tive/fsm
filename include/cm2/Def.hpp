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

#ifndef _cm2_Def_hpp_
#define _cm2_Def_hpp_
// }}}

#define _USE_MATH_DEFINES
#include <math.h>

#ifdef CM2_USE_LOCAL_STDINT
  #ifdef CM2_USE_MSC_STDINT
      #undef CM2_USE_MSC_STDINT
  #endif
#else
  #ifndef CM2_USE_MSC_STDINT
    #if defined(_MSC_VER) && _MSC_VER < 1600
      #define CM2_USE_MSC_STDINT
    #endif
  #endif
#endif


#ifdef CM2_USE_MSC_STDINT
  #include "cm2/stdint.h"
#else
  #include <stdint.h>
#endif
#include <float.h>

namespace cm2
{
    typedef double Real;
    inline Real pow( const Real r1, const Real r2 ) { return ::pow( r1, r2 ); }
    inline Real sqrt( const Real r ) { return ::sqrt(r); }

    extern const Real g_realEpsilon;
    //---------------------------------------
    /// \brief Floating point comparison.
    /// Test if two Real numbers are almost equal. If there is a difference of
    /// less than CM2_REAL_EPSILON * 10, they are considered equal.
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

    Real degreeToRadian( const Real _angle );
    Real radianToDegree( const Real _angle );
}

#endif
