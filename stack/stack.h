#include<stdlib.h>
typedef struct stack{
	int val;
	struct st* next;
} st;

void pushElement(st**,int);

void popElement(st**);

int getTop(st**);