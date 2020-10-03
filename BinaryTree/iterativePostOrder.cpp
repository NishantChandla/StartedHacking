#include <iostream>
using namespace std;

// node for linked list

struct node
{
    struct tree *data;
    struct node *next;
} *front = NULL, *rear = NULL;

// node for stack
struct stacknode
{
    long long int data;
    struct stacknode *next;
} *top = NULL;

// node for tree

struct tree
{
    struct tree *lchild;
    int data;
    struct tree *rchild;
} *root = NULL;

void push ( long long int data ){
    struct stacknode *t;
    t = new struct stacknode[1];
    t->data = data;
    t->next = top ;
    top = t;
}

long long int pop(){
    struct stacknode *t;
    long long int x = -1;
    if ( top == NULL ){
        printf("stack underflow\n");
    } else {
        t = top;
        top = top->next;
        x = t->data;
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

void iterativePostOrder ( struct tree *p ){
    long long int temp;
    while ( p || !stackIsEmpty()){
        if ( p ){
            push((long long int)p);
            p = p->lchild;
        } else {
            temp = pop();
            if ( temp > 0 ){

                push(-temp);
                p = ((struct tree *) temp )->rchild;

            } else {
                cout<<((struct tree *) temp)->data<<"\t";
                p = NULL;
            }
        }
    }
}

int main(){
    treeCreate();
    iterativePostOrder( root );
}