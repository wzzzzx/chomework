#pragma once
#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int QElemType;
typedef int status;

typedef struct QNode {
	//链队列结点的类型
	QElemType data;
	struct QNode* next;
} QNode, * QueuePtr;

typedef struct {
	//链队列的类型
	QueuePtr front;//对头指针，指向链表的头节点
	QueuePtr rear;//队尾指针，指向队尾节点
}LinkQueue;

status InitQueue(LinkQueue &Q);
status DestoryQueue(LinkQueue &Q);
void EnQueue(LinkQueue& Q, QElemType e);
status DeQueue(LinkQueue& Q, QElemType& e);
status QueueEmpty(LinkQueue Q);
status GetHead(LinkQueue Q, QElemType& e);
status QueueTraverse(LinkQueue Q);