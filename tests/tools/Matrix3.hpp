// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _testtools_Matrix3_hpp_
#define _testtools_Matrix3_hpp_
// }}}

#include <gtest/gtest.h>
#include "Vector3.hpp"

#define ASSERT_9REALS_MAT_EQ( _00, _01, _02, _10, _11, _12, _20, _21, _22, _m ) do { \
    fsm::Matrix3 t1 (_m); \
    ASSERT_XYZ_VECT3_EQ( _00, _01, _02, t1.r0 ); \
    ASSERT_XYZ_VECT3_EQ( _10, _11, _12, t1.r1 ); \
    ASSERT_XYZ_VECT3_EQ( _20, _21, _22, t1.r2 ); \
} while (0)

#define EXPECT_9REALS_MAT_EQ( _00, _01, _02, _10, _11, _12, _20, _21, _22, _m ) do { \
    fsm::Matrix3 t1 (_m); \
    EXPECT_XYZ_VECT3_EQ( _00, _01, _02, t1.r0 ); \
    EXPECT_XYZ_VECT3_EQ( _10, _11, _12, t1.r1 ); \
    EXPECT_XYZ_VECT3_EQ( _20, _21, _22, t1.r2 ); \
} while (0)

#define ASSERT_MAT_EQ( _m1, _m2 ) do { \
    fsm::Matrix3 t1 (_m1), t2 (_m2); \
    ASSERT_VECT3_EQ( t1.r0, t2.r0 ); \
    ASSERT_VECT3_EQ( t1.r1, t2.r1 ); \
    ASSERT_VECT3_EQ( t1.r2, t2.r2 ); \
} while (0)

#define EXPECT_MAT_EQ( _m1, _m2 ) do { \
    fsm::Matrix3 t1 (_m1), t2 (_m2); \
    EXPECT_VECT3_EQ( t1.r0, t2.r0 ); \
    EXPECT_VECT3_EQ( t1.r1, t2.r1 ); \
    EXPECT_VECT3_EQ( t1.r2, t2.r2 ); \
} while (0)

#endif
