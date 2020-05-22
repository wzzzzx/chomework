#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* pnext;
}LNode,*pLink;

void InitList(pLink& L);
void CreatList(pLink& L,int n);
void ListPrint(pLink L);
void DeleteList(pLink& L,int n,int m);