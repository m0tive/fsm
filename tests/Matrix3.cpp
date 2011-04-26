#include "tools/Matrix3.hpp"
#include <fsm/Matrix3.hpp>

#if 1
class Matrix3Test : public testing::Test
{
  protected:
    Matrix3Test()
        : m1_( fsm::Matrix3::cIdentity ),
          m2_( 0,1,2, 3,4,5, 6,7,8 )
    {
    }

    fsm::Matrix3 m0_;
    fsm::Matrix3 m1_;
    fsm::Matrix3 m2_;
};

//---------------------------------------
TEST_F(Matrix3Test, Identity)
{
    ASSERT_9REALS_MAT_EQ( 1,0,0,
                          0,1,0,
                          0,0,1, fsm::Matrix3::cIdentity );
}
//---------------------------------------
TEST_F(Matrix3Test, DefaultConstructor)
{
    ASSERT_9REALS_MAT_EQ( 0,0,0, 0,0,0, 0,0,0, m0_ );
}

//---------------------------------------
TEST_F(Matrix3Test, CopyConstructor)
{
    fsm::Matrix3 m (m2_);
    // the copy contructor is used in the assert_vect2_eq test
    // so we need to use the basic comparison...
    ASSERT_REAL_EQ( m2_.r0.x, m.r0.x );
    ASSERT_REAL_EQ( m2_.r0.y, m.r0.y );
    ASSERT_REAL_EQ( m2_.r0.z, m.r0.z );

    ASSERT_REAL_EQ( m2_.r1.x, m.r1.x );
    ASSERT_REAL_EQ( m2_.r1.y, m.r1.y );
    ASSERT_REAL_EQ( m2_.r1.z, m.r1.z );

    ASSERT_REAL_EQ( m2_.r2.x, m.r2.x );
    ASSERT_REAL_EQ( m2_.r2.y, m.r2.y );
    ASSERT_REAL_EQ( m2_.r2.z, m.r2.z );

    ASSERT_9REALS_MAT_EQ( 1,0,0, 0,1,0, 0,0,1, m1_ );
}

//---------------------------------------
TEST_F(Matrix3Test, Constructor)
{
    ASSERT_9REALS_MAT_EQ( 0,1,2, 3,4,5, 6,7,8, m2_ );

    fsm::Real set[9] = { 9,8,7,
                         6,5,4,
                         3,2,1 };

    fsm::Matrix3 mat1 (set);
    ASSERT_9REALS_MAT_EQ( 9,8,7,6,5,4,3,2,1, mat1 );

    fsm::Matrix3 mat2 (set, fsm::Matrix3::kColMajor);
    ASSERT_9REALS_MAT_EQ( 9,6,3,8,5,2,7,4,1, mat2 );
}

//---------------------------------------
TEST_F(Matrix3Test, Set)
{
    EXPECT_TRUE(false);
}

//---------------------------------------
TEST_F(Matrix3Test, Assignment)
{
    EXPECT_TRUE(false);
}

//---------------------------------------
TEST_F(Matrix3Test, Multiply)
{
    EXPECT_TRUE(false);
}

//---------------------------------------
TEST_F(Matrix3Test, Serialise)
{
    fsm::Real* set;
    set = m2_.serialise();

    EXPECT_9REALS_MAT_EQ( set[0], set[1], set[2],
                          set[3], set[4], set[5],
                          set[6], set[7], set[8],
                          m2_ );

    set = m2_.serialise( fsm::Matrix3::kColMajor );

    EXPECT_9REALS_MAT_EQ( set[0], set[3], set[6],
                          set[1], set[4], set[7],
                          set[2], set[5], set[8],
                          m2_ );
}

//---------------------------------------
TEST_F(Matrix3Test, Transpose)
{
    fsm::Matrix3 mA;
    fsm::Matrix3 mB = m1_.transpose();
    EXPECT_MAT_EQ( m1_, mB );
    mA = fsm::Matrix3::transpose( mB );
    EXPECT_MAT_EQ( m1_, mA );
    EXPECT_MAT_EQ( m1_, mB );

    mA = m2_.transpose();
    EXPECT_9REALS_MAT_EQ( 0,3,6, 1,4,7, 2,5,8, mA );
    EXPECT_9REALS_MAT_EQ( 0,1,2, 3,4,5, 6,7,8, m2_ );
    mB = fsm::Matrix3::transpose( mA );

    EXPECT_9REALS_MAT_EQ( 0,1,2, 3,4,5, 6,7,8, mA );
    EXPECT_MAT_EQ( mA, mB );
}

//---------------------------------------
TEST_F(Matrix3Test, Determinate)
{
    EXPECT_TRUE(false);
}

#endif
