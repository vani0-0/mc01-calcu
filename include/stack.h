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

typedef struct Stack *StackPtr;
typedef struct _Pile *PilePtr;

struct Stack
{
	char *name;
	void (*push)(StackPtr self, int item);
	int (*pop)(StackPtr self);
	int (*top)(StackPtr self);
	bool (*isFull)(StackPtr self);
	bool (*isEmpty)(StackPtr self);
	unsigned int (*size)(StackPtr self);
	// The Stack
	PilePtr _pile;
};

StackPtr initStack(char *name, unsigned int capacity);

#endif // __STACK_H_INCLUDED