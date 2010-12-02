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
    /// \details Constructor.
    /// \param _x - x-axis component.
    /// \param _y - y-axis component.
    Vector2( const Real _x = 0, const Real _y = 0 );
    //---------------------------------------
    /// \details Copy constructor.
    /// \param _v - the Vector2 to copy.
    Vector2( const Vector2& _v );

    //---------------------------------------
    /// \details Destructor
    ~Vector2();


    //---------------------------------------
    /// \brief Set the vectors value by copying another vector
    /// \param _v - vector to copy
    /// \return A copy of the resulting vector
    const Vector2& set( const Vector2& _v );
    //---------------------------------------
    /// \brief Set the vectors value to a given x and y
    /// \param _x - x-axis component
    /// \param _y - y-axis component
    /// \return A copy of the resulting vector
    const Vector2& set( const Real _x = 0, const Real _y = 0 );


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
