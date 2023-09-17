#include <stdio.h>

int TOH(int n, char from_rod, char to_rod, char aux_rod)
{
    static int i=0;
    if (n==0){
        return(i);
    }
    TOH(n-1,from_rod,aux_rod,to_rod);
    printf("Move disk %d from %c to %c \n",n,from_rod,to_rod);
    TOH(n-1,aux_rod,to_rod,from_rod);
    i++;
}
int main()
{
    int n;
    printf("Enter the number of disks\n");
    scanf("%d",&n);
    printf("%d\n",TOH(n,'A','B','C'));
    return 0;
}