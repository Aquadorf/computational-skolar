# This shell script runs the main simulation 

# CD into directory where the testing scripts are
cd unitTests

eigenDirectory="../../../eigen-3.4.0/"

for test in *.cpp
do    
    # Get the length of the string.
    # This is used to get the base name of the files for all of the test scripts
    len=`expr length "$test"`

    # Compile the code for each test function
    g++ -I $eigenDirectory $test ../main/fvm_1d_functions.cpp ../main/testing_functions.cpp -o ${test:0:($len-4)}.out    

    ./${test:0:($len-4)}.out

done


# Go back into upper directory. 
cd ..
