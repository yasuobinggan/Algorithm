#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int b;
    cin>>a>>b;
    //tΪ�̵�ÿһλ
    int t,temp;
    //(�б�Ҫ�����)����̵���λ
    t=(a[0]-'0')/b;
    if(a.size()==1||(t!=0&&a.size()>1))
        cout<<t;
    //����
    temp=(a[0]-'0')%b;
    for(int i=1;i<a.size();i++)
    {
        t=((temp*10)+a[i]-'0')/b;
        cout<<t;
        temp=((temp*10)+a[i]-'0')%b;
    }
    cout<<" "<<temp;
    return 0;
}
