#include "queue.h"

void pushFront(qu** root,int val){
	qu* newEle=(qu*)malloc(sizeof(qu));
	newEle->val=val;
	newEle->next=NULL;
	if(*root==NULL){
		*root=newEle;
		return;
	}
	else{
		qu* temp=*root;
		qu* prev=root;
		while(temp!=NULL){
			prev=temp;
			temp=temp->next;
		}
		prev->next=newEle;
		return;
	}
}

void popBack(qu** root){
	qu* n=*root;
	*root=n->next;
	free(n);
}

int getFront(qu**root){
	qu* n=*root;
	return n->val;
}
