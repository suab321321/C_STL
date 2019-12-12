#ifndef QUEUE_SEEN
#define QUEUE_SEEN

#include<stdlib.h>

typedef struct queue{
	int val;
	struct qu* next;
} qu;

void pushFront(qu**,int);

void popBack(qu**);

int getFront(qu**);

#endif