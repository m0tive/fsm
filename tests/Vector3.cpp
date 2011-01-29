#include "suit.hpp"

#include <fsm/Vector3.hpp>

class Vector3Test : public testing::Test
{
  protected:
    Vector3Test() : v1_(1,2,4), v2_(-0.5,-1,-2) {}

    fsm::Vector3 v0_;
    fsm::Vector3 v1_;
    fsm::Vector3 v2_;
};

//---------------------------------------
TEST_F(Vector3Test, DefaultConstructor)
{
    ASSERT_XYZ_VECT3_EQ( 0, 0, 0, v0_ );
}

//---------------------------------------
TEST_F(Vector3Test, CopyConstructor)
{
    fsm::Vector3 v (v1_);
    // the copy contructor is used in the assert_vect3_eq test
    // so we need to use the basic comparison...
    ASSERT_REAL_EQ( v1_.x, v.x );
    ASSERT_REAL_EQ( v1_.y, v.y );
    ASSERT_REAL_EQ( v1_.z, v.z );
}

//---------------------------------------
TEST_F(Vector3Test, Constructor)
{
    ASSERT_XYZ_VECT3_EQ( 1, 2, 4, v1_ );
}

//---------------------------------------
TEST_F(Vector3Test, DataAccess)
{
    v0_.x = 1; v0_.y = 2; v0_.z = 4;
    ASSERT_REAL_EQ( 1, v0_.data[0] );
    ASSERT_REAL_EQ( 2, v0_.data[1] );
    ASSERT_REAL_EQ( 4, v0_.data[2] );
}

//---------------------------------------
TEST_F(Vector3Test, IsNaN)
{
    ASSERT_FALSE(v0_.isNaN());
    ASSERT_FALSE(v1_.isNaN());
    ASSERT_FALSE(v2_.isNaN());

    v0_.x = fsm::g_realNaN;
    ASSERT_TRUE(v0_.isNaN());

    v1_.y = fsm::g_realNaN;
    ASSERT_TRUE(v1_.isNaN());

    v2_.z = fsm::g_realNaN;
    ASSERT_TRUE(v2_.isNaN());
}

//---------------------------------------
TEST_F(Vector3Test, Set)
{
    v0_ = v1_.set(1,2,4);
    EXPECT_XYZ_VECT3_EQ( 1, 2, 4, v1_ );
    EXPECT_VECT3_EQ( v1_, v0_ );

    v2_.set();
    EXPECT_XYZ_VECT3_EQ( 0, 0, 0, v2_ );
}

//---------------------------------------
TEST_F(Vector3Test, Negate)
{
    v0_ = -v1_;
    EXPECT_XYZ_VECT3_EQ( -1, -2, -4, v0_ );
    EXPECT_XYZ_VECT3_EQ( 1, 2, 4, v1_ );
}

//---------------------------------------
TEST_F(Vector3Test, Copy)
{
    v0_ = v1_ = v2_;
    EXPECT_VECT3_EQ( v2_, v1_ );
    EXPECT_VECT3_EQ( v1_, v0_ );
}

//---------------------------------------
TEST_F(Vector3Test, Add)
{
    v0_ = v1_ + v2_;
    EXPECT_XYZ_VECT3_EQ( 0.5, 1, 2, v0_ );
    EXPECT_XYZ_VECT3_EQ( 1, 2, 4, v1_ );
    EXPECT_XYZ_VECT3_EQ( -0.5,-1,-2, v2_ );

    v1_ += v2_;
    EXPECT_XYZ_VECT3_EQ( 0.5, 1, 2, v1_ );
    EXPECT_XYZ_VECT3_EQ( -0.5,-1,-2, v2_ );
}

//---------------------------------------
TEST_F(Vector3Test, Subtract)
{
    v0_ = v1_ - v2_;
    EXPECT_XYZ_VECT3_EQ( 1.5, 3, 6, v0_ );
    EXPECT_XYZ_VECT3_EQ( 1, 2, 4, v1_ );
    EXPECT_XYZ_VECT3_EQ( -0.5,-1,-2, v2_ );

    v1_ -= v2_;
    EXPECT_XYZ_VECT3_EQ( 1.5, 3, 6, v1_ );
    EXPECT_XYZ_VECT3_EQ( -0.5,-1,-2, v2_ );
}

//---------------------------------------
TEST_F(Vector3Test, ScalarMult)
{
    v0_ = v1_ * 2;
    EXPECT_XYZ_VECT3_EQ( 2, 4, 8, v0_ );
    EXPECT_XYZ_VECT3_EQ( 1, 2, 4, v1_ );

    v1_ *= 2;
    EXPECT_XYZ_VECT3_EQ( 2, 4, 8, v1_ );
}

//---------------------------------------
TEST_F(Vector3Test, CrossProduct)
{
    v0_ = v1_.cross(v2_);
    EXPECT_XYZ_VECT3_EQ( 0, 0, 0, v0_ );
    EXPECT_XYZ_VECT3_EQ( 1, 2, 4, v1_ );
    EXPECT_XYZ_VECT3_EQ( -0.5,-1, -2, v2_ );

    v2_.z *= -1;
    v0_ = v1_.cross(v2_);
    EXPECT_XYZ_VECT3_EQ( 8, -4, 0, v0_ );
    EXPECT_XYZ_VECT3_EQ( 1, 2, 4, v1_ );
    EXPECT_XYZ_VECT3_EQ( -0.5,-1, 2, v2_ );
}

//---------------------------------------
TEST_F(Vector3Test, DotProduct)
{
    fsm::Real result = v1_.dot(v2_);
    EXPECT_REAL_EQ( -10.5, result );
}

//---------------------------------------
TEST_F(Vector3Test, ScalarDivide)
{
    v0_ = v1_ / 2;
    EXPECT_XYZ_VECT3_EQ( 0.5, 1, 2, v0_ );
    EXPECT_XYZ_VECT3_EQ( 1, 2, 4, v1_ );

    v1_ /= 2;
    EXPECT_XYZ_VECT3_EQ( 0.5, 1, 2, v1_ );
}

//---------------------------------------
TEST_F(Vector3Test, Magnitude)
{
    v1_.set(3,4,12);
    fsm::Real resA = v1_.magnitudeSquared();
    EXPECT_REAL_EQ( 169, resA );
    EXPECT_XYZ_VECT3_EQ( 3, 4, 12, v1_ );

    fsm::Real resB = v1_.magnitude();
    EXPECT_REAL_EQ( 13, resB );
    EXPECT_XYZ_VECT3_EQ( 3, 4, 12, v1_ );
}

//---------------------------------------
TEST_F(Vector3Test, Normalise)
{
    v0_.normalise();
    EXPECT_XYZ_VECT3_EQ( 0, 0, 0, v0_ );

    v1_.normalise();
    EXPECT_REAL_EQ( 1, v1_.magnitudeSquared() );

    v1_ = fsm::Vector3( v2_ ).normalise();
    EXPECT_REAL_EQ( 1, v1_.magnitudeSquared() );
    EXPECT_REAL_EQ( 5.25, v2_.magnitudeSquared() );
}

//---------------------------------------
TEST_F(Vector3Test, Comparison)
{
    v0_ = v1_;
    EXPECT_TRUE( v0_ == v1_ );
    EXPECT_FALSE( v0_ == v2_ );

    EXPECT_FALSE( v0_ != v1_ );
    EXPECT_TRUE( v0_ != v2_ );
}
