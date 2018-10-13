//
// Created by benzh on 2018-10-11.
//

#include "ConnectivityMatrix.hpp"



//void runAlgorithm() {
//    ConnectivityMatrix importanceMatrix = getImportanceMatrix();
//};

void ConnectivityMatrix::getImportanceMatrix() {
    for(int j = 0; j < matrix[0].size(); j++) {
        double rowTotal = 0;
        for(int i = 0; i < matrix.size(); i++) {
            rowTotal += matrix[i][j];
        }
        if(rowTotal != 0) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][j] /= rowTotal;
            }
        }
    }
};

void ConnectivityMatrix::getStochasticMatrix() {
    for(int j = 0; j < matrix[0].size(); j++) {
        double rowTotal = 0;
        for(int i = 0; i < matrix.size(); i++) {
            rowTotal += matrix[i][j];
        }
        if(rowTotal == 0) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][j] = 1.0/matrix[i].size();
            }
        }
    }
}

void ConnectivityMatrix::applyRandomWalk() {
    ConnectivityMatrix transitionMatrix(*this);
    for(int j = 0; j < matrix[0].size(); j++) {
        for(int i = 0; i < matrix.size(); i++) {
            transitionMatrix.matrix[i][j] = 1.0 / matrix.size() * randomWalkChance;
        }
    }

    for(int j = 0; j < matrix[0].size(); j++) {
        for(int i = 0; i < matrix.size(); i++) {
            matrix[i][j] *= followChance;
        }
    }

    this->Matrix::operator+=(transitionMatrix);
}

ConnectivityMatrix markovProcess();