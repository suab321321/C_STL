#include<stdio.h>
#include "set/set.h"

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

void ForVector(){
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

void ForSet(){
	tree* hash=NULL;
	int t=1;
	int val=0;
	vec* temp=NULL;
	while(t){
		printf("1 ADD and 2 Delete\n");
		int ch;
		scanf("%d",&ch);
		switch(ch){
			case 1:val=0;
				printf("Enter value\n");
				scanf("%d",&val);
				add(&hash,val);
				break;
			case 2:
				val=0;
				printf("Enter value\n");
				scanf("%d",&val);
				eraseT(&hash,val);
				break;
			case 3:preorder(hash);
				break;
			case 4:printf("\n enter the value to be searched\n");
					scanf("%d",&val);
					tree* it=search(hash,val);
					if(it==NULL)
						printf("Not found\n");
					else
						printf("Found\n");
					break;
			case 5:destroy(&hash);
				break;
			case 6:temp=Itr(hash);
					print(temp);
					break;
			default:printf("Wrong choice\n");
		}
		printf("\n1. Contine 0. exit");
		scanf("%d,",&t);
		printf("\n");
	}
	destroy(&hash);
}

void test(){
	tree* hash=NULL;
	add(&hash,63);
	add(&hash,9);
	add(&hash,19);
	add(&hash,27);
	add(&hash,18);
	add(&hash,108);
	add(&hash,99);
	add(&hash,81);
	preorder(hash);
}

int main(){
	ForVector();
	ForSet();
	test();
}