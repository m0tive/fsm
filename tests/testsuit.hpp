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

//------------------------------------------------------------------------------

#define ASSERT_REAL_EQ( _x, _y ) ASSERT_DOUBLE_EQ( _x, _y )
#define EXPECT_REAL_EQ( _x, _y ) EXPECT_DOUBLE_EQ( _x, _y )

//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------

#define ASSERT_REAL_RADIAN_EQ( _a, _b ) ASSERT_REAL_EQ( _a, (_b).get(cm2::Angle::kRadian) )
#define EXPECT_REAL_RADIAN_EQ( _a, _b ) EXPECT_REAL_EQ( _a, (_b).get(cm2::Angle::kRadian) )

#define ASSERT_RADIAN_EQ( _a, _b ) ASSERT_REAL_RADIAN_EQ( (_a).get(cm2::Angle::kRadian), _b )
#define EXPECT_RADIAN_EQ( _a, _b ) EXPECT_REAL_RADIAN_EQ( (_a).get(cm2::Angle::kRadian), _b )

#define ASSERT_REAL_DEGREE_EQ( _a, _b ) ASSERT_REAL_EQ( _a, (_b).get(cm2::Angle::kDegree) )
#define EXPECT_REAL_DEGREE_EQ( _a, _b ) EXPECT_REAL_EQ( _a, (_b).get(cm2::Angle::kDegree) )

#define ASSERT_DEGREE_EQ( _a, _b ) ASSERT_REAL_DEGREE_EQ( (_a).get(cm2::Angle::kDegree), _b )
#define EXPECT_DEGREE_EQ( _a, _b ) EXPECT_REAL_DEGREE_EQ( (_a).get(cm2::Angle::kDegree), _b )

#endif
