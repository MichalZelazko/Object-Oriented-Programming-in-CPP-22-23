#pragma once
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

class ComplexNumber {
  public:
    ComplexNumber(double real = 0, double imaginary = 0);
    ~ComplexNumber();
    double getReal() const;
    double getImaginary() const;
    void setReal(double newReal);
    void setImaginary(double newImaginary);
    ComplexNumber(const ComplexNumber& c);
    ComplexNumber& operator=(const ComplexNumber& c);
    ComplexNumber& operator+=(const ComplexNumber& c);
    ComplexNumber& operator-=(const ComplexNumber& c);
    ComplexNumber& operator*=(const ComplexNumber& c);
    ComplexNumber& operator/=(const ComplexNumber& c);
    double magnitude() const;
    double phase() const;

  private:
    double real;
    double imaginary;
};

ComplexNumber operator+(ComplexNumber c1, ComplexNumber c2);
ComplexNumber operator-(ComplexNumber c1, ComplexNumber c2);
ComplexNumber operator*(ComplexNumber c1, ComplexNumber c2);
ComplexNumber operator/(ComplexNumber c1, ComplexNumber c2);
bool operator==(ComplexNumber c1, ComplexNumber c2);
bool operator!=(ComplexNumber c1, ComplexNumber c2);
ostream& operator<<(ostream& s, ComplexNumber c);
