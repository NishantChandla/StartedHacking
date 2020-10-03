#include<iostream>
#include "queue.h"
using namespace std;

struct tree {
	struct tree *lchild;
	int data;
	struct tree *rchild;
} *root = NULL;

void insert ( int value ){
	struct tree *t , *p ;
	p = root;
	t = new struct tree [1];
	t->data = value;
	t->lchild = t->rchild = NULL;
	
	if ( p == NULL ){
		root = t ;
	}

	while ( p ){
		if ( value < p->data){
			if ( p->lchild ){
				p = p->lchild;
			} else {
				p->lchild = t;
				break;
			}

		} else {
			if ( p->rchild ){
				p = p->rchild;
			} else {
				p->rchild = t;
				break;
			}
		} 
	}
}

tree* recurrsiveInsert( tree *p , int value ){
	tree *t = new tree [1];
	t->data = value;
	t->lchild = t->rchild = NULL;

	if ( root == NULL ){
		root = t;
		return t;
	}

	if ( p == NULL ){
		p = t ;
	} else if ( value < p->data ){
		p->lchild = recurrsiveInsert ( p->lchild , value );
	} else {
		p->rchild = recurrsiveInsert ( p->rchild , value );
	}
	return p;
}

void inOrder ( tree *p ){
	if (p){
		inOrder(p->lchild);
		cout<<p->data<<"\t";
		inOrder(p->rchild);
	}
}

int main(){

	recurrsiveInsert(root , 30);
	recurrsiveInsert(root , 40);
	recurrsiveInsert(root , 20);
	recurrsiveInsert(root , 15);
	recurrsiveInsert(root , 45);
	recurrsiveInsert(root , 25);
	recurrsiveInsert(root , 35);

	inOrder(root);
	return 0;
}