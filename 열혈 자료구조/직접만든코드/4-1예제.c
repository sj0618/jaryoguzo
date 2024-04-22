#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

int main(void)
{
	Node * head = NULL;    // NULL ï¿½ë£·ï¿½ì”¤ï¿½ê½£ ?¥?‡ë¦°ï¿½?†•
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;
    head = (Node*)malloc(sizeof(Node));

	/**** ï¿½ëœ²ï¿½ì” ï¿½ê½£?‘œï¿? ï¿½ì—¯ï¿½ì ° è«›ì…?’— ??¨ì‡±? ™ ****/
	while(1)
	{
		printf("ï¿½ì˜„ï¿½ë¿°ï¿½ë‹” ï¿½ì—¯ï¿½ì °: ");
		scanf("%d", &readData);
		if(readData < 1)
			break;

		/*** ï¿½ë‚ï¿½ë±¶ï¿½ì“½ ?•°ë¶½ï¿½ï¿½æ?¨ì‡±? ™ ***/
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		tail->next = newNode;

		tail = newNode;
	}
	printf("\n");

	/**** ï¿½ì—¯ï¿½ì ° è«›ì†ï¿½ï¿½ ï¿½ëœ²ï¿½ì” ï¿½ê½£ï¿½ì“½ ?•°?’•? °??¨ì‡±? ™ ****/
	printf("ï¿½ì—¯ï¿½ì ° è«›ì†ï¿½ï¿½ ï¿½ëœ²ï¿½ì” ï¿½ê½£ï¿½ì“½ ï¿½ìŸ¾ï§£ëŒ?—¯ï¿½ì °! \n");
	if(head == NULL) 
	{
		printf("ï¿½ï¿½ï¿½ï¿½?˜£ï¿½ë§‚ ï¿½ì˜„ï¿½ë¿°ï¿½ë‹”åª›ï¿½ è­°ëŒ?˜±ï¿½ë¸¯ï§ï¿½ ï¿½ë¸¡ï¿½ë’¿ï¿½ë•²ï¿½ë–. \n");
	}
	else 
	{
		cur = head; 
		printf("%d  ", cur->data);   // ï§£ï¿½ è¸°ë‰? ï¿½ëœ²ï¿½ì” ï¿½ê½£ ?•°?’•? °
		
		while(cur->next != NULL)    // ï¿½ëª¢ è¸°ë‰? ï¿½ì” ï¿½ì‘ï¿½ì“½ ï¿½ëœ²ï¿½ì” ï¿½ê½£ ?•°?’•? °
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** ï§ë¶¾?ˆ?”±?Šì“½ ï¿½ë¹ï¿½ì £??¨ì‡±? ™ ****/
	if(head == NULL) 
	{
		return 0;    // ï¿½ë¹ï¿½ì £ï¿½ë¸· ï¿½ë‚ï¿½ë±¶åª›ï¿½ è­°ëŒ?˜±ï¿½ë¸¯ï§ï¿½ ï¿½ë¸¡ï¿½ë’—ï¿½ë–.
	}
	else 
	{
		Node * delNode = head;
		Node * delNextNode = head->next;

		printf("%dï¿½ì“£(?‘œï¿?) ï¿½ê¶˜ï¿½ì £ï¿½ë??ï¿½ë•²ï¿½ë–. \n", head->data);
		free(delNode);    // ï§£ï¿½ è¸°ë‰? ï¿½ë‚ï¿½ë±¶ï¿½ì“½ ï¿½ê¶˜ï¿½ì £
		
		while(delNextNode != NULL)    // ï¿½ëª¢ è¸°ë‰? ï¿½ì” ï¿½ì‘ï¿½ì“½ ï¿½ë‚ï¿½ë±¶ ï¿½ê¶˜ï¿½ì £ ï¿½ìï¿½ë¸³ è«›ì„?‚¬?‡¾ï¿?
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%dï¿½ì“£(?‘œï¿?) ï¿½ê¶˜ï¿½ì £ï¿½ë??ï¿½ë•²ï¿½ë–. \n", delNode->data);
			free(delNode);    // ï¿½ëª¢ è¸°ë‰? ï¿½ì” ï¿½ì‘ï¿½ì“½ ï¿½ë‚ï¿½ë±¶ ï¿½ê¶˜ï¿½ì £
		}
	}

	return 0;
}