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
        if(element->first != 0) {
            this->removeZeroCoefficient(element->first);
        }
    }
    return *this;
}

Poly operator+(const Poly& p1, const Poly& p2) {
    return Poly(p1) += p2;
}

Poly& Poly::operator-=(const Poly& other){
    for (auto element = other.elements.begin(); element != other.elements.end(); element++) {
        this->elements[element->first] -= element->second;
        if(element->first != 0) {
            this->removeZeroCoefficient(element->first);
        }
    }
    return *this;
}

Poly operator-(const Poly& p1, const Poly& p2) {
    return Poly(p1) -= p2;
}

Poly operator*(const Poly& p1, const Poly& p2) {
    Poly result;
    for (auto element1: p1.getElements()) {
        for (auto element2: p2.getElements()) {
            result[element1.first + element2.first] += element1.second * element2.second;
            if(element1.first + element2.first != 0) {
                result.removeZeroCoefficient(element1.first + element2.first);
            }
        }
    }
    return result;
}

ostream& operator<<(ostream& os, const Poly& p) {
    map<int, double> elements = p.getElements();
    if (elements.size() == 1 && elements[0] == 0) {
        os << "0";
        return os;
    }
    auto it = elements.rbegin();
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
                if(aux_it->second > 0) {
                    os << "+ ";
                } else {
                    os << "- ";
                }
            }
        }   
    }
    return os;
}