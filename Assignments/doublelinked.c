#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char page[20];
    struct Node *prev;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *last=NULL;
void insert(char page[])
{
    struct Node *newnode;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    strcpy(newnode->page,page);
    newnode->next=NULL;
    newnode->prev=last;
    if(head==NULL)
        head=newnode;
    else
        last->next=newnode;
    last=newnode;
}
void forward()
{
    struct Node *temp=head;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Forward: ");
    while(temp!=NULL)
    {
        printf("%s ",temp->page);
        temp=temp->next;
    }
    printf("\n");
}
void backward()
{
    struct Node *temp=last;
    if(last==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Backward: ");
    while(temp!=NULL)
    {
        printf("%s ",temp->page);
        temp=temp->prev;
    }
    printf("\n");
}
int main()
{
    insert("Google");
    insert("YouTube");
    insert("Wikipedia");
    insert("Amazon");
    forward();
    backward();
    return 0;
}