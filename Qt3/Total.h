#pragma once
#include<stdio.h>
#include<stdlib.h>

#define Price 2//��λʱ��ͣ���ķ���
#define N 2 //���ͣ����
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
	//�����н�������
	ElemType data;
	struct QNode* next;
} QNode, * QueuePtr;

typedef struct {
	//�����е�����
	QueuePtr front;//��ͷָ�룬ָ�������ͷ�ڵ�
	QueuePtr rear;//��βָ�룬ָ���β�ڵ�
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
