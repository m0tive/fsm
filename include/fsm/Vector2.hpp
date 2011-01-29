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

#ifndef _fsm_Vector2_hpp_
#define _fsm_Vector2_hpp_
// }}}

#include "fsm/Def.hpp"

//------------------------------------------------------------------------------

namespace fsm
{
/// \brief A two dimensional point or vector
class Vector2
{
public:
    static const Vector2 cNaN;

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
    /// \brief Test is invalid.
    /// Checks if the components x or y are NaN.
    /// \return True if either parts of the vector are NaN.
    bool isNaN() const;


    //---------------------------------------
    /// \brief Value set.
    /// Set the vectors value to a given x and y
    /// \param _x - x-axis component
    /// \param _y - y-axis component
    /// \return A copy of the resulting vector
    const Vector2& set( const Real _x = 0, const Real _y = 0 );

    //---------------------------------------
    /// \brief Negative operator.
    /// Make a new Vector2 by making each value of this Vector2 negative.
    /// \return The resulting vector
    Vector2 operator -() const;

    //---------------------------------------
    /// \brief Vector assignment.
    /// Copy the value of another Vector2 into this vector
    /// \param _rhs - the vector to copy
    /// \return A copy of the resulting vector
    const Vector2& operator =( const Vector2& _rhs );

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
    /// Subtract another Vector2 from this Vector2.
    /// \param _rhs - the right hand side of the subtraction
    /// \return A copy of the resulting vector
    const Vector2& operator -=( const Vector2& _rhs );

    //---------------------------------------
    /// \brief Vector dot product.
    /// Calculate the dot product of this Vector2 and another Vector2.
    /// \param _rhs - the right hand side of the dot product
    /// \return The dot product
    Real dot( const Vector2& _rhs ) const;

    //---------------------------------------
    /// \brief Scalar multiply.
    /// Create a new Vector2 by multiplying this Vector2 by a Real number.
    /// \param _rhs - the right hand side of the multiplication
    /// \return The resulting vector
    Vector2 operator *( const Real _rhs ) const;
    //---------------------------------------
    /// \brief Scalar division.
    /// Create a new Vector2 by dividing this Vector2 by a Real number.
    /// \param _rhs - the right hand side of the division
    /// \return The resulting vector
    Vector2 operator /( const Real _rhs ) const;

    //---------------------------------------
    /// \brief Scalar multiply.
    /// Multiply each value of this Vector2 by a Real.
    /// \param _rhs - the right hand side of the multiplication
    /// \return A copy of the resulting vector
    const Vector2& operator *=( const Real _rhs );
    //---------------------------------------
    /// \brief Scalar divide.
    /// Divide each value of this Vector2 by a Real.
    /// \param _rhs - the right hand side of the division
    /// \return A copy of the resulting vector
    const Vector2& operator /=( const Real _rhs );

    //---------------------------------------
    /// \brief Vector magnitude.
    /// Calculate the length of this Vector2 using fsm::sqrt
    /// \return The magnitude
    Real magnitude() const;
    //---------------------------------------
    /// \brief Vector magnitude squared.
    /// Calculate the length of this Vector2 but skip the final fsm::sqrt
    /// \return The magnitude squared
    Real magnitudeSquared() const;

    //---------------------------------------
    /// \brief Normalise this vector.
    /// Set the length of this Vector2 to 1 if the vector is not of
    /// length zero.
    /// \return A copy of the resulting vector
    const Vector2& normalise();

    //---------------------------------------
    /// \brief Vector comparison.
    /// Test if this Vector2 is equal to another Vector2 using fsm::realCompare
    /// \param _rhs - the right hand side of the comparison
    /// \return True if the vectors are equal
    /// \see fsm::realCompare
    bool operator ==( const Vector2& _rhs ) const;
    //---------------------------------------
    /// \brief Vector comparison.
    /// Test if this Vector2 is not equal to another Vector2 using fsm::realCompare
    /// \param _rhs - the right hand side of the comparison
    /// \return True if the vectors are not equal
    /// \see fsm::realCompare
    bool operator !=( const Vector2& _rhs ) const;

    union
    {
        struct
        {
            Real x; ///< x-axis component.
            Real y; ///< y-axis component.
        };
        Real data[2]; ///< data in array format.
    };
};
}

#endif
