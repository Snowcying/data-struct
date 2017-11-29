#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct
{
	int num[100];
	int length;
}SqList;

void CreateSqList(SqList &L)
{
	cin>>L.length;
	for(int i=1;i<=L.length;i++)
	{
		cin>>L.num[i];
	}
}

void PrintSqList(SqList &L)
{
	for(int i=1;i<=L.length;i++)
	{
		cout<<L.num[i]<<" ";
	}
	cout<<endl;
}

void InsertSort(SqList &L)
{
	int i,j;
	for(i=2;i<=L.length;i++)
	{
		if(L.num[i]<L.num[i-1])
		{
			L.num[0]=L.num[i];
			L.num[i]=L.num[i-1];
			for(j=i-2;L.num[0]<L.num[j];--j)
			{
				L.num[j+1]=L.num[j];
			}
			L.num[j+1]=L.num[0];
		}
		
	}
}

void BInsertSort(SqList &L)
{
	int i;
	for(i=2;i<=L.length;i++)
	{
		L.num[0]=L.num[i];
		int low=1,high=i-1;
		while(low<=high)
		{
			int m=(low+high)/2;
			if(L.num[0]<L.num[m])	high=m-1;
			else	low=m+1;
		}
		for(int j=i-1;j>=high+1;--j)	L.num[j+1]=L.num[j];
		L.num[high+1]=L.num[0];
	}
}

int  Partition(SqList &L,int low,int high)
{
	L.num[0]=L.num[low];
	int key=L.num[low];
	while(low<high)
	{
		while(low<high&&L.num[high]>=key)	--high;
		L.num[low]=L.num[high];
		while(low<high&&L.num[low]<=key)	++low;
		L.num[high]=L.num[low];
	}
	L.num[low]=L.num[0];
	return low;
}
void QSort(SqList &L,int low,int high)
{
	if(low<high)
	{
		int key=Partition(L,low,high);
		QSort(L,low,key-1);
		QSort(L,key+1,high);
	}
}

int SelectMinKey(SqList &L,int i)
{
	int min=99999;
	int num=999;
	for(i=i;i<=L.length;i++)
	{
		if(L.num[i]<min)
		{
			min=L.num[i];
			num=i;
		}
	}
	return num;
}
void SelectSort(SqList &L)
{
	for(int i=1;i<L.length;i++)
	{
		int j=SelectMinKey(L,i);
		if(i!=j)
		{
			int temp;
			temp=L.num[i];
			L.num[i]=L.num[j];
			L.num[j]=temp;
		}
	}
}

void HeapAdjust(SqList &H,int s,int m)
{
	int rc=H.num[s];
	for(int j=2*s;j<=m;j*=2)
	{
		if(j<m&&H.num[j]<H.num[j+1])	++j;
		if(!(rc<H.num[j]))	break;
		H.num[s]=H.num[j];
		s=j;
	}
	H.num[s]=rc;
}
void HeapSort(SqList &H)
{
	for(int i=H.length/2;i>0;--i)
		HeapAdjust(H,i,H.length);
	for(int i=H.length;i>1;--i)
	{
		int temp=H.num[1];
		H.num[1]=H.num[i];
		H.num[i]=temp;
		HeapAdjust(H,1,i-1);
	}
	
}

int main()
{
	
	freopen("sort.txt","r",stdin);
	SqList l;
	CreateSqList(l);
	
	PrintSqList(l);
	
	
//	InsertSort(l);
//	BInsertSort(l);
//	QSort(l,1,10);
//	SelectSort(l);
	HeapSort(l);
	
	PrintSqList(l);
	return 0;
}
