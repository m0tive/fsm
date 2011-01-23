// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _testsuit_hpp_
#define _testsuit_hpp_
// }}}

// define wrappers
#include <gtest/gtest.h>

#define __do do {
#define enddef } while (0)

//-------------------------------------------

#define ASSERT_REAL_EQ( _x, _y ) ASSERT_DOUBLE_EQ( _x, _y )
#define EXPECT_REAL_EQ( _x, _y ) EXPECT_DOUBLE_EQ( _x, _y )

//-------------------------------------------
// Angle functions {{{

#define ASSERT_REAL_RADIAN_EQ( _a, _b ) ASSERT_REAL_EQ( _a, (_b).get(cm2::Angle::kRadian) )
#define EXPECT_REAL_RADIAN_EQ( _a, _b ) EXPECT_REAL_EQ( _a, (_b).get(cm2::Angle::kRadian) )

#define ASSERT_RADIAN_EQ( _a, _b ) ASSERT_REAL_RADIAN_EQ( (_a).get(cm2::Angle::kRadian), _b )
#define EXPECT_RADIAN_EQ( _a, _b ) EXPECT_REAL_RADIAN_EQ( (_a).get(cm2::Angle::kRadian), _b )

#define ASSERT_REAL_DEGREE_EQ( _a, _b ) ASSERT_REAL_EQ( _a, (_b).get(cm2::Angle::kDegree) )
#define EXPECT_REAL_DEGREE_EQ( _a, _b ) EXPECT_REAL_EQ( _a, (_b).get(cm2::Angle::kDegree) )

#define ASSERT_DEGREE_EQ( _a, _b ) ASSERT_REAL_DEGREE_EQ( (_a).get(cm2::Angle::kDegree), _b )
#define EXPECT_DEGREE_EQ( _a, _b ) EXPECT_REAL_DEGREE_EQ( (_a).get(cm2::Angle::kDegree), _b )

// }}}

//-------------------------------------------
// Vector2 functions {{{

#define ASSERT_XY_VECT2_EQ( _x, _y, _v ) __do \
    cm2::Vector2 temp (_v); \
    ASSERT_REAL_EQ( _x, temp.x ); \
    ASSERT_REAL_EQ( _y, temp.y ); \
enddef

#define EXPECT_XY_VECT2_EQ( _x, _y, _v ) __do \
    cm2::Vector2 temp (_v); \
    EXPECT_REAL_EQ( _x, temp.x ); \
    EXPECT_REAL_EQ( _y, temp.y ); \
enddef

#define ASSERT_VECT2_EQ( _v1, _v2 ) __do \
    cm2::Vector2 temp (_v1); \
    ASSERT_XY_VECT2_EQ( temp.x, temp.y, _v2 ); \
enddef

#define EXPECT_VECT2_EQ( _v1, _v2 ) __do \
    cm2::Vector2 temp (_v1); \
    EXPECT_XY_VECT2_EQ( temp.x, temp.y, _v2 ); \
enddef

// }}}

//-------------------------------------------
// Vector3 functions {{{

#define ASSERT_XYZ_VECT3_EQ( _x, _y, _z,  _v ) __do \
    cm2::Vector3 temp (_v); \
    ASSERT_REAL_EQ( _x, temp.x ); \
    ASSERT_REAL_EQ( _y, temp.y ); \
    ASSERT_REAL_EQ( _z, temp.z ); \
enddef

#define EXPECT_XYZ_VECT3_EQ( _x, _y, _z, _v ) __do \
    cm2::Vector3 temp (_v); \
    EXPECT_REAL_EQ( _x, temp.x ); \
    EXPECT_REAL_EQ( _y, temp.y ); \
    EXPECT_REAL_EQ( _z, temp.z ); \
enddef

#define ASSERT_VECT3_EQ( _v1, _v2 ) __do \
    cm2::Vector3 temp (_v1); \
    ASSERT_XYZ_VECT3_EQ( temp.x, temp.y, temp.z, _v2 ); \
enddef

#define EXPECT_VECT3_EQ( _v1, _v2 ) __do \
    cm2::Vector3 temp (_v1); \
    EXPECT_XYZ_VECT3_EQ( temp.x, temp.y, temp.z, _v2 ); \
enddef

// }}}

//-------------------------------------------
// Matrix3 functions {{{

#define ASSERT_9REALS_MAT_EQ( _00, _01, _02, _10, _11, _12, _20, _21, _22, _m ) __do \
    cm2::Matrix3 t1 (_m); \
    ASSERT_XYZ_VECT3_EQ( _00, _01, _02, t1.r(0) ); \
    ASSERT_XYZ_VECT3_EQ( _10, _11, _12, t1.r(1) ); \
    ASSERT_XYZ_VECT3_EQ( _20, _21, _22, t1.r(2) ); \
enddef

#define EXPECT_9REALS_MAT_EQ( _00, _01, _02, _10, _11, _12, _20, _21, _22, _m ) __do \
    cm2::Matrix3 t1 (_m); \
    EXPECT_XYZ_VECT3_EQ( _00, _01, _02, t1.r(0) ); \
    EXPECT_XYZ_VECT3_EQ( _10, _11, _12, t1.r(1) ); \
    EXPECT_XYZ_VECT3_EQ( _20, _21, _22, t1.r(2) ); \
enddef

#define ASSERT_MAT_EQ( _m1, _m2 ) __do \
    cm2::Matrix3 t1 (_m1), t2 (_m2); \
    ASSERT_VECT3_EQ( t1.r(0), t2.r(0) ); \
    ASSERT_VECT3_EQ( t1.r(1), t2.r(1) ); \
    ASSERT_VECT3_EQ( t1.r(2), t2.r(2) ); \
enddef

#define EXPECT_MAT_EQ( _m1, _m2 ) __do \
    cm2::Matrix3 t1 (_m1), t2 (_m2); \
    EXPECT_VECT3_EQ( t1.r(0), t2.r(0) ); \
    EXPECT_VECT3_EQ( t1.r(1), t2.r(1) ); \
    EXPECT_VECT3_EQ( t1.r(2), t2.r(2) ); \
enddef

// }}}

#endif
