// File Info {{{----------------------------------------------------------------
/// \file Vector2.cpp
/// \date 2010 Dec 01
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

#include "cm2/Vector2.hpp"

//------------------------------------------------------------------------------

namespace cm2
{
    const Vector2 Vector2::cNaN( g_realNaN );

    //---------------------------------------
    Vector2::Vector2( const Real _x/* = 0*/, const Real _y/*= 0*/)
        : x(_x), y(_y)
    {
    }

    //---------------------------------------
    Vector2::Vector2( const Vector2& _v )
        : x(_v.x), y(_v.y)
    {
    }

    //---------------------------------------
    Vector2::~Vector2()
    {
    }

    //---------------------------------------
    bool Vector2::isNaN() const
    {
        return isnan(x) || isnan(y);
    }

    //---------------------------------------
    const Vector2& Vector2::set( const Real _x/*= 0*/, const Real _y/*= 0*/ )
    {
        x = _x;
        y = _y;
        return *this;
    }

    //---------------------------------------
    Vector2 Vector2::operator -() const
    {
        return Vector2( -x, -y );
    }

    //---------------------------------------
    const Vector2& Vector2::operator =( const Vector2& _rhs )
    {
        x = _rhs.x;
        y = _rhs.y;
        return *this;
    }

    //---------------------------------------
    Vector2 Vector2::operator +( const Vector2& _rhs ) const
    {
        return Vector2( x + _rhs.x, y + _rhs.y );
    }

    //---------------------------------------
    Vector2 Vector2::operator -( const Vector2& _rhs ) const
    {
        return Vector2( x - _rhs.x, y - _rhs.y );
    }

    //---------------------------------------
    const Vector2& Vector2::operator +=( const Vector2& _rhs )
    {
        x += _rhs.x;
        y += _rhs.y;
        return *this;
    }

    //---------------------------------------
    const Vector2& Vector2::operator -=( const Vector2& _rhs )
    {
        x -= _rhs.x;
        y -= _rhs.y;
        return *this;
    }

    //---------------------------------------
    Real Vector2::dot( const Vector2& _rhs ) const
    {
        return x * _rhs.x + y * _rhs.y;
    }

    //---------------------------------------
    Vector2 Vector2::operator *( const Real _rhs ) const
    {
        return Vector2( x * _rhs, y * _rhs );
    }

    //---------------------------------------
    Vector2 Vector2::operator /( const Real _rhs ) const
    {
        return Vector2( x / _rhs, y / _rhs );
    }

    //---------------------------------------
    const Vector2& Vector2::operator *=( const Real _rhs )
    {
        x *= _rhs;
        y *= _rhs;
        return *this;
    }

    //---------------------------------------
    const Vector2& Vector2::operator /=( const Real _rhs )
    {
        x /= _rhs;
        y /= _rhs;
        return *this;
    }

    //---------------------------------------
    Real Vector2::magnitude() const
    {
        return cm2::sqrt( x * x + y * y );
    }

    //---------------------------------------
    Real Vector2::magnitudeSquared() const
    {
        return x * x + y * y;
    }

    //---------------------------------------
    const Vector2& Vector2::normalise()
    {
        if( x != 0.0 || y != 0.0 )
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
    bool Vector2::operator ==( const Vector2& _rhs ) const
    {
        return realCompare( x, _rhs.x ) &&
               realCompare( y, _rhs.y );
    }

    //---------------------------------------
    bool Vector2::operator !=( const Vector2& _rhs ) const
    {
        return !realCompare( x, _rhs.x ) ||
               !realCompare( y, _rhs.y );
    }
}
