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
    const Matrix3 Matrix3::cIdentity (1,0,0, 0,1,0, 0,0,1);

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
                      Layout _layout/*= kRowMajor*/)
        : r0( _m00, _m01, _m02 ),
          r1( _m10, _m11, _m12 ),
          r2( _m20, _m21, _m22 )
    {
        if( _layout ) // if kColMajor
        {
            r0.set( _m00, _m10, _m20 );
            r1.set( _m01, _m11, _m21 );
            r2.set( _m02, _m12, _m22 );
        }
    }

    //---------------------------------------
    Matrix3::Matrix3( const Real _mat[], Layout _layout/*= kRowMajor*/)
        : r0( _mat ),
          r1( _mat+3 ),
          r2( _mat+6 )
    {
        if( _layout ) // if kColMajor
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
    const Matrix3& Matrix3::set(
            Real _m00, Real _m01, Real _m02,
            Real _m10, Real _m11, Real _m12,
            Real _m20, Real _m21, Real _m22,
            Layout _layout/*= kRowMajor*/)
    {
        if( _layout ) // if kColMajor
        {
            r0.set( _m00, _m10, _m20 );
            r1.set( _m01, _m11, _m21 );
            r2.set( _m02, _m12, _m22 );
        }
        else
        {
            r0.set( _m00, _m01, _m02 );
            r1.set( _m10, _m11, _m12 );
            r2.set( _m20, _m21, _m22 );
        }

        return *this;
    }

    //---------------------------------------
    const Matrix3& Matrix3::set( const Real _mat[], Layout _layout/*= kRowMajor*/)
    {
        if( _layout ) // if kColMajor
        {
            r0.set( _mat[0], _mat[3], _mat[6] );
            r1.set( _mat[1], _mat[4], _mat[7] );
            r2.set( _mat[2], _mat[5], _mat[8] );
        }
        else
        {
            r0.set( _mat );
            r1.set( _mat+3 );
            r2.set( _mat+6 );
        }

        return *this;
    }

    //---------------------------------------
    const Matrix3& Matrix3::set( const Matrix3& _mat )
    {
        r0.set( _mat.r0.data );
        r1.set( _mat.r1.data );
        r2.set( _mat.r2.data );

        return *this;
    }

    //---------------------------------------
    Real* Matrix3::serialise( Layout _layout/*= kRowMajor*/) const
    {
        static Real s_mat[9];

        if( _layout ) // if kColMajor
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

    //---------------------------------------
    const Matrix3& Matrix3::operator =( const Matrix3& _rhs )
    {
        r0 = _rhs.r0;
        r1 = _rhs.r1;
        r2 = _rhs.r2;
        return *this;
    }

    //---------------------------------------
    Matrix3 Matrix3::operator *( const Matrix3& _rhs ) const
    {
        Matrix3 ret;

        // row 0
        //
        ret.r0.data[0]  = r0.data[0] * _rhs.r0.data[0];
        ret.r0.data[1]  = r0.data[0] * _rhs.r0.data[1];
        ret.r0.data[2]  = r0.data[0] * _rhs.r0.data[2];

        ret.r0.data[0] += r0.data[1] * _rhs.r1.data[0];
        ret.r0.data[1] += r0.data[1] * _rhs.r1.data[1];
        ret.r0.data[2] += r0.data[1] * _rhs.r1.data[2];

        ret.r0.data[0] += r0.data[2] * _rhs.r2.data[0];
        ret.r0.data[1] += r0.data[2] * _rhs.r2.data[1];
        ret.r0.data[2] += r0.data[2] * _rhs.r2.data[2];

        // row 1
        //
        ret.r1.data[0]  = r1.data[0] * _rhs.r0.data[0];
        ret.r1.data[1]  = r1.data[0] * _rhs.r0.data[1];
        ret.r1.data[2]  = r1.data[0] * _rhs.r0.data[2];

        ret.r1.data[0] += r1.data[1] * _rhs.r1.data[0];
        ret.r1.data[1] += r1.data[1] * _rhs.r1.data[1];
        ret.r1.data[2] += r1.data[1] * _rhs.r1.data[2];

        ret.r1.data[0] += r1.data[2] * _rhs.r2.data[0];
        ret.r1.data[1] += r1.data[2] * _rhs.r2.data[1];
        ret.r1.data[2] += r1.data[2] * _rhs.r2.data[2];

        // row 2
        //
        ret.r2.data[0]  = r2.data[0] * _rhs.r0.data[0];
        ret.r2.data[1]  = r2.data[0] * _rhs.r0.data[1];
        ret.r2.data[2]  = r2.data[0] * _rhs.r0.data[2];

        ret.r2.data[0] += r2.data[1] * _rhs.r1.data[0];
        ret.r2.data[1] += r2.data[1] * _rhs.r1.data[1];
        ret.r2.data[2] += r2.data[1] * _rhs.r1.data[2];

        ret.r2.data[0] += r2.data[2] * _rhs.r2.data[0];
        ret.r2.data[1] += r2.data[2] * _rhs.r2.data[1];
        ret.r2.data[2] += r2.data[2] * _rhs.r2.data[2];

        return ret;
    }

    //---------------------------------------
    const Matrix3& Matrix3::preMultiply( const Matrix3& _rhs )
    {
        return *this = _rhs * (*this);
    }

    //---------------------------------------
    const Matrix3& Matrix3::postMultiply( const Matrix3& _rhs )
    {
        return *this = (*this) * _rhs;
    }

    //---------------------------------------
    Matrix3 Matrix3::transpose() const
    {
        return Matrix3(
                r0.data[0], r1.data[0], r2.data[0],
                r0.data[1], r1.data[1], r2.data[1],
                r0.data[2], r1.data[2], r2.data[2] );
    }

    //---------------------------------------
    const Matrix3& Matrix3::transpose( Matrix3& _m )
    {
        return _m.set(
                _m.r0.data[0], _m.r1.data[0], _m.r2.data[0],
                _m.r0.data[1], _m.r1.data[1], _m.r2.data[1],
                _m.r0.data[2], _m.r1.data[2], _m.r2.data[2] );
    }

    //---------------------------------------
    Real Matrix3::determinate() const
    {
        return r0.dot( r1.cross( r2 ) );
    }

    //---------------------------------------
    void doInvert( const Matrix3& s, Matrix3& d )
    {
        const Real m00 = s.r1.data[1]*s.r2.data[2] - s.r1.data[2]*s.r2.data[1];
        const Real m01 = s.r0.data[1]*s.r2.data[1] - s.r0.data[1]*s.r2.data[2];
        const Real m02 = s.r0.data[1]*s.r1.data[2] - s.r0.data[2]*s.r1.data[1];

        const Real m10 = s.r1.data[2]*s.r2.data[0] - s.r1.data[0]*s.r2.data[2];
        const Real m11 = s.r0.data[0]*s.r2.data[2] - s.r0.data[2]*s.r2.data[0];
        const Real m12 = s.r0.data[2]*s.r1.data[0] - s.r0.data[0]*s.r1.data[2];

        const Real m20 = s.r1.data[0]*s.r2.data[1] - s.r1.data[1]*s.r2.data[0];
        const Real m21 = s.r0.data[1]*s.r2.data[0] - s.r0.data[0]*s.r2.data[1];
        const Real m22 = s.r0.data[0]*s.r1.data[1] - s.r0.data[1]*s.r1.data[0];

        d.r0.data[0] = m00;
        d.r0.data[1] = m01;
        d.r0.data[2] = m02;

        d.r1.data[0] = m10;
        d.r1.data[1] = m11;
        d.r1.data[2] = m12;

        d.r2.data[0] = m20;
        d.r2.data[1] = m21;
        d.r2.data[2] = m22;
    }

    //---------------------------------------
    Matrix3 Matrix3::inverse() const
    {
        Real det = determinate();
        if( realCompare( det, 0.0 ) )
        {
            return cIdentity;
        }

        Matrix3 ret;
        doInvert( *this, ret );

        return ret;
    }

    //---------------------------------------
    bool Matrix3::invert( Matrix3& _m )
    {
        Real det = _m.determinate();
        if( realCompare( det, 0.0 ) )
        {
            return false;
        }

        doInvert( _m, _m );

        return true;
    }
}
