#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW 0
#define ERROR 0
#define LENGTH 100
#define MAXSIZE 12500
using namespace std;

typedef struct
{
	int i,j;
	int e;
}Triple;

typedef struct
{
	Triple data[MAXSIZE+1];
	int mu,nu,tu;
}TSMatrix;

void InitMatrix(int m,int n,int num,TSMatrix &M)
{
	M.mu=m;
	M.nu=n;
	M.tu=num;
	for(int i=0;i<num;i++)
	{
		cin>>M.data[i].i>>M.data[i].j>>M.data[i].e;
	}
}

void InitM(int m,int n,int num,TSMatrix &M)
{
	M.mu=m;
	M.nu=n;
	M.tu=num;
	M.data[1].i=1,M.data[1].j=1,M.data[1].e=1;
	M.data[0].i=2,M.data[0].j=2,M.data[0].e=2;
}
void PrintMatrix(TSMatrix M)
{
	int len=M.tu;
	for(int i=0;i<len;i++)
	{
		cout<<M.data[i].i<<" "<<M.data[i].j<<" "<<M.data[i].e<<endl;
	}
}


bool Equel(TSMatrix m1,TSMatrix m2,int i,int j)
{
	if(m1.data[i].i==m2.data[j].i	&&	m1.data[i].j==m2.data[j].j	)
		return true;
	else return false;
}

void changeMa(TSMatrix M,int a[100][100])
{
	int num=M.tu,m=M.mu,n=M.nu;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=0;
		}
	}
	for(int i=0;i<num;i++)
	{
		a[M.data[i].i][M.data[i].j]=M.data[i].e;
	}
}

void SumMatrix(TSMatrix m1,TSMatrix m2,TSMatrix &ans)
{
//	int num=0;
//	for(int i=0;i<m1.tu;i++)
//	{
//		for(int j=0;j<m2.tu;j++)
//		{
//			if(Equel(m1,m2,i,j))
//			{
//				ans.data[num].e=m1.data[i].e+m2.data[j].e;
//				ans.data[num].i=m1.data[i].i;
//				ans.data[num].j=m1.data[i].j;
//				if(ans.data[num].e)
//				{
//					num++;
//				}
//				break;
//			}
//			else if(j==m2.tu-1)
//			{
//				ans.data[num].e=m1.data[i].e;
//				ans.data[num].i=m1.data[i].i;
//				ans.data[num].j=m1.data[i].j;
//				num++;
//			}
//		}
//	}
//	ans.mu=m1.mu,ans.nu=m1.nu,ans.tu=num;
	int a[100][100],b[100][100];
	int c[100][100];
	changeMa(m1,a);
	changeMa(m2,b);
	for(int i=1;i<=m1.mu;i++)
	{
		for(int j=1;j<=m1.nu;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	for(int i=1;i<=m1.mu;i++)
	{
		for(int j=1;j<=m1.nu;j++)
		{
			cout<<c[i][j]<<" "; 
		}
		cout<<endl;
	}
}

void PrintMa(TSMatrix M)
{
	int a[100][100];
	int num=M.tu,m=M.mu,n=M.nu;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=0;
		}
	}
	for(int i=0;i<num;i++)
	{
		a[M.data[i].i][M.data[i].j]=M.data[i].e;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int main()
{
	int a[100][100],b[100][100],c[100][100];
	TSMatrix m1,m2,m3;
	InitMatrix(3,3,2,m1);
	cout<<"矩阵1:"<<endl;
	PrintMa(m1);
//	cout<<m1.tu;
//	InitM(2,2,2,m1);
//	InitM(2,2,2,m2);
	InitMatrix(3,3,2,m2);
	cout<<"矩阵2："<<endl; 
	PrintMa(m2);
	SumMatrix(m1,m2,m3);
//	cout<<m3.data[0].e;
//	cout<<m3.tu;
//	cout<<"相加结果"<<endl;
//	PrintMatrix(m3);
//	[1,0
//	 0,2]

//	PrintMatrix(m);

	
	return 0;
}
//int main()
//{
//	TSMatrix m1;
//	int a[100][100];
//	InitMatrix(3,3,2,m1);
//	changeMa(m1,a);
//	for(int i=1;i<=m1.mu;i++)
//	{
//		for(int j=1;j<=m1.nu;j++)
//		{
//			cout<<a[i][j]<<" "; 
//		}
//		cout<<endl;
//	}
//	return 0;
//}
