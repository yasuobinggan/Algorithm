#include<stdio.h>
int count=0;
void swap(int &a1,int &a2)
{
	int t;
	t=a1;
	a1=a2;
	a2=t;
}
void rank(int a[],int s,int e)
{
	int i;
	
	if(s==e)//��Ҷ�ӽڵ������ʾ,��¼ 
	{
		for(i=0;i<=e;i++)
		{
			printf("%d\t",a[i]);
		}
		printf("\n");
		count++;
	}	
	else
	{
		for(i=s;i<=e;i++)
		{
			swap(a[s],a[i]);
			rank(a,s+1,e);
			swap(a[i],a[s]);
		}
	}
}
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	rank(a,0,4);
	printf("�������:%d",count);
	return 0;
 } 
