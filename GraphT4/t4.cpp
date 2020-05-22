#include"graph.h"
int visited[MaxN] = { 0 };
int main() {
	ALGraph G;
	ArcNode* p;
	printf("输入样例：\n");
	CreatGraph(G);
	printf("输出样例：\n");
	BFSTraverse(G);
	return 0;
}
void CreatGraph(ALGraph& G) {
	int i, j, w, k;
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
			continue;
	}
}
int InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL;
	return 1;
}
void EnQueue(LinkQueue& Q, int e) {
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}
int DeQueue(LinkQueue& Q, int& e) {
	QueuePtr p;
	if (Q.front == Q.rear)
		return -1;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.front = Q.rear;
	free(p);
	return 1;
}
void BFS(ALGraph G, int v) {
	LinkQueue Q;
	int u,w;
	visited[v] = 1;
	printf("%c ", G.vertices[v].data);
	InitQueue(Q);
	EnQueue(Q, v);
	while (!QueueEmpty(Q)) {
		DeQueue(Q,u);
		for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {
			if (!visited[w]) {
				visited[w] = 1;
				printf("%c ", G.vertices[w].data);
				EnQueue(Q, w);
			}
		}
	}
}
int QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear)
		return 1;
	else
		return 0;
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
void BFSTraverse(ALGraph G) {
	int v;
	for (v = 0; v < G.vexnum; v++) {
		if (!visited[v]) {
			BFS(G, v);
		}
	}
}