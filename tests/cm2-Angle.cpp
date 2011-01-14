#include "testsuit.hpp"

#include <cm2/Angle.hpp>

class AngleTest : public testing::Test
{
  protected:
    AngleTest() : r1_(M_PI, cm2::Angle::kRadian) {}

    cm2::Angle r0_;
    cm2::Angle r1_;
};

//---------------------------------------
TEST_F(AngleTest, DefaultConstructor)
{
    ASSERT_REAL_RADIAN_EQ( 0, r0_ );
}

//---------------------------------------
TEST_F(AngleTest, ValueConstructor)
{
    ASSERT_REAL_RADIAN_EQ( M_PI, r1_ );
}

//---------------------------------------
TEST_F(AngleTest, CopyConstructor)
{
    cm2::Angle r (r1_);
    ASSERT_RADIAN_EQ( r1_, r );
}

//---------------------------------------
TEST_F(AngleTest, Constructor)
{
    ASSERT_REAL_RADIAN_EQ( M_PI, r1_ );
}

//---------------------------------------
TEST_F(AngleTest, Copy)
{
    cm2::Angle r2_;
    r2_ = r0_ = r1_;
    EXPECT_RADIAN_EQ( r1_, r0_ );
    EXPECT_RADIAN_EQ( r0_, r2_ );
}

//---------------------------------------
TEST_F(AngleTest, AsUnit)
{
    ASSERT_REAL_EQ( M_PI, r1_.as(cm2::Angle::kRadian) );

    ASSERT_REAL_EQ( 180, r1_.as(cm2::Angle::kDegree) );
}

//---------------------------------------
TEST_F(AngleTest, Comparison)
{
    EXPECT_TRUE( r0_ < r1_ );
    EXPECT_FALSE( r0_ > r1_ );

    EXPECT_TRUE( r0_ <= r1_ );
    EXPECT_FALSE( r0_ >= r1_ );

    EXPECT_TRUE( r0_ != r1_ );
    EXPECT_FALSE( r0_ == r1_ );

    r0_ = r1_;
    EXPECT_TRUE( r0_ <= r1_ );
    EXPECT_TRUE( r0_ >= r1_ );

    EXPECT_TRUE( r0_ == r1_ );
    EXPECT_FALSE( r0_ != r1_ );

    cm2::Angle r2_ ( 5, cm2::Angle::kRadian );
    EXPECT_FALSE( r2_ < r1_ );
    EXPECT_TRUE( r2_ > r1_ );

    EXPECT_FALSE( r2_ <= r1_ );
    EXPECT_TRUE( r2_ >= r1_ );

    EXPECT_TRUE( r2_ != r1_ );
    EXPECT_FALSE( r2_ == r1_ );
}
