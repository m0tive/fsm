#include "suit.hpp"

#include <fsm/Def.hpp>

//---------------------------------------
TEST(DefTest, RealEpsilon)
{
    EXPECT_EQ( 1.0, 1.0 + fsm::g_realEpsilon * 0.5 );
    EXPECT_NE( 1.0, 1.0 + fsm::g_realEpsilon );
}

//---------------------------------------
TEST(DefTest, RealCompare)
{
    fsm::Real a = 1.0 + 2.0;
    EXPECT_TRUE( fsm::realCompare( a, 3.0 ) );

    EXPECT_FALSE( fsm::realCompare( a, 3.0 + fsm::g_realEpsilon*10) );
    EXPECT_FALSE( fsm::realCompare( a, 3.0 - fsm::g_realEpsilon*10) );
}

//---------------------------------------
TEST(DefTest, RealPow)
{
    EXPECT_REAL_EQ( 25, fsm::pow(5.0,2.0) );
    EXPECT_REAL_EQ( 25, fsm::pow(-5.0,2.0) );
}

//---------------------------------------
TEST(DefTest, RealSqrt)
{
    EXPECT_REAL_EQ( 5, fsm::sqrt(25.0) );
}

