//���鼯��һ����
//���鼯�ĳ�ʼ����������Ŀ���Ǽ��ϵ���Ŀ
#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int n,m;
int father[maxn];
int ans;
void Init()
{
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
	}
 }
/*
int f_f(int x)//·��ѹ��:��ȱ��������//�ݹ���һ�㴦��һ����£�����ô����ᵼ�»��ݻ���
{
	if(x==father[x])//���ظ��ڵ�
		return x;

	//�ᵼ������Ľڵ��޷�ָ����ڵ�
	//x=father[x];
	//int Fa=f_f(x);
	//father[x]=Fa;

	int Fa=f_f(father[x]);
	father[x]=Fa;
	//������һ��,���ݵĹؼ�
	return Fa;
}
*/
int f_f(int x)
{
    if(x==father[x])
            return x;
    return father[x]=f_f(father[x]);
}
void Union(int a,int b)
{
	int fa=f_f(a);
	int fb=f_f(b);
	if(fa!=fb)
		father[fa]=fb;
}
int main()
{
	ans=0;
	cin>>n>>m;
	//�����޸������������
	//memset(cnt,0,sizeof(cnt));
    Init();
	while(m-- > 0)
	{
		int a,b;
		cin>>a>>b;
		Union(a,b);
		//cnt[a]=b;
		//cnt[b]=a;
        //���Ϻϲ��������ϵĸ��ڵ㣬�����޻���

	}
	//��ѹ�����ٱ���
	for(int x=1;x<=maxn;x++)
	{
		f_f(x);
	}
	for(int x=1;x<=maxn;x++)
	{

		if(father[x]==x)
			ans++;
	}
	cout<<ans<<endl;

	return 0;
 }
