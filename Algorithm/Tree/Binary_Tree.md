# Binary_Tree
---

 ### Operations

* BTreeNode * MakeBTreeNode(void);
> 이진 트리 노트를 생성하여 그 주소 값을 반환한다.

* BTData GetData(BTreeNode * bt);
> 노드에 저장된 데이터를 반환한다.

* void SetData(BTreeNode * bt, BTData data);
> 노드에 데이터를 저장한다. data로 전달된 값을 저장한다.

* BTreeNode * GetLeftSubTree(BTreeNode * bt);
> 왼쪽 서브 트리의 주소 값을 반환한다.

* BTreeNode * GetRightSubTree(BTreeNode * bt);
> 오른쪽 서브 트리의 주소 값을 반환한다.

* void MakeLeftSubTree(BTreeNode * main,BTreeNode * sub);
> 왼쪽 서브 트리를 연결한다.

* void MakeRighSubTree(BTreeNode * main, BTreeNode * sub);
> 오른쪽 서브 트리를 연결한다.

```c
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#define TRUE 1
#define FALSE 0


typedef int BTData;

typedef struct _btTreeNode
{
	BTData data;
	struct _btTreeNode * left;
	struct _btTreeNode * right;
}BTreeNode;

BTreeNode * MakeBTreeNode(void);

BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRighSubTree(BTreeNode * main, BTreeNode * sub);

#endif // !__BINARY_TREE_H__
```

```c
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
```