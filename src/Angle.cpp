// File Info {{{----------------------------------------------------------------
/// \file Angle.cpp
/// \date 2010 Dec 28
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

#include "fsm/Angle.hpp"

//------------------------------------------------------------------------------

namespace fsm
{
    const Real g_convertToInternal[2] = { 1.0, M_PI / 180.0 };
    const Real g_convertToExternal[2] = { 1.0, 180.0 * M_1_PI };

    const Angle Angle::cWhole( 2.0 * M_PI );
    const Angle Angle::cHalf( M_PI );
    const Angle Angle::cQuarter( M_PI_2 );
    const Angle Angle::cEighth( M_PI_4 );

#if 0
    const Angle Angle::cNaN( g_realNaN );
#endif

    const Angle Angle::Radian::c2PI( Angle::cWhole );
    const Angle Angle::Radian::cPI( Angle::cHalf );
    const Angle Angle::Radian::cPI_2( Angle::cQuarter );
    const Angle Angle::Radian::cPI_4( Angle::cEighth );

    const Angle Angle::Degree::c360( Angle::cWhole );
    const Angle Angle::Degree::c180( Angle::cHalf );
    const Angle Angle::Degree::c90( Angle::cQuarter );
    const Angle Angle::Degree::c45( Angle::cEighth );

    //---------------------------------------
    Angle::Angle()
        : m_data(0.0)
    {
    }

    //---------------------------------------
    Angle::Angle( const Real _angle )
        : m_data(_angle)
    {
    }

    Angle::Angle( const Real _angle, Unit _unit )
    {
      m_data = _angle / g_convertToInternal[_unit];
    }

    //---------------------------------------
    Angle::Angle( const Angle& _r )
        : m_data(_r.m_data)
    {
    }

    //---------------------------------------
    Angle::~Angle()
    {
    }

    //---------------------------------------
    Real Angle::get( Unit _u ) const
    {
        return m_data * g_convertToExternal[_u];
    }

    //---------------------------------------
    const Angle& Angle::set( Real _r, Unit _u )
    {
        m_data = _r * g_convertToInternal[_u];
        return *this;
    }

    //---------------------------------------
    const Angle& Angle::operator =( const Angle& _rhs )
    {
        m_data = _rhs.m_data;
        return *this;
    }

    //---------------------------------------
    Angle Angle::operator -()
    {
        return Angle(-m_data);
    }

    //---------------------------------------
    Angle Angle::operator +( const Angle& _rhs )
    {
        return Angle(m_data + _rhs.m_data);
    }

    //---------------------------------------
    Angle Angle::operator -( const Angle& _rhs )
    {
        return Angle(m_data - _rhs.m_data);
    }

    //---------------------------------------
    const Angle& Angle::operator +=( const Angle& _rhs )
    {
        m_data += _rhs.m_data;
        return *this;
    }

    //---------------------------------------
    const Angle& Angle::operator -=( const Angle& _rhs )
    {
        m_data -= _rhs.m_data;
        return *this;
    }

    //---------------------------------------
    Angle Angle::operator *( const Real _rhs )
    {
        return Angle(m_data * _rhs);
    }

    //---------------------------------------
    Angle Angle::operator /( const Real _rhs )
    {
        return Angle(m_data / _rhs);
    }

    //---------------------------------------
    const Angle& Angle::operator *=( const Real _rhs )
    {
        m_data *= _rhs;
        return *this;
    }

    //---------------------------------------
    const Angle& Angle::operator /=( const Real _rhs )
    {
        m_data /= _rhs;
        return *this;
    }

    //---------------------------------------
    bool Angle::operator ==( const Angle& _rhs ) const
    {
        return realCompare( m_data, _rhs.m_data );
    }

    //---------------------------------------
    bool Angle::operator !=( const Angle& _rhs ) const
    {
        return !realCompare( m_data, _rhs.m_data );
    }

    //---------------------------------------
    bool Angle::operator <( const Angle& _rhs ) const
    {
        return m_data < _rhs.m_data;
    }

    //---------------------------------------
    bool Angle::operator >( const Angle& _rhs ) const
    {
        return m_data > _rhs.m_data;
    }

    //---------------------------------------
    bool Angle::operator <=( const Angle& _rhs ) const
    {
        return m_data < _rhs.m_data || realCompare( m_data, _rhs.m_data );
    }

    //---------------------------------------
    bool Angle::operator >=( const Angle& _rhs ) const
    {
        return m_data > _rhs.m_data || realCompare( m_data, _rhs.m_data );
    }
}
