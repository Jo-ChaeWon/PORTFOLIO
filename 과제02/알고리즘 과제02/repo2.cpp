#define NUMBER_OF_MAN 5   // 처음에 입력받는 사람수. 수를 고칠수 있음.
#include <stdio.h>    
#include <conio.h>       //getch(){키하나 입력받는 함수}를 사용하기위해 포함
#include <process.h>   //exit(){종료함수}를 사용하기위해 포함
#include <string.h>      //strcmp(){문자열두개를 비교하는 함수}를 사용하기위해 포함

struct {
	char name[16];
	char addr[128];
	char tel[32];
} a[256];   // 구조체 256개 생성. 256개인 특별한 이유는 없고 모자라지 않기위해 넉넉히 잡음.
int max_a = NUMBER_OF_MAN;

void add()
{
	printf("new name:");
	scanf("%s", a[max_a].name);
	printf("new addr:");
	scanf("%s", a[max_a].addr);
	printf("new tel:");
	scanf("%s", a[max_a].tel);
	max_a++;
}

void prnt()
{
	int i;

	for (i = 0; i < max_a; i++)
		printf("[%d]name:%s addr:%s tel:%s\n", i + 1, a[i].name, a[i].addr, a[i].tel);
}

void del() //주소 지우는 함수
{
	int i, i2;

	prnt(); //우선 모든 리스트 출력
	printf("select delete number:");
	scanf("%d", &i); // 그중에 선택 입력받음
	i--;

	for (i2 = i; i2 < max_a; i2++)
		a[i2] = a[i2 + 1]; //지울 공간만 빼고 나머지부분을 for문으로 이동시킴
	max_a--;
}

// 아마 del()함수의 for문이 헷깔리실수도 있는데요.

// 간단히 그림으로 설명하자면

// 1234567 데이터가 있는데 5데이터를 지운다고 치죠.

// 그럼 123467이 되자나요?

// 그러면 6을 5로, 7을 6으로 바꾸면 다시 123456이 되죠.

// 데이터가 중간에 비어있을수는 없거든요. 선형(일반적인 배열)데이터이기 때문에...

// for문은 지우기로 한값(예에서는 5번데이터)부터 끝값(예에서는 7번까지)

// 값을 하나씩 이동시킵니다. ^^

void srch()
{
	char find[16];
	int i;

	printf("input search name:");
	scanf("%s", &find); // 검색어를 입력받는다.

	for (i = 0; i ; if (!strcmp(find, a[i].name))
		printf("[%d]name:%s addr:%s tel:%s\n", i + 1, a[i].name, a[i].addr, a[i].tel)); //총 자료와 하나씩 이름을 비교해서 같으면(=찾으면) 출력
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
		printf("[%d]\nname:", i + 1);
		scanf("%s", a[i].name);
		printf("addr:");
		scanf("%s", a[i].addr);
		printf("tel:");
		scanf("%s", a[i].tel);
	}// 처음에 define에서 지정한 만큼 데이터를 입력받습니다.

	while (1) // 무한루프문이기때문에 q()함수의 exit(0)를 만나지 않는한 종료되지 않습니다.
	{
		printf("================주소록 관리 프로그램===============\n");
		printf("1)삽입\n2)삭제\n3)검색\n4)출력\n5)종료\n");
		ch = getch(); // 키하나를 입력받습니다.
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
