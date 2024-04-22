#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)				//리스트를 생성
{
	plist->head = (Node*)malloc(sizeof(Node));	
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List * plist, LData data)		//데이터 삽입 핢수.
{
	Node * newNode = (Node*)malloc(sizeof(Node));  //자유저장소 newnode 생성
	newNode->data = data;							//new노드의 데이터에 데이터를 저장 , plist는 더미데이터.
	newNode->next = plist->head->next;				//new노드의 next는 더미데이터의 다음
	plist->head->next = newNode;					//

	(plist->numOfData)++;							//데이터의 개수 1개 늘림
}

void SInsert(List * plist, LData data)				//list와 data를 인자로 받음. 2번째 이후의 노드를 생성하는 하므수
{
	Node * newNode = (Node*)malloc(sizeof(Node));	//자유저장소 노드생성
	Node * pred = plist->head;						//pred생성하고 헤드에 연결
	newNode->data = data;							//데이터 저장

	while(pred->next != NULL &&						//pred의 다음이 빈칸이 아닐때까지.
		plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}


void LInsert(List * plist, LData data)
{
	if(plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if(plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Node * rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}