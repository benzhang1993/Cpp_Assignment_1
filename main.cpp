#include <iostream>
#include "Matrix.hpp"
#include "Connectivitymatrix.hpp"
#include <fstream>

using namespace std;

int main() {

    /**
     * Open file
     */
    ifstream inFile;
    inFile.open("connectivity.txt");
    if(!inFile) {
        cerr << "Unable to open file.";
        exit(1);
    }

    /**
     * Read file
     */
    int buffer;
    vector<double> a;
    while(inFile >> buffer) {
        a.push_back(buffer);
    }

    /**
     * Construct google page rank algorithm matrix
     */
    ConnectivityMatrix m(a);

    /**
     * Runs algorithm
     */
    m.runAlgorithm();

    return 0;
}