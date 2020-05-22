#include"Queue_Sq.h"

status InitQueue_Sq(SqQueue& Q) {
	//构造一个空队列Q
	Q.base = (QElemType*)malloc(MAXSIZE * sizeof(QElemType));
	//分配一个最大容量为MAXSIZE的数组空间
	if (!Q.base) exit(OVERFLOW);//存储分配失败
	Q.front = Q.rear = 0;//队列为空，头指针和尾指针都为0
	return OK;
}
status EnQueue_Sq(SqQueue& Q, QElemType e) {
	//插入元素e为Q的新的队尾元素
	if ((Q.rear + 1) % MAXSIZE == Q.front)//判断队列是否为满
		return ERROR;
	Q.base[Q.rear] = e; //将元素e插入队尾
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}
status DeQueue_Sq(SqQueue& Q, QElemType e) {
	//删除对头元素，用e返回其值
	if ((Q.rear == Q.front))//判断队列是否为空
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;//修改对头指针
	return OK;
}
status QueueEmpty_Sq(SqQueue Q) {
	//判断队列是否为空队列
	if (Q.front == Q.rear)//对空返回1，否则返回0
		return 1;
	return 0;
}
status GetHead_Sq(SqQueue Q, QElemType& e) {
	//用e返回队首的值
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	return OK;
}
status QueueTraverse_Sq(SqQueue Q) {
	//便利队列
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