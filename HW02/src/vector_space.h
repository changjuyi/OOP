#ifndef VECTOR_SPACE_H
#define VECTOR_SPACE_H

#include <string>

// use array to represent the vector in mathematics
// e.g., let double u[2] = {1, 2}, v[2] = {3, 4},
//       then dot(u, 2, v, 2) = 11

double *add(double *u, int dim_u, double *v, int dim_v) {
    if (dim_u != dim_v || dim_u < 0 || dim_v < 0 || dim_v==0 || dim_u==0) {
        throw std::string("undefined");
    }
    double *result = new double[dim_u];
    for(int i=0 ; i<dim_u ; i++){
        result[i] = u[i] + v[i];
    }
    return result;
    
} 
double *scale(double *u , int dim_u , double a){
    if (dim_u < 0 || dim_u==0) {
        throw std::string("undefined");
    }
    double *result = new double[dim_u];
    for(int i=0 ; i<dim_u ; i++){
        result[i] = u[i] * a;
    }
    return result;
}
#endif // end of include guard: DOT_H