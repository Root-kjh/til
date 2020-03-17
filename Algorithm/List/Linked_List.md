# Linked_List   
---

### Operations

* void ListInit(List * plist);
> * 초기화 할 리스트의 주소 값을 인자로 전달.

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

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node *next;
} Node;

typedef struct _linkedList
{
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
}LinkedList;

typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);


#endif // !__LINKED_LIST_H__
```

```c
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void ListInit(List * plist) {
	plist->head = ((Node*)malloc(sizeof(Node)));
	plist->head->next = NULL;
	plist->numOfData = 0;
}

void SInsert(List * plist, LData data) {

}

void LInsert(List * plist, LData data) {
	Node * TempPlist = plist->head;

		Node * newNode = ((Node*)malloc(sizeof(Node)));
		newNode->data = data;
		newNode->next = plist->head->next;
		plist->head->next = newNode;
		(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata) {
	if (plist->head->next == NULL)
		return FALSE;
	
	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, LData * pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;

	return TRUE;
}

LData LRemove(List * plist) {
	Node * TempNode = plist->cur;
	LData TempData = TempNode->data;
	
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