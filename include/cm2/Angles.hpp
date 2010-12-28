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

    bool operator ==( const Radian& _rhs ) const;
    bool operator !=( const Radian& _rhs ) const;

    //---------------------------------------
    /// \brief Get as Real.
    /// \return The angles value.
    Real asReal();

protected:
    Real m_data;
};
}

#endif
