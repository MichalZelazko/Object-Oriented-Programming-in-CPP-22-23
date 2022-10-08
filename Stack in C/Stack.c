#include "Stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
		int newSize;
		if (s->size == 0) {
			newSize = 2;
		}
		else {
			newSize = s->size * 2;
		}
		int* newItems = realloc(s->items, newSize);
		if (newItems) {
			s->items = newItems;
			printf("Stack size updated: %d -> %d\n", s->size, newSize);
		}
		else {
			printf("Error during expanding the stack. Aborting\n");
			abort();
		}
		s->size = newSize;
	}
	s->items[s->top++] = element;
}

int pop(Stack* s)
{
	if (s->top == 0) {
		printf("Stack is empty. Aborting\n");
		abort();
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
