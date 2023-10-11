#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_ELEMENTS 35

typedef struct
{
    int key;
} Element;

typedef struct
{
    Element elements[MAX_ELEMENTS];
    int front;
    int rear;
    int numElements;
} Queue;

void initialize(Queue *queue)
{
    queue->front = 0;
    queue->rear = -1;
    queue->numElements = 0;
}

bool isFull(Queue *queue)
{
    return queue->numElements == MAX_ELEMENTS;
}

bool isEmpty(Queue *queue)
{
    return queue->numElements == 0;
}

bool enqueue(Queue *queue, int value)
{
    if (isFull(queue))
        return false;

    queue->rear = (queue->rear + 1) % MAX_ELEMENTS;
    queue->elements[queue->rear].key = value;
    queue->numElements++;
    return true;
}

bool dequeue(Queue *queue)
{
    if (isEmpty(queue))
        return false;

    queue->front = (queue->front + 1) % MAX_ELEMENTS;
    queue->numElements--;
    return true;
}

void display(Queue *queue)
{
    int i, count;
    printf("Fila: ");
    if (queue->front <= queue->rear)
    {
        for (i = queue->front, count = 0; count < queue->numElements; i++, count++)
            printf("[%d]", queue->elements[i].key);
    }
    else
    {
        for (i = queue->front, count = 0; count < MAX_ELEMENTS - queue->front; i++, count++)
            printf("[%d]", queue->elements[i].key);

        for (i = 0; count < queue->numElements; i++, count++)
            printf("[%d]", queue->elements[i].key);
    }
    printf("\n\nNúmero de elementos na fila: %d\n", queue->numElements);
}

int main()
{
    char option = '1';
    int value;
    Queue queue;
    initialize(&queue);

    while (option != '0')
    {
        printf("==========>Menu da Fila<==========\n");
        printf("__________________________\n");
        printf("      1-->Enfileirar\n");
        printf("      2-->Desenfileirar\n");
        printf("      3-->Exibir\n");
        printf("      4-->Inicializar\n");
        printf("      0-->Sair\n");
        printf("__________________________\n");
        printf("\nOpção: ");
        scanf(" %c", &option);

        switch (option)
        {
            case '1':
            {
                if (isFull(&queue))
                    printf("A fila está cheia. Não é possível enfileirar.\n");
                else
                {
                    printf("\nDigite o valor para enfileirar: ");
                    scanf("%d", &value);

                    if (enqueue(&queue, value))
                        printf("Enfileirado com sucesso\n");
                }

                printf("\nPressione qualquer tecla para continuar.\n");
                getchar();
                break;
            }

            case '2':
            {
                if (isEmpty(&queue))
                    printf("A fila está vazia. Não é possível desenfileirar.\n");
                else
                {
                    if (dequeue(&queue
