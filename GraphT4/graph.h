#pragma once
//--------图的邻接表存储表示--------//
#include<stdio.h>
#include<stdlib.h>
#define MaxN 20 //最大顶点个数
typedef char VertexType;
typedef struct ArcNode {
	//边结点的类型定义
	int adjvex;//该边所指向的顶点的位置
	int weight;//该弧的权值
	struct ArcNode* nextarc;//指向下一条边的指针
}ArcNode;
typedef struct VNode {
	//顶点结点
	VertexType data;//顶点信息
	ArcNode* firstarc;//指向关联该结点的边链表
}VNode, AdjList[MaxN];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;//图的当前顶点数和边数
}ALGraph;
typedef struct QNode {
	//队列节点的类型
	int data;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct {
	//队列的类型
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


void CreatGraph(ALGraph& G);//采用邻接表表示法创建无向图
int LocateVex(ALGraph G, char v);
int InitQueue(LinkQueue& Q);
void EnQueue(LinkQueue& Q, int e);
int DeQueue(LinkQueue& Q, int& e);
void BFS(ALGraph G, int v);
int FirstAdjVex(ALGraph G, int v);//返回v的第一个邻接点。
int NextAdjVex(ALGraph G, int v, int w);//返回v相当于w的下一个邻接点。
int QueueEmpty(LinkQueue Q);
void BFSTraverse(ALGraph G);

