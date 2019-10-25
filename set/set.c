//#include "vector/vector.h"
#include "set.h"

//declartion of function//
tree* getMin(tree*,tree**);

//declaration for Lremove function//
void Lremove(tree*);

//declaration for find function
void findDefect(tree*,int*,int,tree**,int);

//stablize function declaration
void stablize(tree**,tree*,int,int);

//LL Rotation
void LL(tree**,tree*);

//LR Rotation
void LR(tree**,tree*);

//RL Rotation
void RL(tree**,tree*);

//RR Rotation
void RR(tree**,tree*);

//Getting element of the tree
vec* getElements(tree*,vec*);


//used for allocating memory it returns the new allocated memory//
tree* allocate(){
	tree* t=(tree*)malloc(sizeof(tree));
	t->val=0;
	t->balance=0;
	t->left=NULL;
	t->right=NULL;
	return t;
}
//function ends//

//used for insertion in tree//
void add(tree** root,int data){
	if(*root==NULL){
		tree* n=allocate();
		n->val=data;
		*root=n;
	}
	else{
		tree* temp=*root;
		tree* prev=temp;
		while(temp!=NULL){
			prev=temp;
			if(temp->val==data)
				return;
			else if(data>temp->val)
				temp=temp->right;
			else if(data<temp->val)
				temp=temp->left;
		}
		tree* n=allocate();
		n->val=data;
		if(prev->val>data)
			prev->left=n;
		else if(prev->val<data)
			prev->right=n;
	}
	update(*root);
	int i=1;
	findDefect(*root,&i,data,root,0);
}
//function ends//

//printing the tree in ascending order//
void preorder(tree* t){
	if(t==NULL)
		return;
	else{
		printf("%d ",t->val);
		preorder(t->left);
		preorder(t->right);
	}
}
//function ends//

//removing a node from tree based on the int value provided//
void eraseT(tree** root,int data){
	tree* temp=*root;
	tree* prev=NULL;
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
		tree* tPrev=temp;
		tree* t=getMin(temp->right,&tPrev);
		int sw=t->val;
		t->val=temp->val;
		temp->val=sw;
		if(tPrev->left==t)
			tPrev->left=NULL;
		else
			tPrev->right=NULL;
		free(t);
	}
	update(*root);
	int i=1;
	findDefect(*root,&i,data,root,1);
}
//function ends//

//used in support to deletion function to get minimum value of the node's subtree and a passed by pointer tPrev which stores
//the previous node just before the minimum nnode
tree* getMin(tree* t,tree** prev){
	while(t->left!=NULL){
		*prev=t;
		t=t->left;
	}
	return t;
}
//function ends//

//to get a maximum value from a node's subtree
tree* getMax(tree* t){
	while(t->right->right!=NULL)
		t=t->right;
	return t;
}
//function ends//

//function to delete the whole tree//
void destroy(tree** root){
	tree* temp=*root;
	Lremove(temp);
	*root=NULL;
}
//local function to delete each node of tree called from destroy()
void Lremove(tree* root){
	if(root==NULL)
		return;
	else{
		Lremove(root->left);
		Lremove(root->right);
		free(root);
	}
}

//getting balance factor for the tree//
int update(tree* root){
	if(root==NULL)
		return 0;
	else{
		int lh=update(root->left)+1;
		int rh=update(root->right)+1;
		root->balance=lh-rh;
		int mh;
		mh=lh>rh?lh:rh;
		return mh;
	}
}
//function ends//

//finding the diturbed balance node from bottom//
void findDefect(tree* temp,int *done,int data,tree** root,int type){
	if(temp==NULL)
		return;
	else{
		findDefect(temp->left,done,data,root,type);
		findDefect(temp->right,done,data,root,type);
		if(temp->balance==2||temp->balance==-2&&*done==1){
			*done=0;
			if(temp==*root)
				stablize(root,temp,data,type);
			else
				stablize(root,temp,data,type);
			return;
		}
	}
}
//function ends//

void stablize(tree** root,tree* target,int data,int type){
	if(type==1){
		if(target->left){
			if(target->left->left)
				LL(root,target);
			else if(target->left->right)
				LR(root,target);
		}
		else if(target->right){
			if(target->right->right)
				RR(root,target);
			else if(target->right->left)
				RL(root,target);
		}
		else
			return;
		
	}
	else{
		tree* temp=target;
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
			LL(root,target);
		if(p[0]=='l'&&p[1]=='r')
			LR(root,target);
		if(p[0]=='r'&&p[1]=='l')
			RL(root,target);
		if(p[0]=='r'&&p[1]=='r')
			RR(root,target);
	}
}

void LL(tree** root,tree* target){
	printf("LL %d",target->val);
	if(*root==target){
		tree* temp=*root;
		tree* vr=temp->left;
		*root=vr;
		temp->left=vr->right;
		vr->right=temp;
	}
	else{
		tree* xr=*root;
		tree* prev=*root;
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
		tree* vr=xr->left;
		if(prev->val>xr->val)
			prev->left=vr;
		else
			prev->right=vr;
		xr->left=vr->right;
		vr->right=xr;
		update(*root);
	}
	
}

void LR(tree** root,tree* target){
//	printf("LR %d",target->val);
	if(target==*root){
		tree* temp=*root;
		tree* vr=temp->left->right;
		*root=vr;
		temp->left->right=vr->left;
		vr->left=temp->left;
		temp->left=vr->right;
		vr->right=temp;
	}
	else{
		tree* xr=*root;
		tree* prev=*root;
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
		tree* vr=xr->left->right;
		if(prev->val>xr->val)
			prev->left=vr;
		else
			prev->right=vr;
		xr->left->right=vr->left;
		vr->left=xr->left;
		xr->left=vr->right;
		vr->right=xr;
		update(*root);
	}
	
}

void RL(tree** root,tree* target){
//	printf("RL %d",target->val);
	if(*root=target){
		tree* temp=*root;
		tree *vr=temp->right->left;
		*root=vr;
		temp->right->left=vr->right;
		vr->right=temp->right;
		temp->right=vr->left;
		vr->left=temp;
	}
	else{
		tree* xr=*root;
		tree* prev=*root;
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
		tree* vr=xr->right->left;
		if(prev->val>xr->val)
			prev->left=vr;
		else
			prev->right=vr;
		xr->right->left=vr->right;
		vr->right=xr->right;
		xr->right=vr->left;
		vr->left=xr;
		update(*root);
	}
}

void RR(tree** root,tree* target){
//	printf("RR %d",target->val);
	if(*root==target){
		tree* temp=*root;
		tree* vr=temp->right;
		*root=vr;
		temp->right=vr->left;
		vr->left=temp;
	}
	else{
		tree* xr=*root;
		tree* prev=*root;
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
		tree* temp=xr;
		tree* vr=temp->right;
		if(prev->val>temp->val)
			prev->left=vr;
		else
			prev->right=vr;
		temp->right=vr->left;
		vr->left=temp;
		update(*root);
	}
}

tree* search(tree* root,int data){
	while(root!=NULL){
		if(root->val==data)
			return root;
		else if(root->val>data)
			root=root->left;
		else if(root->val<data)
			root=root->right;
	}
	return NULL;
}

vec* Itr(tree* root){
	vec* elements=NULL;
	elements=getElements(root,elements);
	return elements;
}

vec* getElements(tree* root,vec* con){
	if(root==NULL)
		return con;
	else{
		push_back(&con,root->val);
		getElements(root->left,con);
		getElements(root->right,con);
	}
}