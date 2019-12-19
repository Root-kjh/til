#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode * MakeBTreeNode() {
	BTreeNode * NewNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	NewNode->data = 0;
	NewNode->left = NULL;
	NewNode->right = NULL;

	return NewNode;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub) {
	if (main->left != NULL)
		free(main->left);

;	main->left = sub;
}

void MakeRighSubTree(BTreeNode * main, BTreeNode * sub) {
	if (main->right != NULL)
		free(main->right);

	;	main->right = sub;
}

BTData GetData(BTreeNode * bt) {
	return bt->data;
}

void SetData(BTreeNode * bt, BTData data) {
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt) {
	return bt->left;

}

BTreeNode * GetRightSubTree(BTreeNode * bt) {
	return bt->right;
}