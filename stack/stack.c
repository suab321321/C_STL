#include "stack.h"

//push to front
void pushElement(st** root,int val){
	st* newEle=(st*)malloc(sizeof(st));
	newEle->val=val;
	newEle->next=NULL;
	if(*root==NULL){
		*root=newEle;
		return;
	}
	else{
		newEle->next=*root;
		*root=newEle;
		return;
	}
}
//pop from front//
void popElement(st** root){
	st* temp=*root;
	*root=temp->next;
	free(temp);
}
//ends//

//returns top element of stack//
int getTop(st** root){
	st* temp=*root;
	return temp->val;
}
//ends//