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

//---------------------------------------
TEST_F(Matrix4Test, Copy)
{
    m0_ = m1_ = m2_;
    EXPECT_MAT_EQ( m2_, m1_ );
    EXPECT_MAT_EQ( m1_, m0_ );
}

//---------------------------------------
TEST_F(Matrix4Test, Multiply)
{
    m0_ = m1_ * m2_;
    EXPECT_16REALS_MAT_EQ( 0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15, m2_ );
    EXPECT_MAT_EQ( m1_, fsm::Matrix4::cIdentity );
    EXPECT_MAT_EQ( m0_, m1_ );

    m0_ = m2_ * m1_;
    EXPECT_MAT_EQ( m0_, fsm::Matrix4::cIdentity );

    m0_ = m1_.postMultiply( m2_ );
    EXPECT_16REALS_MAT_EQ( 0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15, m2_ );
    EXPECT_MAT_EQ( m1_, fsm::Matrix4::cIdentity );
    EXPECT_MAT_EQ( m0_, m1_ );

    m0_ = m1_.preMultiply( m2_ );
    EXPECT_16REALS_MAT_EQ( 0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15, m2_ );
    EXPECT_MAT_EQ( m1_, fsm::Matrix4::cIdentity );
    EXPECT_MAT_EQ( m0_, m1_ );

    m1_.set( 2,5,7,8, 4,6,9,7, 1,3,2,6, 2,5,1,5 );

    m0_ = m1_ * m2_;
    EXPECT_16REALS_MAT_EQ( 0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15, m2_ );
    EXPECT_16REALS_MAT_EQ( 2,5,7,8, 4,6,9,7, 1,3,2,6, 2,5,1,5, m1_ );
    EXPECT_16REALS_MAT_EQ( 172,194,216,238,
                           180,206,232,258,
                           100,112,124,136,
                            88,101,114,127, m0_ );

    m0_ = m2_ * m1_;
    EXPECT_16REALS_MAT_EQ( 0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15, m2_ );
    EXPECT_16REALS_MAT_EQ( 2,5,7,8, 4,6,9,7, 1,3,2,6, 2,5,1,5, m1_ );
    EXPECT_16REALS_MAT_EQ(  12, 27, 16, 34,
                            48,103, 92,138,
                            84,179,168,242,
                           120,255,244,346, m0_ );

    m1_.set( 2,5,7,8, 4,6,9,7, 1,3,2,6, 2,5,1,5 );
    m0_ = m1_.postMultiply( m2_ );
    EXPECT_16REALS_MAT_EQ( 0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15, m2_ );
    EXPECT_16REALS_MAT_EQ( 172,194,216,238,
                           180,206,232,258,
                           100,112,124,136,
                            88,101,114,127, m1_ );
    EXPECT_MAT_EQ( m0_, m1_ );

    m1_.set( 2,5,7,8, 4,6,9,7, 1,3,2,6, 2,5,1,5 );
    m0_ = m1_.preMultiply( m2_ );
    EXPECT_16REALS_MAT_EQ( 0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15, m2_ );
    EXPECT_16REALS_MAT_EQ(  12, 27, 16, 34,
                            48,103, 92,138,
                            84,179,168,242,
                           120,255,244,346, m1_ );
    EXPECT_MAT_EQ( m0_, m1_ );
}

//---------------------------------------
TEST_F(Matrix4Test, Serialise)
{
    fsm::Real* set;
    set = m2_.serialise();

    EXPECT_16REALS_MAT_EQ(  set[0],  set[1],  set[2],  set[3],
                            set[4],  set[5],  set[6],  set[7],
                            set[8],  set[9], set[10], set[11],
                           set[12], set[13], set[14], set[15], m2_ );

    set = m2_.serialise( fsm::Matrix4::kColMajor );

    EXPECT_16REALS_MAT_EQ( set[0], set[4],  set[8], set[12],
                           set[1], set[5],  set[9], set[13],
                           set[2], set[6], set[10], set[14],
                           set[3], set[7], set[11], set[15], m2_ );
}

