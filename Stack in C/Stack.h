#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;
    size_t size;
    int* items;
} Stack;

void init(Stack* s);
void destroy(Stack* s);
void push(Stack* s, int element);
int pop(Stack* s);
bool isEmpty(Stack* s);
size_t resize(Stack* s);
