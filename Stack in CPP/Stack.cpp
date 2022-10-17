#include "Stack.h"

using namespace std;

Stack::Stack()
{
    this->top = 0;
    this->size = 0;
    this->items = 0;
}

Stack::~Stack()
{
    free(this->items);
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
