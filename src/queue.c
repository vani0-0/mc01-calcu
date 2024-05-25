#include "../include/queue.h"
#include "../include/my_string.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void enqueue(QueuePtr self, char *item); // Add an item to the queue
char *dequeue(QueuePtr self);			 // Remove an item from the queue
char *peek(QueuePtr self);				 // Get the front item of the queue without removing it
bool isQueueFull(QueuePtr self);		 // Check if the queue is full
bool isQueueEmpty(QueuePtr self);		 // Check if the queue is empty
unsigned int sizeQueue(QueuePtr self);	 // Get the current size of the queue

// Struct representing the queue
struct _Kyu
{
	unsigned int capacity; // Max size of queue
	int front;			   // First in line
	int rear;			   // Last in line
	char **data;		   // Holds the data stored // Changed to INT due to specific reasons
};

// Create a new queue instance with the given capacity
KyuPtr _createKyu(unsigned int capacity)
{
	// Allocate enough space for queue.
	KyuPtr kyu = malloc(sizeof *kyu);
	if (kyu == NULL)
		return NULL;

	kyu->data = malloc(sizeof(char *) * capacity);
	if (kyu->data == NULL)
		return NULL;

	// Initialize capacity, front and rear.
	kyu->capacity = capacity;
	kyu->front = kyu->rear = -1;
	return kyu;
}

// Add an item to the queue
void _enqueue(KyuPtr kyu, char *item)
{
	// Calculate the rear with the circular queue.
	int updatedRear = (kyu->rear + 1) % kyu->capacity;

	// update rear
	kyu->rear = updatedRear;

	// pass the string to data
	kyu->data[updatedRear] = strdup(item);
}

// Remove an item from the queue
char *_dequeue(KyuPtr kyu)
{
	// Calculate the front with the circular queue
	int updatedFront = (kyu->front + 1) % kyu->capacity;

	// update front
	kyu->front = updatedFront;

	// pass the copy of data to variable
	char *data = strdup(kyu->data[updatedFront]);

	// free the allocated space
	free(kyu->data[updatedFront]);

	// set it to NULL
	kyu->data[updatedFront] = NULL;

	return data;
}

// Get the front item of the queue without removing it
char *_peek(KyuPtr kyu)
{
	// Calculate the front using circular queue
	int currentFront = (kyu->front + 1) % kyu->capacity;

	// get the data
	char *data = kyu->data[currentFront];

	return data;
}

// Get the current size of the queue
unsigned int _sizeKyu(KyuPtr kyu)
{
	bool justInitialized = kyu->front == -1 && kyu->rear == -1;
	bool isEqual = kyu->rear == kyu->front && kyu->front != -1;
	bool isWrapped = kyu->front > kyu->rear;

	if (justInitialized)
		return 0;
	if (isEqual)
	{
		bool isEmpty = _peek(kyu) == NULL;
		return isEmpty ? 0 : kyu->capacity;
	}
	else
	{
		if (isWrapped)
			return (kyu->capacity - kyu->front) + kyu->rear;
		else
			return kyu->rear - kyu->front;
	}
}

// Initialize a new queue with the given capacity
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
	instance->peek = &peek;
	instance->isEmpty = &isQueueEmpty;
	instance->isFull = &isQueueFull;
	instance->size = &sizeQueue;
	return instance;
}

// Add an item to the queue
void enqueue(QueuePtr self, char *item)
{
	if (isQueueFull(self))
		return;
		
	_enqueue(self->_kyu, item);
}

// Remove an item from the queue
char *dequeue(QueuePtr self)
{
	if (isQueueEmpty(self))
		return NULL;

	return _dequeue(self->_kyu);
}

// Get the front item of the queue without removing it
char *peek(QueuePtr self)
{
	if (isQueueEmpty(self))
		return NULL;

	return _peek(self->_kyu);
}

// Check if the queue is full
bool isQueueFull(QueuePtr self)
{
	return _sizeKyu(self->_kyu) == self->_kyu->capacity;
}

// Check if the queue is empty
bool isQueueEmpty(QueuePtr self)
{
	return _sizeKyu(self->_kyu) == 0;
}

// Get the current size of the queue
unsigned int sizeQueue(QueuePtr self)
{
	return _sizeKyu(self->_kyu);
}
