#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


typedef struct  BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;



int main()
{
	void CreateBiTree(BiTree &T);
	void PreOrderTraverse(BiTree T);
	void SearchBST(BiTree T,int key,bool isfind);
	void InOrderTraverse(BiTree T);
	freopen("SearchBST.txt","r",stdin);
	
	int key;
	cin>>key;
	bool isfind=false;
	
	BiTNode *t;
	CreateBiTree(t);
	InOrderTraverse(t);
//	SearchBST(t,key,isfind);
//	if(!isfind)  cout<<"not find the number:"<<key; 
			
	return 0;
}

void CreateBiTree(BiTree &T)
{
	int ch;
	cin>>ch;
	if(ch==-1) T=NULL;
	else
	{
		T=(BiTNode *)malloc(sizeof(BiTNode));
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild); 
	}
	
}
void Visit(int e)
{
	cout<<e<<" ";
}

void PreOrderTraverse(BiTree T)
{
	if(T)
	{
		Visit(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}

}

void SearchBST(BiTree T,int key,bool isfind)
{
	if(T)
	{
		if(key==T->data)
		{
			cout<<"find the key:"<<T->data;
			isfind=true;
		}
		else if(key<T->data)	SearchBST(T->lchild,key,isfind);
		else SearchBST(T->rchild,key,isfind);
	}
}
void InOrderTraverse(BiTree T)
{
	if(T)
	{
		
		InOrderTraverse(T->lchild);
		Visit(T->data);
		InOrderTraverse(T->rchild);
	}
//	else
//	{
//		cout<<"#";
//	}
//	
}
