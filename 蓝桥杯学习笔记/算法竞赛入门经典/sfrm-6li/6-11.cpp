/*
	�ķ�����uva297
		һ���ݹ������ñ�ǲ���
			�� ��ά����+��� ������������ 
		����ѭ����ǲ���(��ǲ����Ƚϸ���)
			��Ҫ��ջ 
			Ҳ����ʹ�ö�ά������������� 
	��ά�����൱�ڱ�� 
*/ 
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define LEN 32
#define maxn 1024+5
int draw1(char str1[],char str2[])//ѭ����� 
{
	int p1,pe1,p2,pe2;
	p1=p2=0;
	pe1=p1;pe2=p2;
	int cnt=1;
	int area=0;
	while(p1<strlen(str1)&&p2<strlen(str2))
	{
		if(str1[p1]=='p')
		{
			if(str2[p2]=='p')
			{
				
			}
			if(str2[p2]=='f')
			{
				
			}
			if(str2[p2]=='e')
			{
				
			}
		}
		if(str1[p1]='f')
		{
			area+=(LEN/cnt)*(LEN/cnt);
			p1++;p2++;
		}
		if(str1[p1]='e')
		{
			if(str2[p2]=='p')
			{
				
			}
			if(str2[p2]=='f')
			{
				
			}
			if(str2[p2]=='e')
			{
				area+=0;
			}
		}
	}
	return area; 
} 
int main()
{
	int n;
	char str1[maxn],str2[maxn]; 
	cin>>n;//�������� 
	while(n-- > 0)
	{
		//memset()
		cin>>str1>>str2;
		cout<<draw1(str1,str2)<<endl;
	}
	return 0;
} 
