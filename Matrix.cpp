//
// Created by benzh on 2018-10-05.
//

#include "Matrix.hpp"
#include <cmath>
#include <iostream>

/**
 * Initialize matrix to 1x1 with default value 0.0
 */
Matrix::Matrix(){
    matrix = {1, std::vector<double>(1, 0.0)};
}

/**
 * Initialize square matrix to nxn size with default value 0.0
 * @param n row and column size of the matrix
 */
Matrix::Matrix(int n){
    if(n <= 0) {
        throw "Positive Integers Expected";
    }
    matrix = {(unsigned long)n, std::vector<double>(n, 0.0)};
}

/**
 * Initialize matrix to rxc size with default value 0.0
 * @param r row of matrix
 * @param c colum nof matrix
 */
Matrix::Matrix(int r, int c){
    if(r <= 0 || c <= 0){
        throw "Positive Integers for Row and Column Expected";
    }
    matrix = {(unsigned long)r, std::vector<double>(c, 0.0)};
}

/**
 * Initialize matrix with a vector list
 * @param a vector list
 */
Matrix::Matrix(std::vector<double> a){
    if(sqrt(a.size()) == (int) sqrt(a.size())){
        matrix = {(unsigned long) sqrt(a.size()), std::vector<double>(sqrt(a.size()), 0.0)};
        int index = 0;
        for(int i = 0; i < sqrt(a.size()); i++) {
            for(int j = 0; j < sqrt(a.size()); j++) {
                matrix[i][j] = a[index];
                index++;
            }
        }
    }
    else {
        throw "Input vector must have size  with integer square root. i.e. 1x1, 2x2, 3x3...";
    }
}

/**
 * Copy constructor
 * @param m matrix to copy
 */
Matrix::Matrix(const Matrix& m) {
    this->matrix = m.matrix;
}

/**
 * Sets value of an index of matrix
 * @param row row index
 * @param col column index
 * @param newValue value to set
 */
void Matrix::set_value(int row, int col, double newValue) {
    if(row < 0 || row >= matrix.size()) {
        throw "Row must be less than 0 and less or equal to the size - 1";
    }
    else {
        if(col < 0 || col >= matrix[row].size()) {
            throw "Column must be less than 0 and less or equal to the size - 1";
        }
    }

    matrix[row][col] = newValue;
}

/**
 * Gets value at matrix index
 * @param row row index
 * @param col column index
 * @return value at index
 */
double Matrix::get_value(int row, int col) {
    if(row < 0 || row >= matrix.size()) {
        throw "Row must be less than 0 and less or equal to the size - 1";
    }
    else {
        if(col < 0 || col >= matrix[row].size()) {
            throw "Column must be less than 0 and less or equal to the size - 1";
        }
    }

    return matrix[row][col];
}

/**
 * Clears the matrix content to 0.0
 */
void Matrix::clear(){
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            matrix[i][j] = 0.0;
        }
    }
}

/**
 * Destructor, set to empty to let compiler handle it
 */
Matrix::~Matrix() {
}

/**
 * Overloaded insertion operator to print out content of matrix
 */
std::ostream& operator <<(std::ostream& os, const Matrix& m) {
    for(int i = 0; i < m.matrix.size(); i++) {
        for(int j = 0; j < m.matrix.at(i).size(); j++) {
            os << m.matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

/**
 * Overloaded equality operator to compare two Matrices
 * @param m1 Matrix 1
 * @param m2 Matrix 2
 * @return whether 2 matrices are same size and have same content to a precision of 0.0001
 */
bool operator ==(const Matrix& m1, const Matrix& m2) {
    if(m1.matrix.size() != m2.matrix.size()) {
        return false;
    }

    double TOLERANCE = 0.0001;

    for(int i = 0; i < m1.matrix.size(); i++) {
        if(m1.matrix[i].size() != m2.matrix[i].size()){
            return false;
        }
        for(int j = 0; j < m1.matrix[i].size(); j++) {
            if(fabs(m1.matrix[i][j] - m2.matrix[i][j]) > TOLERANCE) {
                return false;
            }
        }
    }

    return true;
}

/**
 * Overloaded not equals operator for 2 matrices
 */
bool operator !=(const Matrix& m1, const Matrix& m2) {
    return !(m1 == m2);
}

/**
 * Overloaded increment operator to increment matrix values by 1
 * @return pointer to the incremented matrix
 */
Matrix& Matrix::operator++() {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            matrix[i][j]++;
        }
    }
    return *this;
}

/**
 * Overloaded post-increment operator
 */
Matrix Matrix::operator++(int) {
    Matrix tmp(*this);
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            matrix[i][j]++;
        }
    }
    return tmp;
}

