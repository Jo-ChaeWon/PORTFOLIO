#define NUMBER_OF_MAN 5   // ó���� �Է¹޴� �����. ���� ��ĥ�� ����.
#include <stdio.h>    
#include <conio.h>       //getch(){Ű�ϳ� �Է¹޴� �Լ�}�� ����ϱ����� ����
#include <process.h>   //exit(){�����Լ�}�� ����ϱ����� ����
#include <string.h>      //strcmp(){���ڿ��ΰ��� ���ϴ� �Լ�}�� ����ϱ����� ����

struct {
	char name[16];
	char addr[128];
	char tel[32];
} a[256];   // ����ü 256�� ����. 256���� Ư���� ������ ���� ���ڶ��� �ʱ����� �˳��� ����.
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

void del() //�ּ� ����� �Լ�
{
	int i, i2;

	prnt(); //�켱 ��� ����Ʈ ���
	printf("select delete number:");
	scanf("%d", &i); // ���߿� ���� �Է¹���
	i--;

	for (i2 = i; i2 < max_a; i2++)
		a[i2] = a[i2 + 1]; //���� ������ ���� �������κ��� for������ �̵���Ŵ
	max_a--;
}

// �Ƹ� del()�Լ��� for���� ��򸮽Ǽ��� �ִµ���.

// ������ �׸����� �������ڸ�

// 1234567 �����Ͱ� �ִµ� 5�����͸� ����ٰ� ġ��.

// �׷� 123467�� ���ڳ���?

// �׷��� 6�� 5��, 7�� 6���� �ٲٸ� �ٽ� 123456�� ����.

// �����Ͱ� �߰��� ����������� ���ŵ��. ����(�Ϲ����� �迭)�������̱� ������...

// for���� ������ �Ѱ�(�������� 5��������)���� ����(�������� 7������)

// ���� �ϳ��� �̵���ŵ�ϴ�. ^^

void srch()
{
	char find[16];
	int i;

	printf("input search name:");
	scanf("%s", &find); // �˻�� �Է¹޴´�.

	for (i = 0; i ; if (!strcmp(find, a[i].name))
		printf("[%d]name:%s addr:%s tel:%s\n", i + 1, a[i].name, a[i].addr, a[i].tel)); //�� �ڷ�� �ϳ��� �̸��� ���ؼ� ������(=ã����) ���
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
	}// ó���� define���� ������ ��ŭ �����͸� �Է¹޽��ϴ�.

	while (1) // ���ѷ������̱⶧���� q()�Լ��� exit(0)�� ������ �ʴ��� ������� �ʽ��ϴ�.
	{
		printf("================�ּҷ� ���� ���α׷�===============\n");
		printf("1)����\n2)����\n3)�˻�\n4)���\n5)����\n");
		ch = getch(); // Ű�ϳ��� �Է¹޽��ϴ�.
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
