//��������:ģ��(׼ȷģ��)�ۼӼ���
//��������
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int a,b,c,y1,y2;

//�·�����
int monthdays[2][13]={
    {
        0,31,28,31,30,31,30,31,31,30,31,30,31
    },
    {
        0,31,29,31,30,31,30,31,31,30,31,30,31
    },
};
//�����жϺ���
bool leapyear(int year)
{
    if(year%400==0)
        return true;
    else if(year%4==0&&year%100!=0)
        return true;
    else
        return false;
}
int main()
{
    cin>>a>>b>>c>>y1>>y2;

    int days=0;
    //�Ż�
    for(int year=1850;year<y1;year++)
    {
        days+=365+leapyear(year);
    }

    for(int i=y1;i<=y2;i++)
    {
        int curdays=days;
        //���·�
        for(int j=1;j<a;j++)
        {
            if(leapyear(i))
                curdays+=monthdays[1][j];
            else
                curdays+=monthdays[0][j];
        }
        //a��1�����ڼ�
            //int curc=(curdays+1)%7+1;
            //int ansc=c-curc+1;
            //ansc+=(b-1)*7;
            //ansc+=c;
        ///
        int weekd=1+curdays%7;
        int ansc=(b-1)*7+((weekd>=c)?(c+7-weekd):(c-weekd));
        ///
        //���
        if(ansc==0||ansc>monthdays[leapyear(i)][a])
            cout<<"none"<<endl;
        else
            printf("%d/%02d/%02d\n",i,a,ansc);

        days+=365+leapyear(i);
    }
    return 0;
}
//5 2 7 2014 2015
