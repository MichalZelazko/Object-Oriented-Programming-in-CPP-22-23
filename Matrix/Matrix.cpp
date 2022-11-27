#include "Matrix.h"

using namespace std;

Matrix::Matrix(size_t rows = 1, size_t cols = 1){
    this->rows = rows;
    this->cols = cols;
    this->matrix = new double*[rows];
    for(size_t i = 0; i < rows; i++){
        this->matrix[i] = new double[cols];
    }
}

Matrix::Matrix(const Matrix& m){
    this->rows = m.rows;
    this->cols = m.cols;
    this->matrix = new double*[rows];
    for(size_t i = 0; i < rows; i++){
        this->matrix[i] = new double[cols];
    }
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            this->matrix[i][j] = m.matrix[i][j];
        }
    }
}

Matrix::~Matrix(){
    for(size_t i = 0; i < rows; i++){
        delete[] this->matrix[i];
    }
    delete[] this->matrix;
}

size_t Matrix::getRows() const{
    return this->rows;
}

size_t Matrix::getCols() const{
    return this->cols;
}

double** Matrix::getMatrix() const{
    return this->matrix;
}

void Matrix::setRows(size_t rows){
    this->rows = rows;
}

void Matrix::setCols(size_t cols){
    this->cols = cols;
}

void Matrix::setMatrix(double** matrix){
    this->matrix = matrix;
}

Matrix Matrix::operator+(const Matrix& m) const{
    if(this->rows != m.rows || this->cols != m.cols){
        throw "Matrices are not the same size!";
    }
    Matrix result(this->rows, this->cols);
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            result.matrix[i][j] = this->matrix[i][j] + m.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& m) const{
    if(this->rows != m.rows || this->cols != m.cols){
        throw "Matrices are not the same size!";
    }
    Matrix result(this->rows, this->cols);
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            result.matrix[i][j] = this->matrix[i][j] - m.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& m) const{
    if(this->cols != m.rows){
        throw "Matrices are not compatible for multiplication!";
    }
    Matrix result(this->rows, m.cols);
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < m.cols; j++){
            for(size_t k = 0; k < this->cols; k++){
                result.matrix[i][j] += this->matrix[i][k] * m.matrix[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::operator=(const Matrix& m){
    if(this->rows != m.rows || this->cols != m.cols){
        for(size_t i = 0; i < this->rows; i++){
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
        this->rows = m.rows;
        this->cols = m.cols;
        this->matrix = new double*[rows];
        for(size_t i = 0; i < rows; i++){
            this->matrix[i] = new double[cols];
        }
    }
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->matrix[i][j] = m.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+=(const Matrix& m){
    if(this->rows != m.rows || this->cols != m.cols){
        throw "Matrices are not the same size!";
    }
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->matrix[i][j] += m.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator-=(const Matrix& m){
    if(this->rows != m.rows || this->cols != m.cols){
        throw "Matrices are not the same size!";
    }
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->matrix[i][j] -= m.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator*=(const Matrix& m){
    if(this->cols != m.rows){
        throw "Matrices are not compatible for multiplication!";
    }
    Matrix result(this->rows, m.cols);
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < m.cols; j++){
            for(size_t k = 0; k < this->cols; k++){
                result.matrix[i][j] += this->matrix[i][k] * m.matrix[k][j];
            }
        }
    }
    *this = result;
    return *this;
}

double& Matrix::operator()(size_t row, size_t col){
    if(row >= this->rows || col >= this->cols){
        throw "Index out of bounds!";
    }
    return this->matrix[row][col];
}

bool Matrix::operator==(const Matrix& m) const{
    if(this->rows != m.rows || this->cols != m.cols){
        return false;
    }
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            if(this->matrix[i][j] != m.matrix[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& m) const{
    if(this->rows != m.rows || this->cols != m.cols){
        return true;
    }
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            if(this->matrix[i][j] != m.matrix[i][j]){
                return true;
            }
        }
    }
    return false;
}

ostream& operator<<(ostream& os, const Matrix& m){
    for(size_t i = 0; i < m.rows; i++){
        for(size_t j = 0; j < m.cols; j++){
            os << m.matrix[i][j] << " ";
        }
        os << endl;
    }
    return os;
}