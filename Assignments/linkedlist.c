#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
void insert(int x)
{
    struct Node *newnode;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=head;
    head=newnode;
}
void search(int x)
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==x)
        {
            printf("Roll number found\n");
            return;
        }
        temp=temp->next;
    }
    printf("Roll number not found\n");
}
void delete(int x)
{
    struct Node *temp=head;
    struct Node *prev=NULL;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(head->data==x)
    {
        head=head->next;
        free(temp);
        printf("Roll number deleted\n");
        return;
    }
    while(temp!=NULL && temp->data!=x)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Roll number not found\n");
        return;
    }
    prev->next=temp->next;
    free(temp);
    printf("Roll number deleted\n");
}
void display()
{
    struct Node *temp=head;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    insert(10);
    display();
    insert(20);
    display();
    insert(30);
    display();
    search(20);
    delete(20);
    display();
    search(50);
    return 0;
}