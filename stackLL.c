#include<stdio.h>
#include<stdlib.h>

/*
A stack is a fundamental concept in computer science, used for managing data in a specific order. It follows the principle of “Last in, First out” (LIFO), where the last element added to the stack is the first one to be removed. Imagine it like a stack of plates – you add new plates on top and remove them from the same end.

Here’s how we can implement a stack using a linked list:

Structure and Behavior:
A stack is a linear data structure that operates like a stack of items.
Elements are added and removed from the same end (the top).
Think of it as a stack of books – the book you place on top is the one you can easily grab.
Basic Operations:
Push (Insert): Adds an element to the top of the stack.
Pop (Delete): Removes and returns the element from the top of the stack.
Peek: Returns the element at the top without removing it.
Empty: Checks if the stack is empty.
Full: Checks if the stack is full (if it has a maximum capacity).
Advantages of Linked List Implementation:
Dynamic Size: Linked lists can grow or shrink dynamically, unlike fixed-size arrays.
Efficient Push and Pop: Adding or removing elements is efficient because we only need to update pointers.
Memory Flexibility: Nodes can be scattered in memory, allowing efficient memory allocation.
*/

struct node{
    int data;
    struct node* link;
};

struct node* top=NULL;

void push(int x){
struct node * newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=x;
newnode->link=top;
top=newnode;

}

void pop()
{
    if(top==NULL)
    {
        printf("The stack is empty\n");
    }else{
        struct node* temp=top;
        printf("%d \n",top->data);
        top=top->link;
        free(temp);
    }

}

int main()
{
    int choice ,c;
    while(1)
    {
        printf("1->push\n2->pop\nothers to end\nEnter the choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter the element to push: ");
                scanf("%d",&c);
                push(c);
                break;
                }
            case 2:pop();
                    break;
            default:return 0;
        }
    }
}