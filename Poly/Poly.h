#pragma once

#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

class Poly{
    private:
        map<int, double> elements;
        void removeZeroCoefficient(int index);
    public:
        Poly();
        ~Poly();
        Poly(double coefficient);
        Poly(const Poly& p);
        Poly& operator=(const Poly& p);
        Poly& operator+=(const Poly& p);
        Poly& operator-=(const Poly& p);
        Poly operator-() const;
        friend Poly operator+(const Poly& p1, const Poly& p2);
        friend Poly operator-(const Poly& p1, const Poly& p2);
        friend Poly operator*(const Poly& p1, const Poly& p2);
        double operator()(double x) const;
        double& operator[](int index);
        friend ostream& operator<<(ostream& os, const Poly& p);

};