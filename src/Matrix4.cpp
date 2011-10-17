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

        ret.r0.data[0] += r0.data[3] * _rhs.r3.data[0];
        ret.r0.data[1] += r0.data[3] * _rhs.r3.data[1];
        ret.r0.data[2] += r0.data[3] * _rhs.r3.data[2];
        ret.r0.data[3] += r0.data[3] * _rhs.r3.data[3];

        // row 1
        //
        ret.r1.data[0]  = r1.data[0] * _rhs.r0.data[0];
        ret.r1.data[1]  = r1.data[0] * _rhs.r0.data[1];
        ret.r1.data[2]  = r1.data[0] * _rhs.r0.data[2];
        ret.r1.data[3]  = r1.data[0] * _rhs.r0.data[3];

        ret.r1.data[0] += r1.data[1] * _rhs.r1.data[0];
        ret.r1.data[1] += r1.data[1] * _rhs.r1.data[1];
        ret.r1.data[2] += r1.data[1] * _rhs.r1.data[2];
        ret.r1.data[3] += r1.data[1] * _rhs.r1.data[3];

        ret.r1.data[0] += r1.data[2] * _rhs.r2.data[0];
        ret.r1.data[1] += r1.data[2] * _rhs.r2.data[1];
        ret.r1.data[2] += r1.data[2] * _rhs.r2.data[2];
        ret.r1.data[3] += r1.data[2] * _rhs.r2.data[3];

        ret.r1.data[0] += r1.data[3] * _rhs.r3.data[0];
        ret.r1.data[1] += r1.data[3] * _rhs.r3.data[1];
        ret.r1.data[2] += r1.data[3] * _rhs.r3.data[2];
        ret.r1.data[3] += r1.data[3] * _rhs.r3.data[3];

        // row 2
        //
        ret.r2.data[0]  = r2.data[0] * _rhs.r0.data[0];
        ret.r2.data[1]  = r2.data[0] * _rhs.r0.data[1];
        ret.r2.data[2]  = r2.data[0] * _rhs.r0.data[2];
        ret.r2.data[3]  = r2.data[0] * _rhs.r0.data[3];

        ret.r2.data[0] += r2.data[1] * _rhs.r1.data[0];
        ret.r2.data[1] += r2.data[1] * _rhs.r1.data[1];
        ret.r2.data[2] += r2.data[1] * _rhs.r1.data[2];
        ret.r2.data[3] += r2.data[1] * _rhs.r1.data[3];

        ret.r2.data[0] += r2.data[2] * _rhs.r2.data[0];
        ret.r2.data[1] += r2.data[2] * _rhs.r2.data[1];
        ret.r2.data[2] += r2.data[2] * _rhs.r2.data[2];
        ret.r2.data[3] += r2.data[2] * _rhs.r2.data[3];

        ret.r2.data[0] += r2.data[3] * _rhs.r3.data[0];
        ret.r2.data[1] += r2.data[3] * _rhs.r3.data[1];
        ret.r2.data[2] += r2.data[3] * _rhs.r3.data[2];
        ret.r2.data[3] += r2.data[3] * _rhs.r3.data[3];

        // row 3
        //
        ret.r3.data[0]  = r3.data[0] * _rhs.r0.data[0];
        ret.r3.data[1]  = r3.data[0] * _rhs.r0.data[1];
        ret.r3.data[2]  = r3.data[0] * _rhs.r0.data[2];
        ret.r3.data[3]  = r3.data[0] * _rhs.r0.data[3];

        ret.r3.data[0] += r3.data[1] * _rhs.r1.data[0];
        ret.r3.data[1] += r3.data[1] * _rhs.r1.data[1];
        ret.r3.data[2] += r3.data[1] * _rhs.r1.data[2];
        ret.r3.data[3] += r3.data[1] * _rhs.r1.data[3];

        ret.r3.data[0] += r3.data[2] * _rhs.r2.data[0];
        ret.r3.data[1] += r3.data[2] * _rhs.r2.data[1];
        ret.r3.data[2] += r3.data[2] * _rhs.r2.data[2];
        ret.r3.data[3] += r3.data[2] * _rhs.r2.data[3];

        ret.r3.data[0] += r3.data[3] * _rhs.r3.data[0];
        ret.r3.data[1] += r3.data[3] * _rhs.r3.data[1];
        ret.r3.data[2] += r3.data[3] * _rhs.r3.data[2];
        ret.r3.data[3] += r3.data[3] * _rhs.r3.data[3];

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
    Real* Matrix4::serialise( Layout _layout/*= kRowMajor*/) const
    {
        static Real s_mat[16];

        if( _layout ) // if kColMajor
        {
            s_mat[0]=r0[0]; s_mat[4]=r0[1];  s_mat[8]=r0[2]; s_mat[12]=r0[3];
            s_mat[1]=r1[0]; s_mat[5]=r1[1];  s_mat[9]=r1[2]; s_mat[13]=r1[3];
            s_mat[2]=r2[0]; s_mat[6]=r2[1]; s_mat[10]=r2[2]; s_mat[14]=r2[3];
            s_mat[3]=r3[0]; s_mat[7]=r3[1]; s_mat[11]=r3[2]; s_mat[15]=r3[3];
        }
        else
        {
            memcpy( s_mat,    r0.data, 4*sizeof(Real) );
            memcpy( s_mat+4,  r1.data, 4*sizeof(Real) );
            memcpy( s_mat+8,  r2.data, 4*sizeof(Real) );
            memcpy( s_mat+12, r3.data, 4*sizeof(Real) );
        }

        return s_mat;
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

    //---------------------------------------
    Real Matrix4::determinate() const
    {
        Real ret;

        ret  = r0.data[0]*r1.data[1]*r2.data[2]*r3.data[3];
        ret += r0.data[0]*r1.data[2]*r1.data[3]*r3.data[1];
        ret += r0.data[0]*r1.data[3]*r2.data[1]*r3.data[2];

        ret += r0.data[1]*r1.data[0]*r2.data[3]*r3.data[2];
        ret += r0.data[1]*r1.data[2]*r2.data[0]*r3.data[3];
        ret += r0.data[1]*r1.data[3]*r2.data[2]*r3.data[0];

        ret += r0.data[2]*r1.data[0]*r2.data[1]*r3.data[3];
        ret += r0.data[2]*r1.data[1]*r2.data[3]*r3.data[0];
        ret += r0.data[2]*r1.data[3]*r2.data[0]*r3.data[1];

        ret += r0.data[3]*r1.data[0]*r2.data[2]*r3.data[1];
        ret += r0.data[3]*r1.data[1]*r2.data[0]*r3.data[2];
        ret += r0.data[3]*r1.data[2]*r2.data[1]*r3.data[0];

        ret -= r0.data[0]*r1.data[1]*r2.data[3]*r3.data[2];
        ret -= r0.data[0]*r1.data[2]*r2.data[1]*r3.data[3];
        ret -= r0.data[0]*r1.data[3]*r2.data[2]*r3.data[1];

        ret -= r0.data[1]*r1.data[0]*r2.data[2]*r3.data[3];
        ret -= r0.data[1]*r1.data[2]*r2.data[3]*r3.data[0];
        ret -= r0.data[1]*r1.data[3]*r2.data[0]*r3.data[2];

        ret -= r0.data[2]*r1.data[0]*r2.data[3]*r3.data[1];
        ret -= r0.data[2]*r1.data[1]*r2.data[0]*r3.data[3];
        ret -= r0.data[2]*r1.data[3]*r2.data[1]*r3.data[0];

        ret -= r0.data[3]*r1.data[0]*r2.data[1]*r3.data[2];
        ret -= r0.data[3]*r1.data[1]*r2.data[2]*r3.data[0];
        ret -= r0.data[3]*r1.data[2]*r2.data[0]*r3.data[1];

        return ret;
    }

    //---------------------------------------
    void doInvert( const Matrix4& s, Matrix4& d, const Real& det )
    {
        const Real m00 = s.r1[1]*s.r2[2]*s.r3[3] + s.r1[2]*s.r2[3]*s.r3[1] +
                         s.r1[3]*s.r2[1]*s.r3[2] - s.r1[1]*s.r2[3]*s.r3[2] -
                         s.r1[2]*s.r2[1]*s.r3[3] - s.r1[3]*s.r2[2]*s.r3[1];
        const Real m01 = s.r0[1]*s.r2[3]*s.r3[2] + s.r0[2]*s.r2[1]*s.r3[3] +
                         s.r0[3]*s.r2[2]*s.r3[1] - s.r0[1]*s.r2[2]*s.r3[3] -
                         s.r0[2]*s.r2[3]*s.r3[1] - s.r0[3]*s.r2[1]*s.r3[2];
        const Real m02 = s.r0[1]*s.r1[2]*s.r3[3] + s.r0[2]*s.r1[3]*s.r3[1] +
                         s.r0[3]*s.r1[1]*s.r3[2] - s.r0[1]*s.r1[3]*s.r3[2] -
                         s.r0[2]*s.r1[1]*s.r3[3] - s.r0[3]*s.r1[2]*s.r3[1];
        const Real m03 = s.r0[1]*s.r1[3]*s.r2[2] + s.r0[2]*s.r1[1]*s.r2[3] +
                         s.r0[3]*s.r1[2]*s.r2[1] - s.r0[1]*s.r1[2]*s.r2[3] -
                         s.r0[2]*s.r1[3]*s.r2[1] - s.r0[3]*s.r1[1]*s.r2[2];

        const Real m10 = s.r1[0]*s.r2[3]*s.r3[2] + s.r1[2]*s.r2[0]*s.r3[3] +
                         s.r1[3]*s.r2[2]*s.r3[0] - s.r1[0]*s.r2[2]*s.r3[3] -
                         s.r1[2]*s.r2[3]*s.r3[0] - s.r1[3]*s.r2[0]*s.r3[2];
        const Real m11 = s.r0[0]*s.r2[2]*s.r3[3] + s.r0[2]*s.r2[3]*s.r3[0] +
                         s.r0[3]*s.r2[0]*s.r3[2] - s.r0[0]*s.r2[3]*s.r3[2] -
                         s.r0[2]*s.r2[0]*s.r3[3] - s.r0[3]*s.r2[2]*s.r3[0];
        const Real m12 = s.r0[0]*s.r1[3]*s.r3[2] + s.r0[2]*s.r1[0]*s.r3[3] +
                         s.r0[3]*s.r1[2]*s.r3[0] - s.r0[0]*s.r1[2]*s.r3[3] -
                         s.r0[2]*s.r1[3]*s.r3[0] - s.r0[3]*s.r1[0]*s.r3[2];
        const Real m13 = s.r0[0]*s.r1[2]*s.r2[3] + s.r0[2]*s.r1[3]*s.r2[0] +
                         s.r0[3]*s.r1[0]*s.r2[2] - s.r0[0]*s.r1[3]*s.r2[2] -
                         s.r0[2]*s.r1[0]*s.r2[3] - s.r0[3]*s.r1[2]*s.r2[0];

        const Real m20 = s.r1[0]*s.r2[1]*s.r3[3] + s.r1[1]*s.r2[3]*s.r3[0] +
                         s.r1[3]*s.r2[0]*s.r3[1] - s.r1[0]*s.r2[3]*s.r3[1] -
                         s.r1[1]*s.r2[0]*s.r3[3] - s.r1[3]*s.r2[1]*s.r3[0];
        const Real m21 = s.r0[0]*s.r2[3]*s.r3[1] + s.r0[1]*s.r2[0]*s.r3[3] +
                         s.r0[3]*s.r2[1]*s.r3[0] - s.r0[0]*s.r2[1]*s.r3[3] -
                         s.r0[1]*s.r2[3]*s.r3[0] - s.r0[3]*s.r2[0]*s.r3[1];
        const Real m22 = s.r0[0]*s.r1[1]*s.r3[3] + s.r0[1]*s.r1[3]*s.r3[0] +
                         s.r0[3]*s.r1[0]*s.r3[1] - s.r0[0]*s.r1[3]*s.r3[1] -
                         s.r0[1]*s.r1[0]*s.r3[3] - s.r0[3]*s.r1[1]*s.r3[0];
        const Real m23 = s.r0[0]*s.r1[3]*s.r2[1] + s.r0[1]*s.r1[0]*s.r2[3] +
                         s.r0[3]*s.r1[1]*s.r2[0] - s.r0[0]*s.r1[1]*s.r2[3] -
                         s.r0[1]*s.r1[3]*s.r2[0] - s.r0[3]*s.r1[0]*s.r2[1];

        const Real m30 = s.r1[0]*s.r2[2]*s.r3[1] + s.r1[1]*s.r2[0]*s.r3[2] +
                         s.r1[2]*s.r2[1]*s.r3[0] - s.r1[0]*s.r2[1]*s.r3[2] -
                         s.r1[1]*s.r2[2]*s.r3[0] - s.r1[2]*s.r2[0]*s.r3[1];
        const Real m31 = s.r0[0]*s.r2[1]*s.r3[2] + s.r0[1]*s.r2[2]*s.r3[0] +
                         s.r0[2]*s.r2[0]*s.r3[1] - s.r0[0]*s.r2[2]*s.r3[1] -
                         s.r0[1]*s.r2[0]*s.r3[2] - s.r0[2]*s.r2[1]*s.r3[0];
        const Real m32 = s.r0[0]*s.r1[2]*s.r3[1] + s.r0[1]*s.r1[0]*s.r3[2] +
                         s.r0[2]*s.r1[1]*s.r3[0] - s.r0[0]*s.r1[1]*s.r3[2] -
                         s.r0[1]*s.r1[2]*s.r3[0] - s.r0[2]*s.r1[0]*s.r3[1];
        const Real m33 = s.r0[0]*s.r1[1]*s.r2[2] + s.r0[1]*s.r1[2]*s.r2[0] +
                         s.r0[2]*s.r1[0]*s.r2[1] - s.r0[0]*s.r1[2]*s.r2[1] -
                         s.r0[1]*s.r1[0]*s.r2[2] - s.r0[2]*s.r1[1]*s.r2[0];

        d.r0.data[0] = m00 / det;
        d.r0.data[1] = m01 / det;
        d.r0.data[2] = m02 / det;
        d.r0.data[3] = m03 / det;

        d.r1.data[0] = m10 / det;
        d.r1.data[1] = m11 / det;
        d.r1.data[2] = m12 / det;
        d.r1.data[3] = m13 / det;

        d.r2.data[0] = m20 / det;
        d.r2.data[1] = m21 / det;
        d.r2.data[2] = m22 / det;
        d.r2.data[3] = m23 / det;

        d.r3.data[0] = m30 / det;
        d.r3.data[1] = m31 / det;
        d.r3.data[2] = m32 / det;
        d.r3.data[3] = m33 / det;
    }

    //---------------------------------------
    Matrix4 Matrix4::inverse() const
    {
        Real det = determinate();
        if( realCompare( det, 0.0 ) )
        {
            return cIdentity;
        }

        Matrix4 ret;
        doInvert( *this, ret, det );

        return ret;
    }

    //---------------------------------------
    bool Matrix4::invert( Matrix4& _m )
    {
        Real det = _m.determinate();
        if( realCompare( det, 0.0 ) )
        {
            return false;
        }

        doInvert( _m, _m, det );

        return true;
    }
}
