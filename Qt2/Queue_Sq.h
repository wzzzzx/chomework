#pragma once
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100 //�����г���
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int QElemType;
typedef int status;
typedef struct {
	QElemType* base;//��̬����洢�ռ�
	int front;//ͷָ�룬ָʾ����ͷԪ�ص�λ��
	int rear;//βָ�룬ָʾ����βԪ�ص���һλ��
}SqQueue;

status InitQueue_Sq(SqQueue& Q);
status EnQueue_Sq(SqQueue& Q, QElemType e);
status DeQueue_Sq(SqQueue& Q, QElemType e);
status QueueEmpty_Sq(SqQueue Q);
status GetHead_Sq(SqQueue Q, QElemType& e);
status QueueTraverse_Sq(SqQueue Q);