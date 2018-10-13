//
// Created by benzh on 2018-10-05.
//

#ifndef C_ASSIGNMENT_1_MATRIX_HPP
#define C_ASSIGNMENT_1_MATRIX_HPP

#include <vector>
#include <iosfwd>

class Matrix {

    protected:
        std::vector<std::vector<double>> matrix;

    public:
        Matrix();
        Matrix(int n);
        Matrix(int r, int c);
        Matrix(std::vector<double> a);
        Matrix(const Matrix& m);
        ~Matrix();

        void set_value(int row, int col, double newValue);
        double get_value(int row, int col);
        void clear();
        friend std::ostream& operator <<(std::ostream& os, const Matrix& m);
        friend bool operator ==(const Matrix& m1, const Matrix& m2);
        friend bool operator !=(const Matrix& m1, const Matrix& m2);
        friend void swap(Matrix& m1, Matrix& m2);
        friend Matrix operator+(Matrix m1, const Matrix m2);
        friend Matrix operator-(Matrix m1, const Matrix m2);
        friend Matrix operator*(Matrix m1, const Matrix m2);
        Matrix& operator++();
        Matrix operator++(int);
        Matrix& operator--();
        Matrix operator--(int);
        Matrix& operator=(Matrix rhs);
        Matrix& operator+=(const Matrix& rhs);
        Matrix& operator-=(const Matrix& rhs);
        Matrix& operator*=(const Matrix& rhs);
};


#endif //C_ASSIGNMENT_1_MATRIX_HPP
