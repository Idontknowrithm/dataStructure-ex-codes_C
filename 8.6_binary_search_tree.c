#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct _BST {
	element data;
	int key;
	struct _BST* left, * right;
}bst;
bst* recursiveSearch(bst* root, int key);
bst* loopSearch(bst* root, int key);
bst* insertNode(bst* root, int key, element data);
bst* deleteNode(bst* root, int key);
bst* succNode(bst* node);
void inorder(bst* root);

/*********************/
/* MAIN CODE IS HERE */
/*********************/
int main () {
	bst* root = NULL;
	root = insertNode(root, 35, 0);
	root = insertNode(root, 18, 0);
	root = insertNode(root, 68, 0);
	root = insertNode(root, 99, 0);
	root = insertNode(root, 7, 0);
	root = insertNode(root, 26, 0);
	root = insertNode(root, 22, 0);
	root = insertNode(root, 3, 0);
	root = insertNode(root, 12, 0);
	inorder(root);
    system("pause");
}
bst* recursiveSearch(bst* root, int key) {
	if      (root == NULL) 	   return NULL;
	if 	 	(root->key == key) return root;
	else if (root->key < key)  return recursiveSearch(root->right, key);
	else					   return recursiveSearch(root->left, key);
}
bst* loopSearch(bst* root, int key) {
	bst* temp = root;
	while (1) {
		if 		(temp == NULL) 	   return NULL;
		if 		(temp->key == key) return temp;
		else if (root->key < key)  temp = temp->right;
		else					   temp = temp->left;
	}
}
bst* insertNode(bst* root, int key, element data){
	if(root == NULL) {
		root->key = key;
		root->data = data;
		root->left = root->right = NULL;
		return root;
	}
	bst* temp = root;
	while(1){
		if(temp->key < key && temp->right == NULL){
			bst* newNode = (bst*)malloc(sizeof(bst));
			newNode->data = data;
			newNode->key = key;
			newNode->left = NULL;
			newNode->right = NULL;
			temp->right = newNode;
			return root;
		}
		else if(temp->left == NULL){
			bst* newNode = (bst*)malloc(sizeof(bst));
			newNode->data = data;
			newNode->key = key;
			newNode->left = NULL;
			newNode->right = NULL;
			temp->left = newNode;
			return root;
		}
		if	   (temp->key == key) {
			printf("Fail to insert new node : the node which has the same key exists already.\n");
			return root;
		}
		else if(temp->key < key) 
			temp = temp->right;
		else 
			temp = temp->left;
	}
}
bst* deleteNode(bst* root, int key){
	if(root == NULL)
		return root;
	if(key < root->key)
		root->left = deleteNode(root->left, key);
	else if(key > root->key)
		root->right = deleteNode(root->right, key);
	else{
		if(root->left == NULL){
			bst* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			bst* temp = root->left;
			free(root);
			return temp;
		}
		bst* temp = succNode(root->right);
		root->key = temp->key;								// can't understand
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
bst* succNode(bst* node){
	bst* curNode = node;
	while(!curNode->left)
		curNode = curNode->left;
	return curNode;
}
void inorder(bst* root){
	if(root){
		inorder(root->left);
		printf("[%d]", root->key);
		inorder(root->right);
	}
}