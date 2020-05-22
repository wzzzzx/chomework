#include"graph.h"

closedge theclose;
int main() {
	MGraph G;
	char ch,a;
	printf("输入样例：\n");
	CreatUDN(G);
	ch = getchar();
	scanf_s("%c", &a, 5);
	printf("输出样例：\n");
	MiniSpanTree_Prim(G,a);
	return 0;
}
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
void MiniSpanTree_Prim(MGraph G, char u) {
	int k, j,i;
	k = LocateVex(G, u);
	for (j = 0; j < G.vexnum; j++) {
		//辅助数组初始化
		if (j != k) {
			theclose[j].adjvex = u;
			theclose[j].lowcost = G.arcs[k][j];
		}
	}
	theclose[k].lowcost = 0;//初始，U=u
	for (i = 0; i < G.vexnum - 1; i++) {
		//选择其余G.vexnum-1个顶点
		k = minimum(G,theclose);
		printf("%c %c\n", theclose[k].adjvex, G.vexs[k]);
		theclose[k].lowcost = 0;
		//信息辅助数组中存储的信息，由于此时树中新加入了一个顶点，需要判断
		//由此顶点出发，到达其他各顶点的权值是否比之前记录的权值还要小，如果还小，则更新
		for (j = 0; j < G.vexnum; j++) {
			if (G.arcs[k][j] < theclose[j].lowcost) {
				theclose[j].adjvex = G.vexs[k];
				theclose[j].lowcost = G.arcs[k][j];
			}
		}
	}
	printf("\n");
}
int minimum(MGraph G, closedge close) {
	int min = MaxInt;
	int min_i = -1;
	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (close[i].lowcost > 0 && close[i].lowcost < min) {
			min = close[i].lowcost;
			min_i = i;
		}
	}
	return min_i;
}