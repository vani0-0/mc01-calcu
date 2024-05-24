#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/stack.h"

int main()
{
    // Test Case 1: Push and pop elements normally
    StackPtr stack1 = initStack("Test", 5);
    printf("Test Case 1: Push and pop elements normally\n");
    stack1->push(stack1, 'A');
    stack1->push(stack1, 'B');
    printf("Popped: %c\n", stack1->pop(stack1)); // B
    stack1->push(stack1, 'C');
    printf("Popped: %c\n", stack1->pop(stack1)); // C
    stack1->push(stack1, 'D');
    stack1->push(stack1, 'E');
    printf("Popped: %c\n", stack1->pop(stack1)); // E
    printf("Popped: %c\n", stack1->pop(stack1)); // D
    free(stack1);

    // Test Case 2: Push and pop more elements than capacity
    StackPtr stack2 = initStack("Test", 3);
    printf("\nTest Case 2: Push and pop more elements than capacity\n");
    stack2->push(stack2, 'A');
    stack2->push(stack2, 'B');
    stack2->push(stack2, 'C');
    stack2->push(stack2, 'D');                      // Should not push, stack is full
    printf("Popped: %c\n", stack2->pop(stack2)); // C
    stack2->push(stack2, 'E');                      // Should push E
    printf("Popped: %c\n", stack2->pop(stack2)); // B
    printf("Popped: %c\n", stack2->pop(stack2)); // A
    printf("Popped: %c\n", stack2->pop(stack2)); // E
    free(stack2);

    // Test Case 3: Pop from an empty stack
    StackPtr stack3 = initStack("Test", 4);
    printf("\nTest Case 3: Pop from an empty stack\n");
    printf("Attempted to pop: ");
    if (stack3->pop(stack3) == '\0')
        printf("No element popped\n");
    stack3->push(stack3, 'X');
    printf("Popped: %c\n", stack3->pop(stack3)); // X
    free(stack3);

    // Test Case 4: Check isFull and isEmpty functions
    StackPtr stack4 = initStack("Test", 3);
    printf("\nTest Case 4: Check isFull and isEmpty functions\n");
    printf("Is stack full? %s\n", stack4->isFull(stack4) ? "Yes" : "No");   // No
    printf("Is stack empty? %s\n", stack4->isEmpty(stack4) ? "Yes" : "No"); // Yes
    stack4->push(stack4, 'A');
    stack4->push(stack4, 'B');
    stack4->push(stack4, 'C');
    printf("Is stack full? %s\n", stack4->isFull(stack4) ? "Yes" : "No");   // Yes
    printf("Is stack empty? %s\n", stack4->isEmpty(stack4) ? "Yes" : "No"); // No
    free(stack4);

    // Test Case 5: Check top function
    StackPtr stack5 = initStack("Test", 3);
    printf("\nTest Case 5: Check top function\n");
    stack5->push(stack5, 'X');
    printf("Top element: %c\n", stack5->top(stack5)); // X
    stack5->push(stack5, 'Y');
    stack5->push(stack5, 'Z');
    printf("Top element: %c\n", stack5->top(stack5)); // Z
    free(stack5);

    // Test Case 6: Check size function
    StackPtr stack6 = initStack("Test", 4);
    printf("\nTest Case 6: Check size function\n");
    printf("Stack size: %u\n", stack6->size(stack6)); // 0
    stack6->push(stack6, 'A');
    stack6->push(stack6, 'B');
    printf("Stack size: %u\n", stack6->size(stack6)); // 2
    stack6->pop(stack6);
    printf("Stack size: %u\n", stack6->size(stack6)); // 1
    stack6->push(stack6, 'C');
    stack6->push(stack6, 'D');
    printf("Stack size: %u\n", stack6->size(stack6)); // 3
    free(stack6);

    return 0;
}
