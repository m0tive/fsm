#include "tools/Angle.hpp"
#include <fsm/Angle.hpp>

class AngleTest : public testing::Test
{
  protected:
    AngleTest()
        : r1_(M_PI, fsm::Angle::kRadian),
          r2_(fsm::Angle::Degree::c90) {}

    fsm::Angle r0_;
    fsm::Angle r1_;
    fsm::Angle r2_;
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
    fsm::Angle r (r1_);
    ASSERT_RADIAN_EQ( r1_, r );
}

//---------------------------------------
TEST_F(AngleTest, Constructor)
{
    ASSERT_REAL_RADIAN_EQ( M_PI, r1_ );
}

//---------------------------------------
TEST_F(AngleTest, GetSet)
{
    ASSERT_REAL_EQ( 0, r0_.get(fsm::Angle::kRadian) );
    ASSERT_REAL_EQ( 0, r0_.get(fsm::Angle::kDegree) );

    ASSERT_REAL_EQ( M_PI, r1_.get(fsm::Angle::kRadian) );
    ASSERT_REAL_EQ( 180, r1_.get(fsm::Angle::kDegree) );

    r0_.set( M_PI+M_PI_4, fsm::Angle::kRadian);
    ASSERT_REAL_EQ( M_PI+M_PI_4, r0_.get(fsm::Angle::kRadian) );
    ASSERT_REAL_EQ( 225.0, r0_.get(fsm::Angle::kDegree) );

    r1_.set( 60.0, fsm::Angle::kDegree );
    ASSERT_REAL_EQ( M_PI/3.0, r1_.get(fsm::Angle::kRadian) );
    ASSERT_REAL_EQ( 60.0, r1_.get(fsm::Angle::kDegree) );
}

//---------------------------------------
TEST_F(AngleTest, Copy)
{
    r2_ = r0_ = r1_;
    EXPECT_RADIAN_EQ( r1_, r0_ );
    EXPECT_RADIAN_EQ( r0_, r2_ );
}

//---------------------------------------
TEST_F(AngleTest, Constants)
{
    EXPECT_REAL_RADIAN_EQ( 2.0 * M_PI, fsm::Angle::Radian::c2PI );
    EXPECT_REAL_RADIAN_EQ( M_PI,   fsm::Angle::Radian::cPI );
    EXPECT_REAL_RADIAN_EQ( M_PI_2, fsm::Angle::Radian::cPI_2 );
    EXPECT_REAL_RADIAN_EQ( M_PI_4, fsm::Angle::Radian::cPI_4 );

    EXPECT_REAL_DEGREE_EQ( 360.0, fsm::Angle::Degree::c360 );
    EXPECT_REAL_DEGREE_EQ( 180.0, fsm::Angle::Degree::c180 );
    EXPECT_REAL_DEGREE_EQ( 90.0,  fsm::Angle::Degree::c90 );
    EXPECT_REAL_DEGREE_EQ( 45.0,  fsm::Angle::Degree::c45 );
}

//---------------------------------------
TEST_F(AngleTest, Negative)
{
    r0_ = -r1_;
    ASSERT_REAL_RADIAN_EQ( -M_PI, r0_ );
    ASSERT_REAL_RADIAN_EQ( M_PI, r1_ );
}

//---------------------------------------
TEST_F(AngleTest, Add)
{
    r0_ = r1_ + r2_;
    EXPECT_REAL_RADIAN_EQ( M_PI_2, r2_ );
    EXPECT_REAL_RADIAN_EQ( M_PI, r1_ );
    EXPECT_REAL_RADIAN_EQ( M_PI + M_PI_2, r0_ );

    r1_ += r2_;
    EXPECT_REAL_RADIAN_EQ( M_PI_2, r2_ );
    EXPECT_REAL_RADIAN_EQ( M_PI + M_PI_2, r1_ );
}

//---------------------------------------
TEST_F(AngleTest, Subtract)
{
    r0_ = r1_ - r2_;
    EXPECT_REAL_RADIAN_EQ( M_PI_2, r2_ );
    EXPECT_REAL_RADIAN_EQ( M_PI, r1_ );
    EXPECT_REAL_RADIAN_EQ( M_PI - M_PI_2, r0_ );

    r1_ -= r2_;
    EXPECT_REAL_RADIAN_EQ( M_PI_2, r2_ );
    EXPECT_REAL_RADIAN_EQ( M_PI - M_PI_2, r1_ );
}

//---------------------------------------
TEST_F(AngleTest, Multiply)
{
    r0_ = r2_ * fsm::Real(3.0);
    EXPECT_REAL_RADIAN_EQ( M_PI_2, r2_ );
    EXPECT_REAL_RADIAN_EQ( M_PI_2 * 3.0, r0_ );

    r1_ *= fsm::Real(-0.3);
    EXPECT_REAL_RADIAN_EQ( M_PI * -0.3, r1_ );
}

//---------------------------------------
TEST_F(AngleTest, Divide)
{
    r0_ = r2_ / fsm::Real(3.0);
    EXPECT_REAL_RADIAN_EQ( M_PI_2, r2_ );
    EXPECT_REAL_RADIAN_EQ( M_PI_2 / 3.0, r0_ );

    r1_ /= fsm::Real(-0.3);
    EXPECT_REAL_RADIAN_EQ( M_PI / -0.3, r1_ );
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

    fsm::Angle r2_ ( 5, fsm::Angle::kRadian );
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
