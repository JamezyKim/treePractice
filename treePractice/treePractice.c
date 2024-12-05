#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node* right;
	struct Node* left;
}Node;

Node* createNode(int data) {
	Node* newNode = malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	return newNode;
}

Node* insertNode(Node* root, int data) {
	if (root == NULL) {
		return createNode(data);
	}
	else {
		if (data < root->data) {
			root->left = insertNode(root->left, data);
		}
		else if (data > root->data) {
			root->right = insertNode(root->right, data);
		}
	}
	return root;
}

Node* searchNode(Node* root, int data) {
	if (root == NULL) {
		printf("Data %d does not exist in the tree.\n", data);
		return root;
	}
	if (root->data == data) {
		printf("%d", data);
		return;
	}
	else if (data < root->data) {
		return searchNode(root->left, data);
	}
	else {
		return searchNode(root->right, data);
	}
}

void printTree(Node* root) {
	if (root == NULL) {
		return;
	}
	printTree(root->left);
	printf("%d ", root->data);
	printTree(root->right);
	return;
}

int main() {
	Node* root = NULL;
	
	root = insertNode(root, 50);
	insertNode(root, 40);
	insertNode(root, 10);
	insertNode(root, 60);

	//searchNode(root, 10);
	printTree(root);

	return 0;
}