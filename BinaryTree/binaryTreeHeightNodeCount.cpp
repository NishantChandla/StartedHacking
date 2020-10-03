#include<iostream>
#include "queue.h"
using namespace std;

struct tree {
	struct tree *lchild;
	int data;
	struct tree *rchild;
} *root = NULL;

void create(){
	root = new tree [1];
	tree *t , *l , *r;
	cout<<"give value of root :\n";
	cin>>root->data;
	enqueue(root);

	while ( !isEmpty()){
		t = dequeue();
		int x , y;

		cout<<"give value of left child of "<<t->data<<"\n";
		cin>>x;
		if ( x == -1 ){
			t->lchild = NULL;
		} else {
			l = new tree [1];
			l->data = x;
			t->lchild = l;
			enqueue(l);
		}

		cout<<"give value of right child of "<<t->data<<"\n";
		cin>>y;
		if ( y == -1 ){
			t->rchild = NULL;
		} else {
			r = new tree [1];
			r->data = y;
			t->rchild = r;
			enqueue(r);
		}
	}
}

void preOrder ( tree *p ){
	if(p){
		cout<<p->data<<"\t";
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

int height( tree *p ){
	static int x = 0  , y = 0 ;
	if ( p ){
		x = height(p->lchild);
		y = height(p->rchild);

		if ( x > y ){
			return x + 1;
		} else {
			return y + 1;
		}
	} else {
		return 0;
	} 
}

int nodeCount ( tree *p ){
	int x = 0  , y = 0 ;
	if ( p ){
		x = nodeCount(p->lchild);
		y = nodeCount(p->rchild);
		return x + y + 1;
	} else {
		return 0 ;
	}
}

int main(){
	create();
	preOrder(root);
	cout<<"\n";

	cout<<height(root)<<"\n";
	cout<<nodeCount(root)<<"\n";

	return 0;
}