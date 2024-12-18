#include<stdio.h>
#include<stdlib.h>

//AVL tree is a self balancing binary search tree 

struct node{
    int data;
    int height;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to get the height of a node
int getHeight(struct node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Function to update the height of a node
void updateHeight(struct node* node) {
    node->height = (getHeight(node->left) > getHeight(node->right)) ?
                   getHeight(node->left) + 1 : getHeight(node->right) + 1;
}

// Function to get the balance factor of a node
int getBalanceFactor(struct node* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Function to perform left rotation
struct node* leftRotate(struct node* z) {
    struct node* y = z->right;
    struct node* T2 = y->left;

    y->left = z;
    z->right = T2;

    updateHeight(z);
    updateHeight(y);

    return y;
}

// Function to perform right rotation
struct node* rightRotate(struct node* z) {
    struct node* y = z->left;
    struct node* T3 = y->right;

    y->right = z;
    z->left = T3;

    updateHeight(z);
    updateHeight(y);

    return y;
}

// Function to rebalance the tree
struct node* rebalance(struct node* node) {
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1) {
        if (getHeight(node->left->left) >= getHeight(node->left->right)) {
            return rightRotate(node);
        } else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (balanceFactor < -1) {
        if (getHeight(node->right->right) >= getHeight(node->right->left)) {
            return leftRotate(node);
        } else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

// Function to insert a node into the AVL tree
struct node* insertNode(struct node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    } else {
        printf("Duplicate data\n");
        return node;
    }

    updateHeight(node);

    node = rebalance(node);

    return node;
}

// Function to print the AVL tree
void printTree(struct node* node, int indent) {
    if (node != NULL) {
        printTree(node->right, indent + 4);
        for (int i = 0; i < indent; i++) {
            printf(" ");
        }
        printf("%d\n", node->data);
        printTree(node->left, indent + 4);
    }
}

int main() {
    struct node* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    printf("AVL Tree:\n");
    printTree(root, 0);

    return 0;
}