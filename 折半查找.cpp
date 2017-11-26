#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
	int num[100];
	int length;
}SSTable;

int main()
{
	freopen("Search_Bin.txt","r",stdin);
	SSTable s1;
	void Search_Bin(SSTable ST,int key,int low,int high);
	cin>>s1.length;
	for(int i=1;i<=s1.length;i++)	cin>>s1.num[i];
	sort(s1.num+1,s1.num+10);
	int key,low,high;
	cin>>key>>low>>high; 
	Search_Bin(s1,key,low,high);
	return 0;
}

void Search_Bin(SSTable ST,int key,int low,int high)
{
	if(low>high)
	{
		cout<<"not find the key";
	}
	else
	{
		int mid=(low+high)/2;
		if(ST.num[mid]==key)	cout<<"find already:"<<key;
		else if(ST.num[mid]>key)	Search_Bin(ST,key,low,mid-1);
		else	Search_Bin(ST,key,mid+1,high);
	}
}

