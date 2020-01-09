#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct _QueueNode {
	element data;
	struct _QueueNode* link;
}QueueNode;
typedef struct _Queue {
	QueueNode *front;
	QueueNode *rear;
}Queue;

Queue* init();
void enqueue(Queue* queue, element data);
void dequeue(Queue* queue);
int isitEmpty(Queue* queue);
void printList(Queue* queue);

int main() {
	Queue* queue = init();
	printList(queue);
	for (int i = 100; i < 501; i += 100) {
		enqueue(queue, i);
		printList(queue);
	}
	for (int i = 0; i < 3; i++) {
		dequeue(queue);
		printList(queue);
	}
	system("pause");
}
Queue* init() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	if (queue == NULL) return NULL;
	queue->front = NULL; queue->rear = NULL;
	return queue;
}
void enqueue(Queue* queue, element data) {
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL) return;
	newNode->data = data;
	newNode->link = NULL;
	if (isitEmpty(queue)) {
		queue->front = newNode;
		queue->rear = newNode;
	}
	else {
		queue->rear->link = newNode;
		queue->rear = newNode;
	}
}
void dequeue(Queue* queue) {
	if (isitEmpty(queue)) return;
	QueueNode* removed = queue->front;
	queue->front = queue->front->link;
	free(removed);
}
int isitEmpty(Queue* queue) {
	return queue->front == NULL && queue->rear == NULL;
}
void printList(Queue* queue) {
	if (isitEmpty(queue)) {
		printf("front -> NULL <- rear\n");
		return;
	}
	QueueNode* temp = queue->front;
	printf("front ");
	do {
		printf("-> |%d| ", temp->data);
		temp = temp->link;
	} while (temp != queue->rear->link);
	printf("<- rear\n");
}