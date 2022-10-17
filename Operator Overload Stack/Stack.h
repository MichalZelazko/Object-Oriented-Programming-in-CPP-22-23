#include <iostream>

class Stack{
    public:
        Stack();
        Stack(const Stack& s);
        Stack& operator=(const Stack& s);
        ~Stack();
        void push(int element);
        int pop();
        bool isEmpty();
    private:
        int top;
        size_t size;
        int* items;
        size_t resize();
};
