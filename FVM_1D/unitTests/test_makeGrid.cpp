// Unit test for the makeGrid function
// This function calculates a cell-centered grid

// This is the command needed to compile the code
// g++ -I ../../eigen-3.4.0/ main.cpp -o out.out 

#include <iostream>
#include <Eigen/Dense>
#include "../main/fvm_1D_functions.h" 
#include "../main/testing_functions.h" 

using namespace std;
using namespace Eigen;

int main() {

    // Set the input parameters to the makeGrid functions
    // The goal is to make a cell centered grid such that the according nodal grid
    // has a left value of -1.5, a right boundary of 0.5, and a dx of 0.5.
    // This would give 4 cells within the domain with an additional 2 ghost cells on either side

    int totalNCells = 8;
    int numGhost = 2;
    double xLeft = -1.5;
    double dx = 0.5;

    ArrayXd x_Exact(8);
    x_Exact << -2.25, -1.75, -1.25, -.75, -.25, .25, .75, 1.25;


    ArrayXd x = makeGrid(totalNCells, numGhost, xLeft, dx);

    cout << isEqualDouble(1.1,2,.1) << endl;

}