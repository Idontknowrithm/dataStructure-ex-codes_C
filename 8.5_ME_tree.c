#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct _Tree {
	int data;
	struct _Tree* left, * right;
}tree;

int evaluate(tree* root);
int main() {
	tree n1 = { 1, NULL, NULL };
	tree n2 = { 4, NULL, NULL };
	tree n3 = { '*', &n1, &n2 };
	tree n4 = { 16, NULL, NULL };
	tree n5 = { 25, NULL, NULL };
	tree n6 = { '+', &n4, &n5 };
	tree n7 = { '+', &n3, &n6 };
	tree* root = &n7;

	printf("The value of mathematical expression is %d\n", evaluate(root));
	system("pause");
	return 0;
}
int evaluate(tree* root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return root->data;
	else {
		int temp1 = evaluate(root->left);
		int temp2 = evaluate(root->right);
		printf("Calculating %d %c %d ...\n", temp1, root->data, temp2);
		switch (root->data) {
		case '+':
			return temp1 + temp2;
		case '-':
			return temp1 - temp2;
		case '*':
			return temp1 * temp2;
		case '/':
			return (temp1 == 0 || temp2 == 0) ? 0 : temp1 / temp2;
		}
	}
}