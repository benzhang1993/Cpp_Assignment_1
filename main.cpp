#include <iostream>
#include "Matrix.hpp"
#include "ConnectivityMatrix.hpp"

using namespace std;

int main() {


    vector<double> a = {0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0};
    ConnectivityMatrix m(a);

    cout << m << endl;

    m.getImportanceMatrix();

    cout << m << endl;

    m.getStochasticMatrix();

    cout << m << endl;

    m.applyRandomWalk();

    cout << m << endl;

    return 0;
}