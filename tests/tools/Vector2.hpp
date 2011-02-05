// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _testtools_Vector2_hpp_
#define _testtools_Vector2_hpp_
// }}}

#include <gtest/gtest.h>
#include "Real.hpp"

#define ASSERT_XY_VECT2_EQ( _x, _y, _v ) do { \
    fsm::Vector2 temp (_v); \
    ASSERT_REAL_EQ( _x, temp.x ); \
    ASSERT_REAL_EQ( _y, temp.y ); \
} while (0)

#define EXPECT_XY_VECT2_EQ( _x, _y, _v ) do { \
    fsm::Vector2 temp (_v); \
    EXPECT_REAL_EQ( _x, temp.x ); \
    EXPECT_REAL_EQ( _y, temp.y ); \
} while (0)

#define ASSERT_VECT2_EQ( _v1, _v2 ) do { \
    fsm::Vector2 temp (_v1); \
    ASSERT_XY_VECT2_EQ( temp.x, temp.y, _v2 ); \
} while (0)

#define EXPECT_VECT2_EQ( _v1, _v2 ) do { \
    fsm::Vector2 temp (_v1); \
    EXPECT_XY_VECT2_EQ( temp.x, temp.y, _v2 ); \
} while (0)

#endif
