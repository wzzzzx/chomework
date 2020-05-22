#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MaxN 20
typedef char VertexType;
typedef struct ArcNode {
	int adjvex;
	int weight;
	struct ArcNode* nextarc;
}ArcNode;
typedef struct VNode {
	VertexType data;
	ArcNode* firstarc;
}VNode,AdjList[MaxN];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;
void CreatGraph(ALGraph& G);
int LocateVex(ALGraph G, char v);
int FirstAdjVex(ALGraph G, int v);//返回v的第一个邻接点。
int NextAdjVex(ALGraph G, int v, int w);//返回v相当于w的下一个邻接点。
void DFS(ALGraph G, int v);//从第v个顶点出发，递归地深度优先遍历图G。
void DFSTraverse(ALGraph G);