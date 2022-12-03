#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

class IncompatibleMatrixDimensionsException : public std::exception {
    public:
        const char * what () const throw() {
            return "Matrices are of incompatible sizes";
        }
};

class InvalidMatrixIndexException : public std::exception {
    public:
        const char * what () const throw() {
            return "Index out of matrix's bounds";
        }
};

class Matrix{
    private:
        struct MatrixData;
        MatrixData* data;
    public:
        Matrix(size_t rows = 1, size_t cols = 1);
        Matrix(string fileName);
        Matrix(const Matrix& m);
        ~Matrix();
        size_t getRows() const;
        size_t getCols() const;
        double** getMatrix() const;
        friend Matrix operator+(const Matrix& m1, const Matrix& m2);
        friend Matrix operator-(const Matrix& m1, const Matrix& m2);
        friend Matrix operator*(const Matrix& m1, const Matrix& m2);
        Matrix& operator=(const Matrix& m);
        Matrix& operator+=(const Matrix& m);
        Matrix& operator-=(const Matrix& m);
        Matrix& operator*=(const Matrix& m);
        double& operator()(size_t row, size_t col);
        double operator()(size_t row, size_t col) const;
        bool operator==(const Matrix& m) const;
        bool operator!=(const Matrix& m) const;
        friend ostream& operator<<(ostream& os, const Matrix& m);
};

struct Matrix::MatrixData{
    size_t rows;
    size_t cols;
    double** matrix;
    size_t refCount;

    MatrixData(size_t newRows, size_t newCols);
    ~MatrixData();
    MatrixData* detach();
};
