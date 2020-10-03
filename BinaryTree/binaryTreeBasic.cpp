#include <iostream>
using namespace std;

// node for linked list

struct node
{
    struct tree *data;
    struct node *next;
} *front = NULL, *rear = NULL , *top = NULL;

// node for tree

struct tree
{
    struct tree *lchild;
    int data;
    struct tree *rchild;
} *root = NULL;

void push ( struct tree *data ){
    struct node *t;
    t = new struct node[1];
    t->data = data;
    t->next = top ;
    top = t;
}

struct tree* pop(){
    struct node *t;
    struct tree *x = NULL;
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

bool stackIsEmpty(){
    if ( top == NULL ){
        return true;
    } else {
        return false;
    }
}


bool isEmpty()
{
    if (front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue( struct tree *data )
{
    struct node *t = new struct node[1];
    t->data = data;
    t->next = NULL;

    if (front == NULL)
    {
        front = t;
        rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }
}

struct tree* dequeue()
{
    if (isEmpty())
    {
        cout << "queue is empty\n";
        return NULL;
    }
    else
    {
        struct node *t;
        struct tree* x;
        x = front->data;
        t = front;
        front = front->next;
        return x;
    }
}

void treeCreate (){

    struct tree *l , *r , *t ;
    root = new struct tree [1];

    cout<<"enter root value :\n";
    cin>>root->data;
    enqueue(root);

    while(!isEmpty()){
        t = dequeue();
        if ( t ){
            int x , y ;
            l = new struct tree[1];
            r = new struct tree[1];

            // getting left child

            cout<<"give left child of "<<t->data<<"\n";
            cin>>x;
            if ( x != -1 ){
                l->data = x;
                enqueue(l);
                t->lchild = l;
            } else {
                t->lchild = NULL;
            }

            // getting right child

            cout << "give right child of " << t->data << "\n";
            cin >> y;
            if (y != -1)
            {
                r->data = y;
                enqueue(r);
                t->rchild = r;
            }
            else
            {
                t->rchild = NULL;
            }
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

void inOrder ( struct tree *p ){
    if (p) {
        inOrder(p->lchild);
        cout<<p->data<<"\t";
        inOrder(p->rchild);
    }
}

void postOrder ( struct tree *p ){
    if (p) {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout<<p->data<<"\t";
    }
}

void iterativePreOrder ( struct tree *p ){

    while ( p || !stackIsEmpty()){

        if ( p ){
            cout<<p->data<<"\t";
            push(p);
            p = p->lchild;
        } else {
            p = pop();
            p = p->rchild;
        }

    }
}

void iterativeInOrder ( struct tree *p ){
    while ( p || !stackIsEmpty ){
        if ( p ){
            push(p);
            p = p->lchild;
        } else {
            p = pop();
            cout<<p->data<<"\t";
            p = p->rchild;
        }
    }
}

int main(){

    treeCreate();

    preOrder(root);
        cout<<endl;
    postOrder(root);
        cout<<endl;
    inOrder(root);
        cout<<endl;

    iterativePreOrder(root);
        cout<<endl;
     iterativeInOrder(root);
        cout<<endl;

    return 0;
}
