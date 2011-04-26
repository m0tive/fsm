// File Info {{{----------------------------------------------------------------
/// \file Vector4.cpp
/// \date 2010 Dec 19
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

#include "fsm/Vector4.hpp"
#include "internal.hpp"

//------------------------------------------------------------------------------

namespace fsm
{
#if 0
    const Vector4 Vector4::cNaN( g_realNaN, g_realNaN, g_realNaN );
#endif

    //---------------------------------------
    Vector4::Vector4(
            const Real _x/*= 0*/,
            const Real _y/*= 0*/,
            const Real _z/*= 0*/,
            const Real _w/*= 0*/)
        : x(_x), y(_y), z(_z), w(_w)
    {
    }

    //---------------------------------------
    Vector4::Vector4( const Real _a[] )
        : x(_a[0]), y(_a[1]), z(_a[2]), w(_a[3])
    {
    }

    //---------------------------------------
    Vector4::Vector4( const Vector4& _v )
        : x(_v.x), y(_v.y), z(_v.z), w(_v.w)
    {
    }

    //---------------------------------------
    Vector4::~Vector4()
    {
    }

#if 0
    //---------------------------------------
    bool Vector4::isNaN() const
    {
        return fsm_isnan(x) || fsm_isnan(y) || fsm_isnan(z);
    }
#endif

    //---------------------------------------
    const Vector4& Vector4::set(
            const Real _x/*= 0*/,
            const Real _y/*= 0*/,
            const Real _z/*= 0*/,
            const Real _w/*= 0*/ )
    {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
        return *this;
    }

    //---------------------------------------
    const Vector4& Vector4::set( const Real _a[] )
    {
        x = _a[0];
        y = _a[1];
        z = _a[2];
        w = _a[3];
        return *this;
    }

    //---------------------------------------
    Real Vector4::operator []( const size_t _i ) const
    {
        switch (_i)
        {
            case 0:
                return x;

            case 1:
                return y;

            case 2:
                return z;

            case 3:
                return w;
        }

        FSM_ASSERT_FAIL();
        return g_realNaN;
    }

    //---------------------------------------
    Vector4 Vector4::operator -() const
    {
        return Vector4( -x, -y, -z, -w );
    }

    //---------------------------------------
    const Vector4& Vector4::operator =( const Vector4& _rhs )
    {
        x = _rhs.x;
        y = _rhs.y;
        z = _rhs.z;
        w = _rhs.w;
        return *this;
    }

    //---------------------------------------
    Vector4 Vector4::operator +( const Vector4& _rhs ) const
    {
        return Vector4( x + _rhs.x, y + _rhs.y, z + _rhs.z, w + _rhs.w );
    }

    //---------------------------------------
    Vector4 Vector4::operator -( const Vector4& _rhs ) const
    {
        return Vector4( x - _rhs.x, y - _rhs.y, z - _rhs.z, w - _rhs.w );
    }

    //---------------------------------------
    const Vector4& Vector4::operator +=( const Vector4& _rhs )
    {
        x += _rhs.x;
        y += _rhs.y;
        z += _rhs.z;
        w += _rhs.w;
        return *this;
    }

    //---------------------------------------
    const Vector4& Vector4::operator -=( const Vector4& _rhs )
    {
        x -= _rhs.x;
        y -= _rhs.y;
        z -= _rhs.z;
        w -= _rhs.w;
        return *this;
    }

#if 0
    //---------------------------------------
    Vector4 Vector4::cross( const Vector4& _rhs ) const
    {
        return Vector4( y*_rhs.z - z*_rhs.y,
                        z*_rhs.x - x*_rhs.z,
                        x*_rhs.y - y*_rhs.x );
    }
#endif

    //---------------------------------------
    Real Vector4::dot( const Vector4& _rhs ) const
    {
        return (x * _rhs.x) + (y * _rhs.y) + (z * _rhs.z) + (w * _rhs.w);
    }

    //---------------------------------------
    Vector4 Vector4::operator *( const Real _rhs ) const
    {
        return Vector4( x * _rhs, y * _rhs, z * _rhs, w * _rhs );
    }

    //---------------------------------------
    Vector4 Vector4::operator /( const Real _rhs ) const
    {
        return Vector4( x / _rhs, y / _rhs, z / _rhs, w / _rhs );
    }

    //---------------------------------------
    const Vector4& Vector4::operator *=( const Real _rhs )
    {
        x *= _rhs;
        y *= _rhs;
        z *= _rhs;
        w *= _rhs;
        return *this;
    }

    //---------------------------------------
    const Vector4& Vector4::operator /=( const Real _rhs )
    {
        x /= _rhs;
        y /= _rhs;
        z /= _rhs;
        w /= _rhs;
        return *this;
    }

    //---------------------------------------
    Real Vector4::magnitude() const
    {
        return fsm::sqrt( x * x + y * y + z * z + w * w );
    }

    //---------------------------------------
    Real Vector4::magnitudeSquared() const
    {
        return x * x + y * y + z * z + w * w;
    }

    //---------------------------------------
    const Vector4& Vector4::normalise()
    {
        if( x != 0.0 || y != 0.0 || z != 0.0 || w != 0.0 )
        {
            Real magSquared = magnitudeSquared();
            if( magSquared != 1.0 )
            {
                *this *=  1.0 / fsm::sqrt(magSquared);
            }
        }
        return *this;
    }

    //---------------------------------------
    bool Vector4::operator ==( const Vector4& _rhs ) const
    {
        return realCompare( x, _rhs.x ) &&
               realCompare( y, _rhs.y ) &&
               realCompare( z, _rhs.z ) &&
               realCompare( w, _rhs.w );
    }

    //---------------------------------------
    bool Vector4::operator !=( const Vector4& _rhs ) const
    {
        return !realCompare( x, _rhs.x ) ||
               !realCompare( y, _rhs.y ) ||
               !realCompare( z, _rhs.z ) ||
               !realCompare( w, _rhs.w );
    }
}
