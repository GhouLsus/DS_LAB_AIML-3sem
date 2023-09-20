#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int day;
    int month;
    int year;
} DOB;

typedef struct
{
    int house_number;
    int zip_code;
    char state[50];
} ADDRESS;

typedef struct
{
    char name[100];
    DOB dob;
    ADDRESS add;
} EMP;

void read(EMP *E, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter the employee name");
        scanf("%s", (E + i)->name);
        printf("Enter the employee day of birth");
        scanf("%d", &(E + i)->dob.day);
        printf("Enter the employee month of birth");
        scanf("%d", &(E + i)->dob.month);
        printf("Enter the employee year of birth");
        scanf("%d", &(E + i)->dob.year);
        printf("Enter the employee house number");
        scanf("%d", &(E + i)->add.house_number);
        printf("Enter the employee house zip code");
        scanf("%d", &(E + i)->add.zip_code);
        printf("Enter the employee state");
        scanf("%s", &(E + i)->add.state);
    }
}

void display(EMP *E, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Details of the %d employee", (i + 1));
        printf("\nName of the employee=%s\n Date of birth {%d-%d-%d}\n Address {House No-%d - zip code - %d State - %s}\n", (E + i)->name, (E + i)->dob.day, (E + i)->dob.month, (E + i)->dob.year, (E + i)->add.house_number, (E + i)->add.zip_code, (E + i)->add.state);
    }
}

int main()
{
    int n;
    printf("Enter the number of employees");
    scanf("%d", &n);

    EMP *Em;
    Em = (EMP *)malloc(n * sizeof(EMP *));

    read(Em, n);
    display(Em, n);

    return 0;
}