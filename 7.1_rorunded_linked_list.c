#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct _Node {
	element data;
	struct _Node* link;
} Node;
Node* Create_node_last(Node*, element);
Node* Create_node_first(Node*, element);
void Print_list(Node*);
int main() {
	Node* head = NULL;

	for (int i = 200; i < 501; i += 100)
		head = Create_node_last(head, i);
	head = Create_node_first(head, 100);
	Print_list(head);
	return 0;
}
Node* Create_node_first(Node* head, element data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return NULL;
	newNode->data = data;
	if (head == NULL) {
		head = newNode;
		newNode->link = head;
	}
	else {
		newNode->link = head->link;
		head->link = newNode;
	}
	return head;
}
Node* Create_node_last(Node* head, element data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return NULL;
	newNode->data = data;
	if (head == NULL) {
		head = newNode;
		newNode->link = head;
	}
	else {
		newNode->link = head->link;
		head->link = newNode;
		head = newNode;
	}
	return head;
}
void Print_list(Node* head) {
	Node* nodePointer;

	if (head == NULL) return;
	nodePointer = head->link;
	do {
		printf("%d -> ", nodePointer->data);
		nodePointer = nodePointer->link;
	} while (nodePointer != head);
	printf("%d -> ", nodePointer->data);
}