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
    const Vector2& Vector2::set( const Real _x/*= 0*/, const Real _y/*= 0*/ )
    {
        x = _x;
        y = _y;
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
    Vector2 Vector2::operator *( const Real _rhs ) const
    {
        return Vector2( x * _rhs, y * _rhs );
    }

    //---------------------------------------
    Vector2 Vector2::operator /( const Real _rhs ) const
    {
        return Vector2( x / _rhs, y / _rhs );
    }
}
