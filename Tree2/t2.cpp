#include"tree.h"
int main() {
	BiTree t;
	LinkQueue Q;
	InitQueue(Q);
	CreatBiTree(t);
	LevalOrder(t, Q);
	return 0;
}