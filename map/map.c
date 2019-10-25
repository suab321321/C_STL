//#include "vector/vector.h"
#include "map.h"

//declartion of function//
map* M_getMin(map*,map**);

//declaration for Lremove function//
void M_Lremove(map*);

//declaration for find function
void M_findDefect(map*,int*,int,map**,int);

//stablize function declaration
void M_stablize(map**,map*,int,int);

//LL Rotation
void M_LL(map**,map*);

//LR Rotation
void M_LR(map**,map*);

//RL Rotation
void M_RL(map**,map*);

//RR Rotation
void M_RR(map**,map*);

//Getting element of the tree
vec* M_getElements(map*,vec*);


//used for allocating memory it returns the new allocated memory//
map* M_allocate(){
	map* t=(map*)malloc(sizeof(map));
	t->val=0;
	t->content=0;
	t->balance=0;
	t->left=NULL;
	t->right=NULL;
	return t;
}
//function ends//

//used for insertion in tree//
void M_add(map** root,int data,int content){
	if(*root==NULL){
		map* n=M_allocate();
		n->content=content;
		n->val=data;
		*root=n;
	}
	else{
		map* temp=*root;
		map* prev=temp;
		while(temp!=NULL){
			prev=temp;
			if(temp->val==data)
				return;
			else if(data>temp->val)
				temp=temp->right;
			else if(data<temp->val)
				temp=temp->left;
		}
		map* n=M_allocate();
		n->content=content;
		n->val=data;
		if(prev->val>data)
			prev->left=n;
		else if(prev->val<data)
			prev->right=n;
	}
	M_update(*root);
	int i=1;
	M_findDefect(*root,&i,data,root,0);
}
//function ends//

//printing the tree in ascending order//
void M_preorder(map* t){
	if(t==NULL)
		return;
	else{
		printf("%d ",t->content);
		M_preorder(t->left);
		M_preorder(t->right);
	}
}
//function ends//

//removing a node from tree based on the int value provided//
void M_eraseT(map** root,int data){
	map* temp=*root;
	map* prev=NULL;
	while(temp!=NULL){
		if(temp->val==data)
			break;
		prev=temp;
		if(temp->val>data)
			temp=temp->left;
		else if(temp->val<data)
			temp=temp->right;
	}
	if(temp==NULL)
		return;
	if(temp->left==NULL&&temp->right==NULL){
		if(prev==NULL)
			*root=NULL;
		else if(prev->val>data)
			prev->left=NULL;
		else if(prev->val<data)
			prev->right=NULL;
		free(temp);
	}
	else if(temp->left==NULL&&temp->right!=NULL){
		if(prev==NULL)
			*root=temp->right;
		else
			prev->right=temp->right;
		free(temp);
	}
	else if(temp->left!=NULL&&temp->right==NULL){
		if(prev==NULL)
			*root=temp->left;
		else
			prev->left=temp->left;
		free(temp);
	}
	else{
		map* tPrev=temp;
		map* t=getMin(temp->right,&tPrev);
		int sw=t->val;
		t->val=temp->val;
		temp->val=sw;
		if(tPrev->left==t)
			tPrev->left=NULL;
		else
			tPrev->right=NULL;
		free(t);
	}
	M_update(*root);
	int i=1;
	M_findDefect(*root,&i,data,root,1);
}
//function ends//

//used in support to deletion function to get minimum value of the node's subtree and a passed by pointer tPrev which stores
//the previous node just before the minimum nnode
map* M_getMin(map* t,map** prev){
	while(t->left!=NULL){
		*prev=t;
		t=t->left;
	}
	return t;
}
//function ends//

//to get a maximum value from a node's subtree
map* M_getMax(map* t){
	while(t->right->right!=NULL)
		t=t->right;
	return t;
}
//function ends//

//function to delete the whole tree//
void M_destroy(map** root){
	map* temp=*root;
	M_Lremove(temp);
	*root=NULL;
}
//local function to delete each node of tree called from destroy()
void M_Lremove(map* root){
	if(root==NULL)
		return;
	else{
		M_Lremove(root->left);
		M_Lremove(root->right);
		free(root);
	}
}

//getting balance factor for the tree//
int M_update(map* root){
	if(root==NULL)
		return 0;
	else{
		int lh=M_update(root->left)+1;
		int rh=M_update(root->right)+1;
		root->balance=lh-rh;
		int mh;
		mh=lh>rh?lh:rh;
		return mh;
	}
}
//function ends//

//finding the diturbed balance node from bottom//
void M_findDefect(map* temp,int *done,int data,map** root,int type){
	if(temp==NULL)
		return;
	else{
		M_findDefect(temp->left,done,data,root,type);
		M_findDefect(temp->right,done,data,root,type);
		if(temp->balance==2||temp->balance==-2&&*done==1){
			*done=0;
			if(temp==*root)
				M_stablize(root,temp,data,type);
			else
				M_stablize(root,temp,data,type);
			return;
		}
	}
}
//function ends//

