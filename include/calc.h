#ifndef __CALC_H_INCLUDED
#define __CALC_H_INCLUDED

#include "queue.h"
#include "stack.h"

#define MAX 256

int infixToPostfix(const char *infix, QueuePtr result);
int precedence(char *operator);

#endif //__CALC_H_INCLUDED