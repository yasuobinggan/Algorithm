/*
	����ļ��� uva11988
*/
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=100000+5;
int last,cur,next[maxn];//���λ��cur���ַ��ĺ���
char s[maxn]; 
int main()
{
	int i;
	while(scanf("%s",s+1)==1)
	{
		int n=strlen(s+1);
		last=cur=0;
		next[0]=0;
		//������ 
		for(i=1;i<=n;i++)
		{
			if(s[i]=='[')
			{
				cur=0;
				//next[i]=0;
			}
			else if(s[i]==']')
			{
				cur=last;
				//next[i]=last;
			}
			else
			{
				next[i]=next[cur];
				next[cur]=i;
				if(cur==last)
					last=i;
				cur=i;
			}
		}
		//��ʽ���� 
		for(int i=next[0];i!=0;i=next[i])
		{
			cout<<s[i];
		}
		cout<<"\n";
	}
	return 0;
}
