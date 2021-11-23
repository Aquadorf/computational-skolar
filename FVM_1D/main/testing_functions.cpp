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
} // Tested. Works correctly. 2021/11/14


// This function checks the equality of two 1D arrays of doubles to make sure they are within some epsilon
// It will output a same size array of booleans
// 0 means not equal
// 1 means equal
Array<bool,Dynamic,1> isEqualArray1D(ArrayXd &a, ArrayXd &b, double epsilon) {
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
} // Tested. Works correctly. 2021/11/16


// This function checks the equality of two 2D arrays of doubles to make sure they are within some epsilon
// It will output a same size array of booleans
// 0 means not equal
// 1 means equal
Array<bool,Dynamic,Dynamic> isEqualArray2D(ArrayXXd &a, ArrayXXd &b, double epsilon) {
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
} // Tested. Works correctly. 2021/11/16


// This function checks the equality of two 1D arrays of 1D arrays of doubles to make sure they are within some epsilon
// It will output a same size array of arrays of booleans
// 0 means not equal
// 1 means equal
Array<Array<bool,Dynamic,1>, 3, 1> isEqualArray1D_of_Array1D(Array<ArrayXd, 3, 1> &a, Array<ArrayXd, 3, 1> &b, double epsilon) {
    // This function assumes a and b have the same number of elements for each internal array    

    // Initialize the boolean array of arrays     
    Array<Array<bool,Dynamic,1>, 3, 1> testEquality;

    // We know that these arrays have a size of 3. 
    // Iterate through top array
    for (int i = 0; i < 3; i++) {
        // Can use the isEqualArray1D function for the internal arrays
        testEquality(i) = isEqualArray1D(a(i), b(i), epsilon);
    }
    return testEquality;
} // Tested. Works correctly. 2021/11/21
