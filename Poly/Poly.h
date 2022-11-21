#pragma once

#include <cmath>
#include <iostream>
#include <map>

using namespace std;

class Poly {
  private:
    map<int, double> elements;
    void removeZeroCoefficient(int index);
    ostream& firstElementSignDisplay(ostream& os,
                              const map<int, double>::reverse_iterator element);
    ostream&
    properDegreeDisplay(ostream& os,
                        const map<int, double>::reverse_iterator element);
    ostream&
    followingSignDisplay(ostream& os, const map<int, double>& elements,
                         const map<int, double>::reverse_iterator element);

  public:
    Poly();
    Poly(double coefficient);
    Poly& operator=(const Poly& p);
    Poly& operator+=(const Poly& p);
    Poly& operator-=(const Poly& p);
    Poly operator-() const;
    friend Poly operator+(Poly p1, const Poly& p2);
    friend Poly operator-(Poly p1, const Poly& p2);
    friend Poly operator*(const Poly& p1, const Poly& p2);
    double operator()(double x) const;
    double& operator[](int index);
    friend ostream& operator<<(ostream& os, const Poly& p);
};
