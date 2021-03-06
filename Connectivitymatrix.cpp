//
// Created by benzh on 2018-10-11.
//

#include "Connectivitymatrix.hpp"
#include <iostream>
#include <iomanip>

/**
 * Runs the google page rank algorithms
 */
void ConnectivityMatrix::runAlgorithm() {
    getImportanceMatrix();
    getStochasticMatrix();
    applyRandomWalk();
    markovProcess();
    printResult();
};

/**
 * Calculates the importance matrix by dividing each col by col total
 */
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

/**
 * Calculates stochastic matrix by setting 0 cols to 1/n
 */
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

/**
 * Applies random walk by multiplying non 0 cols by 0.85 and 0 cols by 0.15
 */
void ConnectivityMatrix::applyRandomWalk() {
    /**
     * Why can I call this without declaring it in header?
     */
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

/**
 * Applies the Markov Process
 */
void ConnectivityMatrix::markovProcess() {
    /**
     * Initialize Rank Matrix
     */
    Matrix newRankMatrix(matrix.size(), 1);
    for(int j = 0; j < newRankMatrix.getMatrix()[0].size(); j++) {
        for(int i = 0; i < newRankMatrix.getMatrix().size(); i++) {
            newRankMatrix.set_value(i, j, 1);
        }
    }

    /**
     * Recursively multiply Rank matrix until it remains constant
     */
    Matrix oldRankMatrix;
    while (newRankMatrix != oldRankMatrix) {
        oldRankMatrix = newRankMatrix;
        Matrix tempMatrix(*this);
        newRankMatrix = tempMatrix * oldRankMatrix;
    }

    /**
     * Divide each row element by the total Rank
     */
    for(int j = 0; j < newRankMatrix.getMatrix()[0].size(); j++) {
        double totalRank = 0;
        for(int i = 0; i < newRankMatrix.getMatrix().size(); i++) {
            totalRank += newRankMatrix.get_value(i, j);
        }
        for(int i = 0; i < newRankMatrix.getMatrix().size(); i++) {
            newRankMatrix.set_value(i, j, newRankMatrix.get_value(i, j)/totalRank);
        }
    }

    this->matrix = newRankMatrix.getMatrix();
}

/**
 * Prints the results in percentage with 2 decimal places
 */
void ConnectivityMatrix::printResult() {
    int ascii = 65;
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            std::cout << "Page " << (char) ascii << ": " << std::fixed << std::setprecision(2) << matrix[i][j]*100 << "%" << std::endl;
            ascii++;
        }
    }
}