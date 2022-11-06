#include "Complex.h"

using namespace std;

void testCompoundOperators();
void testCompoundAddition();
void testCompoundSubstraction();
void testCompoundMultiplication();
void testCompoundDivision();
void testRegularOperators();
void testMagnitudeAndPhase();

int main()
{
	testCompoundOperators();
	testRegularOperators();
	testMagnitudeAndPhase();
}

void testCompoundAddition()
{
	ComplexNumber c1(3, 4), c2(4, 5);
	ComplexNumber additionResult(7, 9);
	c1 += c2;
	if (c1 == additionResult) {
		cout << "Compound addition test passed" << endl;
	}
}

void testCompoundSubstraction()
{
	ComplexNumber c1(3, 4), c2(4, 5);
	ComplexNumber substractionResult(-1, -1);
	c1 -= c2;
	if (c1 == substractionResult) {
		cout << "Compound substraction test passed" << endl;
	}
}

void testCompoundMultiplication()
{
	ComplexNumber c1(3, 4), c2(4, 5);
	ComplexNumber multiplicationResult(-8, 31);
	c1 *= c2;
	if (c1 == multiplicationResult) {
		cout << "Compound multiplication test passed" << endl;
	}
}
void testCompoundDivision()
{
	ComplexNumber c1(3, 4), c2(4, 5);
	ComplexNumber divisionResult(32.0 / 41.0, (1.0 / 41.0));
	c1 /= c2;
	if (c1 == divisionResult) {
		cout << "Compound division test passed" << endl;
	}
}

void testCompoundOperators()
{
	cout << "-----------Compound operators test-----------" << endl;
	testCompoundAddition();
	testCompoundSubstraction();
	testCompoundMultiplication();
	testCompoundDivision();
	cout << "---------------------------------------------" << endl;
}

void testRegularOperators()
{
	cout << "\n-----------Regular operators test-----------" << endl;
	ComplexNumber c1(3, 4), c2(4, 5), c3, c4, c5, c6;
	ComplexNumber additionResult(7, 9), substractionResult(-1, -1),
		multiplicationResult(-8, 31), multiplicationByNumberResult(6, 8),
		divisionResult(32.0 / 41.0, (1.0 / 41.0)),
		divisionByNumberResult(1.5, 2);
	c3 = c1 + c2;
	if (c3 == additionResult) {
		cout << "Addition test passed" << endl;
	}
	c4 = c1 - c2;
	if (c4 == substractionResult) {
		cout << "Substraction test passed" << endl;
	}
	c5 = c1 * c2;
	if (c5 == multiplicationResult) {
		cout << "Multiplication test passed" << endl;
	}
	if (c1 * 2 == multiplicationByNumberResult) {
		cout << "Multiplication by an integer test passed" << endl;
	}
	c6 = c1 / c2;
	if (c6 == divisionResult) {
		cout << "Division test passed" << endl;
	}
	if (c1 / 2 == divisionByNumberResult) {
		cout << "Division by an integer test passed" << endl;
	}
	cout << "---------------------------------------------" << endl;
}

void testMagnitudeAndPhase()
{
	cout << "\n----------Magnitude and phase tests----------" << endl;
	ComplexNumber c1(3, 4);
	ComplexNumber c2(-3);
	double magnitudeResult = 5;
	if (c1.magnitude() == magnitudeResult) {
		cout << "Magnitude test passed" << endl;
	}
	double phaseResult = 0.927295;
	cout << "c1.phase() = " << c1.phase()
		 << ", calculator result = " << phaseResult << endl;
	if (c2.phase() == M_PI) {
		cout << "Phase test passed" << endl;
	}
}
