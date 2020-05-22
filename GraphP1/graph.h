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
int FirstAdjVex(ALGraph G, int v);//����v�ĵ�һ���ڽӵ㡣
int NextAdjVex(ALGraph G, int v, int w);//����v�൱��w����һ���ڽӵ㡣
void DFS(ALGraph G, int v);//�ӵ�v������������ݹ��������ȱ���ͼG��
void DFSTraverse(ALGraph G);