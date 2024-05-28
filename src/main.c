#include "../include/calc.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    QueuePtr postfix = initQueue(MAX);
    char infix[MAX] = "8*(5^4+2)-6^2/(9*3)";
    infixToPostfix(infix, postfix);
    printf("result: ");
    while (!postfix->isEmpty(postfix))
    {
        printf("%s", postfix->dequeue(postfix));
    }
    printf("\n");
    free(postfix);
    return 0;
}