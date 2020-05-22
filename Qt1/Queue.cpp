#include"Queue.h"
status InitQueue(LinkQueue& Q)
{//����һ���ն���Q
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL;
	return OK;
}
status DestoryQueue(LinkQueue& Q)
{//�ݻٶ���Q
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}
void EnQueue(LinkQueue& Q, QElemType e)
{//����Ԫ��eΪQ���µĶ�βԪ��
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}
status DeQueue(LinkQueue& Q, QElemType& e)
{//ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}
status QueueEmpty(LinkQueue Q) {
	//�ж϶����Ƿ�Ϊ�ն���
	if (Q.front == Q.rear)
		return TRUE;
	return FALSE;
}
status GetHead(LinkQueue Q,QElemType &e) {
	//��e����Q�Ķ�ͷԪ��
	if (Q.front == Q.rear)
		return ERROR;
	QueuePtr p;
	p = Q.front->next;
	e = p->data;
}
status QueueTraverse(LinkQueue Q) {
	//��������
	QueuePtr p;
	int i;
	p = Q.front->next;
	for (i = 1;; i++) {
		if (p == Q.rear) {
			printf("%d ", p->data);
			return 0;
		}
		printf("%d ", p->data);
		p = p->next;
	}
}