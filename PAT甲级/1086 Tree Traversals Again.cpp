//ջ��������(����) 
//recursive�ݹ� 
#include<bits/stdc++.h>
using namespace std;
const int maxl = 35;
typedef struct node {
	int ltree;
	int rtree;
}node;
node tree[maxl];
int N;
vector<int> inorder;//ģ����еĹ�����ʽ 
vector<int> postorder;//��ȡ������� 
					  //bool vis[maxl];
string op; int Data;
int Root;//��ȡ���ĸ��ڵ� 

void initiate()
{
	for (int i = 1; i <= N; i++)
	{
		tree[i].ltree = tree[i].rtree = -1;
	}
}
void con_tree(int n)
{
	int curp;//��ǰ��Ҫ�������Ľڵ� 
	for (int i = 1; i <= 2 * n; i++)
	{
		cin >> op;//dataΪ�ڵ��� 
		if (op == "Push")
			cin >> Data;
		if (i == 1)
		{
			Root = Data;
			curp = Data;
			inorder.push_back(Data);
		}
		else if (op == "Push")
		{
			inorder.push_back(Data);
			if (tree[curp].ltree == -1)
			{
				tree[curp].ltree = Data;
			}
			else if (tree[curp].rtree == -1)
			{
				tree[curp].rtree = Data;
			}
			curp = Data;
		}
		else
		{
			curp = inorder.back();
			inorder.pop_back();
		}
	}
}
/*
int findroot()
{

}
*/
void posttravel(int root)
{
	if (root == -1)
		return;
	posttravel(tree[root].ltree);
	posttravel(tree[root].rtree);
	postorder.push_back(root);
}
int main()
{
	cin >> N;
	//fill(vis,vis+maxl,0);
	initiate();
	con_tree(N);
	posttravel(Root);
	for (int i = 0; i<postorder.size(); i++)
	{
		cout << postorder[i];
		if (i != postorder.size() - 1)
		{
			cout << " ";
		}
	}
	return 0;
}
/*
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
*/
