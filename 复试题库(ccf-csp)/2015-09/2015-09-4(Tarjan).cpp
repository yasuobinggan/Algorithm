//һ��ͼ,�ĸ�����


//ʱ��� ǿ��ͨ������һ�����ڻ�
//���Ļ����ж�
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
//��������,���ٹ�·����
int n,m;
struct Node{
    int v;
    Node(int _v):v(_v){}
};
vector<Node> G[maxn];
//dfsʱ���,low��������������������С�����ĸ�
int dfn[maxn],low[maxn];
//ǰ�����
//int head[maxn];
//ջ,�ж�ջ���Ƿ���ڱ��
int _stack[maxn];bool visited[maxn];
//dfn�±�,_stack:ָ��ջ��Ԫ��
int index=0,top=0;
//��¼��ͨ������
int ans=0;
void tarjan(int u)
{
    //�Ե�ǰ�ڵ�ķ���,����
    dfn[u]=low[u]=++index;
    _stack[++top]=u;
    visited[u]=true;
    //ö�ٱ߽���dfs����
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i].v;
        if(dfn[v]==0)//visited�����ж�Ҳ��
        {
            tarjan(v);
            //����********
            //����߻���(�ǻ�)
            low[u]=min(low[u],low[v]);
        }
        //����
        //�����ʹ�,��ջ��(ջ��ά��һ����ǿ��ͨ����(��)��,Լ����ͬһ����ֲ��)
        else if(visited[v]==true)
        {
            low[u]=min(low[u],dfn[v]);//dfn���Ĺؼ��ڵ�
        }
    }
    //����
    if(dfn[u]==low[u])
    {
        //�����ĵ�Ϊһ��ǿ��ͨ����
        while(u!=_stack[top])
        {
            //��ʵ��Ⱦɫ����
            visited[_stack[top]]=false;
            --top;
        }
        ans++;
    }
    return;
}
int main()
{
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        G[u].push_back(Node(v));
    }
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(_stack,0,sizeof(_stack));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==0)
            tarjan(i);
    }
    cout<<ans;
    return 0;
}
/*
5 5
1 2
2 3
3 4
4 2
3 5
*/
