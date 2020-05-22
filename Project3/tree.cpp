#include"tree.h"
void CreatTree(BiTree& T) {
	char ch;
	scanf_s("%c", &ch);
	if (ch == '*')
		T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = ch;
		CreatTree(T->lchild);
		CreatTree(T->rchild);
	}
}

void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL;
}
void EnQueue(LinkQueue& Q, BiTree e) {
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}
Status DeQueue(LinkQueue& Q, BiTree& e) {
	QueuePtr p;
	if (Q.front == Q.rear)
		return 0;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return 1;
}
Status QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear)
		return 1;
	return 0;
}

void Order(BiTree T, LinkQueue Q) {
	BiTree e;
	EnQueue(Q, T);
	while (!QueueEmpty(Q)) {
		DeQueue(Q, e);
		printf("%c", e->data);
		if (e->lchild != NULL)
			EnQueue(Q,e->lchild);
		if (e->rchild != NULL)
			EnQueue(Q, e->rchild);
	}
}