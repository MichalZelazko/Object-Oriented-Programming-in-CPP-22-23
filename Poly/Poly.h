#pragma once

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Poly{
    private:
        map<double, int> elements;
    public:
        Poly();
        ~Poly();
        Poly(double coefficient);
        Poly(const Poly& p);
        Poly& operator=(const Poly& p);
        Poly& operator+=(const Poly& other);
        Poly& operator-=(const Poly& other);
        Poly& operator*=(const Poly& other);
        Poly& operator/=(const Poly& other);
        Poly operator+(const Poly& other) const;
        Poly operator-(const Poly& other) const;
        Poly operator*(const Poly& other) const;
        Poly operator/(const Poly& other) const;
        Poly operator[](int index);
        bool operator==(const Poly& other) const;
        bool operator!=(const Poly& other) const;
        friend ostream& operator<<(ostream& os, const Poly& p);
};

    
