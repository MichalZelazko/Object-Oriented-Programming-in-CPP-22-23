#include <iostream>
#include <string>
#include <math.h>

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
        Matrix(const Matrix& m);
        ~Matrix();
        size_t getRows() const;
        size_t getCols() const;
        double** getMatrix() const;
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

struct Matrix::MatrixData{
    size_t rows;
    size_t cols;
    double** matrix;
    size_t refCount;
    
    MatrixData(size_t newRows = 1, size_t newCols = 1){
        rows = newRows;
        cols = newCols;
        refCount = 1;
        matrix = new double*[rows];
        for(size_t i = 0; i <= rows; i++){
            this->matrix[i] = new double[cols]
        }
    }
    
    ~MatrixData(){
        for(size_t i = 0; i <= rows; i++){
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    
    MatrixData* detach(){
        if(refCount == 1){
            return this;
        }
        //do skonczenia
    }
}
