#include"Queue_Sq.h"

status InitQueue_Sq(SqQueue& Q) {
	//����һ���ն���Q
	Q.base = (QElemType*)malloc(MAXSIZE * sizeof(QElemType));
	//����һ���������ΪMAXSIZE������ռ�
	if (!Q.base) exit(OVERFLOW);//�洢����ʧ��
	Q.front = Q.rear = 0;//����Ϊ�գ�ͷָ���βָ�붼Ϊ0
	return OK;
}
status EnQueue_Sq(SqQueue& Q, QElemType e) {
	//����Ԫ��eΪQ���µĶ�βԪ��
	if ((Q.rear + 1) % MAXSIZE == Q.front)//�ж϶����Ƿ�Ϊ��
		return ERROR;
	Q.base[Q.rear] = e; //��Ԫ��e�����β
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}
status DeQueue_Sq(SqQueue& Q, QElemType e) {
	//ɾ����ͷԪ�أ���e������ֵ
	if ((Q.rear == Q.front))//�ж϶����Ƿ�Ϊ��
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;//�޸Ķ�ͷָ��
	return OK;
}
status QueueEmpty_Sq(SqQueue Q) {
	//�ж϶����Ƿ�Ϊ�ն���
	if (Q.front == Q.rear)//�Կշ���1�����򷵻�0
		return 1;
	return 0;
}
status GetHead_Sq(SqQueue Q, QElemType& e) {
	//��e���ض��׵�ֵ
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	return OK;
}
status QueueTraverse_Sq(SqQueue Q) {
	//��������
	int i;
	if (Q.front == Q.rear)
		return ERROR;
	for (i = 1;; i++) {
		printf("%d ", Q.base[Q.front]);
		Q.front = (Q.front + 1) % MAXSIZE;
		if (Q.front == Q.rear)
			return OK;
	}
}