//separate �ֿ�
//�ַ��� 
//����ѭ������һ��ע�� 
#include<bits/stdc++.h>
using namespace std;
int a,b;
char num[10000000+5];
int main()
{
	scanf("%d%d",&a,&b);
	
		int sum=a+b;
		if(sum<0)
			printf("-");
		sum=abs(sum);
		
		int len=0;
		int i3=0; 
		while(sum>0)
		{
			num[len]=sum%10+'0';
			
			sum/=10;
			i3++;
			if(i3%3==0&&sum>0)
				num[++len]=',';
			++len; 
		}
		
		for(int i=len-1;i>=0;i--)
		{
			printf("%c",num[i]);
		}
			
	
	return 0;
	
 } 

