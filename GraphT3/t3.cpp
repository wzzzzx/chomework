#include"graph.h"
int visited[MaxN] = { 0 };
int main() {
	MGraph G;
	printf("输入样例：\n");
	CreatUDN(G);
	printf("输出样例：\n");
	DFS(G, 0);
	return 0;
}
void CreatUDN(MGraph& G) {
	int i, j, k, w;
	char ch;
	scanf_s("%d %d", &G.vexnum, &G.arcnum);//输入总顶点数，总边数
	while ((ch = getchar()) != EOF && ch != '\n');//清理缓冲区，防止讲回车键读入一维数组中
	for (i = 0; i < G.vexnum; i++) {
		scanf_s("%c", &G.vexs[i], 1);//依次输入顶点的信息
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
		scanf_s("%c %c %d", &v1, 5, &v2, 5, &w);//输入一条边依附的顶点及权值
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		//确定v1和v2在G中的位置
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j];
	}
}
int LocateVex(MGraph G, char v) {
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
void DFS(MGraph G, int v) {
	int i;
	visited[v] = 1;
	printf("%c ", G.vexs[v]);
	for (i = 0; i < G.vexnum; i++) {
		if (G.arcs[v][i] != MaxInt && visited[i] == 0) {
			DFS(G, i);
		}
	}
}