#include <iostream>
#include <string.h>
using namespace std;


int main()
{
	
	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
	cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;
	
	
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
	cout << "총 알파벳 수는" << c << endl; 
	
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
