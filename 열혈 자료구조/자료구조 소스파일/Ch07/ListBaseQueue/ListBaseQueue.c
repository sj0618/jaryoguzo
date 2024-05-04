#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"


void QueueInit(Queue * pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}
int QIsEmpty(Queue * pq)
{
	if(pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue * pq, Data data){
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	//만약 첫번째 노드라면.
	if(QIsEmpty(pq)){
		pq->front = newNode;
		pq->rear = newNode;
	}
	else{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}
Data Dequeue(Queue * pq){
	Node * tmpnode;
	Data tmpdata;
	if(QIsEmpty(pq)){					//비었을경우 오류 
		printf("오류");
		exit(-1);
	}
	//front를 삭제하고 한칸옮김.
	tmpdata = pq->front->data;
	tmpnode = pq->front;
	pq->front = pq->front->next; 		//front 옮김.data도 옮김 완료
	
	free(tmpnode);
	return tmpdata;
}
Data QPeek(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->front->data;
}
