#pragma once
#include <iostream>
#include <cstdlib>

class Vect{
    public:
        Vect(size_t s);
        ~Vect();
        void print();
        void setElement(size_t index, double element);
        size_t getSize();
        double getAverage();
        double getMin();
    private:
        size_t size;
        double* items;
};
