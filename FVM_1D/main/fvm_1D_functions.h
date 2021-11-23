

#ifndef  FVM_1D_functions_H
#define FVM_1D_functions_H


#include <Eigen/Dense>


using namespace Eigen;


ArrayXd makeGrid(int totalNCells, int numGhost, double xLeft, double dx);
void prim2cons(double gasGamma, Array<ArrayXd, 3, 1> &prim, Array<ArrayXd, 3, 1> &cons);
void cons2prim(double gasGamma, Array<ArrayXd, 3, 1> &cons, Array<ArrayXd, 3, 1> &prim);
double computeTimeStep(double CFL, double dx, double gasGamma, Array<ArrayXd, 3, 1> &prim);
void runSimulation(double gasGamma, int maxIter, int nCells, \
    int numGhost, double xLeft, double xRight);



#endif