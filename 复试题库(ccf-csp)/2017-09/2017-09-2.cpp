//ʱ��ģ��
//�ṹ��Ĺ��캯��
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int val[maxn];
bool visited[maxn];
int N,K;
//������ýṹ��
struct teacher{
    int key;
    int st;
    int ed;
    /*
    teacher(int _key,int _st,int _len)
    {
        key=_key;
        st=_st;
        len=_len;
    }
    */
};
teacher t[maxn];
void testout()
{
    for(int i=1;i<=N;i++)
        cout<<val[i]<<" ";
}
//�ҵ���һ����λ
int find_empty()
{
    for(int i=1;i<=N;i++)
    {
        if(visited[i]==false)
            return i;
    }
}
int main()
{
    memset(val,0,sizeof(val));
    //falseԿ�ײ�Ϊ��
    memset(visited,true,sizeof(visited));
    for(int i=0;i<=N;i++)
        cout<<visited[i];
    cin>>N>>K;
    for(int i=1;i<=N;i++)
        val[i]=i;
    int k,s,l;
    for(int i=1;i<=k;i++)
    {
        cin>>k>>s>>l;
        t[i].key=k;
        t[i].st=s;
        t[i].ed=s+l;
    }
    //ʱ��ģ��
    for(int i=1;i<=100101;i++)
    {

    }
    //���
    testout();
    return 0;
}
