#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    struct node *next;
} Node;

typedef struct
{
    Node *first;
    Node *last;
    int size;
} Queue;

void createQueue(Queue *queue)
{
    queue->first = NULL;
    queue->last = NULL;
    queue->size = 0;
}

void insertInQueue(Queue *queue)
{
    int newValue = rand() % 999;
    Node *helper, *newItem = malloc(sizeof(Node));
    if (newItem)
    {
        newItem->value = newValue;
        newItem->next = NULL;
        if (queue->first == NULL)
        {
            queue->first = newItem;
            queue->last = newItem;
        }
        else
        {
            queue->last->next = newItem;
            queue->last = newItem;
        }
        queue->size++;
    }
    else
        printf("\nErro no malloc (memória não alocada).\n");
}

Node *removeFromQueue(Queue *queue)
{
    Node *remove = NULL;

    if (queue->first)
    {
        remove = queue->first;
        queue->first = remove->next;
        queue->size--;
    }
    else
        printf("A fila encontra-se vazia.\n");
    return remove;
}

void printQueue(Queue *queue)
{
    if (queue->first)
    {
        Node *helper = queue->first;
        printf("\nInício\t");
        while (helper)
        {
            printf("\n%d ", helper->value);
            helper = helper->next;
        }
        printf("\n");
    }
    else
    {
        printf("\nA fila encontra-se vazia.\n");
    }
}

int main()
{
    Node *toRemove;
    Queue queue;
    int operation, value;

    createQueue(&queue);

    while (1)
    {
        printf("\n1 - Inserir\n2 - Remover\n3 - Imprimir\n0- Sair\n");
        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
            insertInQueue(&queue);
            break;
        case 2:
            toRemove = removeFromQueue(&queue);
            if (toRemove)
            {
                printf("\nRetirado da fila: %d\n", toRemove->value);
                free(toRemove);
            }
            break;
        case 3:
            printQueue(&queue);
            break;
        case 0:
            exit(0);
        default:
            if (operation != 0)
                printf("\nFavor selecionar uma opção válida (de 0 à 3)\n");
        }
    }
}