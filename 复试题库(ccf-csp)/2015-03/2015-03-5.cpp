//���·�� ̰��ѡʳ��
//��Ȩ�ڽ�ͼ
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;

struct Node{
    int v;
    int dis;
    Node(int _v,int _dis):v(_v),dis(_dis){}
};
vector<Node> G[maxn];
int n,m;
int w[maxn];
int d[maxn][maxn];
//floyd��ȡ���·��+���·������
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<)
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    int u,v,dis;
    for(int i=1;i<=n-1;i++)
    {
        cin>>u>>v>>dis;
        G[u].push_back(Node(v,dis));
        G[v].push_back(Node(u,dis));
    }
    floyd();
    //̰��

    return 0;
}
