//�ټ򵥵ĵݹ飬ע��ݹ�߽�
#include<bits/stdc++.h>
using namespace std;
#define maxl 5
typedef struct Node{
    int data;
    struct Node *ltree;
    struct Node *rtree;
}Node,*PNode;
void create_bst(PNode &root,int data)
{
    if(root==NULL)
    {
        root=(PNode)malloc(sizeof(Node));
        root->data=data;
        root->ltree=NULL;
        root->rtree=NULL;
        return;
    }
    else if(data<=root->data)
    {
        create_bst(root->ltree,data);
    }
    else if(data>root->data)
    {
        create_bst(root->rtree,data);
    }
}
void in_travel(PNode root)
{
    if(root==NULL)
        return;
    in_travel(root->ltree);
    cout<<root->data<<" ";
    in_travel(root->rtree);

}
int main()
{
    int data;
    PNode root;
    root=NULL;//�ؼ�ϸ��
    for(int i=0;i<maxl;i++)
    {
        cin>>data;
        create_bst(root,data);
    }
    in_travel(root);
    return 0;
}
