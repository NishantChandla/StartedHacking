struct node {
	int data;
	struct node *next;
} *front = NULL , *rear = NULL ;

bool queueIsEmpty (){
	if (front == NULL ) {
		return true;
	} else {
		return false;
	}
}

void enqueue ( int data ){
	struct node *t = new struct node [1];
	t->data = data;
	t->next = NULL;

	if ( front == NULL ){
		front = t ;
		rear = t ;
	} else {
		rear->next = t ;
		rear = t ;
	}
}

int dequeue (){
	if (queueIsEmpty()){
		return -1;
	} else {
		struct node *t;
		int x ;
		x = front->data;
		t = front;
		front = front->next;
		free(t);
		return x;
	}
}