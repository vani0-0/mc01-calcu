#include "../include/stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct _Pile
{
	unsigned int capacity;
	int top;
	char *data;
};

void push(StackPtr self, char item);
char pop(StackPtr self);
char top(StackPtr self);
bool isStackFull(StackPtr self);
bool isStackEmpty(StackPtr self);
unsigned int sizeStack(StackPtr self);

void _push(PilePtr pile, char item)
{
}

char _pop(PilePtr pile)
{
	return 0;
}

unsigned int _sizePile(PilePtr pile)
{
	return pile->top + 1;
}

PilePtr _createPile(unsigned int capacity)
{
	PilePtr pile = malloc(sizeof *pile);
	if (pile == NULL)
		return NULL;
	pile->data = malloc((sizeof *pile->data) * capacity);
	if (pile->data == NULL)
	{
		free(pile);
		return NULL;
	}

	pile->capacity = capacity;
	pile->top = -1;
}

StackPtr initStack(unsigned int capacity)
{
	StackPtr instance = malloc(sizeof *instance);
	if (instance == NULL)
		return NULL;

	instance->_pile = _createPile(capacity);
	if (instance->_pile == NULL)
	{
		free(instance);
		return NULL;
	}

	instance->push = &push;
	instance->pop = &pop;
	instance->top = &top;
	instance->isFull = &isStackFull;
	instance->isEmpty = &isStackEmpty;
	instance->size = &sizeStack;
	return instance;
}

void push(StackPtr self, char item)
{
	if (isStackFull(self))
		return;

	_push(self->_pile, item);
}

char pop(StackPtr self)
{
	if (isStackEmpty(self))
		return 0;

	return _pop(self->_pile);
}

char top(StackPtr self)
{
	if (isStackEmpty(self))
		return 0;
}

bool isStackFull(StackPtr self)
{
	return _sizePile(self->_pile) == self->_pile->capacity;
}

bool isStackEmpty(StackPtr self)
{
	return _sizePile(self->_pile) == 0;
}

unsigned int sizeStack(StackPtr self)
{
	return _sizePile(self->_pile);
}