#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../include/stack.h"
#include "../include/queue.h"

#define MAX 256
#define WHITESPACE 32     // SPACE
#define PLUS 43           // +
#define MINUS 45          // -
#define MULTIPLICATION 42 // *
#define DIVISION 47       // /
#define CARET 94          // ^

int precedence(char c)
{
    if (c == CARET)
        return 3;
    else if (c == DIVISION || c == MULTIPLICATION)
        return 2;
    else if (c == PLUS || c == MINUS)
        return 1;
    else
        return -1;
}

int main()
{
    StackPtr stack = initStack("Stack", MAX);
    QueuePtr queue = initQueue("Queue", MAX);
    char infix[MAX];

    printf("Enter an expression: ");
    fgets(infix, sizeof(infix), stdin);

    int index = 0;
    bool inParenthesis = false;

    while (infix[index] != 0)
    {
        char current = infix[index++];
        if (isspace(current) || isblank(current))
            continue;

        if (isalnum(current))
        {
            queue->enqueue(queue, current);
        }
        else if (current == '(')
        {
            stack->push(stack, current);
            inParenthesis = true;
        }
        else if (current == ')')
        {
            while (!stack->isEmpty(stack) && stack->top(stack) != '(')
            {
                queue->enqueue(queue, stack->pop(stack));
            }
            stack->pop(stack); // disregard (
            inParenthesis = false;
        }
        else
        {
            while (!stack->isEmpty(stack) && !inParenthesis)
            {
                bool currentHasLowPrio = precedence(current) <= precedence(stack->top(stack));
                if (currentHasLowPrio)
                    queue->enqueue(queue, stack->pop(stack));
                else
                    break;
            }
            stack->push(stack, current);
        }
    }

    while (!stack->isEmpty(stack))
    {
        queue->enqueue(queue, stack->pop(stack));
    }

    while (!queue->isEmpty(queue))
    {
        printf("%c", queue->dequeue(queue));
    }

    free(stack);
    free(queue);
    return 0;
}

// 30 + 4 (4 - 2)
// 30442-+
//