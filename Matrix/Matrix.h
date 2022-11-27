#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Matrix{
    private:
        size_t rows;
        size_t cols;
        double** matrix;
    public:
        Matrix(size_t rows, size_t cols);
        Matrix(const Matrix& m);
        ~Matrix();
        size_t getRows() const;
        size_t getCols() const;
        double** getMatrix() const;
        void setRows(size_t rows);
        void setCols(size_t cols);
        void setMatrix(double** matrix);
        Matrix operator+(const Matrix& m) const;
        Matrix operator-(const Matrix& m) const;
        Matrix operator*(const Matrix& m) const;
        Matrix operator=(const Matrix& m);
        Matrix operator+=(const Matrix& m);
        Matrix operator-=(const Matrix& m);
        Matrix operator*=(const Matrix& m);
        double& operator()(size_t i, size_t j);
        bool operator==(const Matrix& m) const;
        bool operator!=(const Matrix& m) const;
        friend ostream& operator<<(ostream& os, const Matrix& m);
};