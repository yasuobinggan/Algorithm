#include<stdio.h>

int maxN(int,int,int);
int maxSum(int num[],int,int);

int main()
{
	int K;
	scanf("%d",&K);
	int num[K+2];
	int i=0;
	for(i=0;i<K;i++)
	{
		scanf("%d",&num[i]);
	} 
	/* 
	printf("��ӡ���飺");
	for(i=0;i<K;i++)
	{
		printf("%d",num[i]);
	}
	*/ 
	int n = maxSum(num,0,K-1);
	printf("%d",n);
	return 0;
} 
int maxN(int a,int b,int c)
{
	
	int s[3];
	s[0]=a,s[1]=b,s[2]=c;
	int max=s[0];
	int i=0;
	for(i=0;i<3;i++)
	{
		if(s[i]>max)
		{
			max=s[i];
		}
	}
	return max;
}

int maxSum(int num[],int max,int min)
{
	//�����max��min������±����С�±�
	
	int LeftMax;
	int RightMax;//������ߵ����ֵ���ұߵ����ֵ

	int center;
	center = (max+min)/2;
	if(max==min)
		return num[max];

	LeftMax=maxSum(num,min,center);//��ߵ����ֵ
	RightMax=maxSum(num,center+1,max);//�ұߵ����ֵ
	
	/*���Խ���ߵ����ֵ*/
	int LeftSumMax=0,RightSumMax=0; 
	int i;
	int LeftSum=0,RightSum=0;
	/*LeftSum,RightSumһֱ�ڸ��´����ߺ��ұߵ����еĽ��*/
	for(i=center;i>=min;i--)
	{
		LeftSum+=num[i];
		if(LeftSum>LeftSumMax)
			LeftSumMax=LeftSum;
	} 
		
	for(i=center+1;i<=max;i++)
	{
		RightSum+=num[i];
		if(RightSum>RightSumMax)
			RightSumMax=RightSum;
	} 
	
	return maxN(LeftMax,RightMax,LeftSumMax+RightSumMax);
}
