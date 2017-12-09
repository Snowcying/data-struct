#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define OVERFLOW 0
#define ERROR 0
#define MAX 20

using namespace std;

typedef struct ArcBox
{
	int tailvex,headvex;
	struct ArcBox *hlink,*tlink;
//	int *info;	
}ArcBox;

typedef struct VexNode
{
	int data;
	ArcBox *firstin,*firstout;
}VexNode;

typedef struct
{
	VexNode xlist[MAX];
	int vexnum,arcnum;
}OLGraph;

void CreateDG(OLGraph &G)
{
	cin>>G.vexnum>>G.arcnum;
	for(int i=1;i<=G.vexnum;i++)
	{
		cin>>G.xlist[i].data;
		G.xlist[i].firstin=NULL;
		G.xlist[i].firstout=NULL;
	}
	for(int k=0;k<G.arcnum;k++)
	{
		int i,j;
		cin>>i>>j;
		ArcBox *p;
		p=(ArcBox *)malloc(sizeof(ArcBox));
//		*p={i,j,G.xlist[j].firstin,G.xlist[i].firstout};
		p->headvex=i;
		p->tailvex=j;
		p->hlink=G.xlist[j].firstin;
		p->tlink=G.xlist[i].firstout;
		G.xlist[j].firstin=G.xlist[i].firstout=p;
	}
	
	
}

bool visited[MAX];

VexNode VisitFunc(int v,OLGraph g)
{
	return (g.xlist[v]);
}

int FirstAdjVex(OLGraph g,int v)
{
	return v;
}
int NextAdjVex(OLGraph g,int v,int w)
{
	
	if(g.xlist[w].firstout)
	{
		int end=g.xlist[w].firstout->tailvex;
		if(!visited[end])
			return end;
		else return -1;
	}
	else return -1;
}
void DFS(OLGraph G,int v)
{
	cout<<v;
	visited[v]=true;
	VexNode v1=VisitFunc(v,G);
	for(int w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
	{
		if(!visited[w]) 
		{
			DFS(G,w);
		}
	}
}

void DFSTraverse(OLGraph G)
{
	for(int i=1;i<=G.vexnum;i++)
		visited[i]=false;
	
	for(int v=1;v<=G.vexnum;v++)
	{
		if(!visited[v])
		{
			DFS(G,v);
		}
	}
}

queue <int> Q1;

int NextAdjVexof(OLGraph g,int v,int w)
{
	
	if(g.xlist[w].firstout)
	{
		int end=g.xlist[w].firstout->tailvex;
		if(!visited[end])
			return end;
		else return -1;
	}
	else return -1;
}

void BFSTraverse(OLGraph G)
{
	for(int i=1;i<=G.vexnum;i++)
	{
		visited[i]=false;
	}
	for(int v=1;v<=G.vexnum;v++)
	{
		if(!visited[v])
		{
			visited[v]=true;
			cout<<v;
			Q1.push(v);
			while(!Q1.empty())
			{
				int u=Q1.front();
				Q1.pop();
//				for(int w=FirstAdjVex(G,u);w>=0;w=NextAdjVexof(G,u,w))
//				{
//					if(!visited[w])
//					{
//						visited[w]=true;
//						cout<<w;
//						Q1.push(w);
//					}
//				}
				ArcBox *temp=G.xlist[u].firstout;
				for(int w=FirstAdjVex(G,u);w>0;)
				{
					if(temp->tlink)
					{
						temp=temp->tlink;
						w=temp->headvex;
					}
					else
					{
						break;
						
					}
					
					if(!visited[w])
					{
						visited[w]=true;
						cout<<w;
						Q1.push(w);
					}
				}
			}
		}
	}
	
}

int main()
{
	freopen("Graph1.txt","r",stdin);
	OLGraph g1;
	CreateDG(g1);
//	cout<<g1.xlist[1].firstout->tailvex;
	DFSTraverse(g1);
	cout<<endl;
//	cout<<g1.xlist[1].firstout->tlink->tailvex; 
	BFSTraverse(g1);
//	ArcBox *temp=g1.xlist[1].firstout;
//	cout<<temp->tailvex;
//	temp=temp->tlink;
//	cout<<temp->tailvex;
	return 0;
}
