#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW 0
#define ERROR 0
#define LENGTH 100
using namespace std;

typedef struct
{
	char *ch;
	int length;
}HString;

void CreateString(HString &S,char *chars)
{
	int PreLength;
	char *c=chars;
	for(PreLength=0;*c;c++,PreLength++);
	if(!PreLength)
	{
		S.ch=NULL;
		S.length=0;
	}
	else
	{
		S.ch=(char *)malloc((PreLength+1000)*sizeof(char));
		for(int i=0;i<PreLength;i++)
		{
			S.ch[i]=chars[i];
		}
		S.length=PreLength;
	}
}

int FindString(HString S,HString Compa,int pos)
{
	int i=pos,j=0;
	while(i<S.length&&j<Compa.length)
	{
		if(S.ch[i]==Compa.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	if(j==Compa.length)	return i-Compa.length+1;
	else return 0;
}
//1234
//34

void Concat(HString &T,HString S1,HString S2)
{
	if(T.ch)	free(T.ch);
	T.ch=(char *)malloc((S1.length+S2.length)*sizeof(char));
//		exit(OVERFLOW);
	
	for(int i=0;i<S1.length;i++)
		T.ch[i]=S1.ch[i];
		
	T.length=S1.length+S2.length;
	
	for(int i=S1.length;i<T.length;i++)
		T.ch[i]=S2.ch[i-S1.length];
		 
}
void Sub(HString &Sub,HString S,int pos,int len)
{
	Sub.ch=(char *)malloc(len*sizeof(char));
	for(int i=0;i<len;i++)
	{
		Sub.ch[i]=S.ch[pos+i];
	}
	Sub.length=len;
}
void fun(HString &Long,HString Short,HString ti)
{
	int pos=FindString(Long,Short,0);//5 2
	
	int newpos=pos-1+ti.length;
	int newend=Long.length-Short.length+ti.length-1;
	int move=Short.length-ti.length;
	int newlength=Long.length-Short.length+ti.length;
	for(int i=newpos;i<=newend;i++)
	{
		Long.ch[i]=Long.ch[i+move];
	}
	int j=0;
	for(int i=pos-1;i<=ti.length+pos-2;i++)
	{
		Long.ch[i]=ti.ch[j];
		j++;
	}
	if(newend<Long.length)
		for(int i=newend+1;i<Long.length;i++) Long.ch[i]=' ';
//	Long.ch=(char *)malloc(newlength*sizeof(char));
	Long.length=newlength;
}
void function(HString Long,HString Short,HString ti)
{
	int pos=FindString(Long,Short,0);
	int secpos=pos+Short.length;
	HString Pre,End;
	Sub(Pre,Long,0,pos-1);
	Sub(End,Long,secpos-1,Long.length-Short.length-Pre.length);
//	cout<<End.ch;
	//cout<<Pre.length<<endl;
	//cout<<Pre.ch;
	HString ans1,ans2;
	Concat(ans1,Pre,ti);
//	cout<<ans1.length<<endl;
	Concat(ans2,ans1,End);
	cout<<ans2.ch;
//	cout<<ans2.ch;
//	cout<<Pre.ch<<endl<<ti.ch<<endl<<End.ch;
}
int main()
{
	char c1[]="hello";//China  //in 
	char c2[]="c++,hello world";
	char ch[]="hi";
	HString s1,s2,s3,s4;
	CreateString(s1,c1);
	CreateString(s2,c2);
	CreateString(s3,ch);
//	cout<<s1.length<<" "<<s2.length<<endl;
//	int pos=0;
//	pos=FindString(s2,s1,0);
//	Concat(S,s2,s1);
//	cout<<s3.ch;
//	fun(s2,s1,s3);
	function(s2,s1,s3);
	//cout<<s2.ch;
	return 0;
}
