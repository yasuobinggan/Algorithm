//���������
//�ж�����vector�Ƿ����
//�ж�queue��Ԫ��
#include<bits/stdc++.h>
using namespace std;
int N;
struct Node{
    int x;
    int y;
    Node(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
};
vector<Node> initarr;
vector<Node> curarr;
vector<Node> _curarr;
bool judge()//����ȣ�true
{
    if(initarr.size()!=curarr.size())
        return true;
    for(int i=0;i<initarr.size();i++)
    {
        if(initarr[i].x!=curarr[i].x||initarr[i].y!=curarr[i].y)
            return true;
    }
    return false;
}
void testout(vector<Node> pra)
{
    cout<<"�������"<<endl;
    for(int i=0;i<pra.size();i++)
    {
        cout<<pra[i].x<<" "<<pra[i].y<<endl;
    }
    cout<<endl;
}
int main()
{
    while(cin>>N&&N!=0)
    {
        initarr.clear();
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                initarr.push_back(Node(i,j));
            }
        }

        //testout(initarr);
        int cnt=0;
        //curarr=initarr;
        _curarr=initarr;
        while(judge())
        {
            cout<<"_curarr:"<<endl;
            testout(_curarr);
            cnt++;
            curarr.clear();
            for(int i=0;i<_curarr.size();i++)
            {
                int curx=(_curarr[i].x+_curarr[i].y)%N;
                int cury=(_curarr[i].x+_curarr[i].y*2)%N;

                Node curnode(curx,cury);
                curarr.push_back(curnode);
            }
            cout<<"curarr"<<endl;
            testout(curarr);
            _curarr=curarr;
        }
        //cout<<cnt<<endl;
    }
    return 0;
}
