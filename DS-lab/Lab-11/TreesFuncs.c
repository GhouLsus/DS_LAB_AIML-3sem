// #include <stdio.h>
// #include <malloc.h>
// #include <stdlib.h>


// typedef struct{
//     int data;
//     struct Node* left;
//     struct Node* right;
// } Node;

// typedef struct {
//     Node *nodes[100];
//     int tos;
// } Stack;

// void push(Stack *s , Node * n){
//     s->nodes[++(s->tos)] = n;
// }

// Node * pop(Stack *s){
//     return (s->nodes[(s->tos)--]);
// }

// Node *createNode(int x){
//     Node *new = (Node *)malloc(sizeof(Node));
//     new->data = x;
//     new->left = NULL;
//     new->right = NULL; 
//     return new;
// }

// void inO (Node *tree){
//     if(tree!=NULL){
//         inO(tree->left);
//         printf("%d",tree->data);
//         inO(tree->right);
//     }
// }

// void PreO (Node *tree){
//     if(tree!=NULL){
//         printf("%d",tree->data);
//         PreO(tree->left);
//         PreO(tree->right);
//     }
// }

// void PostO (Node *tree){
//     if(tree!=NULL){
//         PostO(tree->left);
//         PostO(tree->right);
//         printf("%d",tree->data);
//     }
// }

// void createBT(Node ** tree) {
//     Node * iter = (Node *) malloc(sizeof(Node));
//     Node * root = (Node *) malloc(sizeof(Node));
//     Stack nodeStack;
//     nodeStack.tos = -1;
//     iter = NULL;
//     int x;
//     int inp = 0;
//     printf("Enter value of root ");
//     scanf("%d",&x);
//     iter = createNode(x);
//     push(&nodeStack,iter);
//     root = iter;
//     *tree = iter;

//     printf("\n1. Enter left, 2. Enter right, 3. Move up, -1. Exit");

//     do {
//         printf("\nEnter choice ");
//         scanf("%d",&inp);
//         if (inp == 1) {
//             printf("Enter value to insert ");
//             scanf("%d",&x);
//             Node * temp = createNode(x);
//             push(&nodeStack,iter);
//             iter->left = temp;
//             iter = iter->left;
//             printf("Moved left");
//         }
//         else if (inp == 2) {
//             printf("Enter value to insert ");
//             scanf("%d",&x);
//             Node * temp = createNode(x);
//             push(&nodeStack,iter);
//             iter->right = temp;
//             iter = iter->right;
//             printf("Moved right");
//         }
//         else if (inp == 3) {
//             if (nodeStack.tos == 0) {
//                 printf("Already at root");
//             }
//             else {
//                 iter = pop(&nodeStack);
//                 printf("Moved up");
//             }
//         }
//         else 
//             inp = -1;
//     } while(inp != -1);
// }
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct {
  int data;
  struct Node* left;
  struct Node* right;
} Node;

typedef struct {
  Node *nodes[100];
  int tos;
} Stack;

static Node *iter; // Use a static variable for iter

void push(Stack *s, Node *n) {
  s->nodes[++(s->tos)] = n;
}

Node *pop(Stack *s) {
  return (s->nodes[(s->tos)--]);
}

Node *createNode(int x) {
  Node *new = (Node *)malloc(sizeof(Node));
  new->data = x;
  new->left = NULL;
  new->right = NULL;
  return new;
}

void inO(Node *tree) {
  if (tree != NULL) {
    inO(tree->left);
    printf("%d", tree->data);
    inO(tree->right);
  }
}

void PreO(Node *tree) {
  if (tree != NULL) {
    printf("%d", tree->data);
    PreO(tree->left);
    PreO(tree->right);
  }
}

void PostO(Node *tree) {
  if (tree != NULL) {
    PostO(tree->left);
    PostO(tree->right);
    printf("%d", tree->data);
  }
}

void createBT(Node **tree) {
  // Use a static variable for iter instead of allocating it on the heap
  iter = (Node *)malloc(sizeof(Node));
  Node *root = (Node *)malloc(sizeof(Node));
  Stack nodeStack;
  nodeStack.tos = -1;
  int x;
  int inp = 0;

  printf("Enter value of root ");
  scanf("%d", &x);
  iter = createNode(x);
  push(&nodeStack, iter);
  root = iter;
  *tree = iter;

  printf("\n1. Enter left, 2. Enter right, 3. Move up, -1. Exit");

  do {
    printf("\nEnter choice ");
    scanf("%d", &inp);

    if (inp == 1) {
      printf("Enter value to insert ");
      scanf("%d", &x);
      Node *temp = createNode(x);
      push(&nodeStack, iter);
      iter->left = temp;
      iter = iter->left;
      printf("Moved left");
    } else if (inp == 2) {
      printf("Enter value to insert ");
      scanf("%d", &x);
      Node *temp = createNode(x);
      push(&nodeStack, iter);
      iter->right = temp;
      iter = iter->right;
      printf("Moved right");
    } else if (inp == 3) {
      if (nodeStack.tos == 0) {
        printf("Already at root");
      } else {
        iter = pop(&nodeStack);
        printf("Moved up");
      }
    } else {
      inp = -1;
    }
  } while (inp != -1);
}