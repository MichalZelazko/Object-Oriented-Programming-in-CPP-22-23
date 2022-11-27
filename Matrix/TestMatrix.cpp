#include "Matrix.h"

using namespace std;

int main(){
    Matrix m1(2, 2);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(1, 0) = 3;
    m1(1, 1) = 4;
    cout << m1 << endl;
}