#pragma once
#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	int weight;
	int parent, lchild, rchild;
}HTNode,*Huffmantree;
typedef char **Huff
