# List_Base_Queue
---

### Operations

* void QueueInit(Queue * pq);
> * 큐의 초기화를 진행한다.
> * 큐 생성 후 제일 먼저 호출되어야 하는 함수이다.

* int QIsEmpty(Queue * pq);
> * 큐가 빈 경우 TRUE(1)을, 그렇지 않은 경우 FALSE(0)을 반환한다.

* void Enqueue(Queue * pq, Data data);
> * 큐에 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다.

* Data Dequeue(Queue * pq);
> * 저장순서가 가장 앞선 데이터를 삭제한다.
> * 삭제된 데이터는 반환된다.
> * 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.

* Data QPeek(Queue * pq);
> * 저장순서가 가장 앞선 데이터를 반환하되 삭제하지 않는다.
> * 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.

```c
#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _lQueue{
	Node * front;
	Node * rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif // !__LB_QUEUE_H__
```

```c
#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue * pq) {
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue * pq) {
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue * pq, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;
	if (QIsEmpty(pq)) {
		pq->rear = newNode;
		pq->front = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
	
}

Data Dequeue(Queue * pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}
	Node* temp = pq->front;
	Data retData = temp->data;
	pq->front = pq->front->next;

	free(temp);
	return retData;
}

Data QPeek(Queue * pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}
	return pq->front->data;
}
```