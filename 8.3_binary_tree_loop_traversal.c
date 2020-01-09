#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)

typedef int element;
typedef struct _binaryTree {
	element data;
	struct _binaryTree* left;
	struct _binaryTree* right;
}tree;
typedef struct _stack {
	tree* data;
	struct _stack* next;
}stack;

stack* push(stack* head, tree* data);
stack* pop(stack* head);
tree* top(stack* head);
void leftFT(tree* root, stack* head);

int main() {
	stack* head = NULL;
	tree n1 = { 1, NULL, NULL };
	tree n2 = { 4, &n1, NULL };
	tree n3 = { 16, NULL, NULL };
	tree n4 = { 25, NULL, NULL };
	tree n5 = { 20, &n3, &n4 };
	tree n6 = { 15, &n2, &n5 };
	tree* root = &n6;

	leftFT(root, head);
	system("pause");
}

stack* push(stack* head, tree* data) {
	stack* newNode = (stack*)malloc(sizeof(stack));
	if (newNode == NULL) return NULL;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
	return head;
}
stack* pop(stack* head) {
	if (head == NULL) return NULL;
	stack* remove = head;
	head = remove->next;
	free(remove);
	return head;
}
tree* top(stack* head) {
	if (head == NULL) return NULL;
	return head->data;
}
void leftFT(tree* root, stack* head) {
	while (1) {
		for (; root; root = root->left) {
			head = push(head, root);
		}
		root = top(head);	 head = pop(head);
		if (!root) break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}