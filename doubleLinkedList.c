#include <stdio.h>
#include <stdlib.h>

/*
A doubly linked list is an extension of the single linked list. It adds an extra layer of connectivity by including a previous pointer in each node, in addition to the next pointer. This bidirectional linkage allows traversal in both directions: forward and backward.

Here are the key components of a doubly linked list:

Node Structure:
Each node contains two parts:
Data: The actual value stored in the node.
Next Pointer: Points to the next node.
Previous Pointer: Points to the previous node (or null for the head).
Advantages of Doubly Linked Lists:
Bidirectional Traversal: You can move both forward and backward through the list.
Efficient Insertions and Deletions: Adding or removing elements is efficient because we update both pointers.
Tail Pointer: The last node’s previous pointer points to the tail, making appending easier.
*/
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* insertFirst(struct node* head, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = head;
    temp->prev = NULL;
    if(head!= NULL) {
        head->prev = temp;
    }
    head = temp;
    return head;
}

struct node* insertLast(struct node* head, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        struct node* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = temp;
        temp->prev = current;
    }
    return head;
}

struct node* delete(struct node* head, int val) {
    struct node* temp = head;
    struct node* prev = NULL;
    while(temp!= NULL) {
        if (temp->data == val) {
            if (prev == NULL) {
                head = temp->next;
                if (head!= NULL) {
                    head->prev = NULL;
                }
            } else {
                prev->next = temp->next;
                if (temp->next!= NULL) {
                    temp->next->prev = prev;
                }
            }
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Element not found\n");
    return head;
}


void traverse(struct node* head) {
    printf("The elements in the linked list is: ");
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int n, ele;
    while (1) {
        printf("1-insert node at front\n2-insert node at last\n3-traverse element\n4-delete element\nEnter choice: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("Enter a element: ");
                scanf("%d", &ele);
                head = insertFirst(head, ele);
                break;
            case 2:
                printf("Enter a element: ");
                scanf("%d", &ele);
                head = insertLast(head, ele);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                printf("Enter a element: ");
                scanf("%d", &ele);
                head = delete(head, ele);
                break;

            default:
                return 0;
        }
    }
}