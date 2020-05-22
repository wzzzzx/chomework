#include<stdio.h>
#include<stdlib.h>
#define initsize 20
#define LISTINCREMENT 3
#define OVERFLOW -2
#define ERROR 0
typedef int ElemType;
typedef struct
{
	int* data;
	int len;
	int listsize;
}Sqlist;

void InitList(Sqlist& L);
void ListInsert(Sqlist& L, int i, ElemType e);
void PrintList(Sqlist L);
void MergeList(Sqlist La, Sqlist Lb, Sqlist& Lc);
