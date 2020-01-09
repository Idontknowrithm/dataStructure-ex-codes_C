#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef int element;
typedef struct _binaryTree {
	element data;
	struct _binaryTree* left;
	struct _binaryTree* right;
}tree;
typedef tree* qelement;
typedef struct _QueueNode {
	qelement data;
	struct _QueueNode* link;
}QueueNode;
typedef struct _Queue {
	QueueNode* front;
	QueueNode* rear;
}Queue;

Queue* init();
void enqueue(Queue* queue, qelement data);
qelement dequeue(Queue* queue);
int isitEmpty(Queue* queue);

void levelT(tree* root, Queue* queue);

int main() {
	Queue* queue = init();
	tree n1 = { 1, NULL, NULL };
	tree n2 = { 4, &n1, NULL };
	tree n3 = { 16, NULL, NULL };
	tree n4 = { 25, NULL, NULL };
	tree n5 = { 20, &n3, &n4 };
	tree n6 = { 15, &n2, &n5 };
	tree* root = &n6;
	levelT(root, queue);
	system("pause");
}
Queue* init() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	if (queue == NULL) return NULL;
	queue->front = NULL; queue->rear = NULL;
	return queue;
}
void enqueue(Queue* queue, qelement data) {
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
qelement dequeue(Queue* queue) {
	qelement temp;
	if (isitEmpty(queue)) return NULL;
	QueueNode* removed = queue->front;
	queue->front = queue->front->link;
	temp = removed->data;
	free(removed);
	return temp;
}
int isitEmpty(Queue* queue) {
	return queue->front == NULL;
}
void levelT(tree* root, Queue* queue) {
	tree* temp;
	enqueue(queue, root);
	while (1) {
		if (isitEmpty(queue)) break;
		temp = dequeue(queue);
		if (temp == NULL) break;
		printf("[%d] ", temp->data);
		enqueue(queue, temp->left);
		enqueue(queue, temp->right);
	}
}