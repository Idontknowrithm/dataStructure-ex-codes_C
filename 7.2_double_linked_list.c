#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct _Node {
	element data;
	struct _Node* fLink;
	struct _Node* bLink;
} Node;
void insertNode(Node* before, element data);
void deleteNode(Node* head, Node* removed);
void init(Node* head);
void printList(Node* head);

int main() {
	Node* head = (Node*)malloc(sizeof(Node));	init(head);
	printf("Adding phase\n");
	for (int i = 0; i < 5; i++) {
		insertNode(head, i);
		printList(head);
	}
	printf("Deleting phase\n");
	for (int i = 0; i < 5; i++) {
		printList(head);
		deleteNode(head, head->bLink);
	}
	free(head);
	system("pause");
}
void insertNode(Node* before, element data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;
	newNode->data = data;
	newNode->fLink = before;
	newNode->bLink = before->bLink;
	before->bLink->fLink = newNode;
	before->bLink = newNode;
}
void deleteNode(Node* head, Node* removed) {
	if (head->fLink == head) return;
	removed->fLink->bLink = removed->bLink;
	removed->bLink->fLink = removed->fLink;
	free(removed);
}
void init(Node* head) {
	head->bLink = head;
	head->fLink = head;
}
void printList(Node* head) {
	Node* p;
	for (p = head->bLink; p != head; p = p->bLink)
		printf("<-| |%d| |-> ", p->data);
	printf("\n");
}