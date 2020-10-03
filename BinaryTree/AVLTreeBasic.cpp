#include<iostream>
using namespace std;

struct tree {
	tree* lchild;
	int data;
	int BF;
	tree* rchild;
} *root = NULL;

int height ( tree* p );
int bf ( tree* p);
void LLroration ( tree *p );
void LRrotation ( tree *p );
void RLrotation ( tree *P );
void RRrotation ( tree *p );
void insert ( int value );
void inOrder ( tree *p );

int height ( tree *p ){
	int x , y ;
	if ( p ){
		x = height(p->lchild);
		y = height(p->rchild);

		return x>y?x+1:y+1;
	}
	return 0;
}

int bf ( tree *p ){
	int x;
	x = height(p->lchild) - height(p->rchild);
	p->BF = x;
	return x;
}

void LLroration ( tree *p ){
	tree *pl = p->lchild;
	tree *plr = pl->rchild;

	p->lchild = plr;
	pl->rchild = p;

	if ( p == root ){
		root = pl;
	}
}

void LRrotation ( tree *p ){
	tree *pl = p->lchild;
	tree *plr = pl->rchild;

	p->lchild = plr->rchild;
	pl->rchild = plr->lchild;

	plr->rchild = p;
	plr->lchild = pl;

	if ( p == root ){
		root = plr;
	}
}

void RRrotation ( tree *p ){
	tree *pr = p->rchild;
	tree *prl = pr->lchild;

	p->rchild = prl;
	pr->lchild = p;

	if ( p == root ){
		root = pr;
	}
}

void RLrotation ( tree *p ){
	tree *pr = p->rchild;
	tree *prl = pr->lchild;

	p->rchild = prl->lchild;
	pr->lchild = prl->lchild;

	prl->lchild = p ;
	prl->rchild = pr;

	if ( p == root ){
		root = prl;
	}
}

tree* insert( tree *p , int value ){
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
		p->lchild = insert ( p->lchild , value );
	} else {
		p->rchild = insert ( p->rchild , value );
	}

	if ( bf(p) == 2 && bf(p->lchild) == 1 ){

		LLroration(p);

	} else if ( bf(p) == 2 && bf(p->lchild) == -1 ){

		LRrotation(p);

	} else if ( bf(p) == -2 && bf(p->rchild) == 1 ){

		RLrotation(p);

	} else if ( bf(p) == -2 && bf(p->rchild) == -1 ){

		RRrotation(p);

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
	root = insert(root , 0);
	insert(root , 5);
	inOrder(root);
	cout<<"\n";
	insert(root , 10);
	inOrder(root);
	cout<<"\n";
	insert(root , 20);
	inOrder(root);
	cout<<"\n";
	insert(root , 25);
	inOrder(root);
	cout<<"\n";
	insert(root , 30);
	inOrder(root);
	cout<<"\n";
	insert(root , 40);
	inOrder(root);
	cout<<"\n";
	insert(root , 50);
	inOrder(root);
	cout<<"\n";
	insert(root , 60);
	inOrder(root);
	cout<<"\n";
	insert(root , 70);
	inOrder(root);
	cout<<"\n";

	cout<<height(root)<<"\n";

	return 0;
}