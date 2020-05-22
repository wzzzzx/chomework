#include"graph.h"
void CreatUDN(MGraph& G) {
	int i,j,k,w;
	char ch;
	scanf_s("%d %d", &G.vexnum, &G.arcnum);//输入总顶点数，总边数
	while ((ch = getchar()) != EOF && ch != '\n');//清理缓冲区，防止讲回车键读入一维数组中
	for (i = 0; i < G.vexnum; i++) {
		scanf_s("%c", &G.vexs[i],1);//依次输入顶点的信息
	}
	for (i = 0; i < G.arcnum; i++) {
		//初始化邻接矩阵，边的犬中均置为最大值MaxInt
		for (j = 0; j < G.arcnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	for (k = 0; k < G.arcnum; k++) {
		char v1, v2;
		ch = getchar();
		scanf_s("%c %c %d",&v1,5,&v2,5,&w);//输入一条边依附的顶点及权值
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		//确定v1和v2在G中的位置
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j];
	}
}
//采用邻接矩阵表示法，构造无向网
int LocateVex(MGraph G, VertexType v) {
	int i;
	for (i = 0;; i++) {
		if (G.vexs[i] == v) {
			return i;
		}
		else
		{
			continue;
		}
	}
}
//返回元素v在G中一维数组的位置