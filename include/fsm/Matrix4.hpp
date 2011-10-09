// File Info {{{
//------------------------------------------------------------------------------
/// \file Matrix4.hpp
/// \date 2011 Oct 08
/// \author Peter Dodds
/// \brief
/// \note
//}}}---------------------------------------------------------------------------

// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _fsm_Matrix4_hpp_
#define _fsm_Matrix4_hpp_
// }}}

#include "fsm/Def.hpp"
#include "fsm/Vector4.hpp"

//------------------------------------------------------------------------------

namespace fsm
{
/// \brief
class Matrix4
{
public:
    //---------------------------------------
    /// \brief The identity matrix
    /// \par
    /// <tt>| 1 0 0 0 |</tt>\n
    /// <tt>| 0 1 0 0 |</tt>\n
    /// <tt>| 0 0 1 0 |</tt>\n
    /// <tt>| 0 0 0 1 |</tt>\n
    static const Matrix4 cIdentity;

    enum Layout
    {
        kRowMajor = 0,
        kColMajor
    };

    //---------------------------------------
    /// \details Default constructor
    Matrix4();

    //---------------------------------------
    /// \details Set constructor. Parameters are in the following format:
    /// \par
    /// <tt>| _m00 _m01 _m02 _m03 |</tt>\n
    /// <tt>| _m10 _m11 _m12 _m13 |</tt>\n
    /// <tt>| _m20 _m21 _m22 _m23 |</tt>\n
    /// <tt>| _m30 _m31 _m32 _m33 |</tt>\n
    /// \param _m00 \param _m01 \param _m02 \param _m03
    /// \param _m10 \param _m11 \param _m12 \param _m13
    /// \param _m20 \param _m21 \param _m22 \param _m23
    /// \param _m30 \param _m31 \param _m32 \param _m33
    /// \param _layout - specify input is column major layout: \par
    /// <tt>| _m00 _m10 _m20 _m30 |</tt>\n
    /// <tt>| _m01 _m11 _m21 _m31 |</tt>\n
    /// <tt>| _m02 _m12 _m22 _m32 |</tt>\n
    /// <tt>| _m03 _m13 _m23 _m33 |</tt>\n
    Matrix4(
            Real _m00, Real _m01, Real _m02, Real _m03,
            Real _m10, Real _m11, Real _m12, Real _m13,
            Real _m20, Real _m21, Real _m22, Real _m23,
            Real _m30, Real _m31, Real _m32, Real _m33,
            Layout _layout = kRowMajor );
    //---------------------------------------
    /// \details Set constructor. Create a matrix from a one-dimensional array
    /// of Reals. The default layout is: \par
    /// <tt>|  0  1  2  3 |</tt>\n
    /// <tt>|  4  5  6  7 |</tt>\n
    /// <tt>|  8  9 10 11 |</tt>\n
    /// <tt>| 12 13 14 15 |</tt>\n
    /// \param _mat[] - The matrix as an one-dimensional array of Reals.
    /// \param _layout - specify input is column major layout: \par
    /// <tt>|  0  4  8 12 |</tt>\n
    /// <tt>|  1  5  9 13 |</tt>\n
    /// <tt>|  2  6 10 14 |</tt>\n
    /// <tt>|  3  7 11 15 |</tt>\n
    Matrix4( const Real _mat[], Layout _layout = kRowMajor );
    //---------------------------------------
    /// \brief Copy constructor
    /// \param _mat - Matrix to copy.
    Matrix4( const Matrix4& _mat );

    //---------------------------------------
    /// \details Destructor
    ~Matrix4();

    const Matrix4& set(
            Real _m00, Real _m01, Real _m02, Real _m03,
            Real _m10, Real _m11, Real _m12, Real _m13,
            Real _m20, Real _m21, Real _m22, Real _m23,
            Real _m30, Real _m31, Real _m32, Real _m33,
            Layout _layout = kRowMajor );
    const Matrix4& set( const Real _mat[], Layout _layout = kRowMajor );

    //---------------------------------------
    /// \brief Matrix assignment.
    /// Copy the value of another Matrix4 into this matrix
    /// \param _rhs - the matrix to copy
    /// \return A copy of the resulting matrix
    const Matrix4& operator =( const Matrix4& _rhs );

    Matrix4 operator *( const Matrix4& _rhs ) const;
    const Matrix4& preMultiply( const Matrix4& _lhs );
    const Matrix4& postMultiply( const Matrix4& _rhs );

    //---------------------------------------
    /// \brief Get the transpose of this matrix.
    /// \return A copy of this matrix is returned.
    Matrix4 transpose() const;
    //---------------------------------------
    /// \brief Transpose a matrix _m.
    /// \param _m - the Matrix4 to be transposed.
    static void transpose( Matrix4& _m );

    Vector4 r0; ///< first row
    Vector4 r1; ///< second row
    Vector4 r2; ///< third row
    Vector4 r3; ///< forth row
};
}

#endif
