/*

//polynomials ����ʽ
//respectively //���Ե�
//accurate up to 1 decimal place��ȷ��С�����һλ
//accurate��ȷ
//decimalС��
#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	int e;//����
	double c;//ϵ��
	struct node* next;
}node,*pnode;
pnode L1,L2;
pnode result;
void read_input(int k,pnode &l)//β��
{
	pnode p;
	l=(pnode)malloc(sizeof(node));
	l->next=NULL;
	p=l;
	for(int i=0;i<k;i++)
	{
		pnode curnode;
		curnode=(pnode)malloc(sizeof(node));
		scanf("%d%lf",&curnode->e,&curnode->c);
		curnode->next=p->next;
		p->next=curnode;
		p=curnode;
	}
 }

void test_output(pnode l)
{
	pnode p=l->next;
	printf("\n");
	while(p)
	{
		printf("%d %f ",p->e,p->c);
		p=p->next;
	 }
	printf("\n");
}


int product(pnode l1,pnode l2)
{
	int length=0;
	result=(pnode)malloc(sizeof(node));
	result->next=NULL;
	pnode p1=l1->next;
	while(p)
	{

	 }
	return length;
 }

int main()
{
	int K1,K2;
	scanf("%d",&K1);
	read_input(K1,L1);
	scanf("%d",&K2);
	read_input(K2,L2);

	int length=product(L1,L2);
	printf("%d ",length);

	return 0;
}

*/
//���
//������ߴ����˼��
#include<bits/stdc++.h>
using namespace std;
struct poly{
    int exp;
    double cof;
}poly[1001];
//�±�:����,�洢��Ԫ:ϵ��
double ans[2001];//2000�˻������ߴ���
int main()
{
    int n,m;
    //���벢����
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %lf",&poly[i].exp,&poly[i].cof);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int exp;
        double cof;
        scanf("%d %lf",&exp,&cof);
        for(int j=0;j<n;j++)
        {
            ans[exp+poly[j].exp]+=(poly[j].cof*cof);
        }
    }
    //���
    int number=0;
    for(int i=0;i<=2000;i++)
    {
        //���ݾ�ȷ��λ���ж�double��������
        if(ans[i]!=0.0)
            number++;
    }
    printf("%d",number);
    //�ɸߵ�������
    for(int i=2000;i>=0;i--)
    {
        if(ans[i]!=0.0)
            printf(" %d %.1f",i,ans[i]);
    }
    return 0;
}
