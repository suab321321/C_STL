#ifndef VECTOR_SEEN
#define VECTOR_SEEN

typedef struct vec{
	int val;
	struct vec* next;
	struct vec* prev;
} vec;

void* newVector();

void insert(vec**,vec*,int);

void push_back(vec**,int);

void push_front(vec**,int);

void erase(vec**,vec**);

vec* find(vec**,int);

vec* reverse(vec**);

void clean(vec**);

#endif