// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _testtools_Vector4_hpp_
#define _testtools_Vector4_hpp_
// }}}

#include <gtest/gtest.h>
#include "Real.hpp"

#define ASSERT_XYZW_VECT4_EQ( _x, _y, _z, _w, _v ) do { \
    fsm::Vector4 temp (_v); \
    ASSERT_REAL_EQ( _x, temp.x ); \
    ASSERT_REAL_EQ( _y, temp.y ); \
    ASSERT_REAL_EQ( _z, temp.z ); \
    ASSERT_REAL_EQ( _w, temp.w ); \
} while (0)

#define EXPECT_XYZW_VECT4_EQ( _x, _y, _z, _w, _v ) do { \
    fsm::Vector4 temp (_v); \
    EXPECT_REAL_EQ( _x, temp.x ); \
    EXPECT_REAL_EQ( _y, temp.y ); \
    EXPECT_REAL_EQ( _z, temp.z ); \
    EXPECT_REAL_EQ( _w, temp.w ); \
} while (0)

#define ASSERT_VECT4_EQ( _v1, _v2 ) do { \
    fsm::Vector4 temp (_v1); \
    ASSERT_XYZW_VECT4_EQ( temp.x, temp.y, temp.z, temp.w, _v2 ); \
} while (0)

#define EXPECT_VECT4_EQ( _v1, _v2 ) do { \
    fsm::Vector4 temp (_v1); \
    EXPECT_XYZW_VECT4_EQ( temp.x, temp.y, temp.z, temp.w, _v2 ); \
} while (0)

#endif
