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

