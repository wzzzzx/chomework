#include"graph.h"
void CreatGraph(ALGraph& G) {
	int i,j,w,k;
	char ch;
	ArcNode* p1, * p2;
	scanf_s("%d %d", &G.vexnum, &G.arcnum);
	while ((ch = getchar()) != EOF && ch!= '\n');
	for (i = 0; i < G.vexnum; i++) {
		scanf_s("%c", &G.vertices[i].data,5);
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
			continue;
	}
}


