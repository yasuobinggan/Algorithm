//���������ý��
#include<bits/stdc++.h>
using namespace std;
//�ޱ������,��last��¼���ڵ�(���������޻��ṹ)
void dfs(int now,int last,int d[],vector<int> tree)
{
    int u;
    for(int i=0;i<tree[now].size();i++)
    {
        if((u=tree[now][i])!=last)
        {
            d[u]=d[now]+1;
            dfs(u,now,d,tree);
        }
    }
}
int main()
{
    int n,m,t;
    //�����ڽ�ͼ
    cin>>n>>m;
    vector<int> tree[n+m+2];
    int dist[n+m+2];
    for(int i=2;i<=n;i++)
    {
        cin>>t;
        tree[i].push_back(t);
        tree[t].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>t;
        tree[n+i].push_back(t);
        tree[t].push_back(n+i);
    }
    //
    memset(dist,0,sizeof(dist));
    dfs(1,0,dist,tree);

    int start=0;
    dist[start]=0;
    //......
    return 0;
}
