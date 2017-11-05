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
	if(Q.front==Q.rear)	cout<<"�ն���"<<endl;
	
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
	if(Q.rear==p)	Q.rear=Q.front;   //һ��ע���� Q.rear==p���� 
	free(p);
}

//void DeRearQueue(LinkQueue &Q,int &e)
//{
//	if(Q.front==Q.rear)	cout<<"�ն���"<<endl;
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
	
	int n=5,m=40,k=3;//�ֱ��ʾ��n ֻ���ӣ�ÿ�����ȡk���ҵ����У�ÿֻ�������ն��ֵ�m�����ӡ�
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
			cout<<"���е���"<<num<<"  deletenum:"<<deletenum+1<<endl; 
			deletenum++;
			//PrintQueue(q1);
			if(deletenum==n) break;
			if(!sum) sum++;
		}
		else
		{
			EnQueue(q1,data,num);
//			cout<<"��ʱ�̵Ķ������";
		//	PrintQueue(q1);
			sum=sum%k+1;  //k=4
		}
	}
	return 0;
	//����㷨�������ǣ��γɿն��е�ʱ��û�и�front->nextָ�������¿�ָ��   ԭ����DeQueue����д���ˡ����� 
}

