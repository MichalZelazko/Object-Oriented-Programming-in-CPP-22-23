#pragma once

#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

class Poly{
    private:
        map<int, double> elements;
    public:
        Poly();
        ~Poly();
        Poly(double coefficient);
        Poly(const Poly& p);
        map<int, double> getElements() const;
        Poly& operator=(const Poly& p);
        Poly& operator+=(const Poly& other);
        Poly& operator-=(const Poly& other);
        Poly& operator*=(const Poly& other);
        Poly operator-() const;
        double operator()(double x) const;
        double& operator[](int index);
        void removeZeroCoefficient(int index);
};


Poly operator+(const Poly& p1, const Poly& p2);
Poly operator-(const Poly& p1, const Poly& p2);
Poly operator*(const Poly& p1, const Poly& p2);
Poly operator/(const Poly& p1, const Poly& p2);
ostream& operator<<(ostream& os, const Poly& p);

void displayMap(map<int, double> elements);