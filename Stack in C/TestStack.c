#include "Stack.h"

int main()
{
    Stack s1;
    Stack s2;
    init(&s1);
    init(&s2);
    if (isEmpty(&s1)) {
        printf("Stack is empty. Test successful\n");
    }
    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    push(&s2, 5);
    push(&s2, 6);
    printf("Popped: from first %d, from second %d\n", pop(&s1), pop(&s2));
    printf("Popped from second %d\n", pop(&s2));
    destroy(&s1);
    printf("Popping from second %d\n", pop(&s2));
    destroy(&s2);
    return 0;
}
