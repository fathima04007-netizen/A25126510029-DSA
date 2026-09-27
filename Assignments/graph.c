#include <stdio.h>
int a[10][10];
int visited[10];
int n;
void BFS(int start)
{
    int queue[10];
    int front=0,rear=0;
    int i,v;
    visited[start]=1;
    queue[rear++]=start;
    while(front<rear)
    {
        v=queue[front++];
        printf("%d ",v);
        for(i=0;i<n;i++)
        {
            if(a[v][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }
}
void DFS(int v)
{
    int i;
    visited[v]=1;
    printf("%d ",v);
    for(i=0;i<n;i++)
    {
        if(a[v][i]==1 && visited[i]==0)
            DFS(i);
    }
}
int main()
{
    int start,i,j;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    printf("Enter starting vertex: ");
    scanf("%d",&start);
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("BFS: ");
    BFS(start);
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("\nDFS: ");
    DFS(start);
    return 0;
}