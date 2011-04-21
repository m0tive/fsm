// File Info {{{
//------------------------------------------------------------------------------
/// \file Angle.hpp
/// \date 2010 Dec 28
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _fsm_Angle_hpp_
#define _fsm_Angle_hpp_
// }}}

#include "fsm/Def.hpp"

//------------------------------------------------------------------------------

namespace fsm
{
/// \brief A rotation or portion of a circle.
class Angle
{
public:
    //---------------------------------------
    /// \brief Angle units of measurement.
    enum Unit
    {
        kRadian = 0,
        kDegree
    };

    //---------------------------------------
    // Constants

    static const Angle cWhole;  ///< 2Pi
    static const Angle cHalf;   ///< Pi
    static const Angle cQuarter; ///< Pi/2
    static const Angle cEighth; ///< Pi/4

#if 0
    static const Angle cNaN;
#endif

    struct Radian ///< Radian constants
    {
        static const Angle c2PI;  ///< 2Pi
        static const Angle cPI;   ///< Pi
        static const Angle cPI_2; ///< Pi/2
        static const Angle cPI_4; ///< Pi/4
    };

    struct Degree ///< Degree constants
    {
        static const Angle c360; ///< 360 degrees
        static const Angle c180; ///< 180 degrees
        static const Angle c90;  ///< 90 degrees
        static const Angle c45;  ///< 45 degrees
    };

    //---------------------------------------
    /// \details Default constructor
    Angle();
    //---------------------------------------
    /// \details By value constructor
    /// \param _angle - angle
    /// \param _unit - unit of measurement to use.
    Angle( const Real _angle, Unit _unit );
    //---------------------------------------
    /// \details Copy constructor
    /// \param _r - angle to copy
    Angle( const Angle& _r );

    //---------------------------------------
    /// \details Destructor
    ~Angle();

    //---------------------------------------
    /// \brief Get the angles size.
    /// Convert this Angle into a Real of the given Angle::Unit.
    /// \param _u - the angle type to get this angle as.
    /// \return The angle, in the desired unit.
    Real get( Unit _u ) const;
    //---------------------------------------
    /// \brief Set the angles size.
    /// Set the value of this Angle to a given Real of a given Angle::Unit.
    /// \param _r - the new value of this angle.
    /// \param _u - the angle type of _r.
    /// \return A copy of this angle
    const Angle& set( Real _r, Unit _u );

    //---------------------------------------
    /// \brief Angle assignment.
    /// Copy the value of another Angle into this Angle
    /// \param _rhs - the angle to copy
    /// \return A copy of this angle
    const Angle& operator =( const Angle& _rhs );

    //---------------------------------------
    /// \brief Negative operator.
    /// Create a new Angle that is the negative of this Angle.
    /// \return The resulting angle.
    Angle operator -();

    //---------------------------------------
    /// \brief Addition operator.
    /// Create a new Angle by adding two angles together.
    /// \param _rhs - the right hand side of the addition.
    /// \return The resulting angle.
    Angle operator +( const Angle& _rhs );
    //---------------------------------------
    /// \brief Subtraction operator.
    /// Create a new Angle by subtracting another angle from this angle.
    /// \param _rhs - the right hand side of the subtraction.
    /// \return The resulting angle.
    Angle operator -( const Angle& _rhs );

    //---------------------------------------
    /// \brief Addition operator.
    /// Change the value of this Angle by adding an Angle to it.
    /// \param _rhs - the right hand side of the addition.
    /// \return A copy of this angle.
    const Angle& operator +=( const Angle& _rhs );
    //---------------------------------------
    /// \brief Subtraction operator.
    /// Change the value of this Angle by subtracting an Angle from it.
    /// \param _rhs - the right hand side of the subtraction.
    /// \return A copy of this angle.
    const Angle& operator -=( const Angle& _rhs );

    //---------------------------------------
    /// \brief Multiply operator.
    /// Create a new Angle from this Angle multiplied by a Real.
    /// \param _rhs - the right hand side of the multiplication.
    /// \return The resulting angle.
    Angle operator *( const Real _rhs );
    //---------------------------------------
    /// \brief Divide operator.
    /// Create a new Angle from this Angle divided by a Real.
    /// \param _rhs - the right hand side of the division.
    /// \return The resulting angle.
    Angle operator /( const Real _rhs );

    //---------------------------------------
    /// \brief Multiply operator.
    /// Change the value of this Angle by multiplying it be a Real.
    /// \param _rhs - the right hand side of the multiplication
    /// \return A copy of this angle
    const Angle& operator *=( const Real _rhs );
    //---------------------------------------
    /// \brief Divide operator.
    /// Change the value of this Angle by dividing it be a Real.
    /// \param _rhs - the right hand side of the division.
    /// \return A copy of this angle.
    const Angle& operator /=( const Real _rhs );

    //---------------------------------------
    /// \brief Angle comparison.
    /// Test if this Angle is equal to another Angle using fsm::realCompare
    /// \param _rhs - the right hand side of the comparison
    /// \return True if the angles are equal
    /// \see fsm::realCompare
    bool operator ==( const Angle& _rhs ) const;
    //---------------------------------------
    /// \brief Angle comparison.
    /// Test if this Angle is not equal to another Angle using fsm::realCompare
    /// \param _rhs - the right hand side of the comparison
    /// \return True if the angles are not equal
    /// \see fsm::realCompare
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
    /// using fsm::realCompare.
    /// \param _rhs - the right hand side of the comparison
    /// \return True if this angle is greater.
    /// \see fsm::realCompare
    bool operator <=( const Angle& _rhs ) const;
    //---------------------------------------
    /// \brief Angle comparison.
    /// Test if this Angle is greater than or almost equal to another radian
    /// using fsm::realCompare.
    /// \param _rhs - the right hand side of the comparison
    /// \return True if this angle is greater.
    /// \see fsm::realCompare
    bool operator >=( const Angle& _rhs ) const;

    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/cos.html">cmath cos()</A>
    friend inline Real cos( const Angle& _r );
    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/sin.html">cmath sin()</A>
    friend inline Real sin( const Angle& _r );
    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/tan.html">cmath tan()</A>
    friend inline Real tan( const Angle& _r );
    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/acos.html">cmath acos()</A>
    friend inline Angle acos( const Real _r );
    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/asin.html">cmath asin()</A>
    friend inline Angle asin( const Real _r );
    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/atan.html">cmath atan()</A>
    friend inline Angle atan( const Real _r );
    //---------------------------------------
    /// \brief Maths function interface
    /// \par See also:
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/atan2.html">cmath atan2()</A>
    friend inline Angle atan2( const Real _r1, const Real _r2 );

protected:
    //---------------------------------------
    /// \brief The internal angle data.
    Real m_data;

private:
    //---------------------------------------
    // Private direct constructor.
    // For setting the value of new angles directly using the internal data type
    Angle( const Real _angle);
};

//------------------------------------------------------------------------------

Real cos( const Angle& _r ) { return ::cos(_r.m_data); }
Real sin( const Angle& _r ) { return ::sin(_r.m_data); }
Real tan( const Angle& _r ) { return ::tan(_r.m_data); }
Angle acos( const Real _r ) { return Angle(::acos(_r)); }
Angle asin( const Real _r ) { return Angle(::asin(_r)); }
Angle atan( const Real _r ) { return Angle(::atan(_r)); }
Angle atan2( const Real _r1, const Real _r2 ) {
    return Angle(::atan2( _r1, _r2 )); }

}

#endif
