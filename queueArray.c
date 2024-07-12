#include<stdio.h>

/*
A queue is a fundamental concept in computer science, used for storing and managing data in a specific order. It follows the principle of “First in, First out” (FIFO), where the first element added to the queue is the first one to be removed. Imagine it like waiting in line at a ticket counter or a cafeteria – the person who arrives first gets served first!

Here are the key points about queues:

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
Applications:
Task Scheduling: Operating systems use queues to manage processes waiting for CPU time.
Data Transfer: Queues model data flow in network communication.
Simulation: Real-world systems like waiting lines (e.g., customers at a bank) can be simulated using queues.
Priority Queues: Queues can prioritize elements based on certain criteria.

*/
//circular queue

int front=-1;
int rear=-1;

int enqueue(int arr[],int size)
{
    int ele;
    if(front==(rear+1)%size) 
    {
        printf("overflow\n");
    }else if(front==-1)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d",&ele);
        front=rear=0;
        arr[rear]=ele;
    }else{
         printf("Enter the element to be inserted : ");
        scanf("%d",&ele);
        rear=(rear+1)%size;
        arr[rear]=ele;
    }
    return 0;
}


int dequeue(int arr[],int size)
{
    if(front ==-1)
    {
        printf("the queue is empty\n");
    }else if(front==rear)
    {
        printf("the dequeued element is %d\n",arr[front]);
        front=rear=-1;
    }else{
        printf("the dequeued element is %d\n",arr[front]);
        front=(front+1)%size;
    }
    return 0;
}


void peek(int arr[],int size)
{
    if(front==-1)
    {
        printf("underflow\n");
    }else{
        printf("the peeked element is %d\n",arr[front]);
    }
}


void display(int arr[],int size)
{
    int temp=front;
    if(front==-1)
    {
        printf("underflow\n");
    }else{
        while(rear!=temp)
        {
            printf("%d\t",arr[temp]);
            temp=(temp+1)%size;
        }printf("%d\n",arr[temp]);
    }
}


int main()
{
    int n,N;
    printf("Enter the size of queue: ");
    scanf("%d",&N);
    int arr[N];
    while(1){
        printf("enter the chioce:\n1:to enqueue.\n2:to dequeue.\n3:to display.\n4:to peek.\nothers to end the program.\nchoice:");
    scanf("%d",&n);
    switch (n)
    {
        case 1:enqueue(arr,N);
               break;
        case 2:dequeue(arr,N);
                break;
        case 3:display(arr,N);
               break;
        case 4:peek(arr,N);
                break;
        default:return 0;

    }}

}