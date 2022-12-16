#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node *next;
} Node;

typedef struct list
{
  Node *beginning, *end;
  int size;
} List;

void createList(List *list)
{
  list->beginning = NULL;
  list->size = 0;
}

// Inserir no início
void insertAtTheBeginning(List *list)
{
  Node *newNode = malloc(sizeof(Node));
  int newValue = rand() % 999;
  if (newNode)
  {
    newNode->value = newValue;
    newNode->next = list->beginning;
    list->beginning = newNode;
    list->size++;
  }
  else
    printf("\nErro no malloc (memória não alocada).\n");
}

// Inserir no fim
void insertAtTheEnd(List *list)
{
  Node *helper, *newNode = malloc(sizeof(Node));
  int newValue = rand() % 999;
  if (newNode)
  {
    newNode->value = newValue;
    newNode->next = NULL;

    // Verifica se é o primeiro elemento
    if (list->beginning == NULL)
      list->beginning = newNode;
    else
    {
      helper = list->beginning;
      while (helper->next)
        helper = helper->next;
      helper->next = newNode;
    }
    list->size++;
  }
  else
    printf("\nErro no malloc (memória não alocada).\n");
}

void insertAfterXValue(List *list, int previousValue)
{
  Node *helper, *newNode = malloc(sizeof(Node));
  int newValue = rand() % 999;
  if (newNode)
  {
    newNode->value = newValue;
    // é o primeiro?
    if (list->beginning == NULL)
    {
      newNode->next = NULL;
      list->beginning = newNode;
    }
    else
    {
      helper = list->beginning;
      while (helper->value != previousValue && helper->next)
        helper = helper->next;
      newNode->next = helper->next;
      helper->next = newNode;
    }
    list->size++;
  }
  else
    printf("\nErro no malloc (memória não alocada).\n");
}

// remover um elemento da lista
void removeItem(List *list, int choosenValue)
{
  Node *beginning = list->beginning; // ajustando ponteiro para o início
  Node *toRemove = NULL;             // ajustando ponteiro para o nó que será removido

  // se o primeiro valor da lista for o valor escolhido pelo usuário, remove
  // ele.
  if (beginning != NULL && list->beginning->value == choosenValue)
  {
    toRemove = list->beginning;
    list->beginning = toRemove->next;
    if (list->beginning == NULL) // caso essa remoção esvazie a lista
      list->end = NULL;
  }
  else
  {
    while (beginning != NULL && beginning->next != NULL &&
           beginning->next->value != choosenValue)
    {
      beginning = beginning->next; // anda através da lista procurando o valor
                                   // escolhido para remover
    }
    if (beginning != NULL && beginning->next != NULL)
    {
      toRemove = beginning->next;
      beginning->next = toRemove->next;
      if (beginning->next == NULL) // caso o elemento removido tenha feito a
                                   // lista restar apenas 1 elemento
        list->end =
            beginning; // o primeiro e o último agora são o mesmo elemento
    }
  }
  /*Abre espaço de memória após remover o elmento e decrementa o tamanho da
   * lista*/
  if (toRemove)
  {
    free(toRemove);
    list->size--;
  }
}

void printList(List list)
{
  Node *node = list.beginning;
  while (node)
  {
    printf("%d ", node->value);
    node = node->next;
  }
  printf("\n\n");
}

int main()
{
  int operation, userInputValue;
  List list;

  createList(&list);

  while (1)
  {
    printf("\n1 - Inserir no início\n2 - Inserir no fim\n3 - Inserir após um "
           "valor específico\n4- Remover valor da lista\n5 - Imprimir Lista\n0- Sair\n");
    scanf("%d", &operation);

    switch (operation)
    {
    case 1:
      insertAtTheBeginning(&list);
      break;
    case 2:
      insertAtTheEnd(&list);
      break;
    case 3:
      printf("\nVocê deseja adicionar um novo elemento após qual valor "
             "presente na lista?\n");
      scanf("%d", &userInputValue);
      insertAfterXValue(&list, userInputValue);
      break;
    case 4:
      printf("\nQual valor você deseja excluir da lista?\n");
      scanf("%d", &userInputValue);
      removeItem(&list, userInputValue);
      break;
    case 5:
      printList(list);
      break;
    case 0:
      exit(0);
      break;
    default:
      if (operation != 0)
        printf("\nFavor selecionar uma opção válida (de 0 à 3)\n");
      break;
    }
  }
}