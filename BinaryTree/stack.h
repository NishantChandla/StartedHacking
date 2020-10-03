#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
} *top = NULL ;

void push ( int data ){
	struct node *t;
	t = (struct node *) malloc ( 1 * sizeof(struct node));
	t->data = data;
	t->next = top ;
	top = t;
}

int pop(){
	struct node *t;
	int x = -1;
	if ( top == NULL ){
		printf("stack underflow\n");
	} else {
		t = top;
		top = top->next;
		x = t->data;
		free(t);
	}
	return x;
}

void Stackdisplay (struct node *p ){
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}