#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

typedef int element;
typedef struct _binaryTree {
	element data;
	struct _binaryTree* left;
	struct _binaryTree* right;
}tree;

tree* createRoot(tree* root, element data);
void leftSub(tree* root, tree* sub);
void rightSub(tree* root, tree* sub);

void rootFT(tree* root);
void leftFT(tree* root);
void subFT(tree* root);

int main() {
	tree* A = NULL; A = createRoot(A, 1);
	tree* B = NULL; B = createRoot(B, 2);
	tree* C = NULL; C = createRoot(C, 3);
	leftSub(A, B);	rightSub(A, C);
	rootFT(A); printf("\n");
	leftFT(A); printf("\n");
	subFT(A);  printf("\n");
	system("pause");
}
tree* createRoot(tree* root, element data) {
	tree* newNode = (tree*)malloc(sizeof(tree));
	if (newNode == NULL) return NULL;
	newNode->data = data;
	newNode->left = NULL; newNode->right = NULL;
	root = newNode;
	return root;
}
void leftSub(tree* root, tree* sub) {
	root->left = sub;
}
void rightSub(tree* root, tree* sub) {
	root->right = sub;
}

void rootFT(tree* root) {
	if (root == NULL) return;
	printf("%d ", root->data);
	rootFT(root->left);
	rootFT(root->right);
}
void leftFT(tree* root) {
	if (root == NULL) return;
	leftFT(root->left);
	printf("%d ", root->data);
	leftFT(root->right);
}
void subFT(tree* root) {
	if (root == NULL) return;
	subFT(root->left);
	subFT(root->right);
	printf("%d ", root->data);
}