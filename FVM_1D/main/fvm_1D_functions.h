

#ifndef  FVM_1D_functions_H
#define FVM_1D_functions_H


#include <Eigen/Dense>


using namespace Eigen;


ArrayXd makeGrid(int totalNCells, int numGhost, double xLeft, double dx);
void runSimulation(double gasGamma, int maxIter, int nCells, \
    int numGhost, double xLeft, double xRight);



#endif