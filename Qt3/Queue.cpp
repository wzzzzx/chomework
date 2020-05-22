#include"Total.h"
Status InitQueue(LinkQueue& Q)
{//����һ���ն���Q
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL;
	return OK;
}
Status DestoryQueue(LinkQueue& Q)
{//�ݻٶ���Q
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}
void EnQueue(LinkQueue& Q, ElemType e)
{//����Ԫ��eΪQ���µĶ�βԪ��
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}
Status DeQueue(LinkQueue& Q, ElemType& e)
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
Status QueueEmpty(LinkQueue Q) {
	//�ж϶����Ƿ�Ϊ�ն���
	if (Q.front == Q.rear)
		return TRUE;
	return FALSE;
}
Status GetHead(LinkQueue Q,ElemType &e) {
	//��e����Q�Ķ�ͷԪ��
	if (Q.front == Q.rear)
		return ERROR;
	QueuePtr p;
	p = Q.front->next;
	e = p->data;
}
Status QueueTraverse(LinkQueue Q) {
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