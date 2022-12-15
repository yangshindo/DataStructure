// Stack implementation in C

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100 //quantidade máxima de itens no stack

int count = 0;

// Creating a stack
struct stack {
  int items[SIZE]; 
  int top;
};
typedef struct stack st;

void createEmptyStack(st *s) {
  s->top = -1;
}

// Checa se a pilha está cheia
int isfull(st *s) {
  if (s->top == SIZE - 1)
    return 1;
  else
    return 0;
}

// Checa se a pilha está vazia
int isempty(st *s) {
  if (s->top == -1)
    return 1;
  else
    return 0;
}

// Adiciona elemento no topo da pilha
void push(st *s) {
  if (isfull(s)) {
    printf("A pilha está cheia.");
  } else {
    int newItem = rand() % 999;
    s->top++;
    s->items[s->top] = newItem;
    printf("\nItem incluido no topo da pilha: %d \n", newItem);
  }
  count++;
  
}

// Remove elemento do topo da pilha
void pop(st *s) {
  if (isempty(s)) {
    printf("\nA pilha está vazia \n");
  } else {
    printf("\nItem removido do topo= %d", s->items[s->top]);
    s->top--;
  }
  count--;
  printf("\n");
}

// Print elements of stack
void printStack(st *s) {
  printf("\nPilha atual: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", s->items[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  int ch;
  st *s = (st *)malloc(sizeof(st));
  
  createEmptyStack(s);

  int choice;

    while (1)
    {
        printf("\nQual operação realizar na pilha?");
        printf("\n1.Incluir no topo (push) \n2.Remover do topo(pop) \n3.Mostrar a pilha (print) \n0.Sair");
        printf("\n\nEscolha: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(s);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            printStack(s);
            break;
        case 0:
            exit(0);

        default:
            printf("\nEscolha inválida, favor digitar um valor de 1 à 3; ou 0 para sair.");
        }
    }
}