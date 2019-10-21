#include<stdio.h>
#include "vector/vector.h"

void print(vec* hash){
	if(hash==NULL)
		printf("NULL\n");
	vec* temp=hash;
	while(temp!=NULL){
		printf("%d",temp->val);
		temp=temp->next;
	}
}

void revPrint(vec* hash){
	while(hash!=NULL){
		printf("%d",hash->val);
		hash=hash->prev;
	}
}

int main(){
	vec* hash=NULL;
	push_front(&hash,1);
	push_front(&hash,2);
	push_front(&hash,3);
	push_front(&hash,4);
	print(hash);
	printf("\n");
	vec* hash2=reverse(&hash);
	vec* t=find(&hash2,1);
	push_front(&hash2,0);
	clean(&hash);
	clean(&hash2);
	print(hash2);
}