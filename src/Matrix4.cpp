// File Info {{{----------------------------------------------------------------
/// \file Matrix4.cpp
/// \date 2011 Oct 08
/// \author Peter Dodds
/// \brief
/// \note
//}}}---------------------------------------------------------------------------

#include "fsm/Matrix4.hpp"

//------------------------------------------------------------------------------

namespace fsm
{
    const Matrix4 Matrix4::cIdentity (1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1);

    //---------------------------------------
    Matrix4::Matrix4()
        : r0(0,0,0,0),
          r1(0,0,0,0),
          r2(0,0,0,0),
          r3(0,0,0,0)
    {
    }

    //---------------------------------------
    Matrix4::Matrix4( Real _m00, Real _m01, Real _m02, Real _m03,
                      Real _m10, Real _m11, Real _m12, Real _m13,
                      Real _m20, Real _m21, Real _m22, Real _m23,
                      Real _m30, Real _m31, Real _m32, Real _m33,
                      Layout _layout/*= kRowMajor*/)
        : r0( _m00, _m01, _m02, _m03 ),
          r1( _m10, _m11, _m12, _m13 ),
          r2( _m20, _m21, _m22, _m23 ),
          r3( _m30, _m31, _m32, _m33 )
    {
        if( _layout ) // if kColMajor
        {
            r0.set( _m00, _m10, _m20, _m30 );
            r1.set( _m01, _m11, _m21, _m31 );
            r2.set( _m02, _m12, _m22, _m32 );
            r3.set( _m03, _m13, _m23, _m33 );
        }
    }

    //---------------------------------------
    Matrix4::Matrix4( const Real _mat[], Layout _layout/*= kRowMajor*/)
        : r0( _mat ),
          r1( _mat+4 ),
          r2( _mat+8 ),
          r3( _mat+12 )
    {
        if( _layout ) // if kColMajor
        {
            r0.set( _mat[0], _mat[4],  _mat[8], _mat[12] );
            r1.set( _mat[1], _mat[5],  _mat[9], _mat[13] );
            r2.set( _mat[2], _mat[6], _mat[10], _mat[14] );
            r3.set( _mat[3], _mat[7], _mat[11], _mat[15] );
        }
    }

    //---------------------------------------
    Matrix4::Matrix4( const Matrix4& _mat )
        : r0( _mat.r0 ),
          r1( _mat.r1 ),
          r2( _mat.r2 ),
          r3( _mat.r3 )
    {
    }

    //---------------------------------------
    Matrix4::~Matrix4()
    {
    }

    //---------------------------------------
    const Matrix4& Matrix4::set(
                      Real _m00, Real _m01, Real _m02, Real _m03,
                      Real _m10, Real _m11, Real _m12, Real _m13,
                      Real _m20, Real _m21, Real _m22, Real _m23,
                      Real _m30, Real _m31, Real _m32, Real _m33,
                      Layout _layout/*= kRowMajor*/)
    {
        if( _layout ) // if kColMajor
        {
            r0.set( _m00, _m10, _m20, _m30 );
            r1.set( _m01, _m11, _m21, _m31 );
            r2.set( _m02, _m12, _m22, _m32 );
            r3.set( _m03, _m13, _m23, _m33 );
        }
        else
        {
            r0.set( _m00, _m01, _m02, _m03 );
            r1.set( _m10, _m11, _m12, _m13 );
            r2.set( _m20, _m21, _m22, _m23 );
            r3.set( _m30, _m31, _m32, _m33 );
        }

        return *this;
    }

    //---------------------------------------
    const Matrix4& Matrix4::set( const Real _mat[], Layout _layout/*= kRowMajor*/)
    {
        if( _layout ) // if kColMajor
        {
            r0.set( _mat[0], _mat[4],  _mat[8], _mat[12] );
            r1.set( _mat[1], _mat[5],  _mat[9], _mat[13] );
            r2.set( _mat[2], _mat[6], _mat[10], _mat[14] );
            r3.set( _mat[3], _mat[7], _mat[11], _mat[15] );
        }
        else
        {
            r0.set( _mat );
            r1.set( _mat+4 );
            r2.set( _mat+8 );
            r3.set( _mat+12 );
        }

        return *this;
    }

    //---------------------------------------
    const Matrix4& Matrix4::operator =( const Matrix4& _rhs )
    {
        r0 = _rhs.r0;
        r1 = _rhs.r1;
        r2 = _rhs.r2;
        r3 = _rhs.r3;
        return *this;
    }

