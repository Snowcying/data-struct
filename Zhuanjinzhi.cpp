#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define STACK_SIZE 100
#define STACK_INCREASE 10 
#define OVERFLOW 0
#define ERROR 0
typedef struct 
{
	int *base;
	int *top;
	int stacksize;
}Stack;

void InitStack(Stack &s)
{
	s.base=(int *)malloc(STACK_SIZE * sizeof(int));
	if(!s.base) exit(OVERFLOW);
	s.top=s.base;
	s.stacksize=STACK_SIZE;
}

void Push(Stack &s,int e)
{
	if(s.top-s.base>=s.stacksize)
	{
		s.base=(int *)realloc(s.base,(s.stacksize+STACK_INCREASE)*sizeof(int));
		if(!s.base) exit(OVERFLOW);
		s.top=s.base+s.stacksize;
		s.stacksize+=STACK_INCREASE;
	}
	*s.top=e;
	s.top++;
}

void Pop(Stack &s,int &e) 
{
	if(s.top==s.base) printf("ERROR");
	s.top--;
	e=*s.top;
}

void GetTop(Stack &s,int &e)
{
	if(s.top==s.base) printf("ERROR");
	e=*(s.top-1);
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
int main()
{
	Stack s1;
	InitStack(s1);
	int num,n;
	cout<<"输入被转换的数"<<endl;
	cin>>num;
	cout<<"输入进制"<<endl;
	cin>>n;
	while(num)
	{
		Push(s1,num%n);
		num=num/n;
	}
	PrintStack(s1);
	DestroyStack(s1);
	return 0;
}
