#include"tree.h"
void PreOrder1(BiTree T) {
	//先序遍历二叉树的递归算法
	if (T) {
		printf("%c", T->data);
		PreOrder1(T->lchild);
		PreOrder1(T->rchild);
	}
}
void PreOrder2(BiTree T) {
	//中序遍历二叉树的递归算法
	if (T) {
		PreOrder2(T->lchild);
		printf("%c", T->data);
		PreOrder2(T->rchild);
	}
}
void PreOrder3(BiTree T) {
	//后序遍历二叉树的递归算法
	if (T) {
		PreOrder3(T->lchild);
		PreOrder3(T->rchild);
		printf("%c", T->data);
	}
}

void CreatBiTree(BiTree& T) {
	char ch;
	scanf_s("%c", &ch);
	if (ch == '*')
		T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = ch;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);
	}
}

Status leaf(BiTree T) {
	if (T) {
		if (T->lchild == NULL && T->rchild == NULL) {
			num1++;
		}
		leaf(T->lchild);
		leaf(T->rchild);
	}
	return num1;
}

Status Depth(BiTree T){
	if (T == NULL)
		return 0;
	else {
		int nLeft = Depth(T->lchild);
		int nRight = Depth(T->rchild);
		return (nLeft > nRight ? nLeft + 1 : nRight + 1);
	}
}
void Swap(BiTree& T) {
	BiTNode* q;
	if (T) {
		q = T->lchild;
		T->lchild = T->rchild;
		T->rchild = q;
		Swap(T->lchild);
		Swap(T->rchild);
	}
}

void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL;
}

void EnQueue(LinkQueue& Q, BiTree e) {
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}

Status DeQueue(LinkQueue& Q, BiTree& e) {
	QueuePtr p;
	if (Q.front == Q.rear)
		return 0;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return 1;
}
Status QueueEmpty(LinkQueue Q) {
	//判断队列是否为空队列
	if (Q.front == Q.rear)
		return 1;
	return 0;
}
void LevalOrder(BiTree T,LinkQueue Q) {
	BiTree e;
	EnQueue(Q, T);
	while (!QueueEmpty(Q)) {
		DeQueue(Q, e);
		printf("%c", e->data);
		if (e->lchild != NULL)
			EnQueue(Q, e->lchild);
		if (e->rchild != NULL)
			EnQueue(Q, e->rchild);
	}
}
