#include"graph.h"
int main() {
	MGraph G;
	int i, j;
	printf("����������\n");
	CreatUDN(G);
	printf("���������\n");
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.arcnum; j++) {
			if(G.arcs[i][j]==32767)
				printf("�� ");
			else
				printf("%2d ", G.arcs[i][j]);
		}
		printf("\n");
	}
	return 0;
}