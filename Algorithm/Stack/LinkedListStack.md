# Linked_List_Stack
---

### Operations

* StackInit(Stack * pstack);
> * 스택의 초기화 진행
> * 스택 생성 후 제일 먼저 호출되어야 하는 함수

* void SIsEmpty(Stack * pstack);
> * 스택이 빈 경우 TRUE(1)을, 그렇지 않은 경우 FALSE(0)을 반환한다.

* void SPush(Stack * pstack, Data data);
> * 스택에 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다.

* Data SPop(Stack * pstack);
> * 마지막에 저장된 요소를 삭제한다.
> * 삭제된 데이터는 반환이 된다.
> * 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.

* Data SPeek(Stack * pstack);
> * 마지막에 저장된 요소를 반환하되 삭제하지 않는다.
> * 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.

```c
#ifndef __LB_STACK_H__
#define _LB_STACK_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node{
	Data data;
	struct _node * next;
} Node;

typedef struct _listStack {
	Node * head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif // !__LB_STACK_H__
```

```c
#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack) {
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack) {
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data SPop(Stack * pstack) {
	Data rdata;
	Node * rnode;
	
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;

	free(rnode);
	return rdata;
}

Data SPeek(Stack * pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}
```