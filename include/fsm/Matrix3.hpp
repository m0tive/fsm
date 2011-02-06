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
    static const Matrix3 kIdentity;

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
    /// \param _colMajor - specify input is column major layout: \par
    /// <tt>| _m00 _m10 _m20 |</tt>\n
    /// <tt>| _m01 _m11 _m21 |</tt>\n
    /// <tt>| _m02 _m12 _m22 |</tt>\n
    Matrix3( Real _m00, Real _m01, Real _m02,
             Real _m10, Real _m11, Real _m12,
             Real _m20, Real _m21, Real _m22,
             bool _colMajor = false );
    //---------------------------------------
    /// \details Set constructor. Create a matrix from a one-dimensional array
    /// of Reals. The default layout is: \par
    /// <tt>| 0 1 2 |</tt>\n
    /// <tt>| 3 4 5 |</tt>\n
    /// <tt>| 6 7 8 |</tt>\n
    /// \param _mat[] - The matrix as an one-dimensional array of Reals.
    /// \param _colMajor - specify input is column major layout: \par
    /// <tt>| 0 3 6 |</tt>\n
    /// <tt>| 1 4 7 |</tt>\n
    /// <tt>| 2 5 8 |</tt>\n
    Matrix3( Real _mat[], bool _colMajor = false );
    //---------------------------------------
    /// \brief Copy constructor
    /// \param _mat - Matrix to copy.
    Matrix3( const Matrix3& _mat );

    //---------------------------------------
    /// \details Destructor
    ~Matrix3();

    //---------------------------------------
    /// \brief Convert to one-dimensional array.
    /// The default layout is: \par
    /// <tt>| 0 1 2 |</tt>\n
    /// <tt>| 3 4 5 |</tt>\n
    /// <tt>| 6 7 8 |</tt>\n
    /// \param _colMajor - specify input is column major layout: \par
    /// <tt>| 0 3 6 |</tt>\n
    /// <tt>| 1 4 7 |</tt>\n
    /// <tt>| 2 5 8 |</tt>\n
    /// \return A temporary array containing the matrix.
    Real* serialise( bool _colMajor = false ) const;

#if 0 // {{{
    //---------------------------------------
    /// \details Set constructor. Parameters are in the following format:
    /// \par
    /// <tt>| _m00 _m01 _m02 |</tt>\n
    /// <tt>| _m10 _m11 _m12 |</tt>\n
    /// <tt>| _m20 _m21 _m22 |</tt>\n
    /// \param _m00 \param _m01 \param _m02
    /// \param _m10 \param _m11 \param _m12
    /// \param _m20 \param _m21 \param _m22
    /// \param _layout - matrix layout [default Matrix3::kRowMajor]
    Matrix3( Real _m00, Real _m01, Real _m02,
             Real _m10, Real _m11, Real _m12,
             Real _m20, Real _m21, Real _m22,
             Order _layout = kRowMajor );
    //---------------------------------------
    /// \details Set constructor.
    /// \param _mat[] - The matrix as an one-dimensional array of Reals.
    /// \param _layout - matrix layout [default Matrix3::kRowMajor]
    Matrix3( Real _mat[], Order _layout = kRowMajor );
    //---------------------------------------
    /// \brief Copy constructor
    /// \param _mat - Matrix to copy.
    Matrix3( const Matrix3& _mat );

    //---------------------------------------
    /// \details Destructor
    ~Matrix3();

    //---------------------------------------
    /// \brief Value set.
    /// Parameters are in the following format: \par
    /// <tt>| _m00 _m01 _m02 |</tt>\n
    /// <tt>| _m10 _m11 _m12 |</tt>\n
    /// <tt>| _m20 _m21 _m22 |</tt>\n
    /// \param _m00 \param _m01 \param _m02
    /// \param _m10 \param _m11 \param _m12
    /// \param _m20 \param _m21 \param _m22
    /// \param _layout - matrix layout [default Matrix3::kRowMajor]
    /// \return A copy of the resulting matrix.
    const Matrix3& set( Real _m00, Real _m01, Real _m02,
                        Real _m10, Real _m11, Real _m12,
                        Real _m20, Real _m21, Real _m22,
                        Order _layout = kRowMajor );
    //---------------------------------------
    /// \brief Value set.
    /// \param _mat[] - The matrix as an one-dimensional array of Reals.
    /// \param _layout - matrix layout [default Matrix3::kRowMajor]
    /// \return A copy of the resulting matrix.
    const Matrix3& set( Real _mat[], Order _layout = kRowMajor );

    //---------------------------------------
    /// \brief Convert to one-dimensional array.
    /// \param _layout - matrix layout [default Matrix3::kRowMajor]
    /// \return A temporary array containing the matrix.
    Real* serialise( Order _layout ) const;

    Vector3 column( size_t _index ) const;
#endif // }}}

    Vector3 r0;
    Vector3 r1;
    Vector3 r2;
};
}

#endif
