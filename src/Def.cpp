// File Info {{{----------------------------------------------------------------
/// \file Def.cpp
/// \date 2010 Dec 08
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

#include "cm2/Def.hpp"

//------------------------------------------------------------------------------

#ifndef CM2_REAL_EPSILON
    #define CM2_REAL_EPSILON DBL_EPSILON
#endif

namespace cm2
{
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
}
