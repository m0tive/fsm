// File Info {{{----------------------------------------------------------------
/// \file Degree.cpp
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
    Degree::Degree( const Real _angle/*= 0*/)
        : m_data(_angle)
    {
    }

    //---------------------------------------
    Degree::Degree( const Degree& _r )
        : m_data(_r.m_data)
    {
    }

    //---------------------------------------
    Degree::~Degree()
    {
    }

    //---------------------------------------
    const Degree& Degree::operator =( const Degree& _rhs )
    {
        m_data = _rhs.m_data;
        return *this;
    }

    //---------------------------------------
    bool Degree::operator ==( const Degree& _rhs ) const
    {
        return realCompare( m_data, _rhs.m_data );
    }

    //---------------------------------------
    bool Degree::operator !=( const Degree& _rhs ) const
    {
        return !realCompare( m_data, _rhs.m_data );
    }

    //---------------------------------------
    bool Degree::operator <( const Degree& _rhs ) const
    {
        return m_data < _rhs.m_data;
    }

    //---------------------------------------
    bool Degree::operator >( const Degree& _rhs ) const
    {
        return m_data > _rhs.m_data;
    }

    //---------------------------------------
    bool Degree::operator <=( const Degree& _rhs ) const
    {
        return m_data < _rhs.m_data || realCompare( m_data, _rhs.m_data );
    }

    //---------------------------------------
    bool Degree::operator >=( const Degree& _rhs ) const
    {
        return m_data > _rhs.m_data || realCompare( m_data, _rhs.m_data );
    }
}
