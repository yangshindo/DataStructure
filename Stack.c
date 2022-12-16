#include <stdio.h>
#include <stdlib.h>

// struct Nó
typedef struct node
{
    int value;
    struct node *next;
} Node;

// struct Pilha
typedef struct stack
{
    Node *top;
    int size;
} Stack;

void print(Node *node)
{
    if (node)
    {
        printf("%d\n", node->value);
        print(node->next);
    }
}

// Empilhar
void stackUp(Stack *s)
{
    Node *node = malloc(sizeof(Node));
    int newValue = rand() % 999;
    node->value = newValue;
    node->next = s->top;
    s->top = node;
    printf("\n");
    print(s->top);
}

//  Retorna topo da pilha (NULL caso esteja vazia);
Node *unstack(Stack *s)
{
    Node *node = NULL;
    if (s->top)
    {
        node = s->top;
        s->top = node->next;
    }
    printf("\nLista após desempilhar:\n");
    printf("\n");
    print(s->top);
    return node;
}

int main()
{
    int operation;
    Node *node;
    Stack s;
    s.size = 0;
    s.top = NULL;

    while (1)
    {
        printf("\n1 - Empilhar\n2 - Desempilhar\n3 - Exibir\n0 - Sair\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            stackUp(&s);
            break;
        case 2:
            node = unstack(&s);
            if (node)
            {
                printf("\nValor desempilhado: %d\n", node->value);
            }
            break;
        case 3:
            printf("\n");
            print(s.top);
            break;
        case 0:
            printf("Encerrado. \n");
            exit(0);
        default:
            printf("Favor escolher uma das opções válidas\n");
            break;
        }
    }
}