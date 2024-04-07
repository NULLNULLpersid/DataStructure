#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef char element;

typedef struct
{
	element arr[SIZE];
	int front, rear;
} QueueType;

void init(QueueType* Q)
{
	Q->front = 0;
	Q->rear = 0;
}

int is_empty(QueueType* Q)
{
    return Q->front == Q->rear;
}

int is_full(QueueType* Q)
{
	return Q->rear == SIZE-1;
}

void enqueue(QueueType* Q, element e)
{
	if (is_full(Q)) return;
	else Q->arr[++(Q->rear)] = e;
}

element dequeue(QueueType* Q)
{
	return (is_empty(Q)) ? '\0' : Q->arr[++(Q->front)];
}

void print(QueueType* Q)
{
	printf("Front Pos : -1, Rear Pos : 2\n");
	for (int i = Q->front+1; i <= Q->rear; i++) {
		printf("[%c] ", Q->arr[i]);
	}
	printf("\n");
}

int main()
{
	QueueType Q;
	init(&Q);

	enqueue(&Q, 'A');
	enqueue(&Q, 'B');
	enqueue(&Q, 'C');
	print(&Q);
	printf("[%c] \n", dequeue(&Q));
	return 0;
}