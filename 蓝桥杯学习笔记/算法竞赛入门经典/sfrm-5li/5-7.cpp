/*
���� 
	һ.^�Ե�ǰ����Ϊ��
	��.�����ɵ���������Ϊ�������ж��в��� 
*/
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;
int ugly[10000];
int getUglyNumber(int n)
{
	int id2,id3,id5,i;
	int u2,u3,u5;
	int min_n;
	id2=id3=id5=0;
	min_n=ugly[0]=1;
	i=1;
	while(i<n)
	{
		u2=ugly[id2]*2;
		u3=ugly[id3]*3;
		u5=ugly[id5]*5;
		min_n=min(u2,min(u3,u5));
		//����else if����Ϊ�����ص�ʱ�±�Ҳ���� 
		if(min_n==u2)
			id2++;
		if(min_n==u3)
			id3++;
		if(min_n==u5)
			id5++;
		ugly[i]=min_n;
		i++;
	}
	return ugly[i-1];
}
int main()
{
	int n;
	cin>>n;//��õڼ������� 
	cout<<getUglyNumber(n)<<endl; 
	return 0;
}
