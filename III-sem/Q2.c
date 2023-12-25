#include <stdio.h>

void sparseM(int m, int n, int mat[m][n])
{
    int count=0;
    int i,j;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(mat[i][j]==0)
            count++;
        }
    }
    if (count>(m*n/2))
    {
        printf("it is a sparse matrix");
    }
    else
        printf("not a sparse matrix");
}

int main()
{
    int m,n,i,j;
    printf("Enter the dimension of the matrix");
    scanf("%d",&m,&n);
    
    int mat[m][n];
    printf("Enter the elements of the matrix/n");

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
       {
        scanf("%d",&mat[i][j]);
       }
    }
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
       {
        printf("%d",&mat[i][j]);
       }
       printf("\n");
    }
sparseM(m,n,mat);
return 0;
}