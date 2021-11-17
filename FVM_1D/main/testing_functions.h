

#ifndef  test_functions_H
#define test_functions_H

#include <Eigen/Dense>
using namespace Eigen;


bool isEqualDouble(double a, double b, double epsilon);
Array<bool,Dynamic,1> isEqualArray1D(ArrayXd a, ArrayXd b, double epsilon);
Array<bool,Dynamic,Dynamic> isEqualArray2D(ArrayXXd a, ArrayXXd b, double epsilon);

#endif