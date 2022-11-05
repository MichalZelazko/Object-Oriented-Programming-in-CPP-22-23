#pragma once
#include <iostream>
#include <stdlib.h>
#include <math.h>

class ComplexNumber{
    public:
        ComplexNumber();
        ComplexNumber(double real);
        ComplexNumber(double real, double imaginary);
        ~ComplexNumber();
        double getRealPart();
        double getImaginaryPart();
        void setRealPart(double newReal);
        void setImaginaryPart(double newImaginary);
        ComplexNumber(const ComplexNumber& c);
        ComplexNumber& operator=(const ComplexNumber& c);
        ComplexNumber operator+(const ComplexNumber& c);
        ComplexNumber operator-(const ComplexNumber& c);
        ComplexNumber operator*(const ComplexNumber& c);
        ComplexNumber operator/(const ComplexNumber& c);
        ComplexNumber& operator+=(const ComplexNumber& c);
        ComplexNumber& operator-=(const ComplexNumber& c);
        ComplexNumber& operator*=(const ComplexNumber& c);
        ComplexNumber& operator/=(const ComplexNumber& c);
        bool operator==(const ComplexNumber& c);
        bool operator!=(const ComplexNumber& c);
        friend std::ostream& operator<<(std::ostream& s, const ComplexNumber& c);
        double magnitude();
        double phase();
    private:
        double real;
        double imaginary;
};

