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
        x(i) = (i - numGhost) * dx + (xLeft + dx / 2);
    }
    return x;
}

// This is the big function that runs the entire simulation based on all of the other functions
void runSimulation(double gasGamma, int maxIter, int nCells, \
    int numGhost, double xLeft, double xRight) {

    // Calculate grid parameters
    const int nNodes = nCells + 1;  // There is one more node than there are cells
    const int totalNCells = nCells + 2*numGhost;   // Total number of cells, including ghost cells
    const int totalNNodes = totalNCells + 1; // Total number of nodes is one plus total number of cells

    // Calculate domain length
    const double L = xRight - xLeft; // Get total domain length
    
    // Calculate dx
    const double dx = L / nCells;

    // Make the cell centered grid
    ArrayXd x = makeGrid(totalNCells, numGhost, xLeft, dx);

    // Set initial conditions

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

