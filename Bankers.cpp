#include "Bankers.hpp"



int main() {

    //initalize the arrays and variables for the project
    int numProcesses, numResources;
    std::vector <std::vector<int> > max;
    std::vector <std::vector<int> > allocation;
    std::vector <std::vector<int> > need;
    std::vector <int> available;

    // Read input from file (assuming "input.txt")
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
       std::cerr << "Error opening input file." << std::endl;
       return 1;
    }

    //read in inputFile
    inputFile >> numProcesses >> numResources;
    //resize all of the vectors so They can be used
    allocation.resize(numProcesses, std::vector<int>(numResources));
    max.resize(numProcesses, std::vector<int>(numResources));
    need.resize(numProcesses, std::vector<int>(numResources));
    available.resize(numResources);

    // collect the available resources
    for (int i = 0; i < numResources; i++) {
            inputFile >> available[i];
    }
    // read max matrix
    for(int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            inputFile >> max[i][j];
        }
    }
    // Read allocation matrix
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            inputFile >> allocation[i][j];
        }
    }


    inputFile.close();


    // Calculate the need matrix
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // initialze a vector to store the safe Sequence of processes
std::vector<int> safeSequence;

// loop through the processes to find the safe sequence
for (int l = 0; l < numProcesses; l++) {
    for (int i = 0; i < numProcesses; i++) {
        //if the process is already in the safe sequence skip it
        if(std::find(safeSequence.begin(), safeSequence.end(), i) != safeSequence.end()){
            continue;
        }
        // check if the process can be allocated
        for (int j = 0; j < numResources; j++) {
            //If the process can't be allocated break no need to check the rest of the resources
            if (available[j] < need[i][j]) {
                break;
            }
            //If the process can be allocated push it into the safe sequence
            else if (j == numResources -1){
                safeSequence.push_back(i);
                for (int k = 0; k < numResources; k++) {
                    available[k] += allocation[i][k];
                }
                break;
            }
        }
    }
}

    //if the safeSequence is not the same size as the number of processes then the system is not in a safe state
    if (safeSequence.size() != numProcesses) {
        std::cout << "System is not in safe state" << std::endl;
    }
    //if the safeSequence is the same size as the number of processes then the system is in a safe state
    else {
        std::cout << "System is in safe state safe sequence is: " << std::endl;
        for(int l = 0; l < safeSequence.size(); l++) {
            std::cout << safeSequence[l] << std::endl;
        }
    }

return 0;
}
