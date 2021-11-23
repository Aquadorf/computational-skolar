// Unit test for the cons2prim function in fvm_1d_functions.cpp
// This function calculates the conservative variables based on the primitive variables for the 1D Euler equations
// COMPLETE. This function works as intended. 2021/11/21

#include <iostream>
#include <Eigen/Dense>
#include "../main/fvm_1D_functions.h" 
#include "../main/testing_functions.h" 

using namespace std;
using namespace Eigen;

int main() {
    
    // Print what we are doing
    cout << "------------------------------------- " << \
    "This is a test of the cons2prim function." << \
    " -------------------------------------" << endl;    

    // Set the input parameters to the cons2prim function
    double gasGamma = 5./3.;   // Use standard gasGamma of 5/3

    // Make an array of primitive variables such that there are two elements in each 1D array
    Array<ArrayXd, 3, 1> Q;
    Q(0) = ArrayXd::Zero(2) + 1.5;
    Q(1) = ArrayXd::Zero(2) + 3.15;
    Q(2) = ArrayXd::Zero(2) + 7.8075;

    // Set the exact values for the primitive variables
    Array<ArrayXd, 3, 1> V_exact;
    V_exact(0) = ArrayXd::Zero(2) + 1.5;
    V_exact(1) = ArrayXd::Zero(2) + 2.1;
    V_exact(2) = ArrayXd::Zero(2) + 3.0;

    // Initialize an array of conservative variables
    Array<ArrayXd, 3, 1> V;
    for (int var = 0; var < 3; var++ ) {
        V(var) = ArrayXd::Zero(2);
    }

    // Calculate what the conserved variables are
    cons2prim(gasGamma, Q, V);

    // Set the acceptable tolerance. (Somewhat arbitrarily chosen)
    double TOL = 1e-14;

    // Determine if the two arrays are equal
    Array<Array<bool,Dynamic,1>, 3, 1> boolArray = isEqualArray1D_of_Array1D(V, V_exact, TOL);

    // Get the minimum value of the boolean array.
    // If it is 0, then at least one value in this array is incorrect    
    for (int var = 0; var < 3; var++) {
        if (boolArray(var).minCoeff() == 0) {
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl \
        << "Test of cons2prim is a failure." << endl \
        << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        break;
        }
        else if (var == 2) {
            cout << "Test of cons2prim is a success." << endl;
        }
    }
 
    cout << endl << endl;
}