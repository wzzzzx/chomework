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

void CreatGraph(ALGraph& G);//�����ڽӱ��ʾ����������ͼ
int LocateVex(ALGraph G, char v);


