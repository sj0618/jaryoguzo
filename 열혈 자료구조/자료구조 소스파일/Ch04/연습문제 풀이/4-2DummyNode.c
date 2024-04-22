#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;					//다음노드의 주소
} Node;

int main(void)
{
	Node * head = NULL;						//코드요악해줘
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;
    head = (Node*)malloc(sizeof(Node));
    tail = head;

	/**** 데이터를 입력받는과정 ****/
	while(1)
	{
		printf("자연수입력 ");
		scanf("%d", &readData);
		if(readData < 1)
			break;

		/***노드의 추가과정*/
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		/*if(head == NULL)
			head = newNode;
		else
			tail->next = newNode;
        */
        tail->next = newNode;
		tail = newNode;
	}
	printf("\n");

	/**압력받은 데이터의 출력과정***/
	printf("입력받은 데이터의 전체출력 \n");
	if(head == NULL) 
	{
		printf("저장된 자연수가 존재하지않습니다 \n");
	}
	else 
	{
		cur = head; 
		//printf("%d  ", cur->data);   //첫번째 데이터 출력
		
		while(cur->next != NULL)    // 두번째 데이터 출력
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**메모리의 해제과정**/
	if(head == NULL) 
	{
		return 0;    // 해제할노드가 존재하지않습니다
	}
	else 
	{
		Node * delNode = head;
		Node * delNextNode = head->next;

		//printf("%d을 삭제합니다 \n", head->data);
		//free(delNode);    // 첫번쨰 노드 삭제
		
		while(delNextNode != NULL)    // 두번째 이후 노드 삭제
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을 삭제합니다. \n", delNode->data);
			free(delNode);    // 두번째 이후 노드 삭제
		}
	}
	return 0;
}//코드 요약해줘