#pragma once
#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define Error 0

typedef char TElemType;
typedef int Status;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
typedef struct QNode {
	BiTree data;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

void InitQueue(LinkQueue& Q);
void EnQueue(LinkQueue& Q, BiTree e);//入队列
Status DeQueue(LinkQueue& Q, BiTree& e);//出队列
Status QueueEmpty(LinkQueue Q);
void CreatTree(BiTree& T);
void Order(BiTree T,LinkQueue Q);