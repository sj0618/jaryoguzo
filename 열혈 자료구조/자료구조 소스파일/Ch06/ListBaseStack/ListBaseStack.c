#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack)		//스택이 비어있으면 1반환 아니면 0반환
{
	if(pstack->head==NULL){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

void SPush(Stack * pstack, Data data)		//스택에 값을 채워넣음
{
	Node * NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = data;
	NewNode->next = pstack->head;
	pstack-> head = NewNode;
	
	
}

Data SPop(Stack * pstack)
{
	Data tmpdata ;
	Node * tmpnode;
	if(pstack->head==NULL){
		printf("삭제할게 없다.");
		exit(-1);
	}
	tmpdata = pstack ->head->data;
	tmpnode = pstack ->head ;		//삭제할 노드가 가르키는 노드가 tmpnode임.

	pstack->head = tmpnode ->next;
	free(tmpnode);

	return tmpdata;

}

Data SPeek(Stack * pstack)
{	
	if(pstack->head == NULL){
		printf("오류");
		exit(-1);
	}
	return (pstack->head->data);	
}