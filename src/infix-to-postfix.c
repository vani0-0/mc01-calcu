#include "../include/my_string.h"
#include "../include/calc.h"

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int precedence(char *operator)
{
	if (strcmp(operator, "^") == 0)
		return 3;
	else if (strcmp(operator, "/") == 0 || strcmp(operator, "*") == 0)
		return 2;
	else if (strcmp(operator, "+") == 0 || strcmp(operator, "-") == 0)
		return 1;
	else
		return -1;
}

int infixToPostfix(const char *infix, QueuePtr result)
{
	StackPtr operators = initStack(MAX);
	int index = 0;
	char current;
	bool inParenthesis = false;
	while (infix[index] != '\0')
	{
		current = infix[index++];
		if (isspace(current))
			continue;
		if (isdigit(current))
		{
			int num = current - '0';
			while (infix[index] && isdigit(infix[index]))
			{
				num = num * 10 + (infix[index++] - '0');
			}
			result->enqueue(result, itoa(num));
		}
		else if (current == '(')
		{
			inParenthesis = true;
			operators->push(operators, "(");
		}
		else if (current == ')')
		{
			inParenthesis = false;
			while (!operators->isEmpty(operators) && strcmp(operators->top(operators), "("))
			{
				result->enqueue(result, operators->pop(operators));
			}
			operators->pop(operators);
		}
		else
		{
			char op[3] = {current, '\0'}; // Save current operator
			if (infix[index] && !isdigit(infix[index]) && !isspace(infix[index]) && infix[index] != '(')
			{
				op[1] = infix[index];
			}
			op[2] = '\0';
			while (!operators->isEmpty(operators) && precedence(operators->top(operators)) >= precedence(op))
			{
				if (inParenthesis)
					break;
				result->enqueue(result, operators->pop(operators));
			}
			operators->push(operators, op);
		}
	}

	while (!operators->isEmpty(operators))
	{
		result->enqueue(result, operators->pop(operators));
	}

	free(operators);
	return 0;
}