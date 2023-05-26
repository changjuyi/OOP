#include <string>
#include "../src/dot.h"

// A single test case has the following form:
//
// TEST(TestSuiteName, TestName) {
//   ... test body ...
// }
//dot(double *u, int dim_u, double *v, int dim_v)
TEST(two_dimesional_vector_int, result){ 
    double v[2]={4,5};
    double u[2]={3,7};
    double *vector_v = v;
    double *vector_u = u;
    double output = dot(vector_v, 2, vector_u, 2);
    double compare = 47;
    ASSERT_EQ(output, compare);
}
TEST(two_dimesional_vector_float, result){ 
    double v[2]={4.5,5.6};
    double u[2]={3.7,7.3};
    double *vector_v = v;
    double *vector_u = u;
    double output = dot(vector_v, 2, vector_u, 2);
    double compare = 57.53;
    ASSERT_NEAR(output, compare, 0.3f);
}

TEST(three_dimesional_vector_int, result){ 
    double v[3]={1,3,-5};
    double u[3]={4,-2,-1};
    double *vector_v = v;
    double *vector_u = u;
    double output = dot(vector_v, 3, vector_u, 3);
    double compare = 3;
    ASSERT_EQ(output, compare);
}
TEST(three_dimesional_vector_float, result){ 
    double v[3]={4.5, 5.6, 7.8};
    double u[3]={3.7, 7.3, 6.4};
    double *vector_v = v;
    double *vector_u = u;
    double output = dot(vector_v, 3, vector_u, 3);
    double compare = 107.45;
    ASSERT_NEAR(output, compare, 0.3f);
}

TEST(ThreeDimesionalVectorDotFourDimesionVectorInt, result){
    double v[3]={1,3,-5};
    double u[4]={4,-2,-1,5};
    double *vector_v = v;
    double *vector_u = u;
    ASSERT_THROW(dot(vector_v, 3, vector_u, 4), std::string);
    
}
TEST(ThreeDimesionalVectorDotFourDimesionVectorFloat, result){
    double v[4]={2.3, 5.2, 3.6, 1.5};
    double u[3]={3.2, 2.5, 6.3};
    double *vector_v = v;
    double *vector_u = u;
    ASSERT_THROW(dot(vector_v, 4, vector_u, 3), std::string);
    
}

TEST(dim_v_pass_int, result){
    double v[1]={2};//-1-dumesional vector is not exist,but vector_v need a value
    double u[3]={3, 2, 6};
    double *vector_v = v;
    double *vector_u = u;
    ASSERT_THROW(dot(vector_v, -1, vector_u, 3), std::string);
    
}
TEST(dim_u_pass_float, result){
    double v[3]={2, 5, 8};
    double u[1]={3};//-1-dumesional vector is not exist,but vector_u need a value
    double *vector_v = v;
    double *vector_u = u;
    ASSERT_THROW(dot(vector_v, 3, vector_u, -1), std::string);
    
}
TEST(dim_v_dim_u_pass, result){
    double v[1]={2};//-1-dumesional vector is not exist,but vector_v need a value
    double u[1]={3};//-1-dumesional vector is not exist,but vector_u need a value
    double *vector_v = v;
    double *vector_u = u;
    ASSERT_THROW(dot(vector_v, -1, vector_u, -1), std::string);
    
}