#include "vector.h"
#include<stdlib.h>

void* newVector(){
	return NULL;
}

void push_back(vec** start,int value){
	if(*start==NULL){
		vec* n=(vec*)malloc(sizeof(vec));
		n->val=value;
		n->next=NULL;
		n->prev=NULL;
		*start=n;
		return;
	}
	vec* temp=*start;
	while(temp->next!=NULL)
		temp=temp->next;
	vec* n=(vec*)malloc(sizeof(vec));
	n->val=value;
	n->next=NULL;
	n->prev=temp;
	temp->next=n;
}

void push_front(vec** start,int value){
	vec* n=(vec*)malloc(sizeof(vec));
	n->val=value;
	n->next=*start;
	n->prev=NULL;
	*start=n;
}

void insert(vec** start,vec* ptr,int value){
	if(*start==NULL||ptr==NULL)
		return;
	else if(ptr==*start){
		vec* n=(vec*)malloc(sizeof(vec));
		n->val=value;
		n->next=ptr->next;
		n->prev=ptr;
		ptr->next=n;
		if(ptr->next!=NULL)
			ptr->next->prev=n;
		return;
	}
	else if(ptr->next==NULL){
		push_back(&*start,value);
		return;
	}
	else{
		vec*temp=*start;
		while(temp!=NULL){
			if(temp==ptr)
				break;
			temp=temp->next;
		}
		if(temp==NULL)
			return;
		vec* n=(vec*)malloc(sizeof(vec));
		n->val=value;
		n->next=ptr->next;
		n->prev=ptr;
		ptr->next->prev=n;
		ptr->next=n;
	}
}

vec* find(vec** start,int value){
	if(*start==NULL)
		return NULL;
	vec* temp=*start;
	while(temp!= NULL){
		if(temp->val==value)
			return temp;
		temp=temp->next;
	}
	return NULL;
}

void erase(vec** start,vec** ptr){
	if(*ptr==NULL)
		return;
	if(*start==NULL)
		return;
	if(*ptr==*start){
		vec* temp=*start;
		if(temp->next==NULL){
			*start=NULL;
			free(*ptr);
			return;
		}
		temp=temp->next;
		temp->prev=NULL;
		*start=temp;
		free(*ptr);
	}
	else{
		vec* temp=*ptr;
		if(temp->next==NULL){
			temp->prev->next=NULL;
			free(*ptr);
			return;
		}
		temp->next->prev=temp->prev;
		temp->prev->next=temp->next;
		free(*ptr);
	}
}

void clean(vec** start){
	if(*start==NULL)
		return;
	vec* temp=*start;
	while(temp!=NULL){
		vec* x=temp;
		temp=temp->next;
		x->next=NULL;
		x->prev=NULL;
		free(x);
	}
	*start=NULL;
}

vec* reverse(vec** start){
	if(*start==NULL)
		return NULL;
	vec* s1=NULL;
	vec* temp=*start;
	vec* p=NULL;
	while(temp!=NULL){
		vec* n=(vec*)malloc(sizeof(vec));
		n->val=temp->val;
		if(temp==*start){
			n->next=p;
			p=n;
			s1=n;
		}
		else if(temp->next==NULL){
			n->prev=NULL;
			n->next=p;
			p->prev=n;
			s1=n;
			p=n;
		}
		else{
			p->prev=n;
			n->next=p;
			p=n;
		}
		temp=temp->next;
	}
	return s1;
}