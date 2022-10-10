#include "Stack.h"

void init(Stack* s)
{
    s->top = 0;
    s->size = 0;
    s->items = 0;
}

void destroy(Stack* s)
{
    free(s->items);
}

void push(Stack* s, int element)
{
    if (s->top >= s->size) {
        size_t newSize = resize(s);
        int* newItems = realloc(s->items, newSize * sizeof(int));
        if (newItems) {
            s->items = newItems;
        }
        else {
            printf("Error during expanding the stack. Aborting\n");
            destroy(s);
            exit(1);
        }
        s->size = newSize;
    }
    s->items[s->top++] = element;
}

int pop(Stack* s)
{
    if (isEmpty(s)) {
        printf("Stack is empty. Aborting\n");
        destroy(s);
        exit(1);
    }
    return s->items[--s->top];
}

bool isEmpty(Stack* s)
{
    if (s->top == 0) {
        return true;
    }
    else {
        return false;
    }
}

size_t resize(Stack* s)
{
    size_t newSize;
    if (s->size == 0) {
        newSize = 2;
    }
    else {
        newSize = s->size * 2;
    }
    return newSize;
}
