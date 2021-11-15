// Unit test for the isEqualDouble function in testing_functions.cpp
// This function determines if two numbers are equal within some tolerance
// This is important because there is inherent error in double precision numbers
// COMPLETE. This function works as intended. 2021/11/14


// Include headers
#include <iostream>
#include <Eigen/Dense>
#include "../main/fvm_1D_functions.h" 
#include "../main/testing_functions.h" 

using namespace std;
using namespace Eigen;

int main() {

    // Print what we are doing
    cout << "-------------------------------------" << \
    "This is a test of the isEqualDouble function." << \
    "-------------------------------------" << endl;    

    // Set a tolerance
    double TOL = 1e-10;

    // Set some arbitrary value
    double val = 1.1;

    // We can test 4 different modes of this function to determine how well it works

    // First, we will test to make sure that val+0.1*TOL is considered equal since it will by definition be within the tolerance
    bool higher_within_TOL = isEqualDouble(val, val + 0.1*TOL, TOL);   // This should result in 1
    if (higher_within_TOL == 1) {  // 
        cout << "Test of higher but within tolerance is a success." << endl;
    } 
    else {
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl \
        << "Test of higher but within tolerance is a failure." << endl \
        << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    }

    // Test to make sure that val+1.1*TOL is not considered equal since it will by definition be outside the tolerance
    bool higher_over_TOL = isEqualDouble(val, val + 1.1*TOL, TOL);   // This should result in 0
    if (higher_over_TOL == 0) {  // 
        cout << "Test of higher over tolerance is a success." << endl;
    } 
    else {        
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl \
        << "Test of higher over tolerance is a failure." << endl \
        << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    }   

    // Test to make sure that val-0.1*TOL is considered equal since it will by definition be within the tolerance
    bool lower_within_TOL = isEqualDouble(val, val - 0.1*TOL, TOL);   // This should result in 1
    if (lower_within_TOL == 1) {  // 
        cout << "Test of lower but within tolerance is a success." << endl;
    } 
    else {
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl \
        << "Test of lower but within tolerance is a failure." << endl \
        << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    } 

    // Test to make sure that val-1.1*TOL is not considered equal since it will by definition be outside the tolerance
    bool lower_less_TOL = isEqualDouble(val, val - 1.1*TOL, TOL);   // This should result in 0
    if (lower_less_TOL == 0) {  // 
        cout << "Test of lower but outside tolerance is a success." << endl;
    } 
    else {
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl \
        << "Test of lower but outside tolerance is a failure." << endl \
        << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    } 

    cout << endl << endl;



}