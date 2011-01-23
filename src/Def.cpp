// File Info {{{----------------------------------------------------------------
/// \file Def.cpp
/// \date 2010 Dec 08
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

#include "cm2/Def.hpp"
#include <limits>

//------------------------------------------------------------------------------

#ifndef CM2_REAL_EPSILON
    #define CM2_REAL_EPSILON DBL_EPSILON
#endif

namespace cm2
{
    const Real g_realNaN = std::numeric_limits<double>::quiet_NaN();

    const Real g_realEpsilon = CM2_REAL_EPSILON;
    Real realCompareDelta = CM2_REAL_EPSILON * 10;

    Real realCompare( const Real _a, const Real _b )
    {
        return ( _a + realCompareDelta ) > _b &&
               ( _a - realCompareDelta ) < _b;
    }

    Real realCompare( const Real _a, const Real _b, const Real _delta )
    {
        return ( _a + _delta ) > _b &&
               ( _a - _delta ) < _b;
    }

    const Real g_pi_180 = M_PI / 180.0;
    Real degreeToRadian( const Real _angle )
    {
        return _angle * g_pi_180;
    }

    const Real g_180_pi = 180.0 * M_1_PI;
    Real radianToDegree( const Real _angle )
    {
        return _angle * g_180_pi;
    }
}
