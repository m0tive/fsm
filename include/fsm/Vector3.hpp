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

#ifndef _fsm_Vector3_hpp_
#define _fsm_Vector3_hpp_
// }}}

#include "fsm/Def.hpp"

//------------------------------------------------------------------------------

namespace fsm
{
/// \brief A three dimensional point or vector
class Vector3
{
public:
#if 0
    static const Vector3 cNaN;
#endif

    //---------------------------------------
    /// \details Default constructor.
    /// \param _x - x-axis component.
    /// \param _y - y-axis component.
    /// \param _z - z-axis component.
    Vector3( const Real _x = 0, const Real _y = 0, const Real _z = 0 );
    //---------------------------------------
    /// \details Set constructor.
    /// \param _a - an array of three Reals.
    /// \todo test TODO
    Vector3( const Real _a[] );
    //---------------------------------------
    /// \details Copy constructor.
    /// \param _v - the Vector3 to copy.
    Vector3( const Vector3& _v );

    //---------------------------------------
    /// \details Destructor
    ~Vector3();

#if 0
    //---------------------------------------
    /// \brief Test is invalid.
    /// Checks if the components x, y or z are NaN.
    /// \return True if either parts of the vector are NaN.
    bool isNaN() const;
#endif


    //---------------------------------------
    /// \brief Value set.
    /// Set the vectors value to a given x, y and z
    /// \param _x - x-axis component
    /// \param _y - y-axis component
    /// \param _z - z-axis component
    /// \return A copy of the resulting vector
    const Vector3& set( const Real _x = 0, const Real _y = 0, const Real _z = 0 );
    /// \todo test TODO
    const Vector3& set( const Real _a[] );

    Real operator []( const size_t _i ) const;

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
    /// \brief Vector add.
    /// Add another Vector3 to this Vector3.
    /// \param _rhs - the right hand side of the addition
    /// \return A copy of the resulting vector
    const Vector3& operator +=( const Vector3& _rhs );
    //---------------------------------------
    /// \brief Vector subtract.
    /// Subtract another Vector3 from this Vector3.
    /// \param _rhs - the right hand side of the subtraction
    /// \return A copy of the resulting vector
    const Vector3& operator -=( const Vector3& _rhs );

    //---------------------------------------
    /// \brief Vector cross product.
    /// Calculate the cross product of this Vector3 and another Vector3
    /// \param _rhs - the right hand side of the cross product
    /// \return The resulting vector
    Vector3 cross( const Vector3& _rhs ) const;

    //---------------------------------------
    /// \brief Vector dot product.
    /// Calculate the dot product of this Vector3 and another Vector3.
    /// \param _rhs - the right hand side of the dot product
    /// \return The dot product
    Real dot( const Vector3& _rhs ) const;

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

    //---------------------------------------
    /// \brief Scalar multiply.
    /// Multiply each value of this Vector3 by a Real.
    /// \param _rhs - the right hand side of the multiplication
    /// \return A copy of the resulting vector
    const Vector3& operator *=( const Real _rhs );
    //---------------------------------------
    /// \brief Scalar divide.
    /// Divide each value of this Vector3 by a Real.
    /// \param _rhs - the right hand side of the division
    /// \return A copy of the resulting vector
    const Vector3& operator /=( const Real _rhs );

    //---------------------------------------
    /// \brief Vector magnitude.
    /// Calculate the length of this Vector3 using fsm::sqrt
    /// \return The magnitude
    Real magnitude() const;
    //---------------------------------------
    /// \brief Vector magnitude squared.
    /// Calculate the length of this Vector3 but skip the final fsm::sqrt
    /// \return The magnitude squared
    Real magnitudeSquared() const;

    //---------------------------------------
    /// \brief Normalise this vector.
    /// Set the length of this Vector3 to 1 if the Vector3 is not of
    /// length zero.
    /// \return A copy of the resulting vector
    const Vector3& normalise();

    //---------------------------------------
    /// \brief Vector comparison.
    /// Test if this Vector3 is equal to another Vector3 using fsm::realCompare
    /// \param _rhs - the right hand side of the comparison
    /// \return True if the vectors are equal
    /// \see fsm::realCompare
    bool operator ==( const Vector3& _rhs ) const;
    //---------------------------------------
    /// \brief Vector comparison.
    /// Test if this Vector3 is not equal to another Vector3 using fsm::realCompare
    /// \param _rhs - the right hand side of the comparison
    /// \return True if the vectors are not equal
    /// \see fsm::realCompare
    bool operator !=( const Vector3& _rhs ) const;

    union
    {
        struct
        {
            Real x; ///< x-axis component.
            Real y; ///< y-axis component.
            Real z; ///< z-axis component.
        };
        Real data[3]; ///< data in array format.
    };
};
}

#endif
