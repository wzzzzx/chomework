#include"Queue.h"
status InitQueue(LinkQueue& Q)
{//构造一个空队列Q
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL;
	return OK;
}
status DestoryQueue(LinkQueue& Q)
{//摧毁队列Q
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}
void EnQueue(LinkQueue& Q, QElemType e)
{//插入元素e为Q的新的队尾元素
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}
status DeQueue(LinkQueue& Q, QElemType& e)
{//删除Q的对头元素，用e返回其值
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
	//判断队列是否为空队列
	if (Q.front == Q.rear)
		return TRUE;
	return FALSE;
}
status GetHead(LinkQueue Q,QElemType &e) {
	//用e返回Q的对头元素
	if (Q.front == Q.rear)
		return ERROR;
	QueuePtr p;
	p = Q.front->next;
	e = p->data;
}
status QueueTraverse(LinkQueue Q) {
	//遍历队列
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