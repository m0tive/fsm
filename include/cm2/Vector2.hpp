// File Info {{{----------------------------------------------------------------
/// \file Vector2.hpp
/// \date 2010 Nov 16
/// \author 
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _cm2_Vector2_hpp_
#define _cm2_Vector2_hpp_
// }}}

#include "cm2/Def.hpp"

//------------------------------------------------------------------------------

namespace cm2
{
/// \brief A two dimensional point or vector
class Vector2
{
public:
    //---------------------------------------
    /// \details Default constructor.
    Vector2();

    /// \details Copy constructor.
    /// \param _v - the Vector2 to copy.
    Vector2( const Vector2& _v );

    /// \details Value constructor.
    /// \param _x - x-axis component.
    /// \param _y - y-axis component.
    Vector2( const Real _x, const Real _y );

    //---------------------------------------
    /// \details Destructor
    ~Vector2();

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
