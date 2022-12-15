// A complete working C program to demonstrate all insertion methods
// on Linked List
#include <stdio.h>
#include <stdlib.h>

// Criando o nó
struct Node {
  int data;
  struct Node *next;
};

/* Dá uma referencia (pointer to pointer) para o HEAD da lista
   e um int, insere um novo nó na parte da frente da lista. */
void push(struct Node **head_ref) {

  /* 1. Aloca o nó */
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  /* 2. coloca os dados  */
  int new_data = rand() % 999;
  new_node->data = new_data;

  /* 3. Define o "próximo" do novo nó como HEAD */
  new_node->next = (*head_ref);

  /* 4. Move o head pro início do novo nó */
  (*head_ref) = new_node;
}

// função requerida para insertAfter
int getCurrSize(struct Node *node) {
  int size = 0;

  while (node != NULL) {
    node = node->next;
    size++;
  }
  return size;
}

// Recebe o nó anterior, insere um nó novo após este
// function to insert after nth node
void insertAfter(struct Node **head, int n) {
  int size = getCurrSize(*head);

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  int data = rand() % 999;
  newNode->data = data;
  newNode->next = NULL;

  // Can't insert if position to insert is greater than size of Linked List
  // can insert after negative pos
  if (n < 0 || n > size)
    printf("Invalid position to insert\n");

  // inserting first node
  else if (n == 0) {
    newNode->next = *head;
    *head = newNode;
  }

  else {
    // temp used to traverse the Linked List
    struct Node *temp = *head;

    // traverse till the nth node
    while (--n)
      temp = temp->next;

    // assign newNode's next to nth node's next
    newNode->next = temp->next;
    // assign nth node's next to this new node
    temp->next = newNode;
    // newNode inserted b/w 3rd and 4th node
  }
}

/* Recebe uma referência (pointer to pointer) para o HEAD da lista e um int,
adiciona um novo node ao fim da lista. */
void append(struct Node **head_ref) {
  /* 1. Aloca o nó */
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  struct Node *last = *head_ref; /* used in step 5*/

  /* 2. coloca os dados  */
  int new_data = rand() % 999;
  new_node->data = new_data;

  /* 3. Este novo nó será o último da lista, então transforma o "próximo" em
   * NULL */
  new_node->next = NULL;

  /* 4. Se a lista estiver fazia, esse novo nó será HEAD */
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }

  /* 5. Caso não esteja vazia, anda-se até o fim da lista */
  while (last->next != NULL)
    last = last->next;

  /* 6. Define o "próximo" do ultimo nó como o novo nó criado */
  last->next = new_node;
  return;
}

// Printa começando por HEAD
void printList(struct Node *node) {
  printf("\n");
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

void deleteN(struct Node **head, int position) {
  struct Node *temp;
  struct Node *prev;
  temp = *head;
  prev = *head;
  for (int i = 0; i < position; i++) {
    if (i == 0 && position == 1) {
      *head = (*head)->next;
      free(temp);
    } else {
      if (i == position - 1 && temp) {
        prev->next = temp->next;
        free(temp);
      } else {
        prev = temp;

        // Posição maior que o número de nós na lista
        if (prev == NULL)
          break;
        temp = temp->next;
      }
    }
  }
}

// MAIN
int main() {
  // Começando com a lista vazia
  struct Node *head = NULL;

  int choice;
  int inputValue;

  while (1) {
    printf("\nQual operação realizar na lista ligada?");
    printf("\n1.Incluir item no fim da lista) \n2. Incluir item no começo da "
           "lista \n3. Inserir após um nó existente \n4. Excluir um nó "
           "existente \n5. Exibir lista \n0.Sair");
    printf("\n\nEscolha: \n\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      append(&head);
      break;
    case 2:
      push(&head);
      break;
    case 3:
      printf("Digite a posição do nó para criar um novo nó após este: \n");
      scanf("%d", &inputValue);
      insertAfter(&head, inputValue);
      break;
    case 4:
      printf("Digite a posição do nó que deve ser excluido: \n");
      scanf("%d", &inputValue);
      deleteN(&head, inputValue - 1);
      break;
    case 5:
      printList(head);
      break;
    case 0:
      exit(0);

    default:
      printf("\nEscolha inválida, favor digitar um valor de 1 à 3; ou 0 para "
             "sair.");
    }
  }

  return 0;
}
