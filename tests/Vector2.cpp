#include "tools/Vector2.hpp"
#include <fsm/Vector2.hpp>

class Vector2Test : public testing::Test
{
  protected:
    Vector2Test() : v1_(1,2), v2_(-0.5,-1) {}

    fsm::Vector2 v0_;
    fsm::Vector2 v1_;
    fsm::Vector2 v2_;
};

//---------------------------------------
TEST_F(Vector2Test, DefaultConstructor)
{
    ASSERT_XY_VECT2_EQ( 0, 0, v0_ );
}

//---------------------------------------
TEST_F(Vector2Test, CopyConstructor)
{
    fsm::Vector2 v (v1_);
    // the copy contructor is used in the assert_vect2_eq test
    // so we need to use the basic comparison...
    ASSERT_REAL_EQ( v1_.x, v.x );
    ASSERT_REAL_EQ( v1_.y, v.y );
}

//---------------------------------------
TEST_F(Vector2Test, Constructor)
{
    ASSERT_XY_VECT2_EQ( 1, 2, v1_ );
}

//---------------------------------------
TEST_F(Vector2Test, DataAccess)
{
    v0_.x = 1; v0_.y = 2;
    ASSERT_REAL_EQ( v0_.x, v0_.data[0] );
    ASSERT_REAL_EQ( v0_.y, v0_.data[1] );
}

//---------------------------------------
TEST_F(Vector2Test, IsNaN)
{
    ASSERT_FALSE(v0_.isNaN());
    ASSERT_FALSE(v1_.isNaN());
    ASSERT_FALSE(v2_.isNaN());

    v0_.x = fsm::g_realNaN;
    ASSERT_TRUE(v0_.isNaN());

    v1_.y = fsm::g_realNaN;
    ASSERT_TRUE(v1_.isNaN());

    v2_.x = fsm::g_realNaN;
    v2_.y = fsm::g_realNaN;
    ASSERT_TRUE(v2_.isNaN());
}

//---------------------------------------
TEST_F(Vector2Test, Set)
{
    v0_ = v1_.set(1,2);
    EXPECT_XY_VECT2_EQ( 1, 2, v1_ );
    EXPECT_VECT2_EQ( v1_, v0_ );

    v2_.set();
    EXPECT_XY_VECT2_EQ( 0, 0, v2_ );
}

//---------------------------------------
TEST_F(Vector2Test, Negate)
{
    v0_ = -v1_;
    EXPECT_XY_VECT2_EQ( -1, -2, v0_ );
    EXPECT_XY_VECT2_EQ( 1, 2, v1_ );
}

//---------------------------------------
TEST_F(Vector2Test, Copy)
{
    v0_ = v1_ = v2_;
    EXPECT_VECT2_EQ( v2_, v1_ );
    EXPECT_VECT2_EQ( v1_, v0_ );
}

//---------------------------------------
TEST_F(Vector2Test, Add)
{
    v0_ = v1_ + v2_;
    EXPECT_XY_VECT2_EQ( 0.5, 1, v0_ );
    EXPECT_XY_VECT2_EQ( 1, 2, v1_ );
    EXPECT_XY_VECT2_EQ( -0.5, -1, v2_ );

    v1_ += v2_;
    EXPECT_XY_VECT2_EQ( 0.5, 1, v1_ );
    EXPECT_XY_VECT2_EQ( -0.5, -1, v2_ );
}

//---------------------------------------
TEST_F(Vector2Test, Subtract)
{
    v0_ = v1_ - v2_;
    EXPECT_XY_VECT2_EQ( 1.5, 3, v0_ );
    EXPECT_XY_VECT2_EQ( 1, 2, v1_ );
    EXPECT_XY_VECT2_EQ( -0.5, -1, v2_ );

    v1_ -= v2_;
    EXPECT_XY_VECT2_EQ( 1.5, 3, v1_ );
    EXPECT_XY_VECT2_EQ( -0.5, -1, v2_ );
}

//---------------------------------------
TEST_F(Vector2Test, ScalarMult)
{
    v0_ = v1_ * 2;
    EXPECT_XY_VECT2_EQ( 2, 4, v0_ );
    EXPECT_XY_VECT2_EQ( 1, 2, v1_ );

    v1_ *= 2;
    EXPECT_XY_VECT2_EQ( 2, 4, v1_ );
}

//---------------------------------------
TEST_F(Vector2Test, ScalarDivide)
{
    v0_ = v1_ / 2;
    EXPECT_XY_VECT2_EQ( 0.5, 1, v0_ );
    EXPECT_XY_VECT2_EQ( 1, 2, v1_ );

    v1_ /= 2;
    EXPECT_XY_VECT2_EQ( 0.5, 1, v1_ );
}

//---------------------------------------
TEST_F(Vector2Test, DotProduct)
{
    fsm::Real result = v1_.dot(v2_);
    EXPECT_REAL_EQ( -2.5, result );
}

//---------------------------------------
TEST_F(Vector2Test, Magnitude)
{
    v1_.set(3,4);
    fsm::Real resA = v1_.magnitudeSquared();
    EXPECT_REAL_EQ( 25, resA );
    EXPECT_XY_VECT2_EQ( 3, 4, v1_ );

    fsm::Real resB = v1_.magnitude();
    EXPECT_REAL_EQ( 5, resB );
    EXPECT_XY_VECT2_EQ( 3, 4, v1_ );
}

//---------------------------------------
TEST_F(Vector2Test, Normalise)
{
    v0_.normalise();
    EXPECT_XY_VECT2_EQ( 0, 0, v0_ );

    v1_.normalise();
    EXPECT_REAL_EQ( 1, v1_.magnitudeSquared() );

    v1_ = fsm::Vector2( v2_ ).normalise();
    EXPECT_REAL_EQ( 1, v1_.magnitudeSquared() );
    EXPECT_REAL_EQ( 1.25, v2_.magnitudeSquared() );
}

//---------------------------------------
TEST_F(Vector2Test, Comparison)
{
    v0_ = v1_;
    EXPECT_TRUE( v0_ == v1_ );
    EXPECT_FALSE( v0_ == v2_ );

    EXPECT_FALSE( v0_ != v1_ );
    EXPECT_TRUE( v0_ != v2_ );
}


