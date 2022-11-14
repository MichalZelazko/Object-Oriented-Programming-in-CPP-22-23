#include "Complex.h"

using namespace std;

ComplexNumber::ComplexNumber(double real, double imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

ComplexNumber::~ComplexNumber() {}

void ComplexNumber::setImaginary(double newImaginary)
{
	this->imaginary = newImaginary;
}

void ComplexNumber::setReal(double newReal)
{
	this->real = newReal;
}

double ComplexNumber::getImaginary()
{
	return this->imaginary;
}

double ComplexNumber::getReal()
{
	return this->real;
}

ComplexNumber::ComplexNumber(const ComplexNumber& c)
{
	this->real = c.real;
	this->imaginary = c.imaginary;
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& c)
{
	this->real = c.real;
	this->imaginary = c.imaginary;
	return *this;
}

ComplexNumber operator+(ComplexNumber c1, ComplexNumber c2)
{
    double newReal = c1.getReal() + c2.getReal();
    double newImaginary = c1.getImaginary() + c2.getImaginary();
    c1.setReal(newReal);
    c1.setImaginary(newImaginary);
	return c1;
}

ComplexNumber operator-(ComplexNumber c1, ComplexNumber c2)
{
	double newReal = c1.getReal() - c2.getReal();
    double newImaginary = c1.getImaginary() - c2.getImaginary();
    c1.setReal(newReal);
    c1.setImaginary(newImaginary);
	return c1;
}

ComplexNumber operator*(ComplexNumber c1, ComplexNumber c2)
{
    c1 *= c2;
	return c1;
}

ComplexNumber operator/(ComplexNumber c1, ComplexNumber c2)
{
    c1 /= c2;
	return c1;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& c)
{
	this->real = this->real + c.real;
	this->imaginary = this->imaginary + c.imaginary;
	return *this;
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& c)
{
	this->real = this->real - c.real;
	this->imaginary = this->imaginary - c.imaginary;
	return *this;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& c)
{
    ComplexNumber aux;
    aux.setReal(this->real * c.real - this->imaginary * c.imaginary);
	aux.setImaginary(this->imaginary = this->real * c.imaginary + this->imaginary * c.real);
    this->real = aux.getReal();
    this->imaginary = aux.getImaginary();
	return *this;
}

ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& c)
{
    ComplexNumber aux;
	aux.setReal((this->real * c.real + this->imaginary * c.imaginary) / (pow(c.real, 2) +
		pow(c.imaginary, 2)));
	aux.setImaginary((this->imaginary * c.real - this->real * c.imaginary) / (pow(c.real, 2) +
		pow(c.imaginary, 2)));
    this->real = aux.getReal();
    this->imaginary = aux.getImaginary();
	return *this;
}

ostream& operator<<(ostream& s, ComplexNumber c)
{
	if (c.getImaginary() < 0) {
		s << c.getReal() << " - " << abs(c.getImaginary()) << "i" << endl;
	}
	else if (c.getImaginary() == 0) {
		s << c.getReal() << endl;
	}
    else if (c.getReal() == 0) {
        s << c.getImaginary() << "i" << endl;
    }
	else {
		s << c.getReal() << " + " << c.getImaginary() << "i" << endl;
	}
	return s;
}

bool operator==(ComplexNumber c1, ComplexNumber c2)
{
	if ((c1.getReal() == c2.getReal()) && (c1.getImaginary() == c2.getImaginary())) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(ComplexNumber c1, ComplexNumber c2)
{
	if ((c1.getReal() != c2.getReal()) || (c1.getImaginary() != c2.getImaginary())) {
		return true;
	}
	else {
		return false;
	}
}

double ComplexNumber::magnitude()
{
	return(sqrt(pow(this->real, 2) + pow(this->imaginary, 2)));
}

double ComplexNumber::phase()
{
    if(this->imaginary != 0 || this->real > 0){
        return(2*atan(this->imaginary / (this->magnitude() + this->real)));
    }else if(this->real < 0 && this->imaginary == 0){
        return M_PI;
    }else{
        cout << "Cannot calculate phase for 0 + 0i" << endl;
        return 0;
    }
}
