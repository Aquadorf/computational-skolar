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

// This function checks the equality of two 1D arrays of doubles to make sure they are within some epsilon
// It will output a same size array of booleans
// 0 means not equal
// 1 means equal
Array<bool,Dynamic,1> isEqualArray1D(ArrayXd a, ArrayXd b, double epsilon) {
    // Get the size of a
    // This function assumes a and b have the same number of elements
    int N = a.size();
    
    // Initialize boolean array
    Array<bool,Dynamic,1> testEquality(N);

    // Iterate through entire array
    // Use isEqualDouble function to determine if each individual element is equal in the double sense
    for (int i = 0; i < N; i++){
        testEquality(i) = isEqualDouble( a(i), b(i), epsilon );
    }
    return testEquality;
}


// This function checks the equality of two 2D arrays of doubles to make sure they are within some epsilon
// It will output a same size array of booleans
// 0 means not equal
// 1 means equal
Array<bool,Dynamic,Dynamic> isEqualArray2D(ArrayXXd a, ArrayXXd b, double epsilon) {
    // Get the size of a
    // This function assumes a and b have the same number of elements
    int NR = a.rows();
    int NC = a.cols();
    
    // Initialize boolean array
    Array<bool,Dynamic,Dynamic> testEquality(NR,NC);

    // Iterate through entire array
    // Use isEqualDouble function to determine if each individual element is equal in the double sense
    for (int i = 0; i < NR; i++){
        for (int j = 0; j < NC; j++){
            testEquality(i,j) = isEqualDouble( a(i,j), b(i,j), epsilon );
        }        
    }
    return testEquality;
}

