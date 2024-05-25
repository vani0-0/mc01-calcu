#include "../include/stack.h"
#include "../include/queue.h"
#include "../include/my_string.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX 256
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
    StackPtr operators = initStack(MAX);
    QueuePtr postfix = initQueue(MAX);
    char infix[MAX] = "8*(5^4+2)-6^2/(9*3)";

    int index = 0;
    bool inParenthesis = false;
    while (infix[index] != '\0')
    {
        const char current = infix[index++];
        if (isspace(current) || isblank(current))
            continue; // ignore if space of blank

        if (isdigit(current))
        {
            int num = current - '0'; // '1'
            postfix->enqueue(postfix, itoa(num));
        }
        else if (current == '(')
        {
            inParenthesis = true;
        }
        else if (current == ')')
        {
            inParenthesis = false;
        }
        else
        {
            while (!operators->isEmpty(operators) && !inParenthesis)
            {
                if (precedence(current) <= precedence(operators->top(operators)[0]))
                {
                    postfix->enqueue(postfix, operators->pop(operators));
                }
                else
                    break;
            }
            char op[2] = {current, '\0'};
            operators->push(operators, op);
        }
    }

    while (!operators->isEmpty(operators))
    {
        postfix->enqueue(postfix, operators->pop(operators));
    }

    while (!postfix->isEmpty(postfix))
    {
        printf("%s", postfix->dequeue(postfix));
    }

    free(postfix);
    free(operators);
    return 0;
}