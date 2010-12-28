// File Info {{{----------------------------------------------------------------
/// \file Radian.cpp
/// \date 2010 Dec 28
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

#include "cm2/Angles.hpp"

//------------------------------------------------------------------------------

namespace cm2
{
    //---------------------------------------
    Radian::Radian( const Real _angle/*= 0*/)
        : m_data(_angle)
    {
    }

    //---------------------------------------
    Radian::Radian( const Radian& _r )
        : m_data(_r.m_data)
    {
    }

    //---------------------------------------
    Radian::~Radian()
    {
    }

    //---------------------------------------
    const Radian& Radian::operator =( const Radian& _rhs )
    {
        m_data = _rhs.m_data;
        return *this;
    }

    //---------------------------------------
    bool Radian::operator ==( const Radian& _rhs ) const
    {
        return realCompare( m_data, _rhs.m_data );
    }

    //---------------------------------------
    bool Radian::operator !=( const Radian& _rhs ) const
    {
        return !realCompare( m_data, _rhs.m_data );
    }

    //---------------------------------------
    bool Radian::operator <( const Radian& _rhs ) const
    {
        return m_data < _rhs.m_data;
    }

    //---------------------------------------
    bool Radian::operator >( const Radian& _rhs ) const
    {
        return m_data > _rhs.m_data;
    }

    //---------------------------------------
    bool Radian::operator <=( const Radian& _rhs ) const
    {
        return m_data < _rhs.m_data || realCompare( m_data, _rhs.m_data );
    }

    //---------------------------------------
    bool Radian::operator >=( const Radian& _rhs ) const
    {
        return m_data > _rhs.m_data || realCompare( m_data, _rhs.m_data );
    }
}
