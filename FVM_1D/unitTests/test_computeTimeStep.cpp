// Unit test for the computeTimeStep function in fvm_1d_functions.cpp
// This function calculates the time step based on the fastest speed in the system, delta x, and the CFL number
// COMPLETE. This function works as intended. 2021/11/22

#include <iostream>
#include <Eigen/Dense>
#include "../main/fvm_1D_functions.h" 
#include "../main/testing_functions.h" 

using namespace std;
using namespace Eigen;

int main() {
    
    // Print what we are doing
    cout << "------------------------------------- " << \
    "This is a test of the computeTimeStep function." << \
    " -------------------------------------" << endl;    

    // Set the input parameters to the cons2prim function
    double gasGamma = 5./3.;   // Use standard gasGamma of 5/3
    double CFL = 0.9;          // Set CFL number
    double dx = 0.5;           // Set delta x

    // Make an array of primitive variables such that there are two elements in each 1D array
    Array<ArrayXd, 3, 1> V;
    V(0) = ArrayXd::Zero(2);
    V(0)(0) = 5.;
    V(0)(1) = 1.;
    V(1) = ArrayXd::Zero(2);
    V(1)(0) = 1.0;
    V(1)(1) = -0.2;
    V(2) = ArrayXd::Zero(2);
    V(2)(0) = 12.;
    V(2)(1) = 27./5.;

    // Set the exact value of the time step. Calculated by hand based on input values chosen
    double dt_exact = 0.140625;

    // Calculate the time step    
    double dt = computeTimeStep(CFL, dx, gasGamma, V);

    // Set the acceptable tolerance. (Somewhat arbitrarily chosen)
    double TOL = 1e-14;    

    // Determine if the two values are equal
    bool boolVal = isEqualDouble(dt, dt_exact, TOL);    

    // Get the minimum value of the boolean array.
    // If it is 0, then at least one value in this array is incorrect    
    if (boolVal == 1) {
        cout << "Test of computeTimeStep is a success." << endl;            
    }
    else  {
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl \
            << "Test of computeTimeStep is a failure." << endl \
            << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    }    
    cout << endl << endl;
}