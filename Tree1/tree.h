#pragma once
#include"stdio.h"
#include"stdlib.h"

#define OK 1
#define ERROR 0

typedef char TElemType;
typedef int Status;
typedef struct BiTNode {
	TElemType data;//�������
	struct BiTNode* lchild, * rchild;//���Һ���ָ��
}BiTNode,*BiTree;

void PreOrder1(BiTree T);//�������������
void PreOrder2(BiTree T);//�������������
void PreOrder3(BiTree T);//�������������
void CreatBiTree(BiTree& T);//����������
Status leaf(BiTree T);//ͳ��Ҷ�ӽ��ĸ���
Status Depth(BiTree T);//������������
void Swap(BiTree& T);//�������������н������Һ��ӽ��н���
static int num1 = 0;