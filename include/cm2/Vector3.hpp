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
    //---------------------------------------
    /// \details Default constructor.
    /// \param _x - x-axis component.
    /// \param _y - y-axis component.
    /// \param _z - z-axis component.
    Vector3( const Real _x = 0, const Real _y = 0, const Real _z = 0 );
    //---------------------------------------
    /// \details Copy constructor.
    /// \param _v - the Vector3 to copy.
    Vector3( const Vector3& _v );

    //---------------------------------------
    /// \details Destructor
    ~Vector3();


    union
    {
        struct
        {
            Real x; //< x-axis component.
            Real y; //< y-axis component.
            Real z; //< z-axis component.
        };
        Real data[3]; //< data in array format.
    };
};
}

#endif
