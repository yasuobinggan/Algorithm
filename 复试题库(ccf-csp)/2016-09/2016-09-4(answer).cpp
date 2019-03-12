//���Ż�
#include<bits/stdc++.h>
#define inf (1<<30)-1
#define maxn 10005
using namespace std;
class Node{
    public:
        int v;
        int cost;//Դ�㵽�˵����·��
        Node(int vv=0,int c=0)
        {
            v=vv;
            cost=c;
        }
        //���ȼ����н��������С��������
        friend bool operator<(Node n1,Node n2)
        {
            return n1.cost>n2.cost;
        }
};
class Edge{
    public:
        int v,cost;
        Edge(int vv=0,int c=0)
        {
            v=vv;
            cost=c;
        }
};
int n,m;
vector<Edge> G[maxn];//����ͼ
bool marked[maxn];
int disto[maxn];

//˼ά����
int costo[maxn];//��ͨ�ĵ���Ҫ���ӱߵ�Ȩ��
//���Ż�
void dijkstra(int s)
{
    //  ���Ż���dijkstra
//	1. ����Դ�������ĵ����ѣ��������ѡ�
//	2. ѡ���Ѷ�Ԫ��u����������С��Ԫ�أ����Ӷ���ɾ�������Զѽ��е�����
//	3. ������u���ڵģ�δ�����ʹ��ģ��������ǲ���ʽ�Ķ���
//	1):���õ��ڶ�����¾��룬��������Ԫ���ڶ��е�λ�á�
//	2):���õ㲻�ڶ������ѣ����¶ѡ�
//	4. ��ȡ����uΪ�յ㣬�����㷨�������ظ�����2��3
    fill(disto,disto+maxn,inf);
    fill(costo,costo+maxn,inf);
    memset(marked,false,sizeof(marked));
    costo[s]=0;
    disto[s]=0;
    priority_queue<Node> pq;
    pq.push(Node(s,0));
    marked[0]=true;

    Node tmp;
    while(!pq.empty())
    {
        tmp=pq.top();
        pq.pop();
        int v=tmp.v;
        if(marked[v])
            continue;
        marked[v]=true;
        int len=G[v].size();
        for(int i=0;i<len;i++)
        {
            //v--->vv
            int vv=G[v][i].v;
            if(marked[vv])
                continue;
            int cost=G[v][i].cost;
            //��֧�ж�s
            if(disto[v]+cost<disto[vv])
            {
                disto[vv]=disto[v]+cost;
                costo[vv]=cost;
                //
                pq.push(Node(vv,disto[vv]));
            }
            //����ؼ�
            else if(disto[v]+cost==disto[vv])
            {
                costo[vv]=min(costo[vv],cost);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        G[a].push_back(Edge(b,c));
        G[b].push_back(Edge(a,c));
    }

    //��ʼ����dijkstra�н���
    dijkstra(1);

    //ͳ�Ʊ�Ȩ��
    int res=0;
    for(int i=2;i<=n;i++)
    {
        //cout<<costo[i]<<endl;
        res+=costo[i];
    }
    cout<<res;
    return 0;
}
/*
4 5
1 2 4
1 3 5
2 3 2
2 4 3
3 4 2
*/
