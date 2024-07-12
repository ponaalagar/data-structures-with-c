#include<stdio.h>
#include<stdlib.h>

/*
A queue is a fundamental concept in computer science, used for storing and managing data in a specific order. It follows the principle of “First in, First out” (FIFO), where the first element added to the queue is the first one to be removed. Imagine it like waiting in line at a ticket counter or a cafeteria – the person who arrives first gets served first!

Here’s how we can implement a queue using a linked list:

Structure and Behavior:
A queue is a linear data structure that operates like a line or a queue of people.
Elements are added at one end (the rear), and they are removed from the other end (the front).
Think of it as a line of people waiting – the person who joins first gets to leave first.
Basic Operations:
Enqueue (Insert): Adds an element to the rear of the queue.
Dequeue (Delete): Removes and returns the element from the front of the queue.
Peek: Returns the element at the front without removing it.
Empty: Checks if the queue is empty.
Full: Checks if the queue is full (if it has a maximum capacity).
Advantages of Linked List Implementation:
Dynamic Size: Linked lists can grow or shrink dynamically, unlike fixed-size arrays.
Efficient Enqueue and Dequeue: Adding or removing elements is efficient because we only need to update pointers.
Memory Flexibility: Nodes can be scattered in memory, allowing efficient memory allocation.
*/

struct node{
    int data;
    struct node  *next;   
};

struct node *rear=NULL;
struct node *front=NULL;

void enqueue(int x){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    printf("The enqueued element is %d\n",x);
    if(front == NULL && rear==NULL)
    {
        front = rear = newnode;
    }else{
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue(){
    struct node* temp;
if(front==NULL)
{
    printf("underflow\n");
}else if(front==rear)
{
    printf("The dequeued element is %d\n",front->data);
    front=rear=NULL;
}else{
    printf("The dequeued element is %d\n",front->data);
    temp=front;
    front=front->next;
    free(temp);
}
}

void display()
{
    if(front == NULL ){
    printf("Queue is empty \n" );
} else{  
    struct node *t;
    t=front;
    do{
        printf("%d\t",t->data);
        t=t->next;
    }while(t!=rear);
    printf("%d\n",t->data);
}
}

void peek(){
if(front == NULL ){
printf(" Queue is Empty \n");
}else{
    printf("the peeked element is %d\n",front->data);
}
}

int main()
{
    int n;
    int ele;
    while(1){
        printf("enter the chioce:\n1:to enqueue.\n2:to dequeue.\n3:to display.\n4:to peek.\nothers to end the program.\nchoice:");
    scanf("%d",&n);
    switch (n)
    {
        case 1:printf("Enter the element to enqueue:");
                scanf("%d",&ele);
                enqueue(ele);
                break;
        case 2:dequeue();
                break;
        case 3:display();
               break;
        case 4:peek();
                break;
        default:return 0;

    }
    }
}
