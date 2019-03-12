//����Ϊʲô����&����Ҳ�޸���root->index��ֵ
//�ж�һ�ö�̬������ȫ������
//����дƽ�������
//������������������ʼ��ָ��
//propetry����,����,�Ʋ�
//rotation��ת,ת��

//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef struct node {
	int data;
	int height;
	int index;//����ȫ�������±��Ӧ 
	struct node* ltree;
	struct node* rtree;
}node, *pnode;
const int maxl = 25;
int N;//�ڵ��� 
vector<int> layerorder;
vector<int> judgeorder;
//int l[maxl];//��¼ÿһ���ϵĽڵ��������ݴ������ж��Ƿ�����ȫ������ 
void bfs(pnode root)
{
	queue<pnode> q;
	//queue<int> judgeq;
	root->index=1; 
	q.push(root);

	while (!q.empty())
	{
		pnode curroot = q.front();
		layerorder.push_back(curroot->data);
		judgeorder.push_back(curroot->index);
		q.pop();
		if (curroot->ltree)
		{
			curroot->ltree->index=((curroot->index)*2);
			//judgeq.push(curroot
			q.push(curroot->ltree);
		}
		if (curroot->rtree)
		{
			curroot->rtree->index=((curroot->index)*2+1); 
			q.push(curroot->rtree);
		}
	}
}
int judge(int n)
{
	for(int i=0;i<n;i++)
	{
		//cout<<judgeorder[i]<<"��"; 

		if(judgeorder[i]!=i+1)
			return false;
	}

	return true;
}
/*
void dfs_test(pnode root)
{
	if(root==NULL)
		return;
	cout<<root->index<<" ";
	dfs_test(root->ltree);
	dfs_test(root->rtree);

}
*/
//����������������
int getheight(pnode root)
{
	if (root==NULL)
	{
		return 0;
	}
	return root->height;
}
void updateheight(pnode &root)
{
	root->height = max(getheight(root->ltree), getheight(root->rtree)) + 1;
}
int getbalancefactor(pnode root)
{
	return getheight(root->ltree) - getheight(root->rtree);
}
void l(pnode &root)//���� 
{
	pnode temp;
	temp = root->rtree;
	root->rtree = temp->ltree;
	temp->ltree = root;
	//���¶��ϸ��¸߶� 
	updateheight(root);
	updateheight(temp);
	root = temp;
}
void r(pnode &root)//���� 
{
	pnode temp;
	temp = root->ltree;
	root->ltree = temp->rtree;
	temp->rtree = root;
	updateheight(root);
	updateheight(temp);
	root = temp;
}
void insert(pnode &root, int v)
{
	if (root == NULL)//�ݹ�߽� 
	{
		root = (pnode)malloc(sizeof(node));
		root->data = v;
		root->height = 1;//��ʼ���ڵ��Ϊ 1 
		root->ltree = NULL;
		root->rtree = NULL;
		return;
	}
	if (v >= root->data)
	{
		insert(root->rtree, v);
		//�������¸��ڵ�ĸ߶� 
		updateheight(root);
		if (getbalancefactor(root) == -2)
		{
			//ֻ���������ж���Ϊ������һ������
			if (getbalancefactor(root->rtree) == -1)//rr��
				l(root);
			else if (getbalancefactor(root->rtree) == 1)//rl��
			{
				r(root->rtree);
				l(root);
			}
		}
	}
	else if (v<root->data)
	{
		insert(root->ltree, v);
		//�������¸��ڵ�ĸ߶�
		updateheight(root);
		if (getbalancefactor(root) == 2)
		{
			//ֻ���������ж���Ϊ������һ������
			if (getbalancefactor(root->ltree) == 1)//ll��
				r(root);
			else if (getbalancefactor(root->ltree) == -1)//lr��
			{
				l(root->ltree);
				r(root);
			}
		}
	}
}
pnode createtree(int n)
{
	pnode root;//��̬���ĸ��ڵ�
	root = NULL;
	for (int i = 0; i<n; i++)
	{
		int v;
		cin >> v;
		insert(root, v);
	}
	return root;
}
int main()
{
	cin >> N;

	pnode root = createtree(N);
	bfs(root);
	for (int i = 0; i<layerorder.size(); i++)
	{
		cout << layerorder[i];
		if (i != layerorder.size() - 1)
			cout << " ";
	}
	
	if (judge(N))
	{	
		cout << endl << "YES";
	}
	else
		cout <<endl<< "NO";
	//dfs_test(root);
	return 0;
}
/*
5
88 70 61 63 65
*/
