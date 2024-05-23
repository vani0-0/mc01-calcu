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

/* Pointer to Incomplete Type. */
typedef struct Queue *QueuePtr;
typedef struct _Kyu *KyuPtr;

struct Queue
{
	void (*enqueue)(QueuePtr self, char item);
	char (*dequeue)(QueuePtr self);
	char (*peek)(QueuePtr self);
	bool (*isFull)(QueuePtr self);
	bool (*isEmpty)(QueuePtr self);
	unsigned int (*size)(QueuePtr self);
	KyuPtr _kyu;
};

/**
 * Initialize Queue operations and implement queue
 * @param capacity the maximum size of queue
 * @return QueuePtr
 */
QueuePtr initQueue(unsigned int capacity);

#endif // __QUEUE_H_INCLUDED