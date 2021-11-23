

#ifndef  test_functions_H
#define test_functions_H

#include <Eigen/Dense>
using namespace Eigen;


bool isEqualDouble(double a, double b, double epsilon);
Array<bool,Dynamic,1> isEqualArray1D(ArrayXd &a, ArrayXd &b, double epsilon);
Array<bool,Dynamic,Dynamic> isEqualArray2D(ArrayXXd &a, ArrayXXd &b, double epsilon);
Array<Array<bool,Dynamic,1>, 3, 1> isEqualArray1D_of_Array1D(Array<ArrayXd, 3, 1> &a, Array<ArrayXd, 3, 1> &b, double epsilon);

#endif