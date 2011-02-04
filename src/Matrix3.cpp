// File Info {{{----------------------------------------------------------------
/// \file Matrix3.cpp
/// \date 2011 Jan 23
/// \author Peter Dodds
/// \brief
/// \note
//}}}---------------------------------------------------------------------------

#include "fsm/Matrix3.hpp"

#include <string.h>

//------------------------------------------------------------------------------

namespace fsm
{
    const Matrix3 Matrix3::kIdentity (1,0,0, 0,1,0, 0,0,1);

    //---------------------------------------
    Matrix3::Matrix3()
        : m00(0), m01(0), m02(0),
          m10(0), m11(0), m12(0),
          m20(0), m21(0), m22(0)
    {
    }

    //---------------------------------------
    Matrix3::Matrix3( Real _m00, Real _m01, Real _m02,
                      Real _m10, Real _m11, Real _m12,
                      Real _m20, Real _m21, Real _m22,
                      Order _layout/*= kRowMajor*/)
    {
        if( _layout == kRowMajor )
        {
            m00 = m00; m01 = m01; m02 = m02;
            m10 = m10; m11 = m11; m12 = m12;
            m20 = m20; m21 = m21; m22 = m22;
        }
        else
        {
            m00 = m00; m01 = m10; m02 = m20;
            m10 = m01; m11 = m11; m12 = m21;
            m20 = m02; m21 = m12; m22 = m22;
        }
    }

    //---------------------------------------
    Matrix3::Matrix3( Real _mat[], Order _layout/*= kRowMajor*/)
    {
        if( _layout == kRowMajor )
        {
            memcpy( m_data, _mat, 9*sizeof(Real) );
        }
        else
        {
            m00 = _mat[0]; m01 = _mat[3]; m02 = _mat[6];
            m10 = _mat[1]; m11 = _mat[4]; m12 = _mat[7];
            m20 = _mat[2]; m21 = _mat[5]; m22 = _mat[8];
        }
    }

    //---------------------------------------
    Matrix3::Matrix3( const Matrix3& _mat )
    {
        memcpy( m_data, _mat.m_data, 9*sizeof(Real) );
    }

    //---------------------------------------
    Matrix3::~Matrix3()
    {
    }

    //---------------------------------------
    const Matrix3& Matrix3::set( Real _m00, Real _m01, Real _m02,
                                 Real _m10, Real _m11, Real _m12,
                                 Real _m20, Real _m21, Real _m22,
                                 Order _layout/*= kRowMajor*/)
    {
        if( _layout == kRowMajor )
        {
            m00 = m00; m01 = m01; m02 = m02;
            m10 = m10; m11 = m11; m12 = m12;
            m20 = m20; m21 = m21; m22 = m22;
        }
        else
        {
            m00 = m00; m01 = m10; m02 = m20;
            m10 = m01; m11 = m11; m12 = m21;
            m20 = m02; m21 = m12; m22 = m22;
        }
        return *this;
    }

    //---------------------------------------
    const Matrix3& Matrix3::set( Real _mat[], Order _layout/*= kRowMajor*/)

    {
        if( _layout == kRowMajor )
        {
            memcpy( m_data, _mat, 9*sizeof(Real) );
        }
        else
        {
            m00 = _mat[0]; m01 = _mat[3]; m02 = _mat[6];
            m10 = _mat[1]; m11 = _mat[4]; m12 = _mat[7];
            m20 = _mat[2]; m21 = _mat[5]; m22 = _mat[8];
        }
        return *this;
    }

    //---------------------------------------
    Real* Matrix3::toArray( Order _layout ) const
    {
        static Real s_mat[9];

        if( _layout == kRowMajor )
        {
            memcpy( s_mat, m_data, 9*sizeof(Real) );
        }
        else
        {
            s_mat[0] = m00; s_mat[3] = m01; s_mat[6] = m02;
            s_mat[1] = m10; s_mat[4] = m11; s_mat[7] = m12;
            s_mat[2] = m20; s_mat[5] = m21; s_mat[8] = m22;
        }

        return s_mat;
    }

    //---------------------------------------
    Vector3 Matrix3::row( size_t _index ) const
    {
        switch (_index)
        {
            case 0:
                return Vector3( m00, m01, m02 );

            case 1:
                return Vector3( m10, m11, m12 );

            case 2:
                return Vector3( m20, m21, m22 );
        }

        // return a bad vector
        return Vector3::cNaN;
    }

    //---------------------------------------
    Vector3 Matrix3::col( size_t _index ) const
    {
        switch (_index)
        {
            case 0:
                return Vector3( m00, m10, m20 );

            case 1:
                return Vector3( m01, m11, m21 );

            case 2:
                return Vector3( m02, m12, m22 );
        }

        // return a bad vector
        return Vector3::cNaN;
    }
}
