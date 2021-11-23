// Unit test for the isEqualArray1D function in testing_functions.cpp
// This function determines if each element in two 1D arrays are equal within some tolerance
// This is important because there is inherent error in double precision numbers
// COMPLETE. This function works as intended. 2021/11/16


// Include headers
#include <iostream>
#include <Eigen/Dense>
#include "../main/fvm_1D_functions.h" 
#include "../main/testing_functions.h" 

using namespace std;
using namespace Eigen;

int main() {

    // Print what we are doing
    cout << "------------------------------------- " << \
    "This is a test of the isEqualArray1D function." << \
    " -------------------------------------" << endl;    

    // Set a tolerance
    double TOL = 1e-10;

    // Set an array of values
    ArrayXd vals(4);
    vals.setConstant(1.1);        

    // We can test 4 different modes of this function to determine how well it works:
    // Greater and within tolerance
    // Greater and outside tolerance
    // Lower and within tolerance
    // Lower and outside tolerance

    // Build the test array
    ArrayXd testArray(4);
    testArray(0) = vals(0) + 0.1*TOL;
    testArray(1) = vals(1) + 1.1*TOL;
    testArray(2) = vals(2) - 0.1*TOL;
    testArray(3) = vals(3) - 1.1*TOL;

    // Use the isEqualArray1D function to see if these are equal.
    Array<bool,Dynamic,1> boolArray = isEqualArray1D(vals, testArray, TOL);

    // First, we will test to make sure that val+0.1*TOL is considered equal since it will by definition be within the tolerance
    // This should result in 1
    if (boolArray(0) == 1) {  // 
        cout << "Test of higher but within tolerance is a success." << endl;
    } 
    else {
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl \
        << "Test of higher but within tolerance is a failure." << endl \
        << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    }

    // Test to make sure that val+1.1*TOL is not considered equal since it will by definition be outside the tolerance
    // This should result in 0
    if (boolArray(1) == 0) {  // 
        cout << "Test of higher over tolerance is a success." << endl;
    } 
    else {        
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl \
        << "Test of higher over tolerance is a failure." << endl \
        << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    }   

    // Test to make sure that val-0.1*TOL is considered equal since it will by definition be within the tolerance
    // This should result in 1
    if (boolArray(2) == 1) {  // 
        cout << "Test of lower but within tolerance is a success." << endl;
    } 
    else {
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl \
        << "Test of lower but within tolerance is a failure." << endl \
        << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    } 

    // Test to make sure that val-1.1*TOL is not considered equal since it will by definition be outside the tolerance
    // This should result in 0
    if (boolArray(3) == 0) {  // 
        cout << "Test of lower but outside tolerance is a success." << endl;
    } 
    else {
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl \
        << "Test of lower but outside tolerance is a failure." << endl \
        << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    } 

    cout << endl << endl;
}