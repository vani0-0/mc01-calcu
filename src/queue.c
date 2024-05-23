#include "../include/queue.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
	Private functions are functions that are only used inside the queue.c file.
	Public functions are functions that can be used outisde the queue.c file.
*/

// FUNCTIONS Prototypes:
void enqueue(QueuePtr self, char item);
char dequeue(QueuePtr self);
unsigned int sizeQueue(QueuePtr self);
char peek(QueuePtr self);
bool isQueueFull(QueuePtr self);
bool isQueueEmpty(QueuePtr self);

/* Internal representation of Kyu */
struct _Kyu
{
	unsigned int capacity; // Max size of queue
	int front;			   // First in line
	int rear;			   // Last in line
	char *data;			   // Holds the data stored
};

// PRIVATE:

KyuPtr _createKyu(unsigned int capacity)
{
	KyuPtr kyu = malloc(sizeof *kyu);
	if (kyu == NULL)
		return NULL;

	kyu->data = malloc((sizeof *kyu->data) * capacity);
	if (kyu->data == NULL)
	{
		free(kyu);
		return NULL;
	}

	kyu->capacity = capacity;
	kyu->front = kyu->rear = -1; // set both front and rear to -1
	return kyu;
}

void _enqueue(KyuPtr kyu, char item)
{
	int updatedRear = (kyu->rear + 1) % kyu->capacity;
	kyu->data[updatedRear] = item;
	kyu->rear = updatedRear;
}

char _dequeue(KyuPtr kyu)
{
	int nextIndex = (kyu->front + 1) % kyu->capacity;
	char item = kyu->data[nextIndex];

	kyu->data[nextIndex] = 0;
	kyu->front = nextIndex;

	return item;
}

char _peek(KyuPtr kyu)
{
	int nextIndex = (kyu->front + 1) % kyu->capacity;
	return kyu->data[nextIndex];
}

unsigned int _sizeKyu(KyuPtr kyu)
{
	// Conditions:
	bool justInitialized = kyu->front == -1 && kyu->rear == -1; // after initializing, front and rear are both set to -1.
	bool isEqual = !justInitialized && kyu->front == kyu->rear;
	bool rearIsWrapped = kyu->front > kyu->rear;

	if (justInitialized)
		return 0;

	if (isEqual)
	{
		bool isItemEmpty = _peek(kyu) == 0;
		return isItemEmpty ? 0 : kyu->capacity;
	}
	else
	{
		if (rearIsWrapped)
			return (kyu->capacity - kyu->front) + kyu->rear;
		else
			return kyu->rear - kyu->front;
	}
}

// PUBLIC:

QueuePtr initQueue(unsigned int capacity)
{
	QueuePtr instance = malloc(sizeof *instance);
	if (instance == NULL)
		return NULL;
	instance->_kyu = _createKyu(capacity);
	if (instance->_kyu == NULL)
	{
		free(instance);
		return NULL;
	}

	instance->enqueue = &enqueue;
	instance->dequeue = &dequeue;
	instance->size = &sizeQueue;
	instance->peek = &peek;
	instance->isFull = &isQueueFull;
	instance->isEmpty = &isQueueEmpty;
	return instance;
}

void enqueue(QueuePtr self, char item)
{
	if (isQueueFull(self))
	{
		printf("Queue is full\n");
		return;
	}

	_enqueue(self->_kyu, item);
}

char dequeue(QueuePtr self)
{
	if (isQueueEmpty(self))
	{
		printf("Queue is empty\n");
		return 0;
	}

	return _dequeue(self->_kyu);
}

char peek(QueuePtr self)
{
	if (isQueueEmpty(self))
	{
		printf("Queue is empty\n");
		return 0;
	}

	return _peek(self->_kyu);
}

bool isQueueFull(QueuePtr self)
{
	return _sizeKyu(self->_kyu) == self->_kyu->capacity;
}

bool isQueueEmpty(QueuePtr self)
{
	return _sizeKyu(self->_kyu) == 0;
}

unsigned int sizeQueue(QueuePtr self)
{
	return _sizeKyu(self->_kyu);
}
