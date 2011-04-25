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
    /// \param _mat[] - The matrix as an one-dimensional array of Reals.
    /// \param _layout - specify input is column major layout: \par
    /// <tt>| 0 3 6 |</tt>\n
    /// <tt>| 1 4 7 |</tt>\n
    /// <tt>| 2 5 8 |</tt>\n
    Matrix3( Real _mat[], Layout _layout = kRowMajor );
    //---------------------------------------
    /// \brief Copy constructor
    /// \param _mat - Matrix to copy.
    Matrix3( const Matrix3& _mat );

    //---------------------------------------
    /// \details Destructor
    ~Matrix3();

#if 0 // unfinished
    const Matrix3& set(
            Real _m00, Real _m01, Real _m02,
            Real _m10, Real _m11, Real _m12,
            Real _m20, Real _m21, Real _m22,
            Layout _layout = kRowMajor );
    const Matrix3& set( Real _mat, Layout _layout = kRowMajor );
#endif

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

    Vector3 r0;
    Vector3 r1;
    Vector3 r2;
};
}

#endif
