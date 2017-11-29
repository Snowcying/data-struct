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
	void SearchBST(BiTree T,int key,bool isfind,BiTree f,BiTree &p);
	void InOrderTraverse(BiTree T);
	void DeleteBST(BiTree &T,int k);
	void InsertBST(BiTree &T,int e);

	freopen("SearchBST.txt","r",stdin);
	
	int key;
	cin>>key;
	bool isfind=false;
	
	BiTNode *t;
	CreateBiTree(t);
//	InOrderTraverse(t);
	cout<<endl;
//	DeleteBST(t,12);	
//	InOrderTraverse(t);

	BiTNode *p;
	SearchBST(t,key,isfind,NULL,p);
	if(!isfind)  cout<<"not find the number:"<<key<<endl; 
//	cout<<p->data;
	
	InsertBST(t,11);
	InOrderTraverse(t);
	
	return 0;
}
void SearchBST(BiTree T,int key,bool isfind,BiTree f,BiTree &p);

void InsertBST(BiTree &T,int e)
{
	BiTree p;
	SearchBST(T,e,false,NULL,p);
	BiTree s=(BiTree)malloc(sizeof(BiTNode));
	s->data=e;
	s->lchild=s->rchild=NULL;
	if(!p) T=s;
	else if(e<p->data) p->lchild=s;
	else p->rchild=s;
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

void SearchBST(BiTree T,int key,bool isfind,BiTree f,BiTree &p)
{
		if(!T)	{p=f;}
		else if(key==T->data)
		{
			p=T;
			cout<<"find the key:"<<T->data;
			isfind=true;
		}
		else if(key<T->data)	SearchBST(T->lchild,key,isfind,T,p);
		else SearchBST(T->rchild,key,isfind,T,p);
	
	
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

void DeleteT(BiTree &p)
{
	BiTree q;
	if(!p->rchild)
	{
		q=p;p=p->lchild;
		free(q);
	}
	else if(!p->lchild)
	{
		q=p;
		p=p->rchild;
		free(q);
	}
	else
	{
		q=p;
		BiTree s=p->lchild;
		while(s->rchild)
		{
			q=s;
			s=s->rchild;
		}
		p->data=s->data;
		if(q!=p)	q->rchild=s->lchild;
		else q->lchild=s->lchild;
		delete s;
	}
}

void DeleteBST(BiTree &T,int key)
{
	if(!T) cout<<"ERROR"<<endl;
	else
	{
		if(key==T->data) DeleteT(T);
		else if(key<T->data) DeleteBST(T->lchild,key);
		else DeleteBST(T->rchild,key);
	}
}
