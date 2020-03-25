# Circular_Queue
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
#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue{
	int front;
	int rear;
	Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif // !__C_QUEUE_H__
```

```c
#include <stdio.h>
#include <stdlib.h>
#include "Circular_Queue.h"

void QueueInit(Queue * pq) {
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue * pq) {
	if (pq->front == pq->rear)
		return TRUE;
	else 
		return FALSE;
}

int NextPosIdx(int pos) {
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue * pq, Data data) {
	if (NextPosIdx(pq->rear) == pq->front) {
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear]=data;
}

Data Dequeue(Queue * pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
			exit(-1);
	}
	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue * pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}
	return pq->queArr[NextPosIdx(pq->front)];
}
```