#include "Poly.h"

using namespace std;

void displayMap(map<int, double> elements)
{
    for (auto element = elements.begin(); element != elements.end();
         element++) {
        cout << "degree " << element->first
             << " coefficient: " << element->second << endl;
    }
}

Poly::Poly()
{
    this->elements[0] = 0;
}

Poly::Poly(double coefficient)
{
    this->elements[0] = coefficient;
}

Poly& Poly::operator=(const Poly& p)
{
    this->elements = p.elements;
    return *this;
}

Poly Poly::operator-() const
{
    Poly temp;
    for (auto element = this->elements.begin(); element != this->elements.end();
         element++) {
        temp.elements[element->first] = -1 * element->second;
    }
    return temp;
}

double Poly::operator()(double x) const
{
    double result = 0;
    for (auto element = this->elements.begin(); element != this->elements.end();
         element++) {
        result += element->second * pow(x, element->first);
    }
    return result;
}

double& Poly::operator[](int index)
{
    return this->elements[index];
}

void Poly::removeZeroCoefficient(int index)
{
    if (this->elements[index] == 0) {
        this->elements.erase(index);
    }
}

Poly& Poly::operator+=(const Poly& other)
{
    for (auto element = other.elements.begin(); element != other.elements.end();
         element++) {
        this->elements[element->first] += element->second;
        if (element->first != 0) {
            this->removeZeroCoefficient(element->first);
        }
    }
    return *this;
}

Poly operator+(Poly p1, const Poly& p2)
{
    return p1 += p2;
}

Poly& Poly::operator-=(const Poly& other)
{
    for (auto element = other.elements.begin(); element != other.elements.end();
         element++) {
        this->elements[element->first] -= element->second;
        if (element->first != 0) {
            this->removeZeroCoefficient(element->first);
        }
    }
    return *this;
}

Poly operator-(Poly p1, const Poly& p2)
{
    return p1 -= p2;
}

Poly operator*(const Poly& p1, const Poly& p2)
{
    Poly result;
    for (auto element1 : p1.elements) {
        for (auto element2 : p2.elements) {
            result[element1.first + element2.first] +=
                element1.second * element2.second;
            if (element1.first + element2.first != 0) {
                result.removeZeroCoefficient(element1.first + element2.first);
            }
        }
    }
    return result;
}

ostream& firstElementSignDisplay(ostream& os,
                          const map<int, double>::reverse_iterator element)
{
    if (element->second < 0) {
        os << "-";
    }
    return os;
}

ostream& properDegreeDisplay(ostream& os,
                             const map<int, double>::reverse_iterator element)
{
    if (element->first != 0) {
        os << abs(element->second) << "x^" << element->first << " ";
    }
    else {
        os << abs(element->second) << " ";
    }
    return os;
}

ostream& followingSignDisplay(ostream& os, const map<int, double>& elements,
                              const map<int, double>::reverse_iterator element)
{
    auto auxElement = element;
    auxElement++;
    if (auxElement != elements.rend()) {
        if (element->second > 0) {
            os << "+ ";
        }
        else {
            os << "- ";
        }
    }
    return os;
}

ostream& operator<<(ostream& os, const Poly& p)
{
    map<int, double> elements = p.elements;
    if (elements.size() == 1 && elements[0] == 0) {
        os << "0";
        return os;
    }
    auto element = elements.rbegin();
    firstElementSignDisplay(os, element);
    for (auto element = elements.rbegin(); element != elements.rend();
         element++) {
        if (element->second != 0) {
            properDegreeDisplay(os, element);
            followingSignDisplay(os, elements, element);
        }
    }
    return os;
}
