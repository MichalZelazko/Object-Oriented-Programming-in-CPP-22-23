#include "Matrix.h"

using namespace std;

int main(){
    Matrix m1(2, 2);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(1, 0) = 3;
    m1(1, 1) = 4;
    Matrix m2(m1);
    Matrix m3 = m2 + m1;
    Matrix m4 = m2 - m1;
    Matrix m5 = m2 * m1;
    const Matrix m6(m1);
    Matrix m7("matrix.txt");
    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3 << endl;
    cout << m4 << endl;
    cout << m5 << endl;
    cout << m6(0, 1) << endl;
    cout << m7 << endl;
}
