#include<iostream>
using namespace std;

// structure for linked list for queue

struct node {
	struct tree *data;
	struct node *next;
} *front = NULL , *rear = NULL , *top = NULL , *frontSecond = NULL , *rearSecond = NULL ;

// structure for tree nodes

struct tree {
	struct tree *lchild;
	int data;
	struct tree *rchild;
} *root = NULL;

// checking is empty for stack

bool stackIsEmpty(){
	if ( top == NULL ){
		return true;
	} else {
		return false;
	}
}

// push function for stack

void push ( struct tree *data ){

	struct node *t = new struct node [1];
	t->data = data;
	t->next = top;
	top = t;
}

// pop function for stack

struct tree* pop(){
	struct tree *x = NULL;
	if ( !stackIsEmpty()){
		x = top->data;
		top = top->next;
	}
	return x;
}

// checking is empty for queue

bool isEmpty(){
	if ( front == NULL ){
		return true;
	} else {
		return false;
	}
}

bool isEmptySecond(){
	if ( frontSecond == NULL ){
		return true;
	} else {
		return false;
	}
}

// enqueue function

void enqueue ( struct tree *data ){
	struct node *t ;
	t = new struct node [1] ;
	t->data = data;
	t->next = NULL;

	if ( front == NULL ){
		front = t ;
		rear = t;
	} else {
		rear->next = t;
		rear = t;
	}
}

void enqueueSecond ( struct tree *data ){
	struct node *t ;
	t = new struct node [1] ;
	t->data = data;
	t->next = NULL;

	if ( frontSecond == NULL ){
		frontSecond = t ;
		rearSecond = t;
	} else {
		rearSecond->next = t;
		rearSecond = t;
	}
}

// dequeue function

struct tree* dequeue (){
	struct tree *x = NULL;
	if ( isEmpty()){
		return NULL;
	} else {
		x = front->data;
		front = front->next;
		return x;
	}
}

struct tree* dequeueSecond (){
	struct tree *x = NULL;
	if ( isEmptySecond()){
		return NULL;
	} else {
		x = frontSecond->data;
		frontSecond = frontSecond->next;
		return x;
	}
}

// tree creation

void treeCreate(){
	cout<<"give the value of root :\n";
	root = new struct tree[1];
	cin>>root->data;
	enqueue(root);

	while ( !isEmpty() ){
		struct tree *t , *p , *q;
		int x , y ;
		t = dequeue();

		cout<<"give value of left child of "<<t->data<<"\n";
		cin>>x;

		if ( x != -1 ){
			p = new struct tree[1];
			p->data = x;
			p->lchild = p->rchild = NULL;
			enqueue(p);
			t->lchild = p;
		} else {
			t->lchild = NULL;
		}

		cout<<"give value of right child of "<<t->data<<"\n";
		cin>>y;

		if ( y != -1 ){
			q = new struct tree[1];
			q->data = y;
			q->lchild = q->rchild = NULL;
			enqueue(q);
			t->rchild = q;
		} else {
			t->rchild = NULL;
		}
	}
}

void preOrder(struct tree *p ){

        if (p){
            cout<<p->data<<"\t";
            preOrder(p->lchild);
            preOrder(p->rchild);
        }
}

void levelOrder( struct tree *p ){
	struct tree *t , *q  , *r ;
	cout<<p->data<<"\t";
	enqueueSecond(p);
	while ( !isEmptySecond()){
		t = dequeueSecond();
		q = t->lchild;
		r = t->rchild;
		if(q){
			cout<<q->data<<"\t";
			enqueueSecond(q);
		}
		if ( r ){
			cout<<r->data<<"\t";
			enqueueSecond(r);
		}
	}
}

int main(){

	treeCreate();
	preOrder(root);

	return 0;
}