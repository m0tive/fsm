// File Info {{{
//------------------------------------------------------------------------------
/// \file Angles.hpp
/// \date 2010 Dec 28
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _cm2_Angle_hpp_
#define _cm2_Angle_hpp_
// }}}

#include "cm2/Def.hpp"

//------------------------------------------------------------------------------

namespace cm2
{
//class Degree;

/// \brief
class Angle
{
public:
    enum Unit
    {
        kRadian = 0,
        kDegree
    };

    //---------------------------------------
    /// \details Default constructor
    Angle();
    //---------------------------------------
    /// \details By value constructor
    /// \param _angle - angle
    /// \param _unit - unit of messurement to use.
    Angle( const Real _angle, Unit _unit );
    //---------------------------------------
    /// \details Copy constructor
    /// \param _r - angle to copy
    Angle( const Angle& _r );

    //---------------------------------------
    /// \details Destructor
    ~Angle();

    //---------------------------------------
    /// \brief Angle assignment.
    /// Copy the value of another Angle into this Angle
    /// \param _rhs - the angle to copy
    /// \return A copy of this angle
    const Angle& operator =( const Angle& _rhs );

    //---------------------------------------
    /// \brief Angle comparison.
    /// Test if this Angle is equal to another Angle using cm2::realCompare
    /// \param _rhs - the right hand side of the comparison
    /// \return True if the angles are equal
    /// \see cm2::realCompare
    bool operator ==( const Angle& _rhs ) const;
    //---------------------------------------
    /// \brief Angle comparison.
    /// Test if this Angle is not equal to another Angle using cm2::realCompare
    /// \param _rhs - the right hand side of the comparison
    /// \return True if the angles are not equal
    /// \see cm2::realCompare
    bool operator !=( const Angle& _rhs ) const;

    //---------------------------------------
    /// \brief Angle comparison.
    /// Test if this Angle is less than another radian.
    /// \param _rhs - the right hand side of the comparison
    /// \return True if this angle is less.
    bool operator <( const Angle& _rhs ) const;
    //---------------------------------------
    /// \brief Angle comparison.
    /// Test if this Angle is greater than another radian.
    /// \param _rhs - the right hand side of the comparison
    /// \return True if this angle is greater.
    bool operator >( const Angle& _rhs ) const;
    //---------------------------------------
    /// \brief Angle comparison.
    /// Test if this Angle is less than or almost equal to another radian
    /// using cm2::realCompare.
    /// \param _rhs - the right hand side of the comparison
    /// \return True if this angle is greater.
    /// \see cm2::realCompare
    bool operator <=( const Angle& _rhs ) const;
    //---------------------------------------
    /// \brief Angle comparison.
    /// Test if this Angle is greater than or almost equal to another radian
    /// using cm2::realCompare.
    /// \param _rhs - the right hand side of the comparison
    /// \return True if this angle is greater.
    /// \see cm2::realCompare
    bool operator >=( const Angle& _rhs ) const;

    //---------------------------------------
    /// \brief Get as Real.
    /// \return The angles value.
    Real as( Unit _u ) const;

    // TODO : set value function...

protected:
    Real m_data;
};

inline Real cos( const Angle r ) { return ::cos(r.as(Angle::kRadian)); }
inline Real sin( const Angle r ) { return ::sin(r.as(Angle::kRadian)); }
inline Real tan( const Angle r ) { return ::tan(r.as(Angle::kRadian)); }
inline Real acos( const Angle r ) { return ::acos(r.as(Angle::kRadian)); }
inline Real asin( const Angle r ) { return ::asin(r.as(Angle::kRadian)); }
inline Real atan( const Angle r ) { return ::atan(r.as(Angle::kRadian)); }
inline Real atan2( const Angle r1, const Angle r2 ) {
    return ::atan2( r1.as(Angle::kRadian), r2.as(Angle::kRadian) );
}

}

#endif
