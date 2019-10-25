#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "../vector/vector.h"

typedef struct MapNode{
	int val;
	int content;
	int balance;
	struct MapNode* left;
	struct MapNode* right;
} map;

void M_add(map**,int,int);

void M_preorder(map*);

void M_eraseT(map**,int);

map* M_getMax(map*);

void M_destroy(map**);

int M_search(map*,int);

vec* M_Itr(map*);
