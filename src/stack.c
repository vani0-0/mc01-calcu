#include "../include/stack.h"
#include "../include/my_string.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
	Private functions are functions that are only used inside the queue.c file.
	Public functions are functions that can be used outisde the queue.c file.
*/

// FUNCTIONS Prototypes:

void push(StackPtr self, char *item);
char *pop(StackPtr self);
char *top(StackPtr self);
bool isStackFull(StackPtr self);
bool isStackEmpty(StackPtr self);
unsigned int sizeStack(StackPtr self);

// Struct representing the stack
struct _Pile
{
	unsigned int capacity;
	int top;
	char **data;
};

// PRIVATE:

PilePtr _createPile(unsigned int capacity)
{
	PilePtr pile = malloc(sizeof *pile);
	if (pile == NULL)
		return NULL;
	pile->data = malloc(sizeof(char *) * capacity); // Allocate memory for the data array
	if (pile->data == NULL)
	{
		free(pile);
		return NULL;
	}

	pile->capacity = capacity;
	pile->top = -1;
	return pile;
}

void _push(PilePtr pile, char *item)
{
	int nextIndex = pile->top + 1;
	pile->data[nextIndex] = strdup(item);
	pile->top = nextIndex;
}

char *_pop(PilePtr pile)
{
	int currentIndex = pile->top;
	char *item = strdup(pile->data[currentIndex]);
	pile->top = currentIndex - 1;
	free(pile->data[currentIndex]);
	return item;
}

char *_top(PilePtr pile)
{
	int index = pile->top;
	char *item = pile->data[index];
	return item;
}

unsigned int _sizePile(PilePtr pile)
{
	return pile->top + 1;
}

// PUBLIC:

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

void push(StackPtr self, char *item)
{
	if (isStackFull(self))
		return;

	_push(self->_pile, item);
}

char *pop(StackPtr self)
{
	if (isStackEmpty(self))
		return NULL;

	return _pop(self->_pile);
}

char *top(StackPtr self)
{
	if (isStackEmpty(self))
		return NULL;

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