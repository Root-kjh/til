# Array_List
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
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100

typedef int LData;

typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;

typedef ArrayList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif // !__ARRAY_LIST_H__
```

```c
#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist) {
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List * plist, LData data) {
	if ((plist->numOfData) >= LIST_LEN) {
		puts("No more values ​​can be entered.");
		return;
	}
	
	(plist->arr[(plist->numOfData)]) = data;
	(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata) {
	if (plist->numOfData == 0)
		return FALSE;
	
	(plist->curPosition) = 0;
	*pdata = (plist->arr[0]);

	return true;
}

int LNext(List * plist, LData * pdata) {
	if ((plist->curPosition) + 1 >= (plist->numOfData))
		return FALSE;

	(plist->curPosition)++;
	*pdata = (plist->arr[(plist->curPosition)]);

	return TRUE;
}

LData LRemove(List * plist) {
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	LData rdata = plist->arr[rpos];

	while (rpos < num - 1) {
		plist->arr[rpos] = plist->arr[rpos + 1];
		rpos++;
	}

	(plist->numOfData)--;
	(plist->curPosition)--;

	return rdata;
}

int LCount(List * plist) {
	return (plist->numOfData);
}
```