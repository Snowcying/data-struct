
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct LNode
{
	int elem,num;
	LNode *next;
	
}LNode,*LinkList;

void CreateList(LNode *&L)
{
	
	L->next=NULL;
	int people;
//	cout<<"����m�ĳ�ֵ:";
//	cin>>m;
//	cout<<"��������:";
//	cin>>people;
//	cout<<"��������";
//	int a[100];
	
	people=7; 
	int a[7]={3,1,7,2,4,8,4};
	L->num=1;
	L->elem=a[0];
//	for(int i=0;i<people;i++)
//	{
//		cin>>a[i];
//	}
	for(int i=people-1;i>0;--i)
	{
		LNode *p=new LNode;
		p->elem=a[i];
		p->num=i+1;
		p->next=L->next;
		L->next=p;
		if(i==people-1)
		{
			p->next=L;
		}
	}

}

void Delete(LNode *&p)  //ɾ����̽��; x` 
{
	LNode *willdelete=new LNode;
	willdelete=p->next;
	p->next=willdelete->next;
	p=p->next;
	free(willdelete);
}

void DeleteSelf(LNode *&p)
{
	LNode *DeletePreNode=new LNode;
	DeletePreNode=p;
	while(p->next!=DeletePreNode)
	{
		p=p->next;
	}
	Delete(p);
	p=p->next;
	
}

int GetLength(LNode *p)
{
	LNode *temp=new LNode;
	temp=p;
	int length=1;
	while(temp->next!=p)
	{
		temp=temp->next;
		length++;
	}
	return length;
}

void Change(LNode *&p)
{
	p=p->next;
}

void circle(LNode *&p,int m)
{
	void PrintList(LNode *&p);
	int f=1;
	PrintList(p);
	cout<<"Ԥ��ӡ���"<<endl;
	while(p->next->num!=p->num)
	{	
//		if(f)
//		{
//			f=0;
//		}
//		else
//		{
//			m=p->elem;
//		}
	
		 
		if(m==1)
		{
			m=p->elem;
			DeleteSelf(p);
		}
		else
		{
			for(int i=0;i<m-2;i++)
			{
				p=p->next;
			}
			m=p->next->elem;
			Delete(p);
		}
		PrintList(p);
		cout<<endl;	
	}
	cout<<p->num<<endl;
}

void PrintList(LNode *&p)
{
	LNode *p1=new LNode;
	p1=p;
	int f=7;
	f=GetLength(p);
	while(f--)
	{
		cout<<p1->num<<" "<<p1->elem<<endl;
		p1=p1->next;
	}
	cout<<endl;
}

int main()
{
	LNode *p1=new LNode;
	CreateList(p1);
//	PrintList(p1);
	circle(p1,20);
//	Delete(p1);
//	DeleteSelf(p1);
//	Delete(p1);
//	Delete(p1);
	cout<<"�������ǽ�����ӡ"<<endl;
	PrintList(p1);
	
	return 0;
}
//1 1 1
