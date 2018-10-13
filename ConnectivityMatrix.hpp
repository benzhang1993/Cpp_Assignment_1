//
// Created by benzh on 2018-10-11.
//

#ifndef C_ASSIGNMENT_1_CONNECTIVITYMATRIX_HPP
#define C_ASSIGNMENT_1_CONNECTIVITYMATRIX_HPP

#include "Matrix.hpp"

class ConnectivityMatrix : public Matrix{

    public:
        constexpr static double followChance = 0.85;
        constexpr static double randomWalkChance = 1 - followChance;
        ConnectivityMatrix():Matrix(){};
        ConnectivityMatrix(std::vector<double> a):Matrix(a){};

        void runAlgorithm();
        void getImportanceMatrix();
        void getStochasticMatrix();
        void applyRandomWalk();
        void markovProcess();

};


#endif //C_ASSIGNMENT_1_CONNECTIVITYMATRIX_HPP
