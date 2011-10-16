// File Info {{{----------------------------------------------------------------
/// \file Vector4.hpp
/// \date 2010 Dec 19
/// \author 
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _fsm_Vector4_hpp_
#define _fsm_Vector4_hpp_
// }}}

#include "fsm/Def.hpp"

//------------------------------------------------------------------------------

namespace fsm
{
/// \brief A four dimensional point or vector
class Vector4
{
public:
#if 0
    static const Vector4 cNaN;
#endif

    //---------------------------------------
    /// \details Default constructor.
    /// \param _x - x-axis component.
    /// \param _y - y-axis component.
    /// \param _z - z-axis component.
    /// \param _w - w-axis component.
    Vector4(
        const Real _x = 0,
        const Real _y = 0,
        const Real _z = 0,
        const Real _w = 0 );
    //---------------------------------------
    /// \details Set constructor.
    /// \param _a - an array of four Reals { x, y, z, w }
    Vector4( const Real _a[] );
    //---------------------------------------
    /// \details Copy constructor.
    /// \param _v - the Vector4 to copy.
    Vector4( const Vector4& _v );

    //---------------------------------------
    /// \details Destructor
    ~Vector4();

#if 0
    //---------------------------------------
    /// \brief Test is invalid.
    /// Checks if the components x, y or z are NaN.
    /// \return True if either parts of the vector are NaN.
    bool isNaN() const;
#endif


    //---------------------------------------
    /// \brief Value set.
    /// Set the vectors value to a given x, y, z and w
    /// \param _x - x-axis component
    /// \param _y - y-axis component
    /// \param _z - z-axis component
    /// \param _w - w-axis component
    /// \return A copy of the resulting vector
    /// \todo split this out into a default and a set ctor...
    const Vector4& set(
        const Real _x = 0,
        const Real _y = 0,
        const Real _z = 0,
        const Real _w = 0 );
    //---------------------------------------
    /// \brief Value set.
    /// Set the vectors value to a given array.
    /// \param _a - an array of four Reals { x, y, z, w }
    /// \return A copy of the resulting vector
    const Vector4& set( const Real _a[] );

    //---------------------------------------
    /// \brief Array access.
    /// \param _i - the index to access elements in the array { x, y, z, w }
    /// \return The vector element
    inline Real& operator []( const size_t _i ) { return data[_i]; };
    //---------------------------------------
    /// \brief Array access.
    /// \param _i - the index to access elements in the array { x, y, z, w }
    /// \return The vector element
    inline const Real& operator []( const size_t _i ) const { return data[_i]; };

    //---------------------------------------
    /// \brief Negative operator.
    /// Make a new Vector4 by making each value of this Vector4 negative.
    /// \return The resulting vector
    Vector4 operator -() const;

    //---------------------------------------
    /// \brief Vector assignment.
    /// Copy the value of another Vector4 into this vector
    /// \param _rhs - the vector to copy
    /// \return A copy of the resulting vector
    const Vector4& operator =( const Vector4& _rhs );

    //---------------------------------------
    /// \brief Vector add.
    /// Create a new Vector4 by adding two Vector4 together
    /// \param _rhs - the right hand side of the addition
    /// \return The resulting vector
    Vector4 operator +( const Vector4& _rhs ) const;
    //---------------------------------------
    /// \brief Vector subtract.
    /// Create a new Vector4 by subtracted one Vector4 from anther.
    /// \param _rhs - the right hand side of the subtraction
    /// \return The resulting vector
    Vector4 operator -( const Vector4& _rhs ) const;

    //---------------------------------------
    /// \brief Vector add.
    /// Add another Vector4 to this Vector4.
    /// \param _rhs - the right hand side of the addition
    /// \return A copy of the resulting vector
    const Vector4& operator +=( const Vector4& _rhs );
    //---------------------------------------
    /// \brief Vector subtract.
    /// Subtract another Vector4 from this Vector4.
    /// \param _rhs - the right hand side of the subtraction
    /// \return A copy of the resulting vector
    const Vector4& operator -=( const Vector4& _rhs );

#if 0 // don't think vect4 has this...
    //---------------------------------------
    /// \brief Vector cross product.
    /// Calculate the cross product of this Vector4 and another Vector4
    /// \param _rhs - the right hand side of the cross product
    /// \return The resulting vector
    Vector4 cross( const Vector4& _rhs ) const;
#endif

    //---------------------------------------
    /// \brief Vector dot product.
    /// Calculate the dot product of this Vector4 and another Vector4.
    /// \param _rhs - the right hand side of the dot product
    /// \return The dot product
    Real dot( const Vector4& _rhs ) const;

    //---------------------------------------
    /// \brief Scalar multiply.
    /// Create a new Vector4 by multiplying this Vector4 by a Real number.
    /// \param _rhs - the right hand side of the multiplication
    /// \return The resulting vector
    Vector4 operator *( const Real _rhs ) const;
    //---------------------------------------
    /// \brief Scalar division.
    /// Create a new Vector4 by dividing this Vector4 by a Real number.
    /// \param _rhs - the right hand side of the division
    /// \return The resulting vector
    Vector4 operator /( const Real _rhs ) const;

    //---------------------------------------
    /// \brief Scalar multiply.
    /// Multiply each value of this Vector4 by a Real.
    /// \param _rhs - the right hand side of the multiplication
    /// \return A copy of the resulting vector
    const Vector4& operator *=( const Real _rhs );
    //---------------------------------------
    /// \brief Scalar divide.
    /// Divide each value of this Vector4 by a Real.
    /// \param _rhs - the right hand side of the division
    /// \return A copy of the resulting vector
    const Vector4& operator /=( const Real _rhs );

    //---------------------------------------
    /// \brief Vector magnitude.
    /// Calculate the length of this Vector4 using fsm::sqrt
    /// \return The magnitude
    Real magnitude() const;
    //---------------------------------------
    /// \brief Vector magnitude squared.
    /// Calculate the length of this Vector4 but skip the final fsm::sqrt
    /// \return The magnitude squared
    Real magnitudeSquared() const;

    //---------------------------------------
    /// \brief Normalise this vector.
    /// Set the length of this Vector4 to 1 if the Vector4 is not of
    /// length zero.
    /// \return A copy of the resulting vector
    const Vector4& normalise();

    //---------------------------------------
    /// \brief Vector comparison.
    /// Test if this Vector4 is equal to another Vector4 using fsm::realCompare
    /// \param _rhs - the right hand side of the comparison
    /// \return True if the vectors are equal
    /// \see fsm::realCompare
    bool operator ==( const Vector4& _rhs ) const;
    //---------------------------------------
    /// \brief Vector comparison.
    /// Test if this Vector4 is not equal to another Vector4 using fsm::realCompare
    /// \param _rhs - the right hand side of the comparison
    /// \return True if the vectors are not equal
    /// \see fsm::realCompare
    bool operator !=( const Vector4& _rhs ) const;

    union
    {
        struct
        {
            Real x; ///< x-axis component.
            Real y; ///< y-axis component.
            Real z; ///< z-axis component.
            Real w; ///< w-axis component.
        };
        Real data[4]; ///< data in array format.
    };
};
}

#endif
