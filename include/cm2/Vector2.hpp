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
    /// \brief Value set.
    /// Set the vectors value to a given x and y
    /// \param _x - x-axis component
    /// \param _y - y-axis component
    /// \return A copy of the resulting vector
    const Vector2& set( const Real _x = 0, const Real _y = 0 );

    //---------------------------------------
    /// \brief Vector add.
    /// Create a new Vector2 by adding two Vector2 together
    /// \param _rhs - the right hand side of the addition
    /// \return The resulting vector
    Vector2 operator +( const Vector2& _rhs ) const;
    //---------------------------------------
    /// \brief Vector subtract.
    /// Create a new Vector2 by subtracted one Vector2 from anther.
    /// \param _rhs - the right hand side of the subtraction
    /// \return The resulting vector
    Vector2 operator -( const Vector2& _rhs ) const;

    //---------------------------------------
    /// \brief Vector add.
    /// Add another Vector2 to this Vector2.
    /// \param _rhs - the right hand side of the addition
    /// \return A copy of the resulting vector
    const Vector2& operator +=( const Vector2& _rhs );
    //---------------------------------------
    /// \brief Vector subtract.
    /// Subtract another Vector2 to this Vector2.
    /// \param _rhs - the right hand side of the subtraction
    /// \return A copy of the resulting vector
    const Vector2& operator -=( const Vector2& _rhs );

    // dot

    //---------------------------------------
    /// \brief Scalar multiply.
    /// Create a new Vector2 by multiplying this Vector2 by a Real number.
    /// \param _rhs - the right hand side of the multiplcation
    /// \return The resulting vector
    Vector2 operator *( const Real _rhs ) const;
    //---------------------------------------
    /// \brief Scaler division.
    /// Create a new Vector2 by dividing this Vector2 by a Real number.
    /// \param _rhs - the right hand side of the division
    /// \return The resulting vector
    Vector2 operator /( const Real _rhs ) const;

    // Vect *= Real
    // Vect /= Real

    // magnitude
    // magnitudeSquared
    // normalise

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
