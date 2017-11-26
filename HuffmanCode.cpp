#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define OVERFLOW 0
#define ERROR 0
#define LENGTH 100

using namespace std;

typedef struct
{
	unsigned int weight;
	unsigned int paren,lchild,rchild;
}HTNode,*HuffmanTree;

void HuffmamCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
