#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"
#include "CLLBaseStack.h"

void StackInit(Stack * pstack)			//스택생성함수
{
	pstack->plist = (List*)malloc(sizeof(List));
    ListInit(pstack->plist);
}

int SIsEmpty(Stack * pstack)
{
	
}

void SPush(Stack * pstack, Data data)
{
	
}

Data SPop(Stack * pstack)
{
	
}

Data SPeek(Stack * pstack)
{
}