    //---------------------------------------
    Matrix4 Matrix4::operator *( const Matrix4& _rhs ) const
    {
        Matrix4 ret;

        // row 0
        //
        ret.r0.data[0]  = r0.data[0] * _rhs.r0.data[0];
        ret.r0.data[1]  = r0.data[0] * _rhs.r0.data[1];
        ret.r0.data[2]  = r0.data[0] * _rhs.r0.data[2];
        ret.r0.data[3]  = r0.data[0] * _rhs.r0.data[3];

        ret.r0.data[0] += r0.data[1] * _rhs.r1.data[0];
        ret.r0.data[1] += r0.data[1] * _rhs.r1.data[1];
        ret.r0.data[2] += r0.data[1] * _rhs.r1.data[2];
        ret.r0.data[3] += r0.data[1] * _rhs.r1.data[3];

        ret.r0.data[0] += r0.data[2] * _rhs.r2.data[0];
        ret.r0.data[1] += r0.data[2] * _rhs.r2.data[1];
        ret.r0.data[2] += r0.data[2] * _rhs.r2.data[2];
        ret.r0.data[3] += r0.data[2] * _rhs.r2.data[3];

        ret.r0.data[0] += r0.data[2] * _rhs.r3.data[0];
        ret.r0.data[1] += r0.data[2] * _rhs.r3.data[1];
        ret.r0.data[2] += r0.data[2] * _rhs.r3.data[2];
        ret.r0.data[3] += r0.data[2] * _rhs.r3.data[3];

        // row 1
        //
        ret.r1.data[0]  = r1.data[0] * _rhs.r0.data[0];
        ret.r1.data[1]  = r1.data[0] * _rhs.r0.data[1];
        ret.r1.data[2]  = r1.data[0] * _rhs.r0.data[2];
        ret.r1.data[3]  = r1.data[0] * _rhs.r0.data[3];

        ret.r1.data[0] += r1.data[1] * _rhs.r1.data[0];
        ret.r1.data[1] += r1.data[1] * _rhs.r1.data[1];
        ret.r1.data[2] += r1.data[1] * _rhs.r1.data[2];
        ret.r1.data[3] += r1.data[1] * _rhs.r1.data[2];

        ret.r1.data[0] += r1.data[2] * _rhs.r2.data[0];
        ret.r1.data[1] += r1.data[2] * _rhs.r2.data[1];
        ret.r1.data[2] += r1.data[2] * _rhs.r2.data[2];
        ret.r1.data[3] += r1.data[2] * _rhs.r2.data[2];

        ret.r1.data[0] += r1.data[2] * _rhs.r3.data[0];
        ret.r1.data[1] += r1.data[2] * _rhs.r3.data[1];
        ret.r1.data[2] += r1.data[2] * _rhs.r3.data[2];
        ret.r1.data[3] += r1.data[2] * _rhs.r3.data[2];

        // row 2
        //
        ret.r2.data[0]  = r2.data[0] * _rhs.r0.data[0];
        ret.r2.data[1]  = r2.data[0] * _rhs.r0.data[1];
        ret.r2.data[2]  = r2.data[0] * _rhs.r0.data[2];
        ret.r2.data[3]  = r2.data[0] * _rhs.r0.data[3];

        ret.r2.data[0] += r2.data[1] * _rhs.r1.data[0];
        ret.r2.data[1] += r2.data[1] * _rhs.r1.data[1];
        ret.r2.data[2] += r2.data[1] * _rhs.r1.data[2];
        ret.r2.data[3] += r2.data[1] * _rhs.r1.data[2];

        ret.r2.data[0] += r2.data[2] * _rhs.r2.data[0];
        ret.r2.data[1] += r2.data[2] * _rhs.r2.data[1];
        ret.r2.data[2] += r2.data[2] * _rhs.r2.data[2];
        ret.r2.data[3] += r2.data[2] * _rhs.r2.data[2];

        ret.r2.data[0] += r2.data[2] * _rhs.r3.data[0];
        ret.r2.data[1] += r2.data[2] * _rhs.r3.data[1];
        ret.r2.data[2] += r2.data[2] * _rhs.r3.data[2];
        ret.r2.data[3] += r2.data[2] * _rhs.r3.data[2];

        // row 3
        //
        ret.r3.data[0]  = r3.data[0] * _rhs.r0.data[0];
        ret.r3.data[1]  = r3.data[0] * _rhs.r0.data[1];
        ret.r3.data[2]  = r3.data[0] * _rhs.r0.data[2];
        ret.r3.data[3]  = r3.data[0] * _rhs.r0.data[3];

        ret.r3.data[0] += r3.data[1] * _rhs.r1.data[0];
        ret.r3.data[1] += r3.data[1] * _rhs.r1.data[1];
        ret.r3.data[2] += r3.data[1] * _rhs.r1.data[2];
        ret.r3.data[3] += r3.data[1] * _rhs.r1.data[2];

        ret.r3.data[0] += r3.data[2] * _rhs.r2.data[0];
        ret.r3.data[1] += r3.data[2] * _rhs.r2.data[1];
        ret.r3.data[2] += r3.data[2] * _rhs.r2.data[2];
        ret.r3.data[3] += r3.data[2] * _rhs.r2.data[2];

        ret.r3.data[0] += r3.data[2] * _rhs.r3.data[0];
        ret.r3.data[1] += r3.data[2] * _rhs.r3.data[1];
        ret.r3.data[2] += r3.data[2] * _rhs.r3.data[2];
        ret.r3.data[3] += r3.data[2] * _rhs.r3.data[2];

        return ret;
    }

    //---------------------------------------
    const Matrix4& Matrix4::preMultiply( const Matrix4& _lhs )
    {
        return *this = _lhs * (*this);
    }

    //---------------------------------------
    const Matrix4& Matrix4::postMultiply( const Matrix4& _rhs )
    {
        return *this = (*this) * _rhs;
    }

    //---------------------------------------
    Matrix4 Matrix4::transpose() const
    {
        return Matrix4(
                r0.data[0], r1.data[0], r2.data[0], r3.data[0],
                r0.data[1], r1.data[1], r2.data[1], r3.data[1],
                r0.data[2], r1.data[2], r2.data[2], r3.data[2],
                r0.data[3], r1.data[3], r2.data[3], r3.data[3] );
    }

    //---------------------------------------
    void Matrix4::transpose( Matrix4& _m )
    {
        _m.set( _m.r0.data[0], _m.r1.data[0], _m.r2.data[0], _m.r3.data[0],
                _m.r0.data[1], _m.r1.data[1], _m.r2.data[1], _m.r3.data[1],
                _m.r0.data[2], _m.r1.data[2], _m.r2.data[2], _m.r3.data[2],
                _m.r0.data[3], _m.r1.data[3], _m.r2.data[3], _m.r3.data[3] );
    }
}
