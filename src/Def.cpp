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
    Real g_realEpsilon = CM2_REAL_EPSILON;

    Real realCompare( const Real _a, const Real _b )
    {
        return ( _a + g_realEpsilon ) > _b &&
               ( _a - g_realEpsilon ) < _b;
    }
}
