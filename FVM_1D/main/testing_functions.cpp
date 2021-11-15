#include <iostream>
#include <Eigen/Dense>
#include "testing_functions.h"

using namespace std;
using namespace Eigen;

// This function checks the equality of two doubles to make sure they are within some epsilon
// It will output a 0 or a 1. 
// 0 means not equal
// 1 means equal
bool isEqualDouble(double a, double b, double epsilon) {   // Works as intended. 2021/11/14
    return abs(a - b) <= epsilon;
}