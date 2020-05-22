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

void PreOrder1(BiTree T);//先序遍历二叉树
void PreOrder2(BiTree T);//中序遍历二叉树
void PreOrder3(BiTree T);//后序遍历二叉树
void CreatBiTree(BiTree& T);//创立二叉树
Status leaf(BiTree T);//统计叶子结点的个数
Status Depth(BiTree T);//求二叉树的深度
void Swap(BiTree& T);//将二叉树中所有结点的左、右孩子进行交换
static int num1 = 0;