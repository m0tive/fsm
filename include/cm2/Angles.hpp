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

#ifndef _cm2_Radian_hpp_
#define _cm2_Radian_hpp_
// }}}

#include "cm2/Def.hpp"

//------------------------------------------------------------------------------

namespace cm2
{
class Degree;

/// \brief
class Radian
{
public:
    //---------------------------------------
    /// \details Default constructor
    Radian( const Real _angle = 0 );
    //---------------------------------------
    /// \details Copy constructor
    /// \param _r
    Radian( const Radian& _r );

    //---------------------------------------
    /// \details Destructor
    ~Radian();

    //---------------------------------------
    /// \brief Radian assignment.
    /// Copy the value of another Radian into this Radian
    /// \param _rhs - the angle to copy
    /// \return A copy of this angle
    const Radian& operator =( const Radian& _rhs );

    //---------------------------------------
    /// \brief Radian comparison.
    /// Test if this Radian is equal to another Radian using cm2::realCompare
    /// \param _rhs - the right hand side of the comparison
    /// \return True if the angles are equal
    /// \see cm2::realCompare
    bool operator ==( const Radian& _rhs ) const;
    //---------------------------------------
    /// \brief Radian comparison.
    /// Test if this Radian is not equal to another Radian using cm2::realCompare
    /// \param _rhs - the right hand side of the comparison
    /// \return True if the angles are not equal
    /// \see cm2::realCompare
    bool operator !=( const Radian& _rhs ) const;

    //---------------------------------------
    /// \brief Radian comparison.
    /// Test if this Radian is less than another radian.
    /// \param _rhs - the right hand side of the comparison
    /// \return True if this angle is less.
    bool operator <( const Radian& _rhs ) const;
    //---------------------------------------
    /// \brief Radian comparison.
    /// Test if this Radian is greater than another radian.
    /// \param _rhs - the right hand side of the comparison
    /// \return True if this angle is greater.
    bool operator >( const Radian& _rhs ) const;
    //---------------------------------------
    /// \brief Radian comparison.
    /// Test if this Radian is less than or almost equal to another radian
    /// using cm2::realCompare.
    /// \param _rhs - the right hand side of the comparison
    /// \return True if this angle is greater.
    /// \see cm2::realCompare
    bool operator <=( const Radian& _rhs ) const;
    //---------------------------------------
    /// \brief Radian comparison.
    /// Test if this Radian is greater than or almost equal to another radian
    /// using cm2::realCompare.
    /// \param _rhs - the right hand side of the comparison
    /// \return True if this angle is greater.
    /// \see cm2::realCompare
    bool operator >=( const Radian& _rhs ) const;

    //---------------------------------------
    /// \brief Get as Real.
    /// \return The angles value.
    inline Real asReal() const { return m_data; }

protected:
    Real m_data;
};

//------------------------------------------------------------------------------

/// \brief
class Degree
{
public:
    //---------------------------------------
    /// \details Default constructor
    Degree( const Real _angle = 0 );
    //---------------------------------------
    /// \details Copy constructor
    /// \param _r
    Degree( const Degree& _r );

    //---------------------------------------
    /// \details Destructor
    ~Degree();

    //---------------------------------------
    /// \brief Degree assignment.
    /// Copy the value of another Degree into this Degree
    /// \param _rhs - the angle to copy
    /// \return A copy of this angle
    const Degree& operator =( const Degree& _rhs );

    //---------------------------------------
    /// \brief Degree comparison.
    /// Test if this Degree is equal to another Degree using cm2::realCompare
    /// \param _rhs - the right hand side of the comparison
    /// \return True if the angles are equal
    /// \see cm2::realCompare
    bool operator ==( const Degree& _rhs ) const;
    //---------------------------------------
    /// \brief Degree comparison.
    /// Test if this Degree is not equal to another Degree using cm2::realCompare
    /// \param _rhs - the right hand side of the comparison
    /// \return True if the angles are not equal
    /// \see cm2::realCompare
    bool operator !=( const Degree& _rhs ) const;

    //---------------------------------------
    /// \brief Degree comparison.
    /// Test if this Degree is less than another radian.
    /// \param _rhs - the right hand side of the comparison
    /// \return True if this angle is less.
    bool operator <( const Degree& _rhs ) const;
    //---------------------------------------
    /// \brief Degree comparison.
    /// Test if this Degree is greater than another radian.
    /// \param _rhs - the right hand side of the comparison
    /// \return True if this angle is greater.
    bool operator >( const Degree& _rhs ) const;
    //---------------------------------------
    /// \brief Degree comparison.
    /// Test if this Degree is less than or almost equal to another radian
    /// using cm2::realCompare.
    /// \param _rhs - the right hand side of the comparison
    /// \return True if this angle is greater.
    /// \see cm2::realCompare
    bool operator <=( const Degree& _rhs ) const;
    //---------------------------------------
    /// \brief Degree comparison.
    /// Test if this Degree is greater than or almost equal to another radian
    /// using cm2::realCompare.
    /// \param _rhs - the right hand side of the comparison
    /// \return True if this angle is greater.
    /// \see cm2::realCompare
    bool operator >=( const Degree& _rhs ) const;

    //---------------------------------------
    /// \brief Get as Real.
    /// \return The angles value.
    inline Real asReal() const { return m_data; }

protected:
    Real m_data;
};

inline Real cos( const Radian r ) { return ::cos(r.asReal()); }
inline Real sin( const Radian r ) { return ::sin(r.asReal()); }
inline Real tan( const Radian r ) { return ::tan(r.asReal()); }
inline Real acos( const Radian r ) { return ::acos(r.asReal()); }
inline Real asin( const Radian r ) { return ::asin(r.asReal()); }
inline Real atan( const Radian r ) { return ::atan(r.asReal()); }
inline Real atan2( const Radian r1, const Radian r2 ) {
    return ::atan2( r1.asReal(), r2.asReal() );
}

}

#endif
