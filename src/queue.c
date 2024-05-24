#include "../include/queue.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
	Private functions are functions that are only used inside the queue.c file.
	Public functions are functions that can be used outisde the queue.c file.
*/

// FUNCTIONS Prototypes:

void enqueue(QueuePtr self, char item); // Add an item to the queue
char dequeue(QueuePtr self);			// Remove an item from the queue
unsigned int sizeQueue(QueuePtr self);	// Get the current size of the queue
char peek(QueuePtr self);				// Get the front item of the queue without removing it
bool isQueueFull(QueuePtr self);		// Check if the queue is full
bool isQueueEmpty(QueuePtr self);		// Check if the queue is empty

// Struct representing the queue
struct _Kyu
{
	unsigned int capacity; // Max size of queue
	int front;			   // First in line
	int rear;			   // Last in line
	char *data;			   // Holds the data stored
};

// PRIVATE:

// Create a new queue instance with the given capacity
KyuPtr _createKyu(unsigned int capacity)
{
	KyuPtr kyu = malloc(sizeof *kyu); // Allocate memory for the queue
	if (kyu == NULL)				  // Check if memory allocation failed
		return NULL;

	kyu->data = malloc((sizeof *kyu->data) * capacity); // Allocate memory for the data array
	if (kyu->data == NULL)								// Check if memory allocation failed
	{
		free(kyu);
		return NULL;
	}

	kyu->capacity = capacity;
	kyu->front = kyu->rear = -1; // Initialize front and rear indices
	return kyu;
}

// Add an item to the queue
void _enqueue(KyuPtr kyu, char item)
{
	int updatedRear = (kyu->rear + 1) % kyu->capacity; // Calculate the new rear index
	kyu->data[updatedRear] = item;					   // Add the item to the queue
	kyu->rear = updatedRear;						   // Update the rear index
}

// Remove an item from the queue
char _dequeue(KyuPtr kyu)
{
	int nextIndex = (kyu->front + 1) % kyu->capacity; // Calculate the index of the next item
	char item = kyu->data[nextIndex];				  // Get the next item
	kyu->data[nextIndex] = 0;						  // Clear the dequeued item from the data array
	kyu->front = nextIndex;							  // Update the front index
	return item;									  // Return the dequeued item
}

// Get the front item of the queue without removing it
char _peek(KyuPtr kyu)
{
	int nextIndex = (kyu->front + 1) % kyu->capacity; // Calculate the index of the next item
	return kyu->data[nextIndex];					  // Return the next item
}

// Get the current size of the queue
unsigned int _sizeKyu(KyuPtr kyu)
{
	// Conditions to check various scenarios of the queue
	bool justInitialized = kyu->front == -1 && kyu->rear == -1;
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
// Initialize a new queue with the given capacity
QueuePtr initQueue(char *name, unsigned int capacity)
{
	QueuePtr instance = malloc(sizeof *instance); // Allocate memory for the queue instance
	if (instance == NULL)
		return NULL;

	instance->name = malloc(strlen(name) + 1);
	strcpy(instance->name, name);

	instance->_kyu = _createKyu(capacity); // Create a new queue
	if (instance->_kyu == NULL)
	{
		free(instance);
		return NULL;
	}

	// Assign function pointers to public functions
	instance->enqueue = &enqueue;
	instance->dequeue = &dequeue;
	instance->size = &sizeQueue;
	instance->peek = &peek;
	instance->isFull = &isQueueFull;
	instance->isEmpty = &isQueueEmpty;
	return instance; // Return the initialized queue instance
}

// Add an item to the queue
void enqueue(QueuePtr self, char item)
{
	if (isQueueFull(self))
	{
		printf("%s is full\n", self->name);
		return;
	}

	_enqueue(self->_kyu, item);
}

// Remove an item from the queue
char dequeue(QueuePtr self)
{
	if (isQueueEmpty(self))
	{
		printf("%s is empty\n", self->name);
		return 0;
	}

	return _dequeue(self->_kyu);
}

// Get the front item of the queue without removing it
char peek(QueuePtr self)
{
	if (isQueueEmpty(self))
	{
		printf("%s is empty\n", self->name);

		return 0;
	}

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