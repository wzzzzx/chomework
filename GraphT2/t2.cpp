#include"graph.h"
int main() {
	ALGraph G;
	ArcNode* p;
	int i, j;
	printf("����������\n");
	CreatGraph(G);
	printf("���������\n");
	for (i = 0; i < G.arcnum; i++) {
		p = G.vertices[i].firstarc;
		printf("%c     ", G.vertices[i].data);
		do {
			printf("%d %d     ", p->adjvex, p->weight);
			p = p->nextarc;
		} while (p != NULL);
		printf("\n");
	}
	return 0;
}
