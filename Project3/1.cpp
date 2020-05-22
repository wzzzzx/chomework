#include"tree.h"

int main() {
	BiTree T;
	LinkQueue Q;
	InitQueue(Q);
	CreatTree(T);
	Order(T,Q);
	return 0;
}