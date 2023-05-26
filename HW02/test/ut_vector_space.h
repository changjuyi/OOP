#include "../src/vector_space.h"

const double DELTA = 0.001;

// TEST example below.
// Using 'EXPECT' instead of 'ASSERT' here is because if 'ASSERT' fails,
// the delete statement will NOT be executed, which causes memory leak.

TEST(VectorTest, add_TA) {
  double u[3] = {1, 2, 3};
  double v[3] = {1.5, 2.5, 3.5};

  double * result = add(u, 3, v, 3);

  EXPECT_NEAR(2.5, result[0], DELTA);
  EXPECT_NEAR(4.5, result[1], DELTA);
  EXPECT_NEAR(6.5, result[2], DELTA);

  delete [] result;   // heap allocation in 'add'
}
TEST(VectorTest, add_interger) {
  double u[3] = {2, 4, 5};
  double v[3] = {3, 5, 7};

  double * result = add(u, 3, v, 3);

  ASSERT_EQ(5, result[0]);
  ASSERT_EQ(9, result[1]);
  ASSERT_EQ(12, result[2]);

  delete [] result;   // heap allocation in 'add'
}
TEST(VectorTest, add_float) {
    double u[3] = {4, 8, 16};
    double v[3] = {1.5, 3.5, 5.6};
    double * result = add(u, 3, v, 3);
    ASSERT_NEAR(5.5, result[0], DELTA);
    ASSERT_NEAR(11.5, result[1], DELTA);
    ASSERT_NEAR(21.6, result[2], DELTA);
    delete [] result;   // heap allocation in 'add'
}
TEST(VetorTest, add_different_dim){
    double v[3]={1,3,-5};
    double u[4]={4,-2,-1,5};
    ASSERT_THROW(add(v, 3, u, 4), std::string);
    
}
TEST(VetorTest, add_dimNeg){
    double v[1]={2};//-1-dumesional vector is not exist,but vector_v need a value
    double u[3]={3, 2, 6};
    ASSERT_THROW(add(v, -1, u, 3), std::string);
}
TEST(VetorTest, add_dimZero){
    double v[1]={2};//0-dumesional vector is not exist,but vector_v need a value
    double u[1]={3};//0-dumesional vector is not exist,but vector_u need a value
    ASSERT_THROW(add(v, 0, u, 0), std::string);
}
TEST(VectorTest, scale_TA) {
    double u[3] = {1.5, 2.5, 3.5};
    double * result = scale(u, 3, 1.2);
    EXPECT_NEAR(1.8, result[0], DELTA);
    EXPECT_NEAR(3.0, result[1], DELTA);
    EXPECT_NEAR(4.2, result[2], DELTA);
    delete [] result;  // heap allocation in 'scale'
}
TEST(VectorTest, scale_interger) {
    double u[3] = {2, 4, 5};
    double * result = scale(u, 3, 6);
    ASSERT_EQ(12, result[0]);
    ASSERT_EQ(24, result[1]);
    ASSERT_EQ(30, result[2]);
    delete [] result;   // heap allocation in 'scale'
}
TEST(VectorTest, scale_float) {
    double v[3] = {1.5, 3.5, 5.5};
    double * result = scale(v, 3, 2.2);
    ASSERT_NEAR(3.3, result[0], DELTA);
    ASSERT_NEAR(7.7, result[1], DELTA);
    ASSERT_NEAR(12.1, result[2], DELTA);
    delete [] result;   // heap allocation in 'scale'
}
TEST(VetorTest, scale_dimZeroNeg){
    double v[1]={2};//-1-dumesional vector is not exist,but vector_v need a value
    ASSERT_THROW(scale(v, -1, 3), std::string);
}