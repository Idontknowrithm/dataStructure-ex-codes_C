#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct _binaryTree {
	element data;
	struct _binaryTree* left;
	struct _binaryTree* right;
}tree;

tree* createRoot(tree* root, element data);
void leftSub(tree* root, tree* sub);
void rightSub(tree* root, tree* sub);

int main() {
	system("pause");
}
tree* createRoot(tree* root, element data) {
	root = (tree*)malloc(sizeof(tree));
	if (root == NULL) return NULL;
	root->data = data;
	root->left = NULL; root->right = NULL;
	return root;
}
void leftSub(tree* root, tree* sub) {
	root->left = sub;
}
void rightSub(tree* root, tree* sub) {
	root->right = sub;
}