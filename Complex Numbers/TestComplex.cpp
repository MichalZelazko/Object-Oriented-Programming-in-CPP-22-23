#include "Complex.h"

using namespace std;

int main(){
    ComplexNumber c1(3, 4), c2(4, 5), c3, c4(-2, -5), c5(1);
    c3 = c2 * c1;
    cout << c3;
    cout << c4;
    cout << c5;
}
