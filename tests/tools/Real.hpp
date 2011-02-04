// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _testtools_Real_hpp_
#define _testtools_Real_hpp_
// }}}

#include <gtest/gtest.h>

#define ASSERT_REAL_EQ( _x, _y ) ASSERT_DOUBLE_EQ( _x, _y )
#define EXPECT_REAL_EQ( _x, _y ) EXPECT_DOUBLE_EQ( _x, _y )

#endif
