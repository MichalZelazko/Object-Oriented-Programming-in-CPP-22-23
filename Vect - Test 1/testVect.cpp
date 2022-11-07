#include <iostream>
#include "Vect.h"
using namespace std;
int main()
{
    Vect v1(3);
    v1.setElement(0, 0.5);
    v1.setElement(1, 1.5);
    v1.setElement(2, 2.5);
    v1.print();
    cout << endl;
    cout << v1.getSize() << endl;
    cout << v1.getAverage() << endl;

    Vect v2(2);
    v2.setElement(0, 0.1);
    v2.setElement(1, -0.2);
    v2.print();
    cout << endl;
    cout << v2.getSize() << endl;
    cout << v2.getAverage() << endl;
}
