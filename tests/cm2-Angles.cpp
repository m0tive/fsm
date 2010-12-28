#include "testsuit.hpp"

#include <cm2/Angles.hpp>

class RadianTest : public testing::Test
{
  protected:
    RadianTest() : r1_(M_PI) {}

    cm2::Radian r0_;
    cm2::Radian r1_;
};

//---------------------------------------
TEST_F(RadianTest, DefaultConstructor)
{
    ASSERT_REAL_RADIAN_EQ( 0, r0_ );
}

//---------------------------------------
TEST_F(RadianTest, CopyConstructor)
{
    cm2::Radian r (r1_);
    ASSERT_RADIAN_EQ( r1_, r );
}

//---------------------------------------
TEST_F(RadianTest, Constructor)
{
    ASSERT_REAL_RADIAN_EQ( M_PI, r1_ );
}

//---------------------------------------
TEST_F(RadianTest, Copy)
{
    cm2::Radian r2_;
    r2_ = r0_ = r1_;
    EXPECT_RADIAN_EQ( r1_, r0_ );
    EXPECT_RADIAN_EQ( r0_, r2_ );
}

//---------------------------------------
TEST_F(RadianTest, AsReal)
{
    ASSERT_REAL_EQ( M_PI, r1_.asReal() );
}

//---------------------------------------
TEST_F(RadianTest, Comparison)
{
    EXPECT_TRUE( r0_ != r1_ );
    EXPECT_FALSE( r0_ == r1_ );

    r0_ = r1_;
    EXPECT_TRUE( r0_ == r1_ );
    EXPECT_FALSE( r0_ != r1_ );
}