//---------------------------------------
TEST_F(Matrix4Test, Transpose)
{
    fsm::Matrix4 mA;
    fsm::Matrix4 mB = m1_.transpose();
    EXPECT_MAT_EQ( m1_, mB );
    fsm::Matrix4::transpose( mB );
    EXPECT_MAT_EQ( m1_, mB );

    mA = m2_.transpose();
    EXPECT_16REALS_MAT_EQ( 0, 4, 8,12,
                           1, 5, 9,13,
                           2, 6,10,14,
                           3, 7,11,15, mA );
    EXPECT_16REALS_MAT_EQ( 0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15, m2_ );
    fsm::Matrix4::transpose( mA );
    EXPECT_16REALS_MAT_EQ( 0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15, mA );
}

//---------------------------------------
TEST_F(Matrix4Test, Determinate)
{
    fsm::Real d = m0_.determinate();
    EXPECT_REAL_EQ( 0, d );

    d = m1_.determinate();
    EXPECT_REAL_EQ( 1, d );

    d = m2_.determinate();
    EXPECT_REAL_EQ( 0, d );

#if 0 // det element test. good for debugging, not really needed {{{
    // 0
    d = fsm::Matrix4( 2,0,0,0,
                      0,3,0,0,
                      0,0,4,0,
                      0,0,0,5 ).determinate();
    EXPECT_REAL_EQ( 120, d );
    // 1
    d = fsm::Matrix4( 2,0,0,0,
                      0,0,4,0,
                      0,0,0,5,
                      0,3,0,0 ).determinate();
    EXPECT_REAL_EQ( 120, d );
    // 2
    d = fsm::Matrix4( 2,0,0,0,
                      0,0,0,5,
                      0,3,0,0,
                      0,0,4,0 ).determinate();
    EXPECT_REAL_EQ( 120, d );

    // not done some, I found the problem, add more if needed

    // 23
    d = fsm::Matrix4( 0,0,4,0,
                      0,0,0,5,
                      0,3,0,0,
                      2,0,0,0 ).determinate();
    EXPECT_REAL_EQ( -120, d );
#endif // }}}

    d = fsm::Matrix4( 2,5,7,8, 4,6,9,7, 1,3,2,6, 2,5,1,5 ).determinate();
    EXPECT_REAL_EQ( -93, d );
}

//---------------------------------------
TEST_F(Matrix4Test, Invert)
{
    bool result = fsm::Matrix4::invert( m0_ );
    EXPECT_FALSE(result);
    EXPECT_16REALS_MAT_EQ( 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, m0_ );

    result = fsm::Matrix4::invert( m1_ );
    EXPECT_TRUE(result);
    EXPECT_MAT_EQ( fsm::Matrix4::cIdentity, m1_ );

    m0_ = m2_.inverse();
    EXPECT_MAT_EQ( fsm::Matrix4::cIdentity, m0_ );
    EXPECT_16REALS_MAT_EQ( 0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15, m2_ );

    m2_.set( 0,1,2,3,
             4,5,6,7,
             8,9,4,1,
             2,3,1,9 );

    m1_ = m2_.inverse();
    const fsm::Real d = m2_.determinate();
    ASSERT_REAL_EQ( 216.0, d );
    EXPECT_16REALS_MAT_EQ( 0,1,2,3, 4,5,6,7, 8,9,4,1, 2,3,1,9, m2_ );
    EXPECT_16REALS_MAT_EQ(
           -314.0/d, 130.0/d, -40.0/d,   8.0/d,
            280.0/d,-140.0/d,  68.0/d,   8.0/d,
              4.0/d,  52.0/d, -16.0/d, -40.0/d,
            -24.0/d,  12.0/d, -12.0/d,  24.0/d,
            m1_ );
}
