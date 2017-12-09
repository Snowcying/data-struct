
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


typedef struct LNode
{
	char data;
	LNode *next;
	
}LNode,*LinkList;

void CreateList(LNode *&L)
{
	
	L->next=NULL;
	char zimus[26]; 
	for(int i=0;i<26;i++)
	{
		zimus[i]='a'+i;
	}
	for(int i=26;i>0;--i)
	{
		LNode *p=new LNode;
		p->data=zimus[i];
		p->next=L->next;
		L->next=p;		
	}
}

void PrintList(LNode *&p)
{
	LNode *p1=new LNode;
	p1=p;
	p1=p1->next;
	while(p1)
	{
		cout<<p1->data<<" ";
		p1=p1->next;
	}
	cout<<endl;
}

void InsertList(LNode *&p,char Insert)
{
	LNode *p1=new LNode;
	p1=p;
	p1=p1->next;
	while(p1)
	{
		if(p1->data==Insert)
		{
			LNode *q=new LNode;
			q->data=Insert;
			q->next=p1->next;
			p1->next=q;
			break;
		}
		p1=p1->next;
	}
}

void DeleteList(LNode *&p,char Delete)
{
	LNode *p1=new LNode;
	LNode *q=new LNode;
	p1=p;
	while(p1->next!=NULL)
	{
		char zimu=p1->next->data;	
		if(zimu==Delete)
		{
			LNode *willdelete=new LNode;
			willdelete=p1->next;
			p1->next=willdelete->next; 
			free(willdelete);
			break;
		}
		p1=p1->next;
	}
}

int main()
{
	LNode *p=new LNode;
	
	CreateList(p);
	PrintList(p);
	
	InsertList(p,'b');
	PrintList(p);
	
	DeleteList(p,'z');
	PrintList(p);
	return 0;
	
}
