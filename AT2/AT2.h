#pragma once
#include<stdio.h>
#include<stdlib.h>

#define initsize 20
typedef struct {
	int* data;
	int len;
	int listsize;
}List;

void InitList(List& L);
void ListInsert(List& L, int i, int e);
void PrintList(List L);