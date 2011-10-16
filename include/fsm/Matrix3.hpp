// File Info {{{----------------------------------------------------------------
/// \file Matrix3.hpp
/// \date 2010 Nov 16
/// \author Peter Dodds
/// \brief
/// \note 
//}}}---------------------------------------------------------------------------

// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _fsm_Matrix3_hpp_
#define _fsm_Matrix3_hpp_
// }}}

#include "fsm/Def.hpp"
#include "fsm/Vector3.hpp"

//------------------------------------------------------------------------------

namespace fsm
{
/// \brief A matix with 3 rows and 3 columns.
/// \note The matrix is stored internally as a row major Real array
class Matrix3
{
public:
    //---------------------------------------
    /// \brief The identity matrix
    /// \par
    /// <tt>| 1 0 0 |</tt>\n
    /// <tt>| 0 1 0 |</tt>\n
    /// <tt>| 0 0 1 |</tt>\n
    static const Matrix3 cIdentity;

    //---------------------------------------
    /// \brief Row major or column major flags.
    /// This is used when converting to Matrix3 from Real[].
    enum Layout
    {
        kRowMajor = 0,
        kColMajor
    };

    //---------------------------------------
    /// \details Default constructor.
    Matrix3();
    //---------------------------------------
    /// \details Set constructor. Parameters are in the following format:
    /// \par
    /// <tt>| _m00 _m01 _m02 |</tt>\n
    /// <tt>| _m10 _m11 _m12 |</tt>\n
    /// <tt>| _m20 _m21 _m22 |</tt>\n
    /// \param _m00 \param _m01 \param _m02
    /// \param _m10 \param _m11 \param _m12
    /// \param _m20 \param _m21 \param _m22
    /// \param _layout - specify input is column major layout: \par
    /// <tt>| _m00 _m10 _m20 |</tt>\n
    /// <tt>| _m01 _m11 _m21 |</tt>\n
    /// <tt>| _m02 _m12 _m22 |</tt>\n
    Matrix3(
            Real _m00, Real _m01, Real _m02,
            Real _m10, Real _m11, Real _m12,
            Real _m20, Real _m21, Real _m22,
            Layout _layout = kRowMajor );
    //---------------------------------------
    /// \details Set constructor. Create a matrix from a one-dimensional array
    /// of Reals. The default layout is: \par
    /// <tt>| 0 1 2 |</tt>\n
    /// <tt>| 3 4 5 |</tt>\n
    /// <tt>| 6 7 8 |</tt>\n
    /// \param _mat - The matrix as an one-dimensional array of Reals.
    /// \param _layout - specify input is column major layout: \par
    /// <tt>| 0 3 6 |</tt>\n
    /// <tt>| 1 4 7 |</tt>\n
    /// <tt>| 2 5 8 |</tt>\n
    Matrix3( const Real _mat[], Layout _layout = kRowMajor );
    //---------------------------------------
    /// \brief Copy constructor
    /// \param _mat - Matrix to copy.
    Matrix3( const Matrix3& _mat );

    //---------------------------------------
    /// \details Destructor
    ~Matrix3();

