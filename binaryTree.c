#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *right;  
    struct node *left;
};

struct node * create()
{
    int x;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the data(-1 to return ): ");
    scanf("%d",&x);
    if( x==-1)
    {
        return NULL;
    }
    newnode->data=x;
    printf("Enter left child of %d \n",x);
    newnode->left=create();
    printf("Enter right child of %d \n",x);
    newnode->right=create();
    return newnode;
}

void inorderTraverse(struct node *root)
{
    if (root==NULL)
    {
        return ;
    }
    inorderTraverse(root->left);
    printf("%d ",root->data);
    inorderTraverse(root->right);
    return ;
}

void preorderTraverse(struct node *root)
{
    if (root==NULL)
    {
        return ;
    }
    printf("%d ",root->data);
    preorderTraverse(root->left);
    preorderTraverse(root->right);
    return ;
}

void postorderTraverse(struct node *root){
    if (root==NULL)
    {
        return;
    }
    postorderTraverse(root->left);
    postorderTraverse(root->right);
    printf("%d ",root->data);
}

int main()
{
    struct node *root;
    root=create();
    printf("Inorder Traversal: \n");
    inorderTraverse(root);
    printf("\n");
    printf("Preorder Traversal: \n");
    preorderTraverse(root);
    printf("\n");
    printf("Postorder Traversal: \n");
    postorderTraverse(root);
    printf("\n");
    return 0;
}