/*
	�Գ���uva1595
	һ.ʹ��map�����Ǹо�map������� 
*/
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
map<int,int> cnt;//����ֵ������ֵ 
bool judge()
{
	double aw1,aw2;
	//����������,it,jʵ������ָ�� 
	map<int,int>::iterator it,j;//jΪ����жϵ����� 
	double sum;
	for(it=cnt.begin();it!=cnt.end();it=it+cnt.count(it->first))
	{
		if(it==cnt.begin())
		{
			if(cnt.count(it->first)%2==0)
			{	
				sum=0;
				for(j=it;j<(it+cnt.count(it->first));j++)
					sum+=j->second;
				sum/=cnt.count(it->first);
				aw1=sum;	
			}
			else
			{
				aw1=it.
			}	
		}
		else
		{
			if(cnt.count(it->first)%2==0)
			{	
				sum=0;
				for(j=it;j<it+cnt.count(it->first);j++)
					sum+=j->second;
				sum/=cnt.count(it->first);
				aw2=sum;
				if(aw2!=aw1)
					return 0;	
			}
			else
			{
				aw2=cnt[(it+it+cnt.count(it->first)-1)/2];
				if(aw2!=aw1)
				return 0;
			}
		}
		//
	}
	
	return 1;
}
int main()
{
 	int n,a,b;
 	cin>>n;
 	while(n-->0)
 	{
 		cin>>a>>b;
 		map[b]=a;
 	}
 	if(judge())
 		cout<<"YES\n";
 	else
 		cout<<"NO\n";
	return 0;
}