    //---------------------------------------
    /// \brief Value set.
    /// Parameters are in the following format:
    /// \par
    /// <tt>| _m00 _m01 _m02 |</tt>\n
    /// <tt>| _m10 _m11 _m12 |</tt>\n
    /// <tt>| _m20 _m21 _m22 |</tt>\n
    /// \param _m00 \param _m01 \param _m02
    /// \param _m10 \param _m11 \param _m12
    /// \param _m20 \param _m21 \param _m22
    /// \param _layout - specify input is column major layout: \par
    /// <tt>| _m00 _m10 _m20 |</tt>\n
    /// <tt>| _m01 _m11 _m21 |</tt>\n
    /// <tt>| _m02 _m12 _m22 |</tt>\n
    /// \return A copy of the resulting matrix
    const Matrix3& set(
            Real _m00, Real _m01, Real _m02,
            Real _m10, Real _m11, Real _m12,
            Real _m20, Real _m21, Real _m22,
            Layout _layout = kRowMajor );
    //---------------------------------------
    /// \brief Value set.
    /// \details Set constructor. Create a matrix from a one-dimensional array
    /// of Reals. The default layout is: \par
    /// <tt>| 0 1 2 |</tt>\n
    /// <tt>| 3 4 5 |</tt>\n
    /// <tt>| 6 7 8 |</tt>\n
    /// \param _mat - The matrix as an one-dimensional array of Reals.
    /// \param _layout - specify input is column major layout: \par
    /// <tt>| 0 3 6 |</tt>\n
    /// <tt>| 1 4 7 |</tt>\n
    /// <tt>| 2 5 8 |</tt>\n
    /// \return A copy of the resulting matrix
    const Matrix3& set( const Real _mat[], Layout _layout = kRowMajor );

    //---------------------------------------
    /// \brief Matrix assignment.
    /// Copy the value of another Matrix3 into this matrix
    /// \param _rhs - the matrix to copy
    /// \return A copy of the resulting matrix
    const Matrix3& operator =( const Matrix3& _rhs );

    //---------------------------------------
    /// \brief Matrix multiply.
    /// Combine two matrices by multiplying lhs rows with rhs columns.
    /// \param _rhs - the right hand side of the multiplication
    /// \return The resulting matrix
    Matrix3 operator *( const Matrix3& _rhs ) const;
    //---------------------------------------
    /// \brief In-place pre-multiply.
    /// Multiply this Matrix3 with another, using this as the rhs of the
    ///   operation.
    /// \param _lhs - the left hand side of the multiplication
    /// \return A copy of the resulting matrix
    const Matrix3& preMultiply( const Matrix3& _lhs );
    //---------------------------------------
    /// \brief In-place post-multiply.
    /// Multiply this Matrix3 with another, using this as the lhs of the
    ///   operation.
    /// \param _rhs - the right hand side of the multiplication
    /// \return A copy of the resulting matrix
    const Matrix3& postMultiply( const Matrix3& _rhs );

    //---------------------------------------
    /// \brief Convert to one-dimensional array.
    /// The default layout is: \par
    /// <tt>| 0 1 2 |</tt>\n
    /// <tt>| 3 4 5 |</tt>\n
    /// <tt>| 6 7 8 |</tt>\n
    /// \param _layout - specify input is column major layout: \par
    /// <tt>| 0 3 6 |</tt>\n
    /// <tt>| 1 4 7 |</tt>\n
    /// <tt>| 2 5 8 |</tt>\n
    /// \return A temporary array containing the matrix.
    Real* serialise( Layout _layout = kRowMajor ) const;

    //---------------------------------------
    /// \brief Get the transpose of this matrix.
    /// Create a copy of this matrix flipped along the major diagonal (top-left
    ///   to bottom-right).
    /// \return The resulting matrix
    Matrix3 transpose() const;
    //---------------------------------------
    /// \brief Transpose a matrix.
    /// Flip a Matrix3 _m, in-place along the major diagonal (top-left to
    ///   bottom-right).
    /// \param _m - the Matrix3 to be transposed.
    static void transpose( Matrix3& _m );

    //---------------------------------------
    /// \brief Calculate the determinate.
    Real determinate() const;

    //---------------------------------------
    /// \brief Calculate the inverse.
    /// \return If determinate is not zero, the resulting inverse matrix,
    ///   else Matrix3::kIdentity
    Matrix3 inverse() const;
    //---------------------------------------
    /// \brief Invert a matrix.
    /// \param _m - the Matrix3 to invert in-place.
    /// \return true if determinate is not zero and the inverse was possible.
    static bool invert( Matrix3& _m );

    Vector3 r0; ///< first row
    Vector3 r1; ///< second row
    Vector3 r2; ///< third row
};
}

#endif
