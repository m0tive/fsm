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
}
