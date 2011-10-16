#include "tools/Vector4.hpp"
#include <fsm/Vector4.hpp>

class Vector4Test : public testing::Test
{
  protected:
    Vector4Test() : v1_(1,2,4,8), v2_(-0.5,-1,-2,-4) {}

    fsm::Vector4 v0_;
    fsm::Vector4 v1_;
    fsm::Vector4 v2_;
};

//---------------------------------------
TEST_F(Vector4Test, DefaultConstructor)
{
    ASSERT_XYZW_VECT4_EQ( 0, 0, 0, 0, v0_ );
}

//---------------------------------------
TEST_F(Vector4Test, CopyConstructor)
{
    fsm::Vector4 v (v1_);
    // the copy contructor is used in the assert_vect3_eq test
    // so we need to use the basic comparison...
    ASSERT_REAL_EQ( v1_.x, v.x );
    ASSERT_REAL_EQ( v1_.y, v.y );
    ASSERT_REAL_EQ( v1_.z, v.z );
    ASSERT_REAL_EQ( v1_.w, v.w );
}

//---------------------------------------
TEST_F(Vector4Test, Constructor)
{
    ASSERT_XYZW_VECT4_EQ( 1, 2, 4, 8, v1_ );

    fsm::Real set[] = { 9,8,7,6 };

    fsm::Vector4 vect (set);
    ASSERT_XYZW_VECT4_EQ( 9, 8, 7, 6, vect );
}

//---------------------------------------
TEST_F(Vector4Test, DataAccess)
{
    v0_.x = 1; v0_.y = 2; v0_.z = 4; v0_.w = 5;
    ASSERT_REAL_EQ( 1, v0_.data[0] );
    ASSERT_REAL_EQ( 2, v0_.data[1] );
    ASSERT_REAL_EQ( 4, v0_.data[2] );
    ASSERT_REAL_EQ( 5, v0_.data[3] );

    ASSERT_REAL_EQ( 1, v0_[0] );
    ASSERT_REAL_EQ( 2, v0_[1] );
    ASSERT_REAL_EQ( 4, v0_[2] );
    ASSERT_REAL_EQ( 5, v0_[3] );

    v0_[0] = 3; v0_[1] = 4; v0_[2] = 6; v0_[3] = 7;
    ASSERT_REAL_EQ( 3, v0_.data[0] );
    ASSERT_REAL_EQ( 4, v0_.data[1] );
    ASSERT_REAL_EQ( 6, v0_.data[2] );
    ASSERT_REAL_EQ( 7, v0_.data[3] );

    ASSERT_REAL_EQ( 3, v0_.x );
    ASSERT_REAL_EQ( 4, v0_.y );
    ASSERT_REAL_EQ( 6, v0_.z );
    ASSERT_REAL_EQ( 7, v0_.w );

    v0_.data[0] = -1; v0_.data[1] = 0; v0_.data[2] = 2; v0_.data[3] = 3;
    ASSERT_REAL_EQ(-1, v0_[0] );
    ASSERT_REAL_EQ( 0, v0_[1] );
    ASSERT_REAL_EQ( 2, v0_[2] );
    ASSERT_REAL_EQ( 3, v0_[3] );

    ASSERT_REAL_EQ(-1, v0_.x );
    ASSERT_REAL_EQ( 0, v0_.y );
    ASSERT_REAL_EQ( 2, v0_.z );
    ASSERT_REAL_EQ( 3, v0_.w );
}

#if 0
//---------------------------------------
TEST_F(Vector4Test, IsNaN)
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
#endif

//---------------------------------------
TEST_F(Vector4Test, Set)
{
    v0_ = v1_.set(1,2,4,5);
    EXPECT_XYZW_VECT4_EQ( 1, 2, 4, 5, v1_ );
    EXPECT_VECT4_EQ( v1_, v0_ );

    v2_.set();
    EXPECT_XYZW_VECT4_EQ( 0, 0, 0, 0, v2_ );

    fsm::Real set[] = { 9,8,7,6 };

    v0_ = v1_.set(set);
    EXPECT_XYZW_VECT4_EQ( 9, 8, 7, 6, v1_ );
    EXPECT_VECT4_EQ( v1_, v0_ );
}

