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
> 오른쪽 서브 트리를 연결한다..