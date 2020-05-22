#include"graph.h"
int main() {
	MGraph G;
	int i, j;
	printf("输入样例：\n");
	CreatUDN(G);
	printf("输出样例：\n");
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.arcnum; j++) {
			if(G.arcs[i][j]==32767)
				printf("∞ ");
			else
				printf("%2d ", G.arcs[i][j]);
		}
		printf("\n");
	}
	return 0;
}