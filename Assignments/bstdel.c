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
        root->left=insert(root->left,x);
    else
        root->right=insert(root->right,x);
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
struct Node* minimum(struct Node *root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;
}
struct Node* delete(struct Node *root,int key)
{
    struct Node *temp;
    if(root==NULL)
        return root;
    if(key<root->data)
        root->left=delete(root->left,key);
    else if(key>root->data)
        root->right=delete(root->right,key);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        if(root->left==NULL)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL)
        {
            temp=root->left;
            free(root);
            return temp;
        }
        temp=minimum(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
    return root;
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
    printf("Before deletion: ");
    inorder(root);
    root=delete(root,20);
    printf("\nAfter deleting leaf node: ");
    inorder(root);
    root=delete(root,30);
    printf("\nAfter deleting one-child node: ");
    inorder(root);
    root=delete(root,50);
    printf("\nAfter deleting two-child node: ");
    inorder(root);
    return 0;
}