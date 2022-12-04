#include "Matrix.h"

using namespace std;

Matrix::Matrix(size_t rows, size_t cols){
    data = new MatrixData(rows, cols);
}

Matrix::Matrix(string fileName){
    ifstream file;
    file.open(fileName);
    if(!file.is_open()){
        throw FileNotOpenException();
    }
    size_t rows, cols;
    file >> rows >> cols;
    data = new MatrixData(rows, cols);
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            if(file.eof()){
                file.close();
                throw InvalidDataFromFileException();
            }
            file >> data->matrix[i][j];
        }
    }
    file.close();
}

Matrix::Matrix(const Matrix& m){
    m.data->refNum++;
    data = m.data;
}

Matrix::~Matrix(){
    if(--data->refNum == 0){
        delete data;
    }
}

size_t Matrix::getRows() const{
    return data->rows;
}

size_t Matrix::getCols() const{
    return data->cols;
}

double** Matrix::getMatrix() const{
    return data->matrix;
}

Matrix operator+(const Matrix& m1, const Matrix& m2){
    if(m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols()){
        throw IncompatibleMatrixDimensionsException();
    }
    Matrix newMatrix(m1.getRows(), m1.getCols());
    for(size_t i = 0; i < newMatrix.getRows(); i++){
        for(size_t j = 0; j < newMatrix.getCols(); j++){
            newMatrix.data->matrix[i][j] = m1.data->matrix[i][j] + m2.data->matrix[i][j];
        }
    }
    return newMatrix;
}

Matrix operator-(const Matrix& m1, const Matrix& m2){
    if(m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols()){
        throw IncompatibleMatrixDimensionsException();
    }
    Matrix newMatrix(m1.getRows(), m1.getCols());
    for(size_t i = 0; i < newMatrix.getRows(); i++){
        for(size_t j = 0; j < newMatrix.getCols(); j++){
            newMatrix.data->matrix[i][j] = m1.data->matrix[i][j] - m2.data->matrix[i][j];
        }
    }
    return newMatrix;
}

Matrix operator*(const Matrix& m1, const Matrix& m2){
    if(m1.getCols() != m2.getRows()){
        throw IncompatibleMatrixDimensionsException();
    }
    Matrix newMatrix(m1.getRows(), m2.getCols());
    for(size_t i = 0; i < newMatrix.getRows(); i++){
        for(size_t j = 0; j < newMatrix.getCols(); j++){
            newMatrix.data->matrix[i][j] = 0;
            for(size_t k = 0; k < m1.getCols(); k++){
                newMatrix.data->matrix[i][j] += m1.data->matrix[i][k] * m2.data->matrix[k][j];
            }
        }
    }
    return newMatrix;
}

Matrix& Matrix::operator=(const Matrix& m){
    if(this != &m){
        if(--data->refNum == 0){
            delete data;
        }
        m.data->refNum++;
        data = m.data;
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& m){
    for(size_t i = 0; i < data->rows; i++){
        for(size_t j = 0; j < data->cols; j++){
            data->matrix[i][j] += m.data->matrix[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& m){
    for(size_t i = 0; i < data->rows; i++){
        for(size_t j = 0; j < data->cols; j++){
            data->matrix[i][j] -= m.data->matrix[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& m){
    Matrix newMatrix = *this * m;
    *this = newMatrix;
    return *this;
}

double Matrix::operator()(size_t row, size_t col) const{
    if(row < 0 || row >= data->rows || col < 0 || col >= data->cols ){
        throw InvalidMatrixIndexException();
    }
    return data->matrix[row][col];
}

ostream& operator<<(ostream& os, const Matrix& m){
    for(size_t i = 0; i < m.data->rows; i++){
        for(size_t j = 0; j < m.data->cols; j++){
            os << m.data->matrix[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

Matrix::MatrixData::MatrixData(size_t newRows, size_t newCols){
    rows = newRows;
    cols = newCols;
    refNum = 1;
    matrix = new double*[rows];
    for(size_t i = 0; i < rows; i++){
        this->matrix[i] = new double[cols];
    }
}
    
Matrix::MatrixData::~MatrixData(){
    for(size_t i = 0; i < rows; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}
    
Matrix::MatrixData* Matrix::MatrixData::detach(){
    if(refNum == 1){
        return this;
    }
    MatrixData* newData = new MatrixData(rows, cols);
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            newData->matrix[i][j] = matrix[i][j];
        }
    }
    refNum--;
    return newData;
}

MatrixReference Matrix::operator()(size_t row, size_t col){
	if (this->data->rows < row || this->data->cols < col ||
		row < 0 || col < 0) {
		throw InvalidMatrixIndexException();
	}
	return MatrixReference(this, row, col);
}

MatrixReference::MatrixReference(Matrix* matrix, size_t rows, size_t cols)
{
	this->matrix = matrix;
	this->rows = rows;
	this->cols = cols;
}

MatrixReference::operator double() const
{
	return this->matrix->read(this->rows, this->cols);
}