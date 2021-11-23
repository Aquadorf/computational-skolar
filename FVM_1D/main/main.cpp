// Some sort of comment up top describing the code
// This is a 1D Euler equation solver using the finite volume method
// Uses MUSCL scheme
// Think about what I want to use for time integration. 

// This is the command needed to compile the code
// g++ -I ../../../eigen-3.4.0/ main.cpp fvm_1d_functions.cpp -o runSim.out && ./runSim.out

#include <iostream>
#include <Eigen/Dense>
#include "fvm_1D_functions.h" 

using namespace std;
using namespace Eigen;

int main() {
    
    // Set physical constants
    const double gasGamma = 5./3.;

    // Set important constants for code
    const int maxIter = 100;            // The maximum number of iterations 
    const double CFL = 0.9;             // Set CFL number

    // Set grid parameters
    const int nCells = 4;      // Number of cells in the domain. Note these set based on their cell centered values
    const int numGhost = 2;      // Number of ghost cells on either side of the domain

    // Set domain parameters
    const double xLeft = 0;   // Left boundary 
    const double xRight = 1;   // Right boundary

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

    // Set initial conditions based on Sod paper on shock tube simulations
    // See https://doi.org/10.1016/0021-9991(78)90023-2
    // The simulation is done in normalized units    
    // The initial states are presented in primitive variables (rho, u, p)  
    Array3d leftStates;
    leftStates << 1.0, 0.0, 1.0;
    Array3d rightStates;
    rightStates << 0.125, 0.0, 0.1;

    // Set initial shock location
    double x0 = 0.5;
    
    // Initialize an array of primitive variables
    Array<ArrayXd, 3, 1> V;
    
    // There is an interface at some x0
    // To the left is one set of states, to the right is another set of states  
    // Loop through the variables
    for (int var = 0; var < 3; var++) {
        // Initialize an array of zeros
        V(var) = ArrayXd::Zero(totalNCells);

        // Iterate through x
        for (int i = 0; i < totalNCells; i++) {
            // If we are less than x0, then the IC is the left state. 
            // Note that this is a simplified IC in that it will move the initial shock location based on the resolution. This should have a minimal impact on sufficiently resolved sims
            if (x(i) <= x0) {
                V(var)(i) = leftStates(var);
            }
            else {
                V(var)(i) = rightStates(var);
            }
        }
    }

    // Maybe think about a way to specify what BCs to use here.     

    // Initialize the conserved variables
    Array<ArrayXd, 3, 1> Q;
    for (int var = 0; var < 3; var++) {
        // Initialize an array of zeros
        Q(var) = ArrayXd::Zero(totalNCells);
    }

    // Calculate the conserved variables based on the primitive variables
    prim2cons(gasGamma, V, Q);

    // Next, start populating the run sim function
    // Choose which ode solver to use and figure out a nice way to do the time integration as a loop
    // Look into SSPRK methods. maybe 4 stage 3rd order? Gets us a nice CFL condition

    // Think about how I want to setup my variables. Do I use rho, u, p or one big variable? Maybe the big variable is the way to go? 
    // Each conservation law is the same general idea, just the values internally will be different
    
    // Maybe put everything below this in some sort of "runSim" function?
    //runSimulation_FVM1D(gasGamma, maxIter, nCells, numGhost, xLeft, xRight);
    // std::cout << "Hello World!" << endl;


    Array<ArrayXd, 3, 1> test;
    
    test(0) = ArrayXd::Zero(5) + 5.;
    test(1) = ArrayXd::Zero(5) + 1.;
    test(2) = ArrayXd::Zero(5) + 2.;

    //test.setConstant(1.1);


    

    cout << CFL * dx / (abs(V(1)) + pow(gasGamma*V(2)/V(0),0.5)).minCoeff() << endl;
   
    


    
}