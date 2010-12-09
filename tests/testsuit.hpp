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

#define ASSERT_XY_VECT2_EQ( _x, _y, _v ) __do \
    ASSERT_REAL_EQ( _x, _v.x ); \
    ASSERT_REAL_EQ( _y, _v.y ); \
enddef

#define EXPECT_XY_VECT2_EQ( _x, _y, _v ) __do \
    EXPECT_REAL_EQ( _x, _v.x ); \
    EXPECT_REAL_EQ( _y, _v.y ); \
enddef

#define ASSERT_VECT2_EQ( _v1, _v2 ) __do \
    ASSERT_XY_VECT2_EQ( (_v1).x, (_v1).y, _v2 ); \
enddef

#define EXPECT_VECT2_EQ( _v1, _v2 ) __do \
    EXPECT_XY_VECT2_EQ( (_v1).x, (_v1).y, _v2 ); \
enddef


#endif
