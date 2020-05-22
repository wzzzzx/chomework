#include"tree.h"
int main() {
	BiTree t1;
	printf("输入样例:\n");
	CreatBiTree(t1);
	printf("输出样例:\n");
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