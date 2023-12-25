
// #include <stdio.h>
// #include <stdlib.h>
// #include "functions.h"

// void deleteDuplicates(Node **list)
// {
//     Node *i1 = (Node *)malloc(sizeof(Node));
//     Node *i2 = (Node *)malloc(sizeof(Node));
//     i1 = *list;
//     i2 = *list;
//     while (i1->next != NULL)
//     {
//         int x = i1->val;
//         i2 = i1->next;
//         while (i2 != NULL)
//         {
//             if (i2->val != x)
//                 break;
//             else
//                 i2 = i2->next;
//         }
//         if (i2 == NULL)
//         {
//             i1->next = NULL;
//             break;
//         }
//         else if (i2 != i1->next)
//             i1->next = i2;
//         i1 = i1->next;
//     }
// }

// int main()
// {
//     int n, x;
//     Node *list = (Node *)malloc(sizeof(Node));
//     printf("enter length of list ");
//     scanf("%d", &n);
//     printf("enter input for list:\n");
//     input(list, n);
//     printf("after removing duplicates: ");
//     deleteDuplicates(&list);
//     display(list);
// }
#include <stdio.h>
#include <stdlib.h>
struct Node
{
          int data;
          struct Node *next;
};
struct Node *first = NULL, *temp, *t;
void Add(int a)
{
          temp = (struct Node *)malloc(sizeof(struct Node));
          temp->data = a;
          temp->next = NULL;
          if (first == NULL)
          {
                    first = temp;
          }
          else
          {
                    struct Node *ptr;
                    ptr = first;
                    while (ptr->next != NULL)
                    {
                              ptr = ptr->next;
                    }
                    ptr->next = temp;
          }
}
void DelDup()
{
          temp = first;
          while (temp->next!=NULL)
          {
                    int a = temp->data;
                    struct Node *s;
                    s = temp;
                    t = temp->next;
                    while(t != NULL)
                    {
                              if(t->data == a)
                              {
                                        s->next = t->next;
                                        t = t->next; 
                              }
                              t = t->next;
                              s = s->next;
                    }
                    temp = temp->next;
          }
}
void Display()
{
          if (first == NULL)
          {
                    printf("List is Empty\n");
          }
          else
          {
                    t = first;
                    while (t->next != NULL)
                    {
                              printf("|%d|-->",t->data);
                              t = t->next;
                    }
                    printf("NULL\n");
          }
}
int main()
{
          int ele;
          printf("Add to Linked List (Enter 1990 to exit) : ");
          do
          {
                    printf("Input : ");
                    scanf("%d", &ele);
                    Add(ele);
          } while (ele != 1990);
          DelDup();
          Display();
          return 0;
}