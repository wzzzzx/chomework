#include"tree.h"
int main() {
	BiTree t1;
	printf("��������:\n");
	CreatBiTree(t1);
	printf("�������:\n");
	PreOrder1(t1);
	printf(" ");
	PreOrder2(t1);
	printf(" ");
	PreOrder3(t1);
	printf("\n");
	printf("%d %d\n", leaf(t1),Depth(t1));
	Swap(t1);
	PreOrder1(t1);
	printf(" ");
	PreOrder2(t1);
	printf(" ");
	PreOrder3(t1);
	return 0;
}