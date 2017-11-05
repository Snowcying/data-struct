#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100
#define STACK_INCREASE 10 
#define OVERFLOW 0
#define ERROR 0
using namespace std;

typedef struct QNode
{
	char data;
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

void EnQueue(LinkQueue &Q,int e)
{
	//insert e into queue
	QNode *p;
	p=(QueuePtr)malloc(sizeof(QNode));
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}

void DeQueue(LinkQueue &Q,char &e)
{
	if(Q.front==Q.rear)	cout<<"空队列"<<endl;
	
	QNode *p;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)	Q.rear=Q.front;
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
//	if(Q.front==p)	Q.rear=Q.front;
//	free(p);
//}

char GetFront(LinkQueue Q)
{
	return Q.front->next->data;
}

char GetRear(LinkQueue Q)
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
		cout<<p->data<<" ";
		
	}
}



//**************************************************************************************************************
typedef struct 
{
	char *base;
	char *top;
	int stacksize;
}Stack;

void InitStack(Stack &s)
{
	s.base=(char *)malloc(STACK_SIZE * sizeof(char));
	if(!s.base) exit(OVERFLOW);
	s.top=s.base;
	s.stacksize=STACK_SIZE;
}

void Push(Stack &s,char e)
{
	if(s.top-s.base>=s.stacksize)
	{
		s.base=(char *)realloc(s.base,(s.stacksize+STACK_INCREASE)*sizeof(char));
		if(!s.base) exit(OVERFLOW);
		s.top=s.base+s.stacksize;
		s.stacksize+=STACK_INCREASE;
	}
	*s.top=e;
	s.top++;
}

void Pop(Stack &s,char &e) 
{
	if(s.top==s.base) printf("ERROR");
	s.top--;
	e=*s.top;
}

//void GetTop(Stack &s,int &e)
//{
//	if(s.top==s.base) printf("ERROR");
//	e=*(s.top-1);
//}

char GetTop(Stack &s)
{
	return *(s.top-1);
}

void PrintStack(Stack s)
{
	while(s.top!=s.base)
	{
		s.top--;
		cout<<*s.top<<" ";
	}
}

void DestroyStack(Stack &s)
{
	free(s.base);
	s.base=NULL;
	s.top=NULL;
	s.stacksize=0;
}
//**************************************************************************************************************
int main()
{
	LinkQueue q1;
	InitQueue(q1);
	Stack s1;
	InitStack(s1);
	
	char a;
	cin>>a;
	int length=0,f=0;
	while(a!='@')
	{
		EnQueue(q1,a);
		Push(s1,a);
		cin>>a;
		length++;
	}
	length=length/2;
	while(length--)
	{
		char top,down;
		Pop(s1,top);
		DeQueue(q1,down);
		if(top!=down)
		{
			f=1;
		}
	}
	if(f)
	{
		cout<<"no"<<endl;
	}
	else
	{
		cout<<"yes"<<endl;
	}
//	PrintStack(s1);
//	PrintQueue(q1);
	return 0;
}
