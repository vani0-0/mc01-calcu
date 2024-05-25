/**
 * stack.h
 * Author: Ashley Corpuz
 *
 *  Using 'ADT' design pattern
 * 		referenced from: https://leanpub.com/patternsinc
 *
 *  Stack Library Header
 */

#ifndef __STACK_H_INCLUDED
#define __STACK_H_INCLUDED

#define bool _Bool
#define STRING_SIZE 8

typedef struct Stack *StackPtr;
typedef struct _Pile *PilePtr;

struct Stack
{
	void (*push)(StackPtr self, char *item);
	char *(*pop)(StackPtr self);
	char *(*top)(StackPtr self);
	bool (*isFull)(StackPtr self);
	bool (*isEmpty)(StackPtr self);
	unsigned int (*size)(StackPtr self);
	// The Stack
	PilePtr _pile;
};

StackPtr initStack(unsigned int capacity);

#endif // __STACK_H_INCLUDED