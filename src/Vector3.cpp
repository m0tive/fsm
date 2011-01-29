// File Info {{{----------------------------------------------------------------
/// \file Vector3.cpp
/// \date 2010 Dec 19
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

#include "cm2/Vector3.hpp"

//------------------------------------------------------------------------------

namespace cm2
{
    const Vector3 Vector3::cNaN( g_realNaN, g_realNaN, g_realNaN );

    //---------------------------------------
    Vector3::Vector3(
            const Real _x/* = 0*/, const Real _y/*= 0*/, const Real _z/*= 0*/)
        : x(_x), y(_y), z(_z)
    {
    }

    //---------------------------------------
    Vector3::Vector3( const Vector3& _v )
        : x(_v.x), y(_v.y), z(_v.z)
    {
    }

    //---------------------------------------
    Vector3::~Vector3()
    {
    }

    //---------------------------------------
    bool Vector3::isNaN() const
    {
        return isnan(x) || isnan(y) || isnan(z);
    }

    //---------------------------------------
    const Vector3& Vector3::set(
            const Real _x/*= 0*/, const Real _y/*= 0*/, const Real _z/*= 0*/ )
    {
        x = _x;
        y = _y;
        z = _z;
        return *this;
    }

    //---------------------------------------
    Vector3 Vector3::operator -() const
    {
        return Vector3( -x, -y, -z );
    }

    //---------------------------------------
    const Vector3& Vector3::operator =( const Vector3& _rhs )
    {
        x = _rhs.x;
        y = _rhs.y;
        z = _rhs.z;
        return *this;
    }

    //---------------------------------------
    Vector3 Vector3::operator +( const Vector3& _rhs ) const
    {
        return Vector3( x + _rhs.x, y + _rhs.y, z + _rhs.z );
    }

    //---------------------------------------
    Vector3 Vector3::operator -( const Vector3& _rhs ) const
    {
        return Vector3( x - _rhs.x, y - _rhs.y, z - _rhs.z );
    }

    //---------------------------------------
    const Vector3& Vector3::operator +=( const Vector3& _rhs )
    {
        x += _rhs.x;
        y += _rhs.y;
        z += _rhs.z;
        return *this;
    }

    //---------------------------------------
    const Vector3& Vector3::operator -=( const Vector3& _rhs )
    {
        x -= _rhs.x;
        y -= _rhs.y;
        z -= _rhs.z;
        return *this;
    }

    //---------------------------------------
    Vector3 Vector3::cross( const Vector3& _rhs ) const
    {
        return Vector3( y*_rhs.z - z*_rhs.y,
                        z*_rhs.x - x*_rhs.z,
                        x*_rhs.y - y*_rhs.x );
    }

    //---------------------------------------
    Real Vector3::dot( const Vector3& _rhs ) const
    {
        return x * _rhs.x + y * _rhs.y + z * _rhs.z;
    }

    //---------------------------------------
    Vector3 Vector3::operator *( const Real _rhs ) const
    {
        return Vector3( x * _rhs, y * _rhs, z * _rhs );
    }

    //---------------------------------------
    Vector3 Vector3::operator /( const Real _rhs ) const
    {
        return Vector3( x / _rhs, y / _rhs, z / _rhs );
    }

    //---------------------------------------
    const Vector3& Vector3::operator *=( const Real _rhs )
    {
        x *= _rhs;
        y *= _rhs;
        z *= _rhs;
        return *this;
    }

    //---------------------------------------
    const Vector3& Vector3::operator /=( const Real _rhs )
    {
        x /= _rhs;
        y /= _rhs;
        z /= _rhs;
        return *this;
    }

    //---------------------------------------
    Real Vector3::magnitude() const
    {
        return cm2::sqrt( x * x + y * y + z * z );
    }

    //---------------------------------------
    Real Vector3::magnitudeSquared() const
    {
        return x * x + y * y + z * z;
    }

    //---------------------------------------
    const Vector3& Vector3::normalise()
    {
        if( x != 0.0 || y != 0.0 || z != 0.0 )
        {
            Real magSquared = magnitudeSquared();
            if( magSquared != 1.0 )
            {
                *this *=  1.0 / cm2::sqrt(magSquared);
            }
        }
        return *this;
    }

    //---------------------------------------
    bool Vector3::operator ==( const Vector3& _rhs ) const
    {
        return realCompare( x, _rhs.x ) &&
               realCompare( y, _rhs.y ) &&
               realCompare( z, _rhs.z );
    }

    //---------------------------------------
    bool Vector3::operator !=( const Vector3& _rhs ) const
    {
        return !realCompare( x, _rhs.x ) ||
               !realCompare( y, _rhs.y ) ||
               !realCompare( z, _rhs.z );
    }
}
