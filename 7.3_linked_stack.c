#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct _Node {
	element data;
	struct _Node* link;
} StackNode;
typedef struct _TopPointer {
	StackNode* top;
}TopPointer;

void push(TopPointer* top, element data);
void pop(TopPointer* top);
void printList(StackNode* top);
TopPointer* init();
int isitEmpty(StackNode* top);

int main() {
	TopPointer* stack = init();	
	for (int i = 100; i < 600; i += 100) {
		push(stack, i);
		printList(stack->top);
	}
	for(int i = 0; i < 5; i++){
		pop(stack);
		printList(stack->top);
	}
	free(stack);
	system("pause");
}
void push(TopPointer* top, element data) {
	printf("Push\n");
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	if (newNode == NULL) return;
	newNode->data = data;
	newNode->link = top->top;
	top->top = newNode;
}
void pop(TopPointer* top) {
	if (isitEmpty(top->top)) return;
	printf("Pop\n");
	StackNode* removed = top->top;
	top->top = removed->link;
	free(removed);
}
void printList(StackNode* top) {
	StackNode* print = top;
	printf("top -> ");
	while (print) {
		printf("|%d| -> ", print->data);
		print = print->link;
	}	printf("NULL\n");
}
TopPointer* init() {
	TopPointer* top = (TopPointer*)malloc(sizeof(TopPointer));
	if (top == NULL)return NULL; else top->top = NULL;
	return top;
}
int isitEmpty(StackNode* top) {
	return (top == NULL);
}