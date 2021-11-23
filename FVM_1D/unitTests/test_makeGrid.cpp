// Unit test for the makeGrid function in fvm_1d_functions.cpp
// This function calculates a cell-centered grid
// COMPLETE. This function works as intended. 2021/11/18

#include <iostream>
#include <Eigen/Dense>
#include "../main/fvm_1D_functions.h" 
#include "../main/testing_functions.h" 

using namespace std;
using namespace Eigen;

int main() {
    
    // Print what we are doing
    cout << "------------------------------------- " << \
    "This is a test of the makeGrid function." << \
    " -------------------------------------" << endl;    

    // Set the input parameters to the makeGrid function
    // The goal is to make a cell centered grid such that the according nodal grid
    // has a left value of -1.5, a right boundary of 0.5, and a dx of 0.5.
    // This would give 4 cells within the domain with an additional 2 ghost cells on either side
    int totalNCells = 8;
    int numGhost = 2;
    double xLeft = -1.5;
    double dx = 0.5;

    // Set the exact values for the 1D grid
    ArrayXd x_Exact(8);
    x_Exact << -2.25, -1.75, -1.25, -.75, -.25, .25, .75, 1.25;

    // Calculate the values based on the function
    ArrayXd x = makeGrid(totalNCells, numGhost, xLeft, dx);

    // Set the acceptable tolerance. (Somewhat arbitrarily chosen)
    double TOL = dx*1e-14;

    // Determine if the two arrays are equal
    Array<bool, Dynamic, 1> boolArray = isEqualArray1D(x, x_Exact, TOL);

    // Print results
    if (boolArray.minCoeff() == 1) {
        cout << "Test of makeGrid is a success." << endl;
    }
    else {
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl \
        << "Test of makeGrid is a failure." << endl \
        << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    }

    cout << endl << endl;
}