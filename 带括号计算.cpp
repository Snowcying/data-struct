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
//************************* 
char OP[7]={'+','-','*','/','(',')','#'};
char precede[7][7]={
'>','>','<','<','<','>','>',
'>','>','<','<','<','>','>',
'>','>','>','>','<','>','>',
'>','>','>','>','<','>','>',
'<','<','<','<','<','=',0,
'>','>','>','>',0,'>','>',
'<','<','<','<','<',0,'='};
/*************************对数据操作符数组OP及优先权矩阵的定义*/

/*************************判断输入字符是否为操作符，否则将其认为是数字*/
char Precede(char op,char c)
{int pos_op;
int pos_c;
int i;
for (i=0;i<7;i++)
{if(op==OP[i]) pos_op=i;
if(c==OP[i]) pos_c=i;
}
return(precede[pos_op][pos_c]);
}
/*************************对判定为操作符的字符根据优先权矩阵判断其优先顺序*/
char Operate(char a,char theta,char b)
{switch(theta)
	{case '+': return a+b-'0';
	case '-': return a-b+'0';
	case '*': return (a-'0')*(b-'0')+'0';
	case '/': return (a-'0')/(b-'0')+'0';
}
}
/*************************对表达式进行计算，返回计算结果*/

bool In(char c,char OP[])
{
	for(int i=0;i<7;i++)
	{
		if(OP[i]==c)
		{
			return true;
		}
	}
	return false;
}

void EvaluateExpression(Stack &OPTR,Stack &OPND) 
{
	InitStack(OPTR); Push(OPTR,'#');
	InitStack(OPND); 
	char c,temp,theta,a,b;
	c=getchar();
	while(c!='#'||GetTop(OPTR)!='#')
	{
		if(!In(c,OP))
		{
			Push(OPND,c);
			c=getchar();
		}
		else
		{
			switch( Precede(GetTop(OPTR),c) )
			{
				case '<':
					Push(OPTR,c);	c=getchar();
					break;
				
				case '=':
					Pop(OPTR,temp);		c=getchar();
					break;
				
				case '>':
					Pop(OPTR,theta);
					Pop(OPND,b); Pop(OPND,a);
					Push(OPND,Operate(a,theta,b));
					break;
			}
		}
	}
}

int main()
{
	Stack OPTR,OPND;
	EvaluateExpression(OPTR,OPND);
	char a=GetTop(OPND);
	cout<<a-'0';
	DestroyStack(OPTR);
	DestroyStack(OPND);
//	PrintStack(OPND);
//	printf("\nThis expression's result is:    ");
//	printf("%d\n\n\n\n",i-'0');

	return 0;

}

