#include"graph.h"

closedge theclose;
int main() {
	MGraph G;
	char ch,a;
	printf("����������\n");
	CreatUDN(G);
	ch = getchar();
	scanf_s("%c", &a, 5);
	printf("���������\n");
	MiniSpanTree_Prim(G,a);
	return 0;
}
void CreatUDN(MGraph& G) {
	int i,j,k,w;
	char ch;
	scanf_s("%d %d", &G.vexnum, &G.arcnum);//�����ܶ��������ܱ���
	while ((ch = getchar()) != EOF && ch != '\n');//������������ֹ���س�������һά������
	for (i = 0; i < G.vexnum; i++) {
		scanf_s("%c", &G.vexs[i],1);//�������붥�����Ϣ
	}
	for (i = 0; i < G.arcnum; i++) {
		//��ʼ���ڽӾ��󣬱ߵ�Ȯ�о���Ϊ���ֵMaxInt
		for (j = 0; j < G.arcnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	for (k = 0; k < G.arcnum; k++) {
		char v1, v2;
		ch = getchar();
		scanf_s("%c %c %d",&v1,5,&v2,5,&w);//����һ���������Ķ��㼰Ȩֵ
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		//ȷ��v1��v2��G�е�λ��
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
		//���������ʼ��
		if (j != k) {
			theclose[j].adjvex = u;
			theclose[j].lowcost = G.arcs[k][j];
		}
	}
	theclose[k].lowcost = 0;//��ʼ��U=u
	for (i = 0; i < G.vexnum - 1; i++) {
		//ѡ������G.vexnum-1������
		k = minimum(G,theclose);
		printf("%c %c\n", theclose[k].adjvex, G.vexs[k]);
		theclose[k].lowcost = 0;
		//��Ϣ���������д洢����Ϣ�����ڴ�ʱ�����¼�����һ�����㣬��Ҫ�ж�
		//�ɴ˶�����������������������Ȩֵ�Ƿ��֮ǰ��¼��Ȩֵ��ҪС�������С�������
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