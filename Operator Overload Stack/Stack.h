#include <iostream>

class Stack{
    public:
        Stack();
        Stack(Stack& s);
        ~Stack();
        void push(int element);
        int pop();
        bool isEmpty();
    private:
        int top;
        size_t size;
        int* items;
};
