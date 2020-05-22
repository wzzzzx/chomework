#pragma once
#include"stdio.h"
#include"stdlib.h"

#define OK 1
#define ERROR 0

typedef char TElemType;
typedef int Status;
typedef struct BiTNode {
	TElemType data;//结点数据
	struct BiTNode* lchild, * rchild;//左右孩子指针
}BiTNode,*BiTree;
typedef struct QNode {
	//链队列结点类型
	BiTree data;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct {
	//链队列类型
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

void InitQueue(LinkQueue& Q);//建立链队列
void EnQueue(LinkQueue& Q, BiTree e);//入队列
Status DeQueue(LinkQueue& Q, BiTree& e);//出队列
Status QueueEmpty(LinkQueue Q);
void PreOrder1(BiTree T);//先序遍历二叉树
void PreOrder2(BiTree T);//中序遍历二叉树
void PreOrder3(BiTree T);//后序遍历二叉树
void CreatBiTree(BiTree& T);//创立二叉树
Status leaf(BiTree T);//统计叶子结点的个数
Status Depth(BiTree T);//求二叉树的深度
void Swap(BiTree& T);//将二叉树中所有结点的左、右孩子进行交换
void LevalOrder(BiTree T,LinkQueue Q);//层次遍历二叉树
static int num1 = 0;