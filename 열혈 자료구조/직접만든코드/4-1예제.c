#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

int main(void)
{
	Node * head = NULL;    // NULL �룷�씤�꽣 ?��?��린�?��
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;
    head = (Node*)malloc(sizeof(Node));

	/**** �뜲�씠�꽣?���? �엯�젰 諛쏅?�� ??�쇱?�� ****/
	while(1)
	{
		printf("�옄�뿰�닔 �엯�젰: ");
		scanf("%d", &readData);
		if(readData < 1)
			break;

		/*** �끂�뱶�쓽 ?��붽���?�쇱?�� ***/
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		tail->next = newNode;

		tail = newNode;
	}
	printf("\n");

	/**** �엯�젰 諛쏆�� �뜲�씠�꽣�쓽 ?��?��?��??�쇱?�� ****/
	printf("�엯�젰 諛쏆�� �뜲�씠�꽣�쓽 �쟾泥댁?���젰! \n");
	if(head == NULL) 
	{
		printf("����?���맂 �옄�뿰�닔媛� 議댁?���븯吏� �븡�뒿�땲�떎. \n");
	}
	else 
	{
		cur = head; 
		printf("%d  ", cur->data);   // 泥� 踰덉?�� �뜲�씠�꽣 ?��?��?��
		
		while(cur->next != NULL)    // �몢 踰덉?�� �씠�썑�쓽 �뜲�씠�꽣 ?��?��?��
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** 硫붾?��?��?�쓽 �빐�젣??�쇱?�� ****/
	if(head == NULL) 
	{
		return 0;    // �빐�젣�븷 �끂�뱶媛� 議댁?���븯吏� �븡�뒗�떎.
	}
	else 
	{
		Node * delNode = head;
		Node * delNextNode = head->next;

		printf("%d�쓣(?���?) �궘�젣��??�땲�떎. \n", head->data);
		free(delNode);    // 泥� 踰덉?�� �끂�뱶�쓽 �궘�젣
		
		while(delNextNode != NULL)    // �몢 踰덉?�� �씠�썑�쓽 �끂�뱶 �궘�젣 �쐞�븳 諛섎?��?���?
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d�쓣(?���?) �궘�젣��??�땲�떎. \n", delNode->data);
			free(delNode);    // �몢 踰덉?�� �씠�썑�쓽 �끂�뱶 �궘�젣
		}
	}

	return 0;
}