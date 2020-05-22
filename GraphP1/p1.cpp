#include"graph.h"
int visited[MaxN] = { 0 };
int main() {
	ALGraph G;
	ArcNode* p;
	printf("输入样例：\n");
	CreatGraph(G);
	printf("输出样例：\n");
	DFSTraverse(G);
}


void CreatGraph(ALGraph& G) {
	int i, j, k, w;
	char ch;
	ArcNode* p1, * p2;
	scanf_s("%d %d", &G.vexnum, &G.arcnum);
	while ((ch = getchar()) != EOF && ch != '\n');
	for (i = 0; i < G.vexnum; i++) {
		scanf_s("%c", &G.vertices[i].data, 5);
		G.vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G.arcnum; k++) {
		char v1, v2;
		ch = getchar();
		scanf_s("%c %c %d", &v1, 5, &v2, 5, &w);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p1 = (ArcNode*)malloc(sizeof(ArcNode));
		p1->adjvex = j;
		p1->weight = w;
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;
		p2 = (ArcNode*)malloc(sizeof(ArcNode));
		p2->adjvex = i;
		p2->weight = w;
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2;
	}
}
int LocateVex(ALGraph G, char v) {
	int i;
	for (i = 0;; i++) {
		if (G.vertices[i].data == v)
			return i;
		else
		{
			continue;
		}
	}
}
int FirstAdjVex(ALGraph G, int v) {
	ArcNode* p;
	p = G.vertices[v].firstarc;
	if (p != NULL) {
		return p->adjvex;
	}
	else
		return -1;
}
int NextAdjVex(ALGraph G, int v, int w) {
	ArcNode* p;
	p = G.vertices[v].firstarc;
	while (p && p->adjvex != w) {
		p = p->nextarc;
	}
	if (!p || !p->nextarc)
		return -1;
	else
		return p->nextarc->adjvex;
}
void DFS(ALGraph G, int v) {	
	int w;
	printf("%c ", G.vertices[v].data);//访问顶点V
	visited[v] = 1;
	for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)) {
		if (!visited[w])
			DFS(G, w);
	}
}
void DFSTraverse(ALGraph G) {
	int v;
	for (v = 0; v < G.vexnum; v++) {
		if (!visited[v])
			DFS(G, v);
	}
}