#include <stdio.h>

/*
A stack is a fundamental concept in computer science, used for managing data in a specific order. It follows the principle of “Last in, First out” (LIFO), where the last element added to the stack is the first one to be removed. Imagine it like a stack of plates – you add new plates on top and remove them from the same end.

Here’s how we can implement a stack using an array:

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
Advantages of Array Implementation:
Simple and Efficient: Arrays provide direct access to elements, making push and pop operations efficient.
Fixed Size: The array size determines the maximum capacity of the stack.
*/

int top=-1;

void pop(int a[])
{
    if ( top >= 0)
    {
        printf("%d\n",a[top]);
        top=top-1;

    }else{
        printf("Stack is empty");
    }
}

void push(int x,int a[])
{
    top=top+1;
    a[top]=x;
}

int main()
{
    int n;
printf("Enter the size of the array: ");
scanf("%d",&n);

int a[n];

while(1)
{
    printf("1.Push\n2.Pop\nothers to exit\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:if(top==n-1)
        {
            printf("stack is full\n");
        }else{
                printf("Enter the element to push: ");
                int x;
                scanf("%d",&x);
                push(x,a);
              }  
              break;
        case 2:pop(a);
                break;  
        default:return 0;
    }
}
}