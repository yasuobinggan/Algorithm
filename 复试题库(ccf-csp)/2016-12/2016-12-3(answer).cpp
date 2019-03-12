//string::npos�ַ������Ҳ�ƥ��
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;
//�б�Ȩ������
const int NOVALUE=-1;
//�б���
const int TRUE=-2;
const int FALSE=-3;
//Ȩ��*************************
struct _privilege{
    string category;
    int level;
};
vector<_privilege> privilege;
//��ɫ*************************
struct _role{
    string role;
    int s;
    vector<_privilege> privilege;
};
vector<_role> role;
//�û�*************************
struct _user{
    string user;
    int t;
    vector<string> role;
};
vector<_user> user;


//���Ȩ������
string getcategory(string &s)
{
    int pos=s.find(":");
    if(pos==(int)string::npos)
        return s;
    else
        return s.substr(0,pos);
}
//���Ȩ�޼���
int getlevel(string &s)
{
    int pos=s.find(":");
    if(pos==(int)string::npos)
        return NOVALUE;
    else
        return atoi(s.substr(pos+1,s.length()-1).c_str());
}
//Ȩ��ƥ��(p1��ѯ,p2Ϊ��׼)
int privilegematch(_privilege &p1,_privilege &p2)
{
    //Ȩ�����಻ƥ��
    if(p1.category!=p2.category)
        return FALSE;
    //Ȩ������ƥ��
    else if(p2.level==NOVALUE)
    {
        if(p1.level==NOVALUE)
            return TRUE;
        else
            return p1.level;
    }
    //�ּ���ѯ
    else
    {
        if(p1.level==NOVALUE)
            return TRUE;
        else
        {
            if(p1.level>=p2.level)
                return TRUE;
            else
                return FALSE;
        }
    }
}
//��ɫƥ��(��ɫ,Ȩ��)
int rolematch(string &rl,_privilege &prvl)
{
    int ans=FALSE;
    for(int i=0;i<(int)role.size();i++)
    {
        if(role[i].role==rl)
        {
            for(int j=0;j<role[i].s;j++)
            {
                int rt=privilegematch(role[i].privilege[j],prvl);
                if(rt>ans)
                    ans=rt;
            }
        }
    }
    return ans;
}
//���⴦��:(�û�,Ȩ��)
int query(string &usr,_privilege &prvl)
{
    for(int i=0;i<(int)user.size();i++)
    {
        if(user[i].user==usr)
        {
            int ans=FALSE;
            for(int j=0;j<user[i].t;j++)
            {
                int rt=rolematch(user[i].role[j],prvl);
                if(rt>ans)
                    ans=rt;
            }
            return ans;
        }
    }
    return FALSE;
}
int main()
{
    int p,r,u,q;
    //Ȩ��
    cin>>p;
    //����Ȩ�����
    string c;
    _privilege prvl;
    for(int i=1;i<=p;i++)
    {
        cin>>c;
        prvl.category=getcategory(c);
        prvl.level=getlevel(c);
        privilege.push_back(prvl);
    }
    //��ɫ
    cin>>r;
    _role rl;
    for(int i=1;i<=r;i++)
    {
        cin>>rl.role>>rl.s;
        for(int j=1;j<=rl.s;j++)
        {
            cin>>c;
            prvl.category=getcategory(c);
            prvl.level=getlevel(c);
            rl.privilege.push_back(prvl);
        }
        role.push_back(rl);
    }
    //�û�
    cin>>u;
    for(int i=1;i<=u;i++)
    {
        _user us;
        cin>>us.user>>us.t;
        string role_input;
        for(int j=1;j<=us.t;j++)
        {
            cin>>role_input;
            us.role.push_back(role_input);
        }
        user.push_back(us);
    }
    //�����ѯ����q
    cin>>q;
    string user_input;
    for(int i=1;i<=q;i++)
    {
        cin>>user_input>>c;
        prvl.category=getcategory(c);
        prvl.level=getlevel(c);

        int ans=query(user_input,prvl);
        if(ans==TRUE)
            cout<<"true"<<endl;
        else if(ans==FALSE)
            cout<<"false"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
/*
3
crm:2
git:3
game
4
hr 1 crm:2
it 3 crm:1 git:1 game
dev 2 git:3 game
qa 1 git:2
3
alice 1 hr
bob 2 it qa
charlie 1 dev
9
alice game
alice crm:2
alice git:0
bob git
bob poweroff
charlie game
charlie crm
charlie git:3
malice game
*/