/**
 * Overloaded decrement operator to decrease matrix content by 1
 * @return decremented matrix
 */
Matrix& Matrix::operator--() {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            matrix[i][j]--;
        }
    }
    return *this;
}

/**
 * Overloaded post decrement operator
 */
Matrix Matrix::operator--(int){
    Matrix tmp(*this);
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            matrix[i][j]--;
        }
    }
    return tmp;
}

/**
 * Overloaded assignment operator
 */
Matrix& Matrix::operator=(Matrix rhs) {
    swap(*this, rhs);
    return *this;
}

/**
 * Swap function to swap the content of 2 matrices
 */
void swap(Matrix& m1, Matrix& m2) {
    using std::swap;
    swap(m1.matrix, m2.matrix);
}

/**
 * Overloaded addition operator to add the content of 2 matrices
 */
Matrix operator+(Matrix m1, const Matrix m2){
    m1 += m2;
    return m1;
}

/**
 * Overloaded addition/equal operator to add the content of 2 matrices
 */
Matrix& Matrix::operator+=(const Matrix& rhs) {
    if(this->matrix.size() != rhs.matrix.size()) {
        throw "Matrix sizes must be the same";
    }
    for(int i = 0; i < this->matrix.size(); i++) {
        if(this->matrix[i].size() != rhs.matrix[i].size()) {
            throw "Matrix sizes must be the same";
        }
        for(int j = 0; j < this->matrix[i].size(); j++) {
            this->matrix[i][j] += rhs.matrix[i][j];
        }
    }
    return *this;
}

/**
 * Overloaded decrement operator
 */
Matrix operator-(Matrix m1, const Matrix m2){
    m1 -= m2;
    return m1;
}

/**
 * Overloaded decrement/equals operator
 */
Matrix& Matrix::operator-=(const Matrix& rhs) {
    if(this->matrix.size() != rhs.matrix.size()) {
        throw "Matrix sizes must be the same";
    }
    for(int i = 0; i < this->matrix.size(); i++) {
        if(this->matrix[i].size() != rhs.matrix[i].size()) {
            throw "Matrix sizes must be the same";
        }
        for(int j = 0; j < this->matrix[i].size(); j++) {
            this->matrix[i][j] -= rhs.matrix[i][j];
        }
    }
    return *this;
}

/**
 * Overloaded multiplication operator
 */
Matrix operator*(Matrix m1, const Matrix m2){
    m1 *= m2;
    return m1;
}

/**
 * Overloaded multiplication/equals operator
 */
Matrix& Matrix::operator*=(const Matrix& rhs) {
    if(this->matrix[0].size() != rhs.matrix.size()) {
        throw "Number of columns of left Matrix must be equal to number of rows of right Matrix.";
    }
    Matrix newMatrix(this->matrix.size(), rhs.matrix[0].size());
    for(int i = 0; i < this->matrix.size(); i++) {
        for(int j = 0; j < rhs.matrix[0].size(); j++) {
            for(int k = 0; k < this->matrix[i].size(); k++) {
                newMatrix.matrix[i][j] += this->matrix[i][k] * rhs.matrix[k][j];
            }
        }
    }
    this->matrix = newMatrix.matrix;
    return *this;
}

/**
 * Gets the matrix 2D vector
 */
std::vector<std::vector<double>> Matrix::getMatrix() {
    return matrix;
}





