#include <gtest/gtest.h>

#include <cm2/Vector2.hpp>

class Vector2Test : public testing::Test {
  protected:
//    Vector2Test() : v1_(1,2), v_2(-0.5,-1) {}

    cm2::Vector2 v0_;
//    cm2::Vector2 v1_;
//    cm2::Vector2 v2_;
};

TEST_F(Vector2Test, DefaultConstructor) {
    ASSERT_DOUBLE_EQ( 0, v0_.x );
    ASSERT_DOUBLE_EQ( 0, v0_.y );
}

TEST_F(Vector2Test, DataAccess) {
    v0_.x = 1; v0_.y = 2;
    ASSERT_DOUBLE_EQ( v0_.x, v0_.data[0] );
    ASSERT_DOUBLE_EQ( v0_.y, v0_.data[1] );
}
