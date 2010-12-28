#include "testsuit.hpp"

#include <cm2/Angles.hpp>

class DegreeTest : public testing::Test
{
  protected:
    DegreeTest() : r1_(M_PI) {}

    cm2::Degree r0_;
    cm2::Degree r1_;
};

//---------------------------------------
TEST_F(DegreeTest, DefaultConstructor)
{
    ASSERT_REAL_RADIAN_EQ( 0, r0_ );
}

//---------------------------------------
TEST_F(DegreeTest, CopyConstructor)
{
    cm2::Degree r (r1_);
    ASSERT_RADIAN_EQ( r1_, r );
}

//---------------------------------------
TEST_F(DegreeTest, Constructor)
{
    ASSERT_REAL_RADIAN_EQ( M_PI, r1_ );
}

//---------------------------------------
TEST_F(DegreeTest, Copy)
{
    cm2::Degree r2_;
    r2_ = r0_ = r1_;
    EXPECT_RADIAN_EQ( r1_, r0_ );
    EXPECT_RADIAN_EQ( r0_, r2_ );
}

//---------------------------------------
TEST_F(DegreeTest, AsReal)
{
    ASSERT_REAL_EQ( M_PI, r1_.asReal() );
}

//---------------------------------------
TEST_F(DegreeTest, Comparison)
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

    cm2::Degree r2_ ( 5 );
    EXPECT_FALSE( r2_ < r1_ );
    EXPECT_TRUE( r2_ > r1_ );

    EXPECT_FALSE( r2_ <= r1_ );
    EXPECT_TRUE( r2_ >= r1_ );

    EXPECT_TRUE( r2_ != r1_ );
    EXPECT_FALSE( r2_ == r1_ );


}

