#pragma once
//--------ͼ���ڽӱ�洢��ʾ--------//
#include<stdio.h>
#include<stdlib.h>
#define MaxN 20 //��󶥵����
typedef char VertexType;
typedef struct ArcNode {
	//�߽������Ͷ���
	int adjvex;//�ñ���ָ��Ķ����λ��
	int weight;//�û���Ȩֵ
	struct ArcNode* nextarc;//ָ����һ���ߵ�ָ��
}ArcNode;
typedef struct VNode {
	//������
	VertexType data;//������Ϣ
	ArcNode* firstarc;//ָ������ý��ı�����
}VNode, AdjList[MaxN];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͱ���
}ALGraph;
typedef struct QNode {
	//���нڵ������
	int data;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct {
	//���е�����
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


void CreatGraph(ALGraph& G);//�����ڽӱ��ʾ����������ͼ
int LocateVex(ALGraph G, char v);
int InitQueue(LinkQueue& Q);
void EnQueue(LinkQueue& Q, int e);
int DeQueue(LinkQueue& Q, int& e);
void BFS(ALGraph G, int v);
int FirstAdjVex(ALGraph G, int v);//����v�ĵ�һ���ڽӵ㡣
int NextAdjVex(ALGraph G, int v, int w);//����v�൱��w����һ���ڽӵ㡣
int QueueEmpty(LinkQueue Q);
void BFSTraverse(ALGraph G);

