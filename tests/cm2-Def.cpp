#include "testsuit.hpp"

#include <cm2/Def.hpp>

//---------------------------------------
TEST(DefTest, RealEpsilon)
{
    EXPECT_TRUE( (1.0 + cm2::g_realEpsilon*0.5) == 1.0 );
    EXPECT_FALSE( (1.0 + cm2::g_realEpsilon) == 1.0 );
}

//---------------------------------------
TEST(DefTest, RealCompare)
{
    cm2::Real a = 1.0 + 2.0;
    EXPECT_TRUE( cm2::realCompare( a, 3.0 ) );

    EXPECT_FALSE( cm2::realCompare( a, 3.0 + cm2::g_realEpsilon*10) );
    EXPECT_FALSE( cm2::realCompare( a, 3.0 - cm2::g_realEpsilon*10) );
}

//---------------------------------------
TEST(DefTest, RealSqrt)
{
    EXPECT_REAL_EQ( 5, cm2::sqrt(25.0) );
}

