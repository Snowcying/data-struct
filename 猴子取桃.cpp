#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW 0
#define ERROR 0
#define MAXQSIZE 100
using namespace std;

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
	if(Q.front==Q.rear)	cout<<"空队列"<<endl;
	
	QNode *p;
	p=Q.front->next;
	data=p->data;
	num=p->num;
//	if(p->next==NULL)
//	{
//		Q.rear=Q.front;
//	}
//	else
//	{
//		Q.front->next=p->next;
//	}
	Q.front->next=p->next;
	if(Q.rear==p)	Q.rear=Q.front;   //一定注意是 Q.rear==p！！ 
	free(p);
}

//void DeRearQueue(LinkQueue &Q,int &e)
//{
//	if(Q.front==Q.rear)	cout<<"空队列"<<endl;
//	
//	QNode *p;
//	p=Q.rear;
//	e=p->data;
//	Q.front->next=p->next;
//	if(Q.rear==p)	Q.rear=Q.front;
//	free(p);
//}

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

int main()
{
	LinkQueue q1;
	InitQueue(q1);
	
	int n=5,m=40,k=3;//分别表示有n 只猴子，每次最多取k个桃到筐中，每只猴子最终都分到m个桃子。
	for(int i=1;i<=n;i++)	
	{
		EnQueue(q1,0,i);
	}
//	PrintQueue(q1);
	int sum=1;
	int deletenum=0;
	while(1)
	{
		int num,data;
		DeQueue(q1,data,num);
		data=data+sum;
		if(data>=m)  //m=3
		{
			sum=data-m;
			cout<<"出列的是"<<num<<"  deletenum:"<<deletenum+1<<endl; 
			deletenum++;
			//PrintQueue(q1);
			if(deletenum==n) break;
			if(!sum) sum++;
		}
		else
		{
			EnQueue(q1,data,num);
//			cout<<"该时刻的队列情况";
		//	PrintQueue(q1);
			sum=sum%k+1;  //k=4
		}
	}
	return 0;
	//这个算法的问题是，形成空队列的时候，没有给front->next指明，导致空指针   原因是DeQueue函数写错了。。。 
}

