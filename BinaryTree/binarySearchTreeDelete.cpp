#include<iostream>
using namespace std;

struct tree {
	struct tree *lchild;
	int data;
	struct tree *rchild;
} *root = NULL;

void insert(int value) {
	if ( root == NULL ){
		root = new tree[1];
		root->data = value;
		root->lchild = root->rchild = NULL;
	} else {
		struct tree *t = new tree[1] , *p = root ;
		t->data = value;
		t->lchild = t->rchild = NULL;

		while (p){
			if ( value < p->data ){
				if(!p->lchild){
					p->lchild = t;
					break;
				} else {
					p = p->lchild;
				}
			} 
			else if( value == p->data ){
				cout<<"invalid value";
				break;
			} else {
				if (!p->rchild){
					p->rchild = t;
					break;
				} else {
					p = p->rchild;
				}
			}
		}
	}
}

void inorder ( tree *p ){
	if(p){
		inorder(p->lchild);
		cout<<p->data<<"\t";
		inorder(p->rchild);
	}
}

int height ( tree *p ){
	int x , y;
	if ( p ){
		x = height(p->lchild);
		y = height(p->rchild);
		return x>y ? x+1 : y+1;
	} else {
		return 0;
	}
}


// inorder predecessor

tree* inPre ( tree *p ){
	while (p && p->rchild){
		p = p->rchild;
	}
	return p;
}

// inorder successor

tree* inSuc ( tree *p ){
	while ( p && p->lchild ){
		p = p->lchild;
	}
	return p;
}

tree* Delete ( tree *p , int value ){
	
	if ( !p ){
		return NULL;
	}

	if ( p->lchild == NULL && p->rchild == NULL ){

		if ( p == root){
			root = NULL;
		}

		free(p);
		return NULL;
	}

	if ( value < p->data ){
		p->lchild = Delete( p->lchild , value );
	} else if ( value > p->data ){
		p->rchild = Delete( p->rchild , value );
	} else {
		if ( height(p->lchild) > height(p->rchild) ){
			tree *q;
			q = inPre(p->lchild);
			p->data = q->data;
			Delete(q , q->data);
		} else {
			tree *q;
			q = inSuc(p->lchild);
			p->data = q->data;
			Delete(q , q->data);
		}
	}
	return p;
}

int main (){
	insert(30);
	insert(20);
	insert(25);
	insert(40);
	insert(35);
	insert(15);
	insert(45);

	inorder(root);
	cout<<"\n";

	Delete(root,35);

	inorder(root);

	return 0;
}