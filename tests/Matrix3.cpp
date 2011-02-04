#include "tools/Matrix3.hpp"
#include <fsm/Matrix3.hpp>

#if 0
class Matrix3Test : public testing::Test
{
  protected:
    Matrix3Test()
        : m1_( fsm::Matrix3::kIdentity ),
          m2_( 0,1,2, 3,4,5, 6,7,8 )
    {
    }

    fsm::Matrix3 m0_;
    fsm::Matrix3 m1_;
    fsm::Matrix3 m2_;
};

//---------------------------------------
TEST_F(Matrix3Test, DefaultConstructor)
{
    ASSERT_9REALS_MAT_EQ( 0,0,0, 0,0,0, 0,0,0, m0_ );
}

#endif
