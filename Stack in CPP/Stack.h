#pragma once
#include <iostream>

class Stack{
    public:
        Stack();
        ~Stack();
        void push(int element);
        int pop();
        bool isEmpty();
        size_t resize();
    private:
        int top;
        size_t size;
        int* items;
};
