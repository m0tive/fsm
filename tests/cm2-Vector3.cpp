#include "testsuit.hpp"

#include <cm2/Vector3.hpp>

class Vector3Test : public testing::Test
{
  protected:
    Vector3Test() : v1_(1,2,4), v2_(-0.5,-1,-2) {}

    cm2::Vector3 v0_;
    cm2::Vector3 v1_;
    cm2::Vector3 v2_;
};

//---------------------------------------
TEST_F(Vector3Test, DefaultConstructor)
{
    ASSERT_XYZ_VECT3_EQ( 0, 0, 0, v0_ );
}

//---------------------------------------
TEST_F(Vector3Test, CopyConstructor)
{
    cm2::Vector3 v (v1_);
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
TEST_F(Vector3Test, Set)
{
    v0_ = v1_.set(1,2,4);
    EXPECT_XYZ_VECT3_EQ( 1, 2, 4, v1_ );
    EXPECT_VECT3_EQ( v1_, v0_ );

    v2_.set();
    EXPECT_XYZ_VECT3_EQ( 0, 0, 0, v2_ );
}
