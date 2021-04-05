# Circular_Linked_List   
---

### Operations

* void ListInit(List * plist);
> * 초기화 할 리스트의 주소 값을 인자로 전달.

* void LInsertFront(List * plist, LData data);
> * 리스트앞에 데이터 저장.
> * 매개변수 data에 전달된 값 저장 


* void LInsert(List * plist, LData data);
> * 리스트에 데이터 저장.
> * 매개변수 data에 전달된 값 저장 

* int LFirst(List * plist,LData * pdata);
> * pdata가 가리키는 메모리에 첫 번째 데이터 저장
> * 데이터의 참조를 위한 초기화 진행
> * 참조 성공시 1(True) 반환, 실패 시 0(False) 반환

* int LNext(List * plist, LData * pdata);
> * 참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장
> * 순차적인 참조를 위해 반복호출 가능
> * 참조를 새로 시작하려면 먼저 LFirst를 함수 호출해야함
> * 참조 성공시 1(True) 반환, 실패시 0(False) 반환

* LData LRemove(List * plist);
> * LFirst 또는 LNext 함수의 마지막 반환 데이터 삭제
> * 삭제된 데이터 반환
> * 마지막 반환 데이터르 작제하므로 연이은 반복 호춣 X

* int LCount(List * plist);
> * 리스트의 저장되어 있는 데이터의 수 반환

```c
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node *next;
} Node;

typedef struct _CLL
{
	Node * tail;
	Node * cur;
	Node * before;
	int numOfData;
}CList;

typedef CList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);
void LInsertFront(List * plist, Data data);
int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);

Data LRemove(List * plist);
int LCount(List * plist);


#endif // !__LINKED_LIST_H__
```

```c
#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List * plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = NULL;
}

void LInsert(List * plist, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}

	(plist->numOfData)++;

}

void LInsertFront(List * plist, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;

}

int LFirst(List * plist, Data * pdata) {
	if (plist->tail == NULL)
		return FALSE;
	
	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, Data * pdata) {
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;

	return TRUE;
}

Data LRemove(List * plist) {
	Node * TempNode = plist->cur;
	Data TempData = TempNode->data;
	
	if (plist->tail == TempNode) {
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	(plist->numOfData)--;
	free(TempNode);

	return TempData;
}

int LCount(List * plist) {
	return plist->numOfData;
}
```