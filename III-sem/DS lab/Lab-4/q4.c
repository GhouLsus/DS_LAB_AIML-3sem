#include <stdio.h>
#include <stdlib.h>

struct DOB
{
    int day;
    int *month;
    int year;
};

struct STU_INFO
{
    int reg_no;
    char *name;
    char address[50];
};

struct COLLEGE
{
    char *college_name;
    char university_name[50];
};

struct STUDENT
{
    struct DOB *db;
    struct STU_INFO stu;
    struct COLLEGE col;
};
int main()
{
    int N;
    printf("Enter number of records:");
    scanf("%d", &N);
    struct STUDENT *s1;
    s1 = (struct STUDENT *)malloc(sizeof(struct STUDENT));

    int i;
    for (i = 0; i < N; i++)
    {
        s1[i].db = (struct DOB *)malloc(sizeof(struct DOB));
        s1[i].db->month = (int *)malloc(sizeof(int));
        s1[i].stu.name = (char *)malloc(30 * sizeof(char));
        s1[i].col.college_name = (char *)malloc(30 * sizeof(char));
    }
    printf("Enter %d student details \n", N);
    for (i = 0; i < N; i++) // n oR N
    {
        printf("Enter date of birth");
        scanf("%d %d %d", &s1[i].db->day, &s1[i].db->month, &s1[i].db->year);
        printf("Enter registration number:");
        scanf("%d", &s1[i].stu.reg_no);
        printf("Enter name:");
        scanf("%s", s1[i].stu.name);
        printf("Enter address");
        scanf("%s", s1[i].stu.address);
        printf("Enter College name:");
        scanf("%s", s1[i].col.college_name);
        printf("Enter the university name");
        scanf("%s", s1[i].col.university_name);
    }
    printf("Displaying the records");
    for (i = 0; i < N; i++)
    {
        printf("\n Date of birth: %d-%d-%d \nRegistration number: %d \n name: %s \n Address: %s \n College name: %s \n University name: %s\n", s1[i].db->day, s1[i].db->month, s1[i].db->year, s1[i].stu.reg_no, s1[i].stu.name, s1[i].stu.address, s1[i].col.college_name, s1[i].col.university_name);
    }
    return 0;
}
