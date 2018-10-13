#include <iostream>
#include "Matrix.hpp"
#include "ConnectivityMatrix.hpp"

using namespace std;

int main() {


    vector<double> a = {0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0};
    ConnectivityMatrix m(a);

    m.runAlgorithm();

    return 0;
}