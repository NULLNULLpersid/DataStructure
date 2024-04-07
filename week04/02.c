#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // 선형 큐 타입	
    element arr[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// 오류 함수
void error(char *message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 선형 큐 초기화
void init_queue(QueueType *q){
	q->front = q->rear = 0;
}
// 선형 큐가 포화상태인가?
int is_full(QueueType* Q)
{
	return Q->rear == MAX_QUEUE_SIZE-1;
}
// 선형 큐가 공백상태인가?
int is_empty(QueueType *q){
	return (q->front == q->rear);
}
// 선형 큐에 데이터 삽입
void enqueue(QueueType *q, int item){
	if (is_full(q)) return;
	else q->arr[++(q->rear)] = item;
}
// 선형 큐에서 데이터 제거
int dequeue(QueueType *q){
	return (is_empty(q)) ? 0 : q->arr[++(q->front)];
}
// 선형 큐 상태 출력
void queue_print(QueueType *q){
    for (int i = 1; i <= MAX_QUEUE_SIZE; i++) {
        //printf("%d\n", q->front);
        (q->front < i && q->rear >= i) ? printf("%d,", q->arr[i]) : printf(",");
    }
    printf("\n");
}
// 메인
int main(void){
	int item = 0;
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	return 0;
}