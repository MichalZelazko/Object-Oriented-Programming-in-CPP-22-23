#include <iostream>
#include <stdlib.h>
#include "Complex.h"

using namespace std;

int main(){
    ComplexNumber c1(3, 4), c2(4, 5);
    c1 += c2;
    cout << c1.getRealPart() << " + " << c1.getImaginaryPart() << "i" << endl;
}
