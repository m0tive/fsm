
#include "testsuit.hpp"

#include <cm2/Matrix3.hpp>

class Matrix3Test : public testing::Test
{
  protected:
    Matrix3Test()
        : m1_( cm2::Matrix3::kIdentity ),
          m2_( 0,1,2, 3,4,5, 6,7,8 )
    {
    }

    cm2::Matrix3 m0_;
    cm2::Matrix3 m1_;
    cm2::Matrix3 m2_;
};

//---------------------------------------
TEST_F(Matrix3Test, DefaultConstructor)
{
    //ASSERT_VAL_MAT2_EQ( 0, 0, m0_ );
}

