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
        void setRealPart(float newReal);
        void setImaginaryPart(float newImaginary);
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
    private:
        double real;
        double imaginary;
};

