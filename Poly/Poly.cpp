#include "Poly.h"

using namespace std;

void displayMap(map<int, double> elements){
    for (auto it = elements.begin(); it != elements.end(); it++) {
        cout << "degree " << it->first << " coefficient: " << it->second << endl;
    }
}

Poly::Poly() {
    this->elements[0] = 0;
}

Poly::Poly(double coefficient) {
    this->elements[0] = coefficient;
}

Poly::Poly(const Poly& p) {
    this->elements = p.elements;
}

Poly::~Poly() {
    this->elements.clear();
}

map<int, double> Poly::getElements() const {
    return this->elements;
}

Poly& Poly::operator=(const Poly& p) {
    this->elements = p.elements;
    return *this;
}

Poly Poly::operator-() const{
    Poly temp;
    for (auto it = this->elements.begin(); it != this->elements.end(); it++) {
        temp.elements[it->first] = -1 * it->second;
    }
    return temp;
}

double Poly::operator()(double x) const{
    double result = 0;
    for (auto it = this->elements.begin(); it != this->elements.end(); it++) {
        result += it->second * pow(x, it->first);
    }
    return result;
}

double& Poly::operator[](int index){
    return this->elements[index];
}

void Poly::removeZeroCoefficient(int index) {
    if(this->elements[index] == 0) {
        this->elements.erase(index);
    }
}

Poly& Poly::operator+=(const Poly& other){
    for (auto element = other.elements.begin(); element != other.elements.end(); element++) {
        this->elements[element->first] += element->second;
        this->removeZeroCoefficient(element->first);
    }
    return *this;
}

Poly operator+(const Poly& p1, const Poly& p2) {
    return Poly(p1) += p2;
}

Poly& Poly::operator-=(const Poly& other){
    for (auto element = other.elements.begin(); element != other.elements.end(); element++) {
        this->elements[element->first] -= element->second;
        this->removeZeroCoefficient(element->first);
    }
    return *this;
}

Poly operator-(const Poly& p1, const Poly& p2) {
    return Poly(p1) -= p2;
}

Poly& Poly::operator*=(const Poly& p){
    for (auto it = p.getElements().begin(); it != p.getElements().end(); it++) {
        for (auto it2 = this->elements.begin(); it2 != this->elements.end(); it2++) {
            this->elements[it->first + it2->first] += it->second * it2->second;
            this->removeZeroCoefficient(it->first + it2->first);
        }
    }
    return *this;
}

Poly operator*(const Poly& p1, const Poly& p2) {
    return Poly(p1) *= p2;
}

ostream& operator<<(ostream& os, const Poly& p) {
    map<int, double> elements = p.getElements();
    auto it = elements.begin();
    if (it->second < 0) {
        os << "-";
    }
    for (auto it = elements.rbegin(); it != elements.rend(); it++) {
        if(it->second != 0) {
            if(it->first != 0) {
                os << abs(it->second) << "x^" << it->first << " ";
            } else {
                os << abs(it->second) << " ";
            }
            auto aux_it = it;
            aux_it++;
            if(aux_it != elements.rend()) {
                if(it->second > 0) {
                    os << "+ ";
                } else {
                    os << "- ";
                }
            }
        }   
    }
    return os;
}