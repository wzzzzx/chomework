#include"graph.h"
void CreatUDN(MGraph& G) {
	int i,j,k,w;
	char ch;
	scanf_s("%d %d", &G.vexnum, &G.arcnum);//�����ܶ��������ܱ���
	while ((ch = getchar()) != EOF && ch != '\n');//��������������ֹ���س�������һά������
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
//�����ڽӾ����ʾ��������������
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
//����Ԫ��v��G��һά�����λ��