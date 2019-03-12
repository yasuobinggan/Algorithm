//AVL����һЩα�� 
//����,���������������
//�����ĵ����߶Ⱥ��ж�ƽ������ 
#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	int v;//�ڵ��ֵ 
	int height;//�ڵ�ĸ߶� 
	struct node* ltree;
	struct node* rtree; 
}node,*pnode;
//�½����ʱ��ʼ���߶�Ϊ1 
int getHeight(pnode node)
{
	if(node==NULL)
		return 0;
	return node->height; 
}
int getBalanceFactor(pnode node)//����һ����������ƽ������ 
{
	return getHeight(node->ltree)-getHeight(node->rtree);
} 
void updateHeight(pnode &node)
{
	node->height=max(getHeight(node->ltree),getHeight(node->rtree))+1;
} 
void L(pnode &root)//����
{
	pnode temp;
	temp=root->rtree;
	
	root->ltree=temp->ltree;
	temp->ltree=root;
	//���¶��ϸ��½ڵ�߶� 
	updateHeight(root);
	updateHeight(temp);
	
	root=temp;//��Ҫ���� 
 } 
void R(pnode &root)//����
{
	pnode temp;
	temp=root->ltree;
	
	root->ltree=temp->rtree;
	temp->rtree=root;
	//
	updateHeight(root);
	updateHeight(temp);
	
	root=temp;
	 
 } 
void insert(pnode &root,int v)
{
	if(root==NULL)//�ݹ�߽� 
	{
		root=(pnode)malloc(sizeof(node));
		root->v=v;
		root->height=1;//�ڵ�߶ȳ�ʼ��Ϊ1
		root->ltree=root->rtree=NULL;
		return; 
	}
	if(v<root->v)
	{
		insert(root->ltree,v);
		//�������ϵ��������� 
		updateHeight(root);//��������
		if(getBalanceFactor(root)==2)//һ����l�͵�,�ж��Ƿ�ƽ�� 
		{
			if(getBalanceFactor(root->ltree)==1)//ll�� 
			{
				R(root);
			}
			else if(getBalanceFactor(root->ltree)==-1)//lr�� 
			{
				L(root->ltree);
				R(root);
			}
		 } 
	}
	else
	{
		insert(root->rtree,v);
		//�������ϵ��������� 
		updateHeight(root);
		if(getBalanceFactor(root)==-2)
		{
			if(getBalanceFactor(root->rtree)==-1)//rr�� 
			{
				L(root);
			}
			else if(getBalanceFactor(root->rtree)==1)//rl�� 
			{
				R(root->rtree);
				L(root);
			 } 
		}
	}
}
pnode createtree(int n)//����ͷ�ڵ�,����BST��ͬ����Ҫѧϰ 
{
	pnode root=NULL;//�����ڵ� 
	for(int i=0;i<n;i++)
	{
		int data;
		cin>>data;
		insert(root,data);
	}
	cout<<root->v;
	return root;
 } 
 int main()
 {
 	int N;
 	cin>>N;
 	createtree(N);
	 return 0;
 }
