#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 20
int is_empty(int);
int is_full(int);
void push(int*, int*, int);
int pop(int*, int*);
int main() {
	int stack[MAX_STACK_SIZE];
	int top = -1;
	push(stack, &top, 1);
	push(stack, &top, 2);
	push(stack, &top, 3);
	printf("%d\n", pop(stack, &top));
	printf("%d\n", pop(stack, &top));
	printf("%d\n", pop(stack, &top));

	return 0;
}
int is_empty(int top) {
	if (top == -1)
		return 1;
	else
		return 0;
}
int is_full(int top) {
	if (top == MAX_STACK_SIZE - 1)
		return 1;
	else
		return 0;
}
void push(int* stack, int* top, int value) {
	if (is_full(*top)) {
		printf("Can't push\n");
		return;
	}
	stack[++ * top] = value;
	printf("Successfully stacked\n");
}
int pop(int* stack, int* top) {
	int temp = stack[*top];
	if (is_empty(*top)) {
		printf("Can't pop\n");
		return -1;
	}
	(*top) -= 1;
	printf("Successfully poped\n");
	return temp;
}

