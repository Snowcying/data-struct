#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW 0
#define ERROR 0
#define LENGTH 100

using namespace std;

typedef struct  BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T)
{
	char ch;
//	scanf(&ch);
	cin>>ch;
	if(ch=='#') T=NULL;
	else
	{
		T=(BiTNode *)malloc(sizeof(BiTNode));
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild); 
	}
	
}

void Visit(char e)
{
	cout<<e;
}

void PreOrderTraverse(BiTree T,int &l)
{
	if(T)
	{
		Visit(T->data);
		if(T->lchild==NULL&&T->rchild==NULL)
			l++;
		PreOrderTraverse(T->lchild,l);
		PreOrderTraverse(T->rchild,l);
	}
	else
	{
		cout<<"#";
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
	else
	{
		cout<<"#";
	}
	
}

void EndOrderTraverse(BiTree T)
{
	if(T)
	{
		
		EndOrderTraverse(T->lchild);
		EndOrderTraverse(T->rchild);
		Visit(T->data);
	}
	else
	{
		cout<<"#";
	}
}
//abcdegf	cbegdfa		cgefdba abc##de#g##f###
int main()
{
	BiTNode *t; 
	CreateBiTree(t);
//	cout<<t->data;
	int leaf=0;
	PreOrderTraverse(t,leaf);
	cout<<endl<<leaf;
//	cout<<endl;
//	InOrderTraverse(t);
//	cout<<endl;
//	EndOrderTraverse(t);
	
	return 0;
}
