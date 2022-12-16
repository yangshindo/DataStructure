#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}Node;

typedef struct {
    Node *first;
    Node *end;
    int size;
}Queue;

void createQueue(Queue *queue){
    queue->first = NULL;
    queue->end = NULL;
    queue->size = 0;
}

void insert(Queue *queue){
    Node *helper, *new = malloc(sizeof(Node));
    if(new){
        int newValue = rand() % 999;
        new->value = newValue;
        new->next = NULL;
        if(queue->first == NULL){
            queue->first = new;
            queue->first = new;
        }
        else{
            queue->end->next = new;
            queue->end = new;
        }
        queue->size++;
    }
    else
        printf("\nErro no malloc (memória não alocada).\n");
}

Node* remove(Queue *queue){
    Node *remove = NULL;

    if(queue->first){
        remove = queue->first;
        queue->first = remove->next;
        queue->size--;
    }
    else
        printf("A fila encontra-se vazia.\n");
    return remove;
}

void print(Queue *queue){
    Node *helper = queue->first;
    printf("\nInício\n");
    while(helper){
        printf("%d ", helper->value);
        helper = helper->next;
    }
    printf("\nFim\n")
}

int main(){
    Node *toRemove;
    Queue queue;
    int operation, value;

    createQueue(&queue);

    do{
        printf("\n1 - Inserir\n2 - Remover\n3 - Imprimir\n0- Sair\n");
        scanf("%d", &operation);

        switch(operation){
        case 1:
            inserir_na_fila(&queue);
            break;
        case 2:
            toRemove = remove(&queue);
            if(toRemove){
                printf("Retirado da fila: %d\n", toRemove->value);
                free(toRemove);
            }
            break;
        case 3:
            print(&queue);
            break;
        case 0:
            exit(0);
        default:
            if(operation != 0)
                printf("\nOpcao invaluda!\n");
        }

    }while(operation != 0);

    return 0;
}