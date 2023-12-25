#include <stdio.h>

int main()
{
    int n,i,j,k,arr[10];
    printf("Enter the size of the array");
    scanf("%d",&n);

    printf("Enter the elements of the array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
int check;
for(i=0;i<n-2;i++)
{
    for(j=i+1;j<n-1;j++)
    {
        for(k=i+2;k<n-2;k++)
        {
            if(arr[i]+arr[j]+arr[k]==0)
            printf("The triplets formed are %d%d%d",arr[i],arr[j],arr[k]);
            check=1;
        }
    }
if (check==0)
 printf("no triplets formed");
}
}