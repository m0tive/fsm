// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _testtools_Matrix3_hpp_
#define _testtools_Matrix3_hpp_
// }}}

#include <gtest/gtest.h>
#include "Vector4.hpp"

#define ASSERT_16REALS_MAT_EQ( _00, _01, _02, _03, _10, _11, _12, _13, _20, _21, _22, _23, _30, _31, _32, _33, _m ) do { \
    fsm::Matrix4 t1 (_m); \
    ASSERT_XYZW_VECT4_EQ( _00, _01, _02, _03, t1.r0 ); \
    ASSERT_XYZW_VECT4_EQ( _10, _11, _12, _13, t1.r1 ); \
    ASSERT_XYZW_VECT4_EQ( _20, _21, _22, _23, t1.r2 ); \
    ASSERT_XYZW_VECT4_EQ( _30, _31, _32, _33, t1.r3 ); \
} while (0)

#define EXPECT_9REALS_MAT_EQ( _00, _01, _02, _03, _10, _11, _12, _13, _20, _21, _22, _23, _30, _31, _32, _33, _m ) do { \
    fsm::Matrix4 t1 (_m); \
    EXPECT_XYZW_VECT4_EQ( _00, _01, _02, _03, t1.r0 ); \
    EXPECT_XYZW_VECT4_EQ( _10, _11, _12, _13, t1.r1 ); \
    EXPECT_XYZW_VECT4_EQ( _20, _21, _22, _23, t1.r2 ); \
    EXPECT_XYZW_VECT4_EQ( _30, _31, _32, _33, t1.r3 ); \
} while (0)

#define ASSERT_MAT_EQ( _m1, _m2 ) do { \
    fsm::Matrix4 t1 (_m1), t2 (_m2); \
    ASSERT_VECT4_EQ( t1.r0, t2.r0 ); \
    ASSERT_VECT4_EQ( t1.r1, t2.r1 ); \
    ASSERT_VECT4_EQ( t1.r2, t2.r2 ); \
    ASSERT_VECT4_EQ( t1.r3, t2.r3 ); \
} while (0)

#define EXPECT_MAT_EQ( _m1, _m2 ) do { \
    fsm::Matrix4 t1 (_m1), t2 (_m2); \
    EXPECT_VECT4_EQ( t1.r0, t2.r0 ); \
    EXPECT_VECT4_EQ( t1.r1, t2.r1 ); \
    EXPECT_VECT4_EQ( t1.r2, t2.r2 ); \
    EXPECT_VECT4_EQ( t1.r3, t2.r3 ); \
} while (0)

#endif
