#include <iostream>
#include "matrix.hpp"

using namespace std;

int main() {


    Matrix m1(1,2);
    m1.set_value(0, 0, 1);
    m1.set_value(0, 1, 2);

    Matrix m2(2,3);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            m2.set_value(i, j, i+j);
        }
    }

    cout << m1 << endl;

    cout << m2 << endl;

    Matrix m3 = m1 * m2;

    cout << m3 << endl;


    return 0;
}