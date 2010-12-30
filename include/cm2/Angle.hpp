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

    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/cos.html">cmath cos()</A>
    friend inline Real cos( const Radian& _r );
    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/sin.html">cmath sin()</A>
    friend inline Real sin( const Radian& _r );
    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/tan.html">cmath tan()</A>
    friend inline Real tan( const Radian& _r );
    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/acos.html">cmath acos()</A>
    friend inline Real acos( const Radian& _r );
    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/asin.html">cmath asin()</A>
    friend inline Real asin( const Radian& _r );
    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/atan.html">cmath atan()</A>
    friend inline Real atan( const Radian& _r );
    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/atan2.html">cmath atan2()</A>
    friend inline Real atan2( const Radian& _r1, const Radian& _r2 );

protected:
    Real m_data;
};

//------------------------------------------------------------------------------

Real cos( const Angle& _r ) { return ::cos(_r.m_data); }
Real sin( const Angle& _r ) { return ::sin(_r.m_data); }
Real tan( const Angle& _r ) { return ::tan(_r.m_data); }
Real acos( const Angle& _r ) { return ::acos(_r.m_data); }
Real asin( const Angle& _r ) { return ::asin(_r.m_data); }
Real atan( const Angle& _r ) { return ::atan(_r.m_data); }
Real atan2( const Angle& _r1, const Angle& _r2 ) {
    return ::atan2( _r1.m_data, _r2.m_data ); }

}

#endif
