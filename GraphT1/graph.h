#pragma once
#include<stdio.h>
#include<stdlib.h>

//-----ͼ���ڽӾ����ʾ��-----//
/*
#define INFINITY INT_MAX //��ʾ���ֵ
#define MaxN 20 //��󶥵����
typedef enum {DG,DN,AG,AN} GraphKind;//{����ͼ��������������ͼ��������}
typedef struct ArcCell {
	//�ߣ�������Ϣ�ṹ
	VRType adj;//VRType�Ƕ����ϵ���͡�����Ȩͼ��1��0,��ʾ���ڷ񣻶���Ȩͼ����ΪȨֵ����;
	InfoType* info;//�û������Ϣ��ָ��;
}ArcCell,AdjMatrix[MaxN][MaxN];
typedef struct {
	VertexType vexs[MaxN];//�洢�����һά����
	AdjMatrix arcs;//�洢�ڽӾ���Ķ�ά����
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͻ���
	GraphKind kind;//ͼ�������־
}MGraph;//ͼ�Ľṹ
*/

//-----ͼ���ڽӾ���洢��ʾ�����򻯣�-----//
#define MaxInt 32767//��ʾ����ֵ
#define MaxN 20	//��󶥵����
typedef char VertexType;//���趥�����������Ϊ�ַ���
typedef int ArcType;//����ߵ�Ȩֵ����Ϊ����
typedef struct {
	VertexType vexs[MaxN];//�洢�����һά����
	ArcType arcs[MaxN][MaxN]; //�洢�ڽӾ���Ķ�ά����
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͻ���
}MGraph;//ͼ�Ľṹ

void CreatUDN(MGraph& G);//�����ڽӾ����ʾ��������������
int LocateVex(MGraph G, VertexType v);//����Ԫ��v��G��һά�����λ��