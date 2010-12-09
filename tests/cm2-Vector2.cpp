#include "testsuit.hpp"

#include <cm2/Vector2.hpp>

class Vector2Test : public testing::Test
{
  protected:
    Vector2Test() : v1_(1,2), v2_(-0.5,-1) {}

    cm2::Vector2 v0_;
    cm2::Vector2 v1_;
    cm2::Vector2 v2_;
};

//---------------------------------------
TEST_F(Vector2Test, DefaultConstructor)
{
    ASSERT_XY_VECT2_EQ( 0, 0, v0_ );
}

//---------------------------------------
TEST_F(Vector2Test, CopyConstructor)
{
    cm2::Vector2 v (v1_);
    ASSERT_VECT2_EQ( v1_, v );
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
TEST_F(Vector2Test, Set)
{
    v0_ = v1_.set(1,2);
    EXPECT_XY_VECT2_EQ( 1, 2, v1_ );
    EXPECT_VECT2_EQ( v1_, v0_ );

    v2_.set();
    EXPECT_XY_VECT2_EQ( 0, 0, v2_ );
}

//---------------------------------------
TEST_F(Vector2Test, Add)
{
    v0_ = v1_ + v2_;
    EXPECT_XY_VECT2_EQ( 0.5, 1, v0_ );
    EXPECT_XY_VECT2_EQ( 1, 2, v1_ );
    EXPECT_XY_VECT2_EQ( -0.5, -1, v2_ );

    v1_ += v2_;
    EXPECT_XY_VECT2_EQ( 1-0.5, 2-1, v1_ );
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
    cm2::Real result = v1_.dot(v2_);
    EXPECT_REAL_EQ( -2.5, result );
}

//---------------------------------------
TEST_F(Vector2Test, Magnitude)
{
    v1_.set(3,4);
    cm2::Real resA = v1_.magnitudeSquared();
    EXPECT_REAL_EQ( 25, resA );
    EXPECT_XY_VECT2_EQ( 3, 4, v1_ );

    cm2::Real resB = v1_.magnitude();
    EXPECT_REAL_EQ( 5, resB );
    EXPECT_XY_VECT2_EQ( 3, 4, v1_ );
}

