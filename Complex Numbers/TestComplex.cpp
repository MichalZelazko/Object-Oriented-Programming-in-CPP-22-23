#include "Complex.h"

using namespace std;

void testCompoundOperators();
void testRegularOperators();
void testComparisonOperator();
void testMagnitudeAndPhase();

int main(){
    ComplexNumber c1(3, 4), c2(4, 5), c3, c4(-2, -5), c5(1), c6;
    c3 = c2 * c1;
    c6 = c4 * 5;
    (c1 += c2) += c4;
    cout << c1;
    cout << c2;
    cout << c3;
    cout << c4;
    cout << c5;
    cout << c6;
}
