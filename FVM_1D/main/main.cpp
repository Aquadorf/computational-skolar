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
    

    // Set initial conditions based on Sod paper on shock tube simulations
    // See https://doi.org/10.1016/0021-9991(78)90023-2
    // The simulation is done in normalized units
    const double rhoLeft = 1.0;
    const double rhoRight = 0.125;
    const double uLeft = 0.0;
    const double uRight = 0.0;
    const double pLeft = 1.0;
    const double pRight = 0.1;

    // Set grid parameters
    const int nCells = 4;      // Number of cells in the domain. Note these set based on their cell centered values
    const int numGhost = 2;      // Number of ghost cells on either side of the domain
    
    // Set domain parameters
    const double xLeft = -2.5;   // Left boundary 
    const double xRight = 2.5;   // Right boundary


    // Above this is all input parameters. 
    // Below this is any calculation that is independent of the input parameters
    
    // Maybe put everything below this in some sort of "runSim" function?
    runSimulation(gasGamma, maxIter, nCells, numGhost, xLeft, xRight);
    // std::cout << "Hello World!" << endl;

    ArrayXXd test(2,3);

    test.setConstant(1.1);


    //test << 1.,2.,3.,4.,5.,6.,7.;

    cout << test.size() << endl;
    cout << test.rows() << endl;
    cout << test.cols() << endl;


    
}