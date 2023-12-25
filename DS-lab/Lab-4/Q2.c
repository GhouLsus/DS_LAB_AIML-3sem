#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
   char name[50];
   int roll;
   int CGPA;
} student;

student input(student *s1, int n) 
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the student name:");
        scanf("%s",(s1+i)->name);
        printf("Enter the roll number");
        scanf("%d",(s1+i)->roll);
        printf("Enter CGPA:");
        scanf("%d",(s1+i)->CGPA);
    }
}

student display(student *s1, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\name of student: %s \nRoll number: %d \nCGPA: %d\n",(s1+i)->name,(s1+i)->roll,(s1+i)->CGPA);
    }
}

student sort(student *st,int n)
{
    student temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (st[i].roll > st[j].roll)
            {
                temp=st[i];
                st[i]=st[j];
                st[j]=temp;
            }
        }
    }
}
int main()
{
    int n;
    student *s1=(int*)malloc(sizeof(int));
    printf("Enter the number of students");
    scanf("%d",&n);

    input(&s1, n);
    printf("%d",s1->roll);
    printf("\nThe details of the student are:");
    printf("\nThe name of student:%s \nRoll number:%d \nCGPA:%d\n",s1[0]->name,s1[0]->roll,s1[0]->CGPA);
    
    sort(&s1,n);

    printf("\nDetails of students sorted in ascending order:\n");
    display(&s1, n);
    return 0;
}