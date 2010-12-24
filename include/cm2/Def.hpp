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
    inline Real cos( const Real r ) { return ::cos(r); }
    inline Real sin( const Real r ) { return ::sin(r); }
    inline Real tan( const Real r ) { return ::tan(r); }
    inline Real acos( const Real r ) { return ::acos(r); }
    inline Real asin( const Real r ) { return ::asin(r); }
    inline Real atan( const Real r ) { return ::atan(r); }
    inline Real atan2( const Real r1, const Real r2 ) { return ::atan2( r1, r2 ); }

    inline Real pow( const Real r1, const Real r2 ) { return ::pow( r1, r2 ); }
    inline Real sqrt( const Real r ) { return ::sqrt(r); }

    extern const Real g_realEpsilon;
    Real realCompare( const Real _a, const Real _b );
}

#endif
