#include<stdio.h>
//#include "set/set.h"
//#include "map/map.h"
//#include "vector/vector.h"

//#include "stack/stack.h"
#include "queue/queue.h"

//void print(vec* hash,map* hash2){
//	if(hash==NULL)
//		printf("NULL\n");
//	vec* temp=hash;
//	while(temp!=NULL){
//		printf("\n%d",M_search(hash2,temp->val));
//		temp=temp->next;
//	}
//}
//
//void revPrint(vec* hash){
//	while(hash!=NULL){
//		printf("%d",hash->val);
//		hash=hash->prev;
//	}
//}
//
//void ForVector(){
//	vec* hash=NULL;
//	push_front(&hash,1);
//	push_front(&hash,2);
//	push_front(&hash,3);
//	push_front(&hash,4);
//	print(hash);
//	printf("\n");
//	vec* hash2=reverse(&hash);
//	vec* t=find(&hash2,1);
//	push_front(&hash2,0);
//	clean(&hash);
//	clean(&hash2);
//	print(hash2);
//}
//
//void ForSet(){
//	tree* hash=NULL;
//	int t=1;
//	int val=0;
//	vec* temp=NULL;
//	while(t){
//		printf("1 ADD and 2 Delete\n");
//		int ch;
//		scanf("%d",&ch);
//		switch(ch){
//			case 1:val=0;
//				printf("Enter value\n");
//				scanf("%d",&val);
//				add(&hash,val);
//				break;
//			case 2:
//				val=0;
//				printf("Enter value\n");
//				scanf("%d",&val);
//				eraseT(&hash,val);
//				break;
//			case 3:preorder(hash);
//				break;
//			case 4:printf("\n enter the value to be searched\n");
//					scanf("%d",&val);
//					tree* it=search(hash,val);
//					if(it==NULL)
//						printf("Not found\n");
//					else
//						printf("Found\n");
//					break;
//			case 5:destroy(&hash);
//				break;
//			case 6:temp=Itr(hash);
//					print(temp);
//					break;
//			default:printf("Wrong choice\n");
//		}
//		printf("\n1. Contine 0. exit");
//		scanf("%d,",&t);
//		printf("\n");
//	}
//	destroy(&hash);
//}
//
//void test(){
//	tree* hash=NULL;
//	add(&hash,63);
//	add(&hash,9);
//	add(&hash,19);
//	add(&hash,27);
//	add(&hash,18);
//	add(&hash,108);
//	add(&hash,99);
//	add(&hash,81);
//	preorder(hash);
//}

//void ForStack(){
//	st* t=NULL;	ForQueue();

//	popElement(&t);
//	pushElement(&t,1);
//	pushElement(&t,2);
//	pushElement(&t,3);
//	pushElement(&t,4);
//	pushElement(&t,5);
//	popElement(&t);
//	printf("%d\n",getTop(&t));
//	pushElement(&t,6);
//	printf("%d\n",getTop(&t));
//		while(t!=NULL){
//		printf("%d ",getTop(&t));
//		popElement(&t);
//	}
//}

void ForQueue(){
	qu* t;
	pushFront(&t,1);
	pushFront(&t,2);
	pushFront(&t,3);
	pushFront(&t,4);
//	while(t!=NULL){
//		printf("%d ",getFront(&t));
//		popBack(&t);
//	}
	pushFront(&t,5);
	popBack(&t);
	pushFront(&t,6);
	printf("%d",getFront(&t));
	while(t!=NULL){
		printf("%d ",getFront(&t));
		popBack(&t);
	}
}

int main(){
//	ForVector();
//	ForSet();
//	test();
	printf("It works");
//	map* hash=NULL;
//	M_add(&hash,1,10);
//	M_add(&hash,2,11);
//	M_add(&hash,3,12);
//	M_eraseT(&hash,3);
//	vec* hash1=M_Itr(hash);
//	print(hash1,hash);
//	M_destroy(&hash);
//	ForStack();
//	ForQueue();
}