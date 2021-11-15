# This shell script runs the main simulation 

# Set the directory Eigen is stored in
eigenDirectory="../../../eigen-3.4.0/"

# CD into directory where the code is
cd main

# Compile code. Save output file in upper directory
g++ -I $eigenDirectory main.cpp fvm_1d_functions.cpp -o ../sim.out

# Go back into upper directory. 
cd ..

# Run the simulation
./sim.out