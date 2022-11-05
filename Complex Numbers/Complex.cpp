#include "Complex.h"

using namespace std;

ComplexNumber::ComplexNumber()
{
	this->real = 0;
	this->imaginary = 0;
}

ComplexNumber::ComplexNumber(double real)
{
	this->real = real;
	this->imaginary = 0;
}

ComplexNumber::ComplexNumber(double real, double imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

ComplexNumber::~ComplexNumber() {}

void ComplexNumber::setImaginaryPart(double newImaginary)
{
	this->imaginary = newImaginary;
}

void ComplexNumber::setRealPart(double newReal)
{
	this->real = newReal;
}

double ComplexNumber::getImaginaryPart()
{
	return this->imaginary;
}

double ComplexNumber::getRealPart()
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

ComplexNumber ComplexNumber::operator+(const ComplexNumber& c)
{
	return ComplexNumber(this->real + c.real, this->imaginary + c.imaginary);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& c)
{
	return ComplexNumber(this->real - c.real, this->imaginary - c.imaginary);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& c)
{
	return ComplexNumber(this->real * c.real - this->imaginary * c.imaginary,
						 this->real * c.imaginary + this->imaginary * c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& c)
{
	ComplexNumber result;
	result.setRealPart((this->real * c.real + this->imaginary * c.imaginary) /
						   (pow(c.real, 2) +
					   pow(c.imaginary, 2)));
	result.setImaginaryPart(
		(this->imaginary * c.real - this->real * c.imaginary) / (pow(c.real, 2) +
		pow(c.imaginary, 2)));
	return result;
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
    aux.setRealPart(this->real * c.real - this->imaginary * c.imaginary);
	aux.setImaginaryPart(this->imaginary = this->real * c.imaginary + this->imaginary * c.real);
    this->real = aux.getRealPart();
    this->imaginary = aux.getImaginaryPart();
	return *this;
}

ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& c)
{
    ComplexNumber aux;
	aux.setRealPart((this->real * c.real + this->imaginary * c.imaginary) / (pow(c.real, 2) +
		pow(c.imaginary, 2)));
	aux.setImaginaryPart((this->imaginary * c.real - this->real * c.imaginary) / (pow(c.real, 2) +
		pow(c.imaginary, 2)));
    this->real = aux.getRealPart();
    this->imaginary = aux.getImaginaryPart();
	return *this;
}

ostream& operator<<(ostream& s, const ComplexNumber& c)
{
	if (c.imaginary < 0) {
		s << c.real << " - " << abs(c.imaginary) << "i" << endl;
	}
	else if (c.imaginary == 0) {
		s << c.real << endl;
	}
	else {
		s << c.real << " + " << c.imaginary << "i" << endl;
	}
	return s;
}

bool ComplexNumber::operator==(const ComplexNumber& c)
{
	if ((this->real == c.real) && (this->imaginary == c.imaginary)) {
		return true;
	}
	else {
		return false;
	}
}

bool ComplexNumber::operator!=(const ComplexNumber& c)
{
	if ((this->real != c.real) || (this->imaginary != c.imaginary)) {
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
