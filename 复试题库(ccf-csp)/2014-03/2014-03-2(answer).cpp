#include<bits/stdc++.h>
using namespace sts;
const int maxn=10;
//����
struct{
    int winno;
    int x1,y1,x2,y2;
}win[maxn];
//�����
struct{
    int x,y;
}point[maxn];
//˳��
int order[maxn];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        win[i].winno=i+1;
        cin>>win[i].x1>>win[i].y1>>win[i].x1>>win[i].y2;
    }
    for(int i=0;i<m;i++)
    {
        cin>>point[i].x>>point[i].y;
    }
    //��ʼ��������ʾ˳��
    for(int i=0;i<n;i++)
    {
        order[i]=n-i-1;
    }
    //ģ�������
    int winno,temp;
    for(int i=0;i<n;i++)
    {
        winno=-1;
        //�ж��ĸ����ڱ����
        for(int j=0;j<n;j++)
        {
            //�жϵ��Ƿ��ھ��εķ�Χ��
            if(win[order[j]].x1<=point[i].x&&point[i].x<=win[order[j]].x2&&win[order[j]].y1<=point[i].y&&point[i].y<=win[order[j]].y2)
            {
                winno=win[order[j]].winno;
                //������Ĵ����Ƶ���ǰ��
                temp=order[j];
                for(int k=j;k>0;k--)
                    order[k]=order[k-1];
                order[0]=temp;

                break;
            }
        }
        //������
        if(winno==-1)
            cout<<"IGNORED"<<endl;
        else
            cout<<winno<<endl;
    }
    return 0;
}
