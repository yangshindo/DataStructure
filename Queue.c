// C program for array implementation of queue
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define total_capacity 100 //quantidade máxima de itens no stack

// Estrutura da fila
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Função para criar uma fila, recebe a capacidade no argumento
// Inicializa como 0
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    //importante
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}

// Fila cheia
int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

// Fila vazia
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

// Função para adicionar item na fila.
// Modifica o início e o fim da fila
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

// Função para remover um item da fila.
// Muda o início e o tamanho
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Função para obter o início da fila
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Função para obter o fim da fila
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

// Main
int main()
{
    struct Queue* queue = createQueue(total_capacity);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n\n",
           dequeue(queue));

    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    return 0;
}
