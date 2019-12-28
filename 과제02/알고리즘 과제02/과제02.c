#define NUMBER_OF_MAN 5   
#include <stdio.h>    
#include <conio.h>      
#include <process.h>  
#include <string.h>

struct employee
{
	char name[200];
	char number[200];
	char place[200];
	char birthday[200];
} tell[500];

int max_tell = NUMBER_OF_MAN;

void add()
{
	printf("    new name : ");
	scanf("%s", tell[max_tell].name);
	printf("  new number : ");
	scanf("%s", tell[max_tell].number);
	printf("   new place : ");
	scanf("%s", tell[max_tell].place);
	printf("new birthday : ");
	scanf("%s", tell[max_tell].birthday);
	max_tell++;
}

void prnt()
{
	int i;

	for (i = 0; i < max_tell; i++)
	{
		printf("[%d] name : %s    number : %s    place : %s    birthday : %s \n",
			i + 1, tell[i].name, tell[i].number, tell[i].place, tell[i].birthday);
	}
}

void del()
{
	int i, i2;

	prnt();
	printf("select : ");
	scanf("%d", &i);
	i--;

	for (i2 = i; i2 < max_tell; i2++)
	{
		tell[i2] = tell[i2 + 1];
		max_tell--;
	}
}

void srch()
{
	char find[50];
	int i;

	printf("search : ");
	scanf("%s", &find);

	for (i = 0; i < max_tell; i++)
	{

		if (strcmp(find, tell[i].name) == 0)
		{
			printf("[%d] name : %s    number : %s    place : %s   birthday : %s\n",
				i + 1, tell[i].name, tell[i].number, tell[i].place, tell[i].birthday);
		}
	}
}

void q()
{
	exit(0);
}


void main()
{
	int i;
	char ch;

	for (i = 0; i < NUMBER_OF_MAN; i++)
	{
		printf("[%d]\n    name : ", i + 1);
		scanf("%s", tell[i].name);
		printf("  number : ");
		scanf("%s", tell[i].number);
		printf("   place : ");
		scanf("%s", tell[i].place);
		printf("birthday : ");
		scanf("%s", tell[i].birthday);
	}

	while (1)
	{
		printf("                 <주소록 프로그램>                \n");
		printf("1) 추가하기\n2) 삭제하기\n3) 탐색하기\n4) 목록보기\n5) 종료하기\n");
		ch = getch();
		switch (ch)
		{
		case 49: add(); break;
		case 50: del(); break;
		case 51: srch(); break;
		case 52: prnt(); break;
		case 53: q();
		}
	}
}
