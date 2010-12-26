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


    //---------------------------------------
    /// \brief Value set.
    /// Set the vectors value to a given x, y and z
    /// \param _x - x-axis component
    /// \param _y - y-axis component
    /// \param _z - z-axis component
    /// \return A copy of the resulting vector
    const Vector3& set( const Real _x = 0, const Real _y = 0, const Real _z = 0 );

    //---------------------------------------
    /// \brief Negative operator.
    /// Make a new Vector3 by making each value of this Vector3 negative.
    /// \return The resulting vector
    Vector3 operator -() const;

    //---------------------------------------
    /// \brief Vector assignment.
    /// Copy the value of another Vector3 into this vector
    /// \param _rhs - the vector to copy
    /// \return A copy of the resulting vector
    const Vector3& operator =( const Vector3& _rhs );

    //---------------------------------------
    /// \brief Vector add.
    /// Create a new Vector3 by adding two Vector3 together
    /// \param _rhs - the right hand side of the addition
    /// \return The resulting vector
    Vector3 operator +( const Vector3& _rhs ) const;
    //---------------------------------------
    /// \brief Vector subtract.
    /// Create a new Vector3 by subtracted one Vector3 from anther.
    /// \param _rhs - the right hand side of the subtraction
    /// \return The resulting vector
    Vector3 operator -( const Vector3& _rhs ) const;

    //---------------------------------------
    /// \brief Scalar multiply.
    /// Create a new Vector3 by multiplying this Vector3 by a Real number.
    /// \param _rhs - the right hand side of the multiplication
    /// \return The resulting vector
    Vector3 operator *( const Real _rhs ) const;
    //---------------------------------------
    /// \brief Scalar division.
    /// Create a new Vector3 by dividing this Vector3 by a Real number.
    /// \param _rhs - the right hand side of the division
    /// \return The resulting vector
    Vector3 operator /( const Real _rhs ) const;

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
