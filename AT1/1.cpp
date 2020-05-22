#include"AT1.h"
int main() {
	int n,p,q;
	pLink L;
	InitList(L);
	scanf_s("%d", &n);
	CreatList(L, n);
	scanf_s("%d%d", &p, &q);
	DeleteList(L, p, q);
	ListPrint(L);
}