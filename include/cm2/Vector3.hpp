// File Info {{{----------------------------------------------------------------
/// \file Vector3.hpp
/// \date 2010 Dec 19
/// \author 
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _cm2_Vector3_hpp_
#define _cm2_Vector3_hpp_
// }}}

#include "cm2/Def.hpp"

//------------------------------------------------------------------------------

namespace cm2
{
/// \brief A three dimensional point or vector
class Vector3
{
public:
    union
    {
        struct
        {
            Real x; //< x-axis component.
            Real y; //< y-axis component.
        };
        Real data[2]; //< data in array format.
    };
};
}

#endif
