#include "testsuit.hpp"

#include <cm2/Vector3.hpp>

class Vector3Test : public testing::Test
{
  protected:
    cm2::Vector3 v0_;
};

//---------------------------------------
TEST_F(Vector3Test, Null)
{
    EXPECT_EQ( 1, 1 );
}

