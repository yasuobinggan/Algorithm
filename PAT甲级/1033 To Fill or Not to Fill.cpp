#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int INF=1e9;
struct station{
    double price,dis;
}st[maxn];
bool cmp(station a,station b)
{
    return a.dis<b.dis;
}
int main()
{
    int n;
    double Cmax,D,Davg;
    scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&st[i].price,&st[i].dis);
    }
    st[n].price=0;
    st[n].dis=D;
    //���վ�������
    sort(st,st+n,cmp);

    if(st[0].dis!=0)
    {
        printf("The maximum travel distance = 0.00\n");
    }
    else
    {
        int now=0;
        //�ܻ���,��ǰ������,������ʻ����
        double ans=0,nowTank=0,MAX=Cmax*Davg;
        //O(n^2)ѭ��
        while(now<n)
        {
            int k=-1;
            double priceMin=INF;
            //��ǰ����վ�ܵ���ľ��뷶Χ�е��ڵ�ǰ�ͼ۵ļ���վ
            for(int i=now+1;i<=n&&st[i].dis-st[now].dis<=MAX;i++)
            {
                //����ͼ۱ȵ�ǰ�ͼ۵�
                if(st[i].price<priceMin)
                {
                    //��ȡ����ͼ�
                    priceMin=st[i].price;
                    k=i;

                    //(�޷�����)����ҵ���һ���ͼ۵��ڵ�ǰ�ͼ۵ļ���վ,ֱ���ж�ѭ��
                    if(priceMin<st[now].price)
                    {
                        break;
                    }

                }
            }
            //����״̬���޷��ҵ�����վ,�˳�ѭ��������
            if(k==-1)
                break;

            //����1
            //�ҿ��ܵ���ļ���վk������ת�ƻ���
            //need: now��k��Ҫ������
            double need=(st[k].dis-st[now].dis)/Davg;
            //���ڼ���վ�ͼ۵��ڵ�ǰ�ͼ�
            if(priceMin<st[now].price)
            {
                //ֻ���㹻�������վk����
                //��ǰ��������need
                if(nowTank<need)
                {
                    //����need������ͼ�
                    ans+=(need-nowTank)*st[now].price;
                    //���������Ϊ��
                    nowTank=0;
                }
                //��ǰ��������need
                else
                {
                    nowTank-=need;
                }

            }
            //����2
            //�������վk���ͼ۸��ڵ�ǰ�ͼ�
            else
            {
                //���������
                ans+=(Cmax-nowTank)*st[now].price;
                //�������վk�������
                nowTank=Cmax-need;
            }
            now=k;
        }

        if(now==n)
        {
            printf("%.2f\n",ans);
        }
        else
        {
            printf("The maximum travel distance = %.2f\n",st[now].dis+MAX);
        }

    }
    return 0;
}
/*
//��̰�ĳ���
//����̰��
//̰�������ǵ�һ��
//̰�ĵ�����һ�����

//destintationĿ��,Ŀ��
#include<bits/stdc++.h>
using namespace std;
//�����������룬��λ�����������ߵľ���,����վ����
double C,D,D_a;int N;
const int maxn=505;
typedef struct node{
    double p;
    double sD_c;
    double eD_c;

    double value;
}s;
s station[maxn];
bool vis[maxn];
bool cmpsD_c(s a,s b)
{
    return a.sD_c<b.sD_c;
}
bool cmpeD_c(s a,s b)
{
    return a.eD_c>b.eD_c;
}
int main()
{
    //cin>>C,D,D_a,N;
    scanf("%lf %lf %lf",&C,&D,&D_a);
    scanf("%d",&N);
    double minprice=0;
    double maxlength=0;
    for(int i=0;i<N;i++)
    {
        //���뵥λ�ͼۣ�����վ�ຼ�ݵľ���
        scanf("%lf %lf",&station[i].p,&station[i].sD_c);
        station[i].eD_c=station[i].sD_c+C*D_a;

        //һ����ߺ�����ֵ��ʣ�����/��λ�ͼ�
    }
    sort(station,station+N,cmpsD_c);
    //̰�ľ���
    //����lower_bound�Ĳ���
    //memset(vis,vis+N,0);
    maxlength=station[0].eD_c;
    minprice+=station[0].p*C;
    for(int i=1;i<N;i++)
    {
        if(maxlength<=station[i].sD_c&&maxlength>station[i-1].eD_c)
        {
            maxlength=station[i-1].eD_c;
            minprice+=station[i-1].p*C;
        }

    }
    if(maxlength>=D)
        printf("%.2f",maxlength);
    else
        printf("The maximum travel distance = %.2f",maxlength);
    //̰�Ļ���
    return 0;
}
*/