void M_stablize(map** root,map* target,int data,int type){
	if(type==1){
		if(target->left){
			if(target->left->left)
				M_LL(root,target);
			else if(target->left->right)
				M_LR(root,target);
		}
		else if(target->right){
			if(target->right->right)
				M_RR(root,target);
			else if(target->right->left)
				M_RL(root,target);
		}
		else
			return;
		
	}
	else{
		map* temp=target;
		int n=0;
		char p[2];
		while(n!=3){
			if(data>temp->val){
				temp=temp->right;
				p[n]='r';
			}
			else if(data<temp->val){
				temp=temp->left;
				p[n]='l';
			}
			++n;
		}
		if(p[0]=='l'&&p[1]=='l')
			M_LL(root,target);
		if(p[0]=='l'&&p[1]=='r')
			M_LR(root,target);
		if(p[0]=='r'&&p[1]=='l')
			M_RL(root,target);
		if(p[0]=='r'&&p[1]=='r')
			M_RR(root,target);
	}
}

void M_LL(map** root,map* target){
//	printf("LL %d",target->val);
	if(*root==target){
		map* temp=*root;
		map* vr=temp->left;
		*root=vr;
		temp->left=vr->right;
		vr->right=temp;
	}
	else{
		map* xr=*root;
		map* prev=*root;
		while(xr!=NULL){
			if(target->val==xr->val)
				break;
			prev=xr;
			if(target->val>xr->val)
				xr=xr->right;
			if(target->val<xr->val)
				xr=xr->left;
		}
		if(xr==NULL)
			return;
//		printf("%d %d",prev->val,xr->val);
		map* vr=xr->left;
		if(prev->val>xr->val)
			prev->left=vr;
		else
			prev->right=vr;
		xr->left=vr->right;
		vr->right=xr;
		M_update(*root);
	}
	
}

void M_LR(map** root,map* target){
//	printf("LR %d",target->val);
	if(target==*root){
		map* temp=*root;
		map* vr=temp->left->right;
		*root=vr;
		temp->left->right=vr->left;
		vr->left=temp->left;
		temp->left=vr->right;
		vr->right=temp;
	}
	else{
		map* xr=*root;
		map* prev=*root;
		while(xr!=NULL){
			if(target->val==xr->val)
				break;
			prev=xr;
			if(xr->val>target->val)
				xr=xr->left;
			else
				xr=xr->right;
		}
		if(xr==NULL)
			return;
		map* vr=xr->left->right;
		if(prev->val>xr->val)
			prev->left=vr;
		else
			prev->right=vr;
		xr->left->right=vr->left;
		vr->left=xr->left;
		xr->left=vr->right;
		vr->right=xr;
		M_update(*root);
	}
	
}

void M_RL(map** root,map* target){
//	printf("RL %d",target->val);
	if(*root=target){
		map* temp=*root;
		map *vr=temp->right->left;
		*root=vr;
		temp->right->left=vr->right;
		vr->right=temp->right;
		temp->right=vr->left;
		vr->left=temp;
	}
	else{
		map* xr=*root;
		map* prev=*root;
		while(xr!=NULL){
			if(target->val==xr->val)
				break;
			prev=xr;
			if(xr->val>target->val)
				xr=xr->left;
			else
				xr=xr->right;
		}
		if(xr==NULL)
			return;
		map* vr=xr->right->left;
		if(prev->val>xr->val)
			prev->left=vr;
		else
			prev->right=vr;
		xr->right->left=vr->right;
		vr->right=xr->right;
		xr->right=vr->left;
		vr->left=xr;
		M_update(*root);
	}
}

void M_RR(map** root,map* target){
//	printf("RR %d",target->val);
	if(*root==target){
		map* temp=*root;
		map* vr=temp->right;
		*root=vr;
		temp->right=vr->left;
		vr->left=temp;
	}
	else{
		map* xr=*root;
		map* prev=*root;
		while(xr!=NULL){
			if(target->val==xr->val)
				break;
			prev=xr;
			if(xr->val>target->val)
				xr=xr->left;
			else
				xr=xr->right;
		}
		if(xr==NULL)
			return;
		map* temp=xr;
		map* vr=temp->right;
		if(prev->val>temp->val)
			prev->left=vr;
		else
			prev->right=vr;
		temp->right=vr->left;
		vr->left=temp;
		M_update(*root);
	}
}

int M_search(map* root,int data){
	while(root!=NULL){
		if(root->val==data)
			return root->content;
		else if(root->val>data)
			root=root->left;
		else if(root->val<data)
			root=root->right;
	}
	return NULL;
}

vec* M_Itr(map* root){
	vec* elements=NULL;
	elements=M_getElements(root,elements);
	return elements;
}

vec* M_getElements(map* root,vec* con){
	if(root==NULL)
		return con;
	else{
		push_back(&con,root->val);
		M_getElements(root->left,con);
		M_getElements(root->right,con);
	}
}