//---------------------------------------
TEST_F(Vector4Test, Negate)
{
    v0_ = -v1_;
    EXPECT_XYZW_VECT4_EQ( -1, -2, -4, -8, v0_ );
    EXPECT_XYZW_VECT4_EQ( 1, 2, 4, 8, v1_ );
}

//---------------------------------------
TEST_F(Vector4Test, Copy)
{
    v0_ = v1_ = v2_;
    EXPECT_VECT4_EQ( v2_, v1_ );
    EXPECT_VECT4_EQ( v1_, v0_ );
}

//---------------------------------------
TEST_F(Vector4Test, Add)
{
    v0_ = v1_ + v2_;
    EXPECT_XYZW_VECT4_EQ( 0.5, 1, 2, 4, v0_ );
    EXPECT_XYZW_VECT4_EQ( 1, 2, 4, 8, v1_ );
    EXPECT_XYZW_VECT4_EQ( -0.5, -1, -2, -4, v2_ );

    v1_ += v2_;
    EXPECT_XYZW_VECT4_EQ( 0.5, 1, 2, 4, v1_ );
    EXPECT_XYZW_VECT4_EQ( -0.5, -1, -2, -4, v2_ );
}

//---------------------------------------
TEST_F(Vector4Test, Subtract)
{
    v0_ = v1_ - v2_;
    EXPECT_XYZW_VECT4_EQ( 1.5, 3, 6, 12, v0_ );
    EXPECT_XYZW_VECT4_EQ( 1, 2, 4, 8, v1_ );
    EXPECT_XYZW_VECT4_EQ( -0.5, -1, -2, -4, v2_ );

    v1_ -= v2_;
    EXPECT_XYZW_VECT4_EQ( 1.5, 3, 6, 12, v1_ );
    EXPECT_XYZW_VECT4_EQ( -0.5, -1, -2, -4, v2_ );
}

//---------------------------------------
TEST_F(Vector4Test, ScalarMult)
{
    v0_ = v1_ * 2;
    EXPECT_XYZW_VECT4_EQ( 2, 4, 8, 16, v0_ );
    EXPECT_XYZW_VECT4_EQ( 1, 2, 4, 8, v1_ );

    v1_ *= 2;
    EXPECT_XYZW_VECT4_EQ( 2, 4, 8, 16, v1_ );
}

#if 0 // don't think dot product is relivant
//---------------------------------------
TEST_F(Vector4Test, DotProduct)
{
    fsm::Real result = v1_.dot(v2_);
    EXPECT_REAL_EQ( -10.5, result );
}
#endif

//---------------------------------------
TEST_F(Vector4Test, ScalarDivide)
{
    v0_ = v1_ / 2;
    EXPECT_XYZW_VECT4_EQ( 0.5, 1, 2, 4, v0_ );
    EXPECT_XYZW_VECT4_EQ( 1, 2, 4, 8, v1_ );

    v1_ /= 2;
    EXPECT_XYZW_VECT4_EQ( 0.5, 1, 2, 4, v1_ );
}

//---------------------------------------
TEST_F(Vector4Test, Magnitude)
{
    v1_.set(3,0,4,12);
    fsm::Real resA = v1_.magnitudeSquared();
    EXPECT_REAL_EQ( 169, resA );
    EXPECT_XYZW_VECT4_EQ( 3, 0, 4, 12, v1_ );

    fsm::Real resB = v1_.magnitude();
    EXPECT_REAL_EQ( 13, resB );
    EXPECT_XYZW_VECT4_EQ( 3, 0, 4, 12, v1_ );
}

//---------------------------------------
TEST_F(Vector4Test, Normalise)
{
    v0_.normalise();
    EXPECT_XYZW_VECT4_EQ( 0, 0, 0, 0, v0_ );

    v1_.normalise();
    EXPECT_REAL_EQ( 1, v1_.magnitudeSquared() );

    v1_ = fsm::Vector4( v2_ ).normalise();
    EXPECT_REAL_EQ( 1, v1_.magnitudeSquared() );
    EXPECT_REAL_EQ( 21.25, v2_.magnitudeSquared() );
}

//---------------------------------------
TEST_F(Vector4Test, Comparison)
{
    v0_ = v1_;
    EXPECT_TRUE( v0_ == v1_ );
    EXPECT_FALSE( v0_ == v2_ );

    EXPECT_FALSE( v0_ != v1_ );
    EXPECT_TRUE( v0_ != v2_ );
}
