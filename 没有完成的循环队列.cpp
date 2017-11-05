#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW 0
#define ERROR 0
#define MAXQSIZE 100
using namespace std;

typedef struct Data
{
	int num,data;
}Data;

typedef struct Queue
{
	Data *base; 
	int front,rear;
}Queue;

void InitQueue(Queue &Q)
{
	Q.base=(Data *)malloc(MAXQSIZE*sizeof(Data));
	Q.base=Q.front; 
}

int LengthQueue(Queue Q)
{
	return(Q.rear-Q.base+MAXQSIZE)%MAXQSIZE;
}
