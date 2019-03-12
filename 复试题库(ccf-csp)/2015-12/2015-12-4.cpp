//ע������ͼ�����ڽӾ���ߵĲ�ȫ
//oj

//ŷ��·:ͨ��ͼ�����бߵļ�·
//ŷ����·:�պϵ�ŷ��·
//ŷ��ͼ:����ŷ����·��ͼ

//�ж��Ƿ�����ͨͼ,ŷ��ͼ,���·��
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int n,m;
//���鼯
int father[maxn];
//�Ա߽��б��
struct Node{
    int v;
    Node(int _v):v(_v){}
};
//����ͳ��
int out[maxn];
vector<Node> G[maxn];
bool visited[maxn][maxn];

//��ͼ->���֧������
int find_father(int x)
{
    if(father[x]==x)
        return x;
    else
    {
        int f=find_father(father[x]);
        //ѹ��
        father[x]=f;
        return f;
    }
}
bool cmp(Node a,Node b)
{
    return a.v<b.v;
}
//���ŷ��·��
void dfs(int u)
{
    cout<<u<<" ";
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i].v;
        if(visited[u][v]==false)
        {
            visited[u][v]=true;
            visited[v][u]=true;
            dfs(v);
        }
    }
}
int main()
{
    cin>>n>>m;
    //memset(father,0,sizeof(father));
    int u,v;
    for(int i=1;i<=n;i++)
        father[i]=i;
    memset(out,0,sizeof(out));
    memset(visited,false,sizeof(visited));
    for(int i=0;i<m;i++)
    {
        //�����ڽӾ���
        cin>>u>>v;
        G[u].push_back(Node(v));
        G[v].push_back(Node(u));
        out[u]++;
        out[v]++;
        //���鼯
        father[u]=v;
        int f=find_father(u);
        father[u]=f;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        //cout<<father[i]<<" ";
        if(father[i]==i)
            cnt++;
    }

    if(cnt==1)
    {
        int cntodd=0;
        for(int i=1;i<=n;i++)
        {
            //cout<<i<<" "<<out[i]<<endl;
            if(out[i]%2==0)
                continue;
            else
                cntodd++;
        }
        if((cntodd==2&&out[1]%2==1)||cntodd==0)
        {
            //�Է�֧��������������
            for(int i=1;i<=n;i++)
            {
                sort(G[i].begin(),G[i].end(),cmp);
            }
            dfs(1);
        }
        else
        {
            cout<<-1;
            return 0;
        }


    }
    else
    {
        cout<<cnt<<endl;
        cout<<-1;
        return 0;
    }

    return 0;
}
/*
4 5
1 2
1 3
1 4
2 4
3 4

//

4 6
1 2
1 3
1 4
2 4
3 4
2 3
*/
