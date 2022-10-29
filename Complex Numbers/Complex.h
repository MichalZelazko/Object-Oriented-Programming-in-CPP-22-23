#pragma once
#include <stdlib>

class ComplexNumber{
    public:
        ComplexNumber();
        ComplexNumber(double real);
        ComplexNumber(double real, double imaginary);
        ~ComplexNumber();
        double getRealPart();
        double getImaginaryPart();
        void setRealPart(float newReal);
        void setImaginaryPart(float newImaginary);
        ComplexNumber(const Stack& c);
        ComplexNumber& operator=(const ComplexNumber& c);
        ComplexNumber operator+(const ComplexNumber& c);
        ComplexNumber operator-(const ComplexNumber& c);
        ComplexNumber operator*(const ComplexNumber& c);
        ComplexNumber operator/(const ComplexNumber& c);
        ComplexNumber& operator+=(const ComplexNumber& c);
        ComplexNumber& operator-=(const ComplexNumber& c);
        ComplexNumber& operator*=(const ComplexNumber& c);
        ComplexNumber& operator/=(const ComplexNumber& c);
        ostream& operator<<
        bool operator==(const ComplexNumber& c);
        bool operator!=(const ComplexNumber& c);
    private:
        double real;
        double imaginary;
}
