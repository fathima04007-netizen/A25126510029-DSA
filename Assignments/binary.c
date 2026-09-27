#include <stdio.h>
int main()
{
    int a[5],n,key;
    int low,high,mid;
    int count=0;
    printf("Enter number of IDs: ");
    scanf("%d",&n);
    printf("Enter IDs in ascending order:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter ID to search: ");
    scanf("%d",&key);
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        count++;
        if(a[mid]==key)
        {
            printf("ID found at position %d\n",mid+1);
            printf("Comparisons=%d\n",count);
            return 0;
        }
        else if(key<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    printf("ID not found\n");
    printf("Comparisons=%d\n",count);
    return 0;
}