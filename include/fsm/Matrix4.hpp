// File Info {{{
//------------------------------------------------------------------------------
/// \file Matrix4.hpp
/// \date 2011 Oct 08
/// \author Peter Dodds
/// \brief
/// \note
//}}}---------------------------------------------------------------------------

// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _fsm_Matrix4_hpp_
#define _fsm_Matrix4_hpp_
// }}}

#include "fsm/Def.hpp"
#include "fsm/Vector4.hpp"

//------------------------------------------------------------------------------

namespace fsm
{
/// \brief
class Matrix4
{
public:
    //---------------------------------------
    /// \details Default constructor
    Matrix4();

    //---------------------------------------
    /// \details Destructor
    ~Matrix4();

    Vector4 r0; ///< first row
    Vector4 r1; ///< second row
    Vector4 r2; ///< third row
    Vector4 r3; ///< forth row
};
}

#endif
