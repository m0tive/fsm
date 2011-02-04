// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _testtools_Angle_hpp_
#define _testtools_Angle_hpp_
// }}}

#include <gtest/gtest.h>
#include "Real.hpp"

// define wrappers
#define __do do {
#define enddef } while (0)

#define ASSERT_REAL_RADIAN_EQ( _a, _b ) ASSERT_REAL_EQ( _a, (_b).get(fsm::Angle::kRadian) )
#define EXPECT_REAL_RADIAN_EQ( _a, _b ) EXPECT_REAL_EQ( _a, (_b).get(fsm::Angle::kRadian) )

#define ASSERT_RADIAN_EQ( _a, _b ) ASSERT_REAL_RADIAN_EQ( (_a).get(fsm::Angle::kRadian), _b )
#define EXPECT_RADIAN_EQ( _a, _b ) EXPECT_REAL_RADIAN_EQ( (_a).get(fsm::Angle::kRadian), _b )

#define ASSERT_REAL_DEGREE_EQ( _a, _b ) ASSERT_REAL_EQ( _a, (_b).get(fsm::Angle::kDegree) )
#define EXPECT_REAL_DEGREE_EQ( _a, _b ) EXPECT_REAL_EQ( _a, (_b).get(fsm::Angle::kDegree) )

#define ASSERT_DEGREE_EQ( _a, _b ) ASSERT_REAL_DEGREE_EQ( (_a).get(fsm::Angle::kDegree), _b )
#define EXPECT_DEGREE_EQ( _a, _b ) EXPECT_REAL_DEGREE_EQ( (_a).get(fsm::Angle::kDegree), _b )

#endif
