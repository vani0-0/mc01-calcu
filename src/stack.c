#include "../include/stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
	Private functions are functions that are only used inside the queue.c file.
	Public functions are functions that can be used outisde the queue.c file.
*/

// FUNCTIONS Prototypes:

void push(StackPtr self, int item);
int pop(StackPtr self);
int top(StackPtr self);
bool isStackFull(StackPtr self);
bool isStackEmpty(StackPtr self);
unsigned int sizeStack(StackPtr self);

// Struct representing the stack
struct _Pile
{
	unsigned int capacity;
	int top;
	int *data;
};

// PRIVATE:

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
	return pile;
}

void _push(PilePtr pile, int item)
{
	int nextIndex = pile->top + 1;
	pile->data[nextIndex] = item;
	pile->top = nextIndex;
}

int _pop(PilePtr pile)
{
	int currentIndex = pile->top;
	int item = pile->data[currentIndex];
	pile->top = currentIndex - 1;
	return item;
}

int _top(PilePtr pile)
{
	int index = pile->top;
	return pile->data[index];
}

unsigned int _sizePile(PilePtr pile)
{
	return pile->top + 1;
}

// PUBLIC:

StackPtr initStack(char *name, unsigned int capacity)
{
	StackPtr instance = malloc(sizeof *instance);
	if (instance == NULL)
		return NULL;

	instance->name = malloc(strlen(name) + 1);
	strcpy(instance->name, name);

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

void push(StackPtr self, int item)
{
	if (isStackFull(self))
	{
		printf("%s is full\n", self->name);
		return;
	}

	_push(self->_pile, item);
}

int pop(StackPtr self)
{
	if (isStackEmpty(self))
	{
		printf("%s is empty\n", self->name);
		return 0;
	}

	return _pop(self->_pile);
}

int top(StackPtr self)
{
	if (isStackEmpty(self))
	{
		printf("%s is empty\n", self->name);
		return 0;
	}

	return _top(self->_pile);
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