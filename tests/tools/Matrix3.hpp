// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _testtools_Matrix3_hpp_
#define _testtools_Matrix3_hpp_
// }}}

#include <gtest/gtest.h>
#include "Real.hpp"

#define ASSERT_9REALS_MAT_EQ( _00, _01, _02, _10, _11, _12, _20, _21, _22, _m ) do { \
    fsm::Matrix3 t1 (_m); \
    ASSERT_XYZ_VECT3_EQ( _00, _01, _02, t1.row(0) ); \
    ASSERT_XYZ_VECT3_EQ( _10, _11, _12, t1.row(1) ); \
    ASSERT_XYZ_VECT3_EQ( _20, _21, _22, t1.row(2) ); \
} while (0)

#define EXPECT_9REALS_MAT_EQ( _00, _01, _02, _10, _11, _12, _20, _21, _22, _m ) do { \
    fsm::Matrix3 t1 (_m); \
    EXPECT_XYZ_VECT3_EQ( _00, _01, _02, t1.row(0) ); \
    EXPECT_XYZ_VECT3_EQ( _10, _11, _12, t1.row(1) ); \
    EXPECT_XYZ_VECT3_EQ( _20, _21, _22, t1.row(2) ); \
} while (0)

#define ASSERT_MAT_EQ( _m1, _m2 ) do { \
    fsm::Matrix3 t1 (_m1), t2 (_m2); \
    ASSERT_VECT3_EQ( t1.row(0), t2.row(0) ); \
    ASSERT_VECT3_EQ( t1.row(1), t2.row(1) ); \
    ASSERT_VECT3_EQ( t1.row(2), t2.row(2) ); \
} while (0)

#define EXPECT_MAT_EQ( _m1, _m2 ) do { \
    fsm::Matrix3 t1 (_m1), t2 (_m2); \
    EXPECT_VECT3_EQ( t1.row(0), t2.row(0) ); \
    EXPECT_VECT3_EQ( t1.row(1), t2.row(1) ); \
    EXPECT_VECT3_EQ( t1.row(2), t2.row(2) ); \
} while (0)

#endif
