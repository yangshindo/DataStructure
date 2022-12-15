#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *arrayToList(int arr[], int n)
{
    struct Node *root = NULL;
    for (int i = 0; i < n; i++)
        insert(&root, arr[i]);
return root;
}

void insert(struct Node** root, int item)
{
   struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    struct Node* ptr;
    temp->data = item;
    temp->next = NULL;
    if (*root == NULL)
        *root = temp;
    else {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void print(struct Node* root)
{
    while (root != NULL) {
        printf("%d->", root->data);
        root = root->next;
    }
}


void arrayToLinked(int arr[], int size)
{
    struct Node* root = arrayToList(arr, size);

    //Print Lista Ligada
    while (root != NULL) {
        printf("%d->", root->data);
        root = root->next;
    }
}

int main(void) {

  int size; // tamanho do array
  printf("Qual o tamanho do array de números aleatórios que você deseja gerar? "
         "(máximo 1 milhão)?\n\n");
  scanf("%d", &size);
  int *randArray;
  randArray = (int *)malloc(size * sizeof(int)); // mallocando;

  int i;
  for (i = 0; i < size; i++)
    randArray[i] = rand() % RAND_MAX; // máximo random

  // Printa o Array
  /*
  printf("\n");
  for (i = 0; i < size; i++) {11
    printf("%d \n", randArray[i]);
  }
  */

  int structure;
  printf(
      "\n Informe qual tipo de estrutura desejada:\n 1- Lista Ligada\n 2 -Pilha \n "
      "3- Fila\n 0- Sair \n\n");
  scanf("%d", &structure);



  switch (structure) {
  case 1:
    arrayToLinked(randArray, size);
    break;
  case 0:
    exit(0);
  default:
    printf("O método escolhido foi inválido, favor digitar apenas o número do "
           "método desejado");
  }
}
