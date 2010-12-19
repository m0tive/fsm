// File Info {{{----------------------------------------------------------------
/// \file Vector3.cpp
/// \date 2010 Dec 19
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

#include "cm2/Vector3.hpp"

//------------------------------------------------------------------------------

namespace cm2
{
    //---------------------------------------
    Vector3::Vector3(
            const Real _x/* = 0*/, const Real _y/*= 0*/, const Real _z/*= 0*/)
        : x(_x), y(_y), z(_z)
    {
    }

    //---------------------------------------
    Vector3::Vector3( const Vector3& _v )
        : x(_v.x), y(_v.y), z(_v.z)
    {
    }

    //---------------------------------------
    Vector3::~Vector3()
    {
    }

    //---------------------------------------
    const Vector3& Vector3::set(
            const Real _x/*= 0*/, const Real _y/*= 0*/, const Real _z/*= 0*/ )
    {
        x = _x;
        y = _y;
        z = _z;
        return *this;
    }
}
