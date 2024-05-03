#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List * plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List * plist, Data data)					//리스트의 '앞'에 자료 삽입
{
	Node * newNode = (Node*)malloc(sizeof(Node));			//새 노드 할당
	newNode->data = data;									//새 노드에 데이터 할당

	if(plist->tail == NULL) 								//만약 tail이 비어있다면		
	{
		plist->tail = newNode;								//tail은 새 노드
		newNode->next = newNode;							//새 노드의 다음도 새 노드(동일노드) -> 원형 링크드이기 때문
	}
	else													//tail에 뭔가 있다면
	{
		newNode->next = plist->tail->next;					//새 노드의 다음은 tail의 다음. tail의 다음 == head head를 tail로 표현
		plist->tail->next = newNode;						//tail의 다음은 뉴노드.				 == head ;
	}

	(plist->numOfData)++;
}

void LInsert(List * plist, Data data)						//리스트의 뒤에삷입
{
	Node * newNode = (Node*)malloc(sizeof(Node));			
	newNode->data = data;

	if(plist->tail == NULL) 
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else 
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if(plist->tail == NULL)    // 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if(plist->tail == NULL)    // 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data rdata = rpos->data;

	if(rpos == plist->tail)    // 삭제 대상을 tail이 가리킨다면
	{
		if(plist->tail == plist->tail->next)    // 그리고 마지막 남은 노드라면
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

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