#include <stdio.h>
#include <stdlib.h>

/*
A linked list is a fundamental data structure used to organize and manage a collection of elements. Unlike arrays, which store elements in contiguous memory locations, linked lists use nodes that are connected through pointers.

Single linked lists consist of nodes, where each node contains two parts:

Data: The actual value or payload stored in the node.
Next Pointer: A reference to the next node in the list.
Here’s how it works:

The first node is called the head. It holds the initial data and points to the next node.
Each subsequent node follows the same pattern: data and a pointer to the next node.
The last node points to null, indicating the end of the list.
Advantages of Single Linked Lists:

Dynamic Size: Linked lists can grow or shrink dynamically, unlike fixed-size arrays.
Efficient Insertions and Deletions: Adding or removing elements is efficient because we only need to update pointers.
Memory Flexibility: Nodes can be scattered in memory, allowing efficient memory allocation.

*/

struct node {
    int data;
    struct node* next;
};

struct node* insertFirst(struct node* head, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = head;
    head = temp;
    return head;
}

struct node* insertLast(struct node* head, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        struct node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
    return head;
}

struct node* delete(struct node* head, int val) {
    struct node* temp = head;
    struct node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == val) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
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
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct node* reverseList(struct node* head) {
    struct node* prev = NULL;
    struct node* stat = head;
    struct node* nex = NULL;
    while (stat != NULL) {
        nex = stat->next;
        stat->next = prev;
        prev = stat;
        stat = nex;
    }
    return prev;
}

struct node* insertMiddle(struct node* head, int val, int pos) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;

    if (head == NULL || pos == 1) {
        temp->next = head;
        head = temp;
    } else {
        struct node* current = head;
        int count = 1;
        while (current->next != NULL && count < pos - 1) {
            current = current->next;
            count++;
        }
        if (count != pos - 1) {
            printf("Position out of range\n");
            free(temp);
            return head;
        }
        temp->next = current->next;
        current->next = temp;
    }
    return head;
}

void search(struct node* head, int val) {
    struct node* temp = head;
    int count = 1;
    while (temp != NULL) {
        if (temp->data == val) {
            printf("Element found at position %d\n", count);
            return;
        }
        temp = temp->next;
        count++;
    }
    printf("Element not found\n");
}

int main() {
    struct node* head = NULL;
    struct node* freeer;

    int n, ele, pos;
    while (1) {
        printf("1-insert node at front\n2-insert node at last\n3-traverse element\n4-delete element\n5-reverse the list\n6-insert node at middle\n7-search for element\nEnter choice: ");
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
            case 5:
                head = reverseList(head);
                break;
            case 6:
                printf("Enter a element: ");
                scanf("%d", &ele);
                printf("Enter a position: ");
                scanf("%d", &pos);
                head = insertMiddle(head, ele, pos);
                break;
            case 7:
                printf("Enter a element: ");
                scanf("%d", &ele);
                search(head, ele);
                break;
            default:
                freeer = head;
                while (head!= NULL) {
                    head = head->next;
                    free(freeer);
                    freeer = head;
                }
                return 0;
        }
    }
}