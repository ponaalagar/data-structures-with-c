#include <stdio.h>
#include <stdlib.h>

/*
A circular linked list is a variation of linked lists where the last node points back to the first node (forming a loop). Unlike singly or doubly linked lists, which have a linear structure, circular linked lists wrap around like a circle.

Here are the key features of a circular linked list:

Node Structure:
Each node contains two parts:
Data: The actual value stored in the node.
Next Pointer: Points to the next node (and wraps around to the head for the last node).
Advantages of Circular Linked Lists:
Circular Nature: The circular arrangement allows seamless traversal from the last node back to the head.
Efficient Operations: Insertions and deletions at both ends (head and tail) are straightforward.
Applications: Circular linked lists are used in scheduling algorithms, circular buffers, and managing resources with periodic behavior.
*/

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBegin(struct node** head, int data) {
    struct node* newNode = createNode(data);
    if (!newNode) {
        return;
    }
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
    } else {
        struct node* temp = *head;
        while (temp->next!= *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    if (!newNode) {
        return;
    }
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
    } else {
        struct node* temp = *head;
        while (temp->next!= *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertAtMiddle(struct node** head, int data, int pos) {
    struct node* newNode = createNode(data);
    if (!newNode) {
        return;
    }
    if (*head == NULL || pos == 0) {
        insertAtBegin(head, data);
    } else {
        int count = 0;
        struct node* temp = *head;
        while (temp->next!= *head && count < pos - 1) {
            temp = temp->next;
            count++;
        }
        if (temp->next == *head) {
            insertAtEnd(head, data);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deleteAtBegin(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        struct node* temp = *head;
        while (temp->next!= *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
    }
}

void deleteAtMiddle(struct node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else if (pos == 0) {
        deleteAtBegin(head);
    } else {
        int count = 0;
        struct node* temp = *head;
        while (temp->next!= *head && count < pos - 1) {
            temp = temp->next;
            count++;
        }
        if (temp->next == *head) {
            deleteAtBegin(head);
        } else {
            struct node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            free(nodeToDelete);
        }
    }
}

void printList(struct node* head) {
    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp!= head);
    printf("\n");
}

int main() {
    struct node* head = NULL;

    insertAtBegin(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Circular Linked List: ");
    printList(head);

    insertAtMiddle(&head, 25, 3);

    printf("Circular Linked List after inserting 25 at position 3: ");
    printList(head);

    deleteAtBegin(&head);

    printf("Circular Linked List after deleting at the beginning: ");
    printList(head);

    deleteAtMiddle(&head, 2);

    printf("Circular Linked List after deleting at position 2: ");
    printList(head);

    deleteAtMiddle(&head, 4);

    printf("Circular Linked List after deleting at position 4: ");
    printList(head);

    return 0;
}