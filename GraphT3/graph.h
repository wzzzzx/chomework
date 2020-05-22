#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MaxN 20
#define MaxInt 32767
typedef struct {
	char vexs[MaxN];
	int arcs[MaxN][MaxN];
	int vexnum, arcnum;
}MGraph;
void CreatUDN(MGraph& G);
int LocateVex(MGraph G, char v);
void DFS(MGraph G, int v);