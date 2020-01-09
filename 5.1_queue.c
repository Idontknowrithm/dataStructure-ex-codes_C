#include<stdio.h>
#define MAX_QUEUE_SIZE 10
typedef struct _Queue{
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
}Queue;
int is_empty(Queue*);
int is_full(Queue*);
void enqueue(Queue*, int);
int dequeue(Queue*);
void queue_print(Queue*);
void queue_init(Queue*);
int main() {
	Queue queue;
	queue_init(&queue);
	enqueue(&queue, 10);	queue_print(&queue);
	enqueue(&queue, 20);	queue_print(&queue);
	enqueue(&queue, 30);	queue_print(&queue);
	dequeue(&queue);		queue_print(&queue);
	dequeue(&queue);		queue_print(&queue);
	dequeue(&queue);		queue_print(&queue);

	return 0;
}
int is_empty(Queue* queue) {
	if (queue->front == queue->rear) return 1;
	else return 0;
}
int is_full(Queue* queue) {
	if (queue->rear == MAX_QUEUE_SIZE - 1) return 1;
	else return 0;
}
void enqueue(Queue* queue, int value) {
	if (is_full(queue)) printf("Error : queue is full\n");
	queue->data[++queue->rear] = value;
}
int dequeue(Queue* queue) {
	if (is_empty(queue)) printf("Error : queue is empty\n");
	queue->front++;
	return queue->data[queue->front];
}
void queue_print(Queue* queue) {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (queue->front < i && i <= queue->rear)
			printf(" %d |", queue->data[i]);
		else
			printf("    |");
	}		printf("\n");
}
void queue_init(Queue* queue) {
	queue->front = -1;
	queue->rear = -1;
}