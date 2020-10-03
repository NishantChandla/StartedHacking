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

void inOrder ( struct tree *p ){
	if (p){
		inOrder(p->lchild);
		cout<<p->data<<"\t";
		inOrder(p->rchild);
	}
}

bool search ( int key ){
	struct tree *p = root;
	while ( p ){
		if ( key < p->data ){
			p = p->lchild;
		} else if ( key > p->data ){
			p = p->rchild;
		} else {
			return true;
		}
	}
	return false;
}

int main(){

	insert(30);
	insert(40);
	insert(20);
	insert(25);
	insert(15);
	insert(45);
	insert(35);

	inOrder(root);
	cout<<"\n";

	cout<<search(30)<<"\n";
	return 0;
}