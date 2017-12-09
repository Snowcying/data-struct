#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define OVERFLOW 0
#define ERROR 0
#define LENGTH 100

using namespace std;



typedef struct  BiTNode
{
	char data;
	int num;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
queue <BiTNode*> myQ;
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

void PreOrderTraverse(BiTree T)
{
	if(T)
	{
		cout<<T->data;
//		if(T->lchild==NULL&&T->rchild==NULL)
//			l++;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	else
	{
		cout<<"#";
	}
}

void LeafTraverse(BiTree T)
{
	int i=1;
	myQ.push(T);
	while(!myQ.empty())
	{
		BiTNode *t=myQ.front();
		cout<<t->data<<" ";
		myQ.pop();
		if(t->lchild)	myQ.push(t->lchild);
		if(t->rchild)	myQ.push(t->rchild);
	}
}

int main()
{
	freopen("TEST.txt","r",stdin);
	BiTNode *t;
	CreateBiTree(t);
//	PreOrderTraverse(t);
	LeafTraverse(t);
	return 0;
}

//____________________________________


typedef struct QNode
{
	int num,data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

void InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	Q.front->next=NULL;
}

void DestroyQueue(LinkQueue &Q)
{
	while(Q.front)
	{
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
}

void EnQueue(LinkQueue &Q,int data,int num)
{
	//insert e into queue
	QNode *p;
	p=(QueuePtr)malloc(sizeof(QNode));
	p->data=data;
	p->num=num;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}

void DeQueue(LinkQueue &Q,int &data,int &num)
{
	if(Q.front==Q.rear)	cout<<"¿Õ¶ÓÁÐ"<<endl;

	QNode *p;
	p=Q.front->next;
	data=p->data;
	num=p->num;
	Q.front->next=p->next;
	if(Q.rear==p)	Q.rear=Q.front;   //Ò»¶¨×¢ÒâÊÇ Q.rear==p£¡£¡
	free(p);
}

int GetFront(LinkQueue Q)
{
	return Q.front->next->data;
}

int GetRear(LinkQueue Q)
{
	return Q.rear->data;
}

void PrintQueue(LinkQueue Q)
{
	QNode *p;
	p=new QNode;
	p=Q.front;
	while(p!=Q.rear)
	{
		p=p->next;
		cout<<p->data<<" "<<p->num<<endl;
	}
}
