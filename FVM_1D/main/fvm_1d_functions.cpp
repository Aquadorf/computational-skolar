#include <iostream>
#include <Eigen/Dense>
#include "fvm_1d_functions.h"

using namespace std;
using namespace Eigen;

// This function calculates the cell centered grid
ArrayXd makeGrid(int totalNCells, int numGhost, double xLeft, double dx) {
    // Create a uniform Cartesian mesh for x based on cell centers
    ArrayXd x(totalNCells);
    
    // Iterate through the total number of cells.
    // Note we are including ghost cells so the actual limits of this grid are larger than
    // the bounds set by xLeft and xRight 
    for (int i = 0; i < totalNCells; i++) {
        x(i) = (i - numGhost) * dx + (xLeft + dx / 2.);
    }
    return x;
} // Tested. Works correctly. 2021/11/18

// This function calculates conservative variables based on primitive variables for the 1D Euler equations
void prim2cons(double gasGamma, Array<ArrayXd, 3, 1> &prim, Array<ArrayXd, 3, 1> &cons) {
    // See documentation for how conversions are derived
    cons(0) = prim(0);
    cons(1) = prim(0) * prim(1);
    cons(2) = prim(2)/(gasGamma-1.0) + 0.5*prim(0)*prim(1)*prim(1);
} // Tested. Works correctly. 2021/11/21

// This function calculates the primitive variables based on the conservative variables for the 1D Euler equations
void cons2prim(double gasGamma, Array<ArrayXd, 3, 1> &cons, Array<ArrayXd, 3, 1> &prim) {
    // See documentation for how conversions are derived
    prim(0) = cons(0);
    prim(1) = cons(1) / cons(0);
    prim(2) = (gasGamma - 1.) * (cons(2) - 0.5 * cons(1)*cons(1)/cons(0) );
} // Tested. Works correctly. 2021/11/22

// Compute the time step based on the max speed in the system
double computeTimeStep(double CFL, double dx, double gasGamma, Array<ArrayXd, 3, 1> &prim) {
    // This is several calculations done in one go
    // The denominator is the maximum eigenvalue
    // For the Euler 1D equations, this is |u|+a 
    // where a=(gasGamma*p/rho)^.5 is the sound speed
    // The time step is determined by dividing dx by the maximum eigenvalue
    // This value is multiplied by the CFL number to ensure numerical stability    
    return CFL * dx / (abs(prim(1)) + pow(gasGamma*prim(2)/prim(0),0.5)).maxCoeff();
}



// This is the big function that runs the entire simulation based on all of the other functions
void runSimulation(double gasGamma, int maxIter, int nCells, \
    int numGhost, double xLeft, double xRight) {

    

    // Set boundary conditions

    // Initialize other variables important in main time integration loop

    // Start main time loop

    

    // Iterate through time
    for (int i = 0; i < maxIter; i++) {
        
        // Calculate fastest speed

        // Calculate time step

        // Do SSPRK loop (review 4 stage SSPRK3 method). Think about ways to do it nicely in loop

        for (int stage = 0; stage < 4; stage++) {            

            // Do stuff here in the RK loop


        }



    }

    
}

