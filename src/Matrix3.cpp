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
        : r0(0,0,0),
          r1(0,0,0),
          r2(0,0,0)
    {
    }

    //---------------------------------------
    Matrix3::Matrix3( Real _m00, Real _m01, Real _m02,
                      Real _m10, Real _m11, Real _m12,
                      Real _m20, Real _m21, Real _m22,
                      bool _colMajor/*= false*/)
        : r0( _m00, _m01, _m02 ),
          r1( _m10, _m11, _m12 ),
          r2( _m20, _m21, _m22 )
    {
        if( _colMajor )
        {
            r0.set( _m00, _m10, _m20 );
            r1.set( _m01, _m11, _m21 );
            r2.set( _m02, _m12, _m22 );
        }
    }

    //---------------------------------------
    Matrix3::Matrix3( Real _mat[], bool _colMajor/*= false*/)
        : r0( _mat ),
          r1( _mat+3 ),
          r2( _mat+6 )
    {
        if( _colMajor )
        {
            r0.set( _mat[0], _mat[3], _mat[6] );
            r1.set( _mat[1], _mat[4], _mat[7] );
            r2.set( _mat[2], _mat[5], _mat[8] );
        }
    }

    //---------------------------------------
    Matrix3::Matrix3( const Matrix3& _mat )
        : r0( _mat.r0 ),
          r1( _mat.r1 ),
          r2( _mat.r2 )
    {
    }

    //---------------------------------------
    Matrix3::~Matrix3()
    {
    }

    //---------------------------------------
    Real* Matrix3::serialise( bool _colMajor/*= false*/) const
    {
        static Real s_mat[9];

        if( _colMajor )
        {
            s_mat[0] = r0[0]; s_mat[3] = r0[1]; s_mat[6] = r0[2];
            s_mat[1] = r1[0]; s_mat[4] = r1[1]; s_mat[7] = r1[2];
            s_mat[2] = r2[0]; s_mat[5] = r2[1]; s_mat[8] = r2[2];
        }
        else
        {
            memcpy( s_mat,   r0.data, 3*sizeof(Real) );
            memcpy( s_mat+3, r1.data, 3*sizeof(Real) );
            memcpy( s_mat+6, r2.data, 3*sizeof(Real) );
        }

        return s_mat;
    }

#if 0 // {{{
    //---------------------------------------
    Matrix3::Matrix3( Real _m00, Real _m01, Real _m02, Real _m10, Real _m11, Real _m12,
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
            r1.set( _m00, _m01, _m02 );
            r2.set( _m10, _m11, _m12 );
            r3.set( _m20, _m21, _m22 );
        }
        else
        {
            r1.set( _m00, _m10, _m20 );
            r2.set( _m01, _m11, _m21 );
            r3.set( _m02, _m12, _m22 );
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
    Real* Matrix3::serialise( Order _layout ) const
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
    Vector3 Matrix3::column( size_t _index ) const
    {
        switch (_index)
        {
            case 0:
                return Vector3( r1.x, r2.x, r3.x );

            case 1:
                return Vector3( r1.y, r2.y, r3.y );

            case 2:
                return Vector3( r1.z, r2.z, r3.z );
        }

        // return a bad vector
        return Vector3::cNaN;
    }
#endif // }}}
}
