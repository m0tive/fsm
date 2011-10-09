#include "tools/Matrix4.hpp"
#include <fsm/Matrix4.hpp>

class Matrix4Test : public testing::Test
{
  protected:
    Matrix4Test()
        : m1_( fsm::Matrix4::cIdentity ),
          m2_( 0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15 )
    {
    }

    fsm::Matrix4 m0_;
    fsm::Matrix4 m1_;
    fsm::Matrix4 m2_;
};

//---------------------------------------
TEST_F(Matrix4Test, Identity)
{
    ASSERT_16REALS_MAT_EQ( 1,0,0,0,
                           0,1,0,0,
                           0,0,1,0,
                           0,0,0,1, fsm::Matrix4::cIdentity );
}
//---------------------------------------
TEST_F(Matrix4Test, DefaultConstructor)
{
    ASSERT_16REALS_MAT_EQ( 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, m0_ );
}

//---------------------------------------
TEST_F(Matrix4Test, CopyConstructor)
{
    fsm::Matrix4 m (m2_);
    // the copy contructor is used in the assert_mat_eq test
    // so we need to use the basic comparison...
    ASSERT_REAL_EQ( m2_.r0.x, m.r0.x );
    ASSERT_REAL_EQ( m2_.r0.y, m.r0.y );
    ASSERT_REAL_EQ( m2_.r0.z, m.r0.z );
    ASSERT_REAL_EQ( m2_.r0.w, m.r0.w );

    ASSERT_REAL_EQ( m2_.r1.x, m.r1.x );
    ASSERT_REAL_EQ( m2_.r1.y, m.r1.y );
    ASSERT_REAL_EQ( m2_.r1.z, m.r1.z );
    ASSERT_REAL_EQ( m2_.r1.w, m.r1.w );

    ASSERT_REAL_EQ( m2_.r2.x, m.r2.x );
    ASSERT_REAL_EQ( m2_.r2.y, m.r2.y );
    ASSERT_REAL_EQ( m2_.r2.z, m.r2.z );
    ASSERT_REAL_EQ( m2_.r2.w, m.r2.w );

    ASSERT_16REALS_MAT_EQ( 1,0,0,0,
                           0,1,0,0,
                           0,0,1,0,
                           0,0,0,1, m1_ );
}

//---------------------------------------
TEST_F(Matrix4Test, Constructor)
{
    ASSERT_16REALS_MAT_EQ( 0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15, m2_ );

    fsm::Real set[16] = { 16,15,14,13,
                          12,11,10, 9,
                           8, 7, 6, 5,
                           4, 3, 2, 1 };

    fsm::Matrix4 mat1 (set);
    ASSERT_16REALS_MAT_EQ( 16,15,14,13,
                           12,11,10, 9,
                            8, 7, 6, 5,
                            4, 3, 2, 1, mat1 );

    fsm::Matrix4 mat2 (set, fsm::Matrix4::kColMajor);
    ASSERT_16REALS_MAT_EQ( 16,12, 8, 4,
                           15,11, 7, 3,
                           14,10, 6, 2,
                           13, 9, 5, 1, mat2 );
}

