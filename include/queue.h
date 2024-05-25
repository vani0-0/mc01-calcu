/**
 * queue.h
 * Author: Ashley Corpuz
 *
 * Using 'ADT' design pattern
 * 	referenced from: https://leanpub.com/patternsinc
 * Queue has limitations, after a bit of enqueuing and dequeuing,
 * the size of queue is reduced.
 * That's why this queue is modified to Circular Queue.
 *
 * Opaque Data Type
 *
 * Circular Queue reference: https://www.programiz.com/dsa/queue
 * Queue Library Header
 */

#ifndef __QUEUE_H_INCLUDED
#define __QUEUE_H_INCLUDED

#define bool _Bool
#define STRING_SIZE 8
/* Pointer to Incomplete Type. */
typedef struct Queue *QueuePtr;
typedef struct _Kyu *KyuPtr;

struct Queue
{
	// Add new Item to last in queue
	void (*enqueue)(QueuePtr self, char *item);

	// Remove the first item in queue
	char *(*dequeue)(QueuePtr self);

	// Peek at the first item in queue
	char *(*peek)(QueuePtr self);

	// Check if full
	bool (*isFull)(QueuePtr self);

	// Check if empty
	bool (*isEmpty)(QueuePtr self);

	// Get size of queue
	unsigned int (*size)(QueuePtr self);

	// The Queue
	KyuPtr _kyu;
};

// FUNCTIONS Prototypes:
/**
 * Initialize Queue operations and implement queue
 * @param name the name of queue
 * @param capacity the maximum size of queue
 * @return QueuePtr
 */
QueuePtr initQueue(unsigned int capacity);

#endif // __QUEUE_H_INCLUDED