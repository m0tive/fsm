// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _testtools_Vector3_hpp_
#define _testtools_Vector3_hpp_
// }}}

#include <gtest/gtest.h>
#include "Real.hpp"

// define wrappers
#define __do do {
#define enddef } while (0)

#define ASSERT_XYZ_VECT3_EQ( _x, _y, _z,  _v ) __do \
    fsm::Vector3 temp (_v); \
    ASSERT_REAL_EQ( _x, temp.x ); \
    ASSERT_REAL_EQ( _y, temp.y ); \
    ASSERT_REAL_EQ( _z, temp.z ); \
enddef

#define EXPECT_XYZ_VECT3_EQ( _x, _y, _z, _v ) __do \
    fsm::Vector3 temp (_v); \
    EXPECT_REAL_EQ( _x, temp.x ); \
    EXPECT_REAL_EQ( _y, temp.y ); \
    EXPECT_REAL_EQ( _z, temp.z ); \
enddef

#define ASSERT_VECT3_EQ( _v1, _v2 ) __do \
    fsm::Vector3 temp (_v1); \
    ASSERT_XYZ_VECT3_EQ( temp.x, temp.y, temp.z, _v2 ); \
enddef

#define EXPECT_VECT3_EQ( _v1, _v2 ) __do \
    fsm::Vector3 temp (_v1); \
    EXPECT_XYZ_VECT3_EQ( temp.x, temp.y, temp.z, _v2 ); \
enddef

#endif
