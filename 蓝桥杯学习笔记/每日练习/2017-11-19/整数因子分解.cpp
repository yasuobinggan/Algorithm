#include<stdio.h>
int count=0;
int flag(int m)
{
	int i;
	for(i=2;i<m;i++)
	{
		if(m%i==0)
			return 1;//������ 
	}
	return 0;//���� 
}
int factoring(int n)//�ظ� 
{
	int i;
	if(flag(n))
	{
		for(i=2;i<n;i++)//i<abs(n) 
		{
			if(n%i==0)
			{
				
				count++;
				printf("%d %d\t",n/i,i);
				//n=n/i;//�ı����ѭ����С 
				
				factoring(n/i);
				factoring(i);
				
				//printf("%d",i);
			}
		}
	}
	return count; 
}
int main()
{
	int n;
	scanf("%d",&n);
	//factoring(n); 
	printf("����:\n%d",factoring(n)+1);
	return 0;
 } 
