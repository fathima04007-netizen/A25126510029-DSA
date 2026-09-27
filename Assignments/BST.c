#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* create(int x)
{
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct Node* insert(struct Node *root, int x)
{
    if(root==NULL)
        return create(x);
    if(x<root->data)
        root->left=insert(root->left, x);
    else
        root->right=insert(root->right, x);
    return root;
}
void inorder(struct Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct Node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void search(struct Node *root,int key)
{
    if(root==NULL)
    {
        printf("Value not found\n");
        return;
    }
    if(root->data==key)
    {
        printf("Value found\n");
        return;
    }
    if(key<root->data)
        search(root->left,key);
    else
        search(root->right,key);
}
int main()
{
    struct Node *root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,20);
    insert(root,40);
    insert(root,60);
    insert(root,80);
    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");
    search(root,60);
    return 0;
}