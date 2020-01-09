#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct _Node {
	element data;
	struct _Node* link;
} Node;

Node* Create_Node(Node*, element);
Node* Insert_Node(Node*, Node*, element);
Node* Delete_first(Node*);
Node* Delete(Node*, Node*);
void Print_list(Node*);
void error(char*);

int main() {
	Node* head = NULL;	int i;
	for (i = 0; i < 5; i++) {
		head = Create_Node(head, i);
		Print_list(head);
	}
	for (i = 0; i < 5; i++) {
		head = Delete_first(head);
		Print_list(head);
	}
	return 0;
}
Node* Create_Node(Node* head, element newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return NULL;
	newNode->data = newData;
	newNode->link = head;
	head = newNode;
	return head;
}
Node* Insert_Node(Node* head, Node* current_node, element newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return NULL;
	newNode->data = newData;
	newNode->link = current_node->link;
	return head;
}
Node* Delete_first(Node* head) {
	if (head == NULL) return NULL;
	Node* remove = head;
	head = remove->link;
	free(remove);
	return head;
}
Node* Delete(Node* head, Node* pre_node) {
	Node* remove = pre_node->link;
	pre_node->link = remove->link;
	free(remove);
	return head;
}
void Print_list(Node* head) {
	for (Node* printed_node = head; printed_node != NULL; printed_node = printed_node->link)
		printf("%d -> ", printed_node->data);
	printf("NULL\n");
}
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}