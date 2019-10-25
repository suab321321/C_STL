#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "../vector/vector.h"

typedef struct SetNode{
	int val;
	int balance;
	struct SetNode* left;
	struct SetNode* right;
} tree;

void add(tree**,int);

void preorder(tree*);

void eraseT(tree**,int);

tree* getMax(tree*);

void destroy(tree**);

tree* search(tree*,int);

vec* Itr(tree*);
