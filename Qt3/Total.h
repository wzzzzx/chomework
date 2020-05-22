#pragma once
#include<stdio.h>
#include<stdlib.h>

#define Price 2//单位时间停车的费用
#define N 2 //最大停车数
#define INIT_SIZE 10
#define INCREMENT 10
#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef struct {
	int CarNo;
	int Time;
}ElemType;
typedef int Status;

typedef struct {
	ElemType* base;
	ElemType* top;
	int stacksize;
}SqStack;

typedef struct QNode {
	//链队列结点的类型
	ElemType data;
	struct QNode* next;
} QNode, * QueuePtr;

typedef struct {
	//链队列的类型
	QueuePtr front;//对头指针，指向链表的头节点
	QueuePtr rear;//队尾指针，指向队尾节点
}LinkQueue;

Status InitStack(SqStack& S);
Status ClearStack(SqStack& S);
Status StackEmpty(SqStack S);
Status DestroyStack(SqStack& S);
Status Push(SqStack& S,ElemType e);
Status Pop(SqStack& S,ElemType &e);
Status PrintStack(SqStack S);

Status InitQueue(LinkQueue& Q);
Status DestoryQueue(LinkQueue& Q);
void EnQueue(LinkQueue& Q, ElemType e);
Status DeQueue(LinkQueue& Q, ElemType& e);
Status QueueEmpty(LinkQueue Q);
Status GetHead(LinkQueue Q, ElemType& e);
Status QueueTraverse(LinkQueue Q);
