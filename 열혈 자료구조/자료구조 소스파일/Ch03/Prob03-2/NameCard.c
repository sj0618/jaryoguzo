#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone)
{
	NameCard * newcard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(newcard->name,name);
	strcpy(newcard->phone,phone);
	return newcard;
}

void ShowNameCardInfo(NameCard * pcard)
{
	printf("이름: %s\n",pcard->name);
	printf("번호: %s\n",pcard->phone);
}


int NameCompare(NameCard * pcard, char * name)
{
	return strcmp(pcard->name,name);
}

void ChangePhoneNum(NameCard * pcard, char * phone)
{
	strcpy((pcard->phone),phone);
}
/**/