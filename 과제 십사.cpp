#include <iostream>
#include <string.h>
using namespace std;


int main()
{
	
	cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�." << endl;
	cout << "�ؽ�Ʈ�� ���� ; �Դϴ�. 10000������ �����մϴ�." << endl;
	
	
	char text[10000];
	cin.getline(text, 10000, ';');
	
	
	int a, b, c=0;
	int word[30] = {0};
	
	for(a=0 ; a < strlen(text); a++ )
	{
		if(isalpha(text[a])!=0)
		{
			for(b=0; b<26; b++)
			{
				if((text[a] == b +'a')||(text[a] == b +'A'))
				{
					word[b]++;
					c++;
				}
			}
		}
	}
	cout << "�� ���ĺ� ����" << c << endl; 
	
	for(a=0; a<26; a++)
	{
		cout << (char)(a+'a') << "(" << word[a] << ")" <<  ":";
		
		for(b=0; b<word[a]; b++)
		{
			cout << "*";
		}
		cout << endl;
	}
	
	
	
}
