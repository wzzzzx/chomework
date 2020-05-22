#pragma once
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100 //最大队列长度
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int QElemType;
typedef int status;
typedef struct {
	QElemType* base;//动态分配存储空间
	int front;//头指针，指示队列头元素的位置
	int rear;//尾指针，指示队列尾元素的下一位置
}SqQueue;

status InitQueue_Sq(SqQueue& Q);
status EnQueue_Sq(SqQueue& Q, QElemType e);
status DeQueue_Sq(SqQueue& Q, QElemType e);
status QueueEmpty_Sq(SqQueue Q);
status GetHead_Sq(SqQueue Q, QElemType& e);
status QueueTraverse_Sq(SqQueue Q);