#include "testsuit.hpp"

#include <cm2/Def.hpp>

//---------------------------------------
TEST(DefTest, RealEpsilon)
{
    cm2::Real a = 1.0 + 2.0;
    EXPECT_TRUE( (a + cm2::g_realEpsilon) > 3.0 );
    EXPECT_TRUE( (a - cm2::g_realEpsilon) < 3.0 );

    EXPECT_FALSE( (a + cm2::g_realEpsilon) > 3.001 );
    EXPECT_FALSE( (a - cm2::g_realEpsilon) < 2.999 );
}

//---------------------------------------
TEST(DefTest, RealCompare)
{
    cm2::Real a = 1.0 + 2.0;
    EXPECT_TRUE( cm2::realCompare( a, 3.0 ) );
    EXPECT_FALSE( cm2::realCompare( a, 3.001) );
    EXPECT_FALSE( cm2::realCompare( a, 2.999) );
}

//---------------------------------------
TEST(DefTest, RealSqrt)
{
    EXPECT_REAL_EQ( 5, cm2::sqrt(25.0) );
}

