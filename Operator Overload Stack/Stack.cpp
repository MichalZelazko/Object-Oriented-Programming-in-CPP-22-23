#include "Stack.h"
#include <iostream>
#include <cstring>

using namespace std;

Stack::Stack()
{
    this->top = 0;
    this->size = 0;
    this->items = NULL;
    cout << "\nBasic constructor called" << endl;
}

Stack::~Stack()
{
    free(this->items);
}

Stack::Stack(const Stack& s)
{
    cout << "\nCopy constructor called" << endl;
    this->top = s.top;
    this->size = s.size;
    this->items = NULL;
    this->items = (int*)realloc(this->items, this->size * sizeof(int));
    size_t i = 0;
    while(s.items[i]){
        this->items[i] = s.items[i];
        i++;
    }
}

Stack& Stack::operator=(const Stack& s) {
    cout << "\nAssignment operator called" << endl;
    if(this != &s)
    {
        cout << "Assignment was called between different objects" << endl;
        free(this->items);
        this->top = s.top;
        if(this->size < s.size){
            this->size = s.size;
        }
        this->items = (int*)realloc(this->items, this->size * sizeof(int));
        for (int i = 0; i < this->top; i++) {
            this->items[i] = s.items[i];
        }
    }
    return *this;
}

bool Stack::isEmpty()
{
    return (this->top == 0);
}

int Stack::pop()
{
    if (this->isEmpty()) {
        cout << "Stack is empty, cannot pop. Aborting" << endl;
        abort();
    }
    return this->items[--this->top];
}

void Stack::push(int element)
{
    if (this->top >= 0 && (size_t)this->top >= this->size) {
        size_t newSize = this->resize();
        int* newItems = (int*)realloc(this->items, newSize * sizeof(int));
        if (newItems) {
            this->items = newItems;
            this->size = newSize;
        }
        else {
            cout << "Error reallocating memory. Aborting" << endl;
            abort();
        }
    }
    this->items[this->top++] = element;
}

size_t Stack::resize()
{
    size_t newSize;
    if (this->size == 0) {
        newSize = 2;
    }
    else {
        newSize = this->size * 2;
    }
    return newSize;
}

void Stack::printInfo()
{
    cout << "Size: " << this->size << endl;
    cout << "Top: " << this->top << endl;
    for(int i = 0; i < this->top; i++){
        cout << "Element " << i << " : " << this->items[i] << endl;
    }
}

