﻿#include <stdio.h>
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