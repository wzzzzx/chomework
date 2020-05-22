#pragma once
#include<stdio.h>
#include<stdlib.h>

//-----图的邻接矩阵表示法-----//
/*
#define INFINITY INT_MAX //表示最大值
#define MaxN 20 //最大顶点个数
typedef enum {DG,DN,AG,AN} GraphKind;//{有向图，有向网，无向图，无向网}
typedef struct ArcCell {
	//边（弧）信息结构
	VRType adj;//VRType是顶点关系类型。对无权图用1和0,表示相邻否；对有权图，则为权值类型;
	InfoType* info;//该弧相关信息的指针;
}ArcCell,AdjMatrix[MaxN][MaxN];
typedef struct {
	VertexType vexs[MaxN];//存储顶点的一维数组
	AdjMatrix arcs;//存储邻接矩阵的二维数组
	int vexnum, arcnum;//图的当前顶点数和弧数
	GraphKind kind;//图的种类标志
}MGraph;//图的结构
*/

//-----图的邻接矩阵存储表示法（简化）-----//
#define MaxInt 32767//表示极大值
#define MaxN 20	//最大顶点个数
typedef char VertexType;//假设顶点的数据类型为字符型
typedef int ArcType;//假设边的权值类型为整形
typedef struct {
	VertexType vexs[MaxN];//存储顶点的一维数组
	ArcType arcs[MaxN][MaxN]; //存储邻接矩阵的二维数组
	int vexnum, arcnum;//图的当前顶点数和弧数
}MGraph;//图的结构

void CreatUDN(MGraph& G);//采用邻接矩阵表示法，构造无向网
int LocateVex(MGraph G, VertexType v);//返回元素v在G中一维数组的位置