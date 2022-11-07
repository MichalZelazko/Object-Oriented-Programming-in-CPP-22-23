#include "Vect.h"

using namespace std;

Vect::Vect(size_t s){
    this->size = s;
    this->items = NULL;
    this->items = (double*)realloc(this->items, this->size * sizeof(double));
}

Vect::~Vect(){
    free(this->items);
}

void Vect::print(){
    size_t i = 0;
    cout << "[";
    for(i = 0; i < this->size - 1; i++){
        cout << this->items[i] << ", ";
    }
    cout << this->items[i] << "]" << endl;
}

double Vect::getAverage(){
    double sum = 0;
    double average;
    for(size_t i = 0; i < this->size; i++){
        sum += this->items[i];
    }
    average = sum / this->size;
    return average;
}

size_t Vect::getSize(){
    return this->size;
}

double Vect::getMin(){
    double min = this->items[0];
    for(size_t i = 0; i < this->size; i++){
        if(this->items[i] < min){
            min = this->items[i];
        }
    }
    return min;
}

void Vect::setElement(size_t index, double element){
    this->items[index] = element;
}
