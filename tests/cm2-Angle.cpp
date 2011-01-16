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
TEST_F(AngleTest, Constants)
{
    EXPECT_REAL_RADIAN_EQ( 2.0 * M_PI, cm2::Angle::_2_PI );
    EXPECT_REAL_RADIAN_EQ( M_PI, cm2::Angle::PI );
    EXPECT_REAL_RADIAN_EQ( M_PI_2, cm2::Angle::PI_2 );
    EXPECT_REAL_RADIAN_EQ( M_PI_4, cm2::Angle::PI_4 );

    EXPECT_REAL_DEGREE_EQ( 360.0, cm2::Angle::_360_D );
    EXPECT_REAL_DEGREE_EQ( 180.0, cm2::Angle::_180_D );
    EXPECT_REAL_DEGREE_EQ( 90.0, cm2::Angle::_90_D );
    EXPECT_REAL_DEGREE_EQ( 45.0, cm2::Angle::_45_D );
}

//---------------------------------------
TEST_F(AngleTest, AsUnit)
{
    ASSERT_REAL_EQ( M_PI, r1_.get(cm2::Angle::kRadian) );

    ASSERT_REAL_EQ( 180, r1_.get(cm2::Angle::kDegree) );
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

#if 0 // convertion, needs merging
//---------------------------------------
TEST_F(AnglesTest, Convertion)
{
    d0_ = r1_.asDegree();
    EXPECT_REAL_ANGLE_EQ( 180, d0_ );
    EXPECT_REAL_ANGLE_EQ( M_PI, r1_ );

    r0_ = d1_.asRadian();
    EXPECT_REAL_ANGLE_EQ( M_PI, r0_ );
    EXPECT_REAL_ANGLE_EQ( 180, d1_ );

    r0_ = r1_ = 5;
    d0_ = r1_.asDegree();
    EXPECT_ANGLE_EQ( r0_, d0_.asRadian() );

    d0_ = d1_ = 654;
    r0_ = d1_.asRadian();
    EXPECT_ANGLE_EQ( d0_, r0_.asDegree() );
}
#endif
