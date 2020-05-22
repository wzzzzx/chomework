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
	//�����н�������
	QElemType data;
	struct QNode* next;
} QNode, * QueuePtr;

typedef struct {
	//�����е�����
	QueuePtr front;//��ͷָ�룬ָ�������ͷ�ڵ�
	QueuePtr rear;//��βָ�룬ָ���β�ڵ�
}LinkQueue;

status InitQueue(LinkQueue &Q);
status DestoryQueue(LinkQueue &Q);
void EnQueue(LinkQueue& Q, QElemType e);
status DeQueue(LinkQueue& Q, QElemType& e);
status QueueEmpty(LinkQueue Q);
status GetHead(LinkQueue Q, QElemType& e);
status QueueTraverse(LinkQueue Q);