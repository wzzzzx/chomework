#include"AT2.h"
int main() {
	int n, i,x;
	List L1,L2,L3;
	int* p1, * p2, * p3;
	InitList(L1);
	InitList(L2);
	InitList(L3);
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &x);
		ListInsert(L1, L1.len + 1, x);
	}
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &x);
		ListInsert(L2, L2.len + 1, x);
	}
	p1 = L1.data;
	p2 = L2.data;
	p3 = L3.data;
	while (p1 <= L1.data + L1.len - 1 && p2 <= L2.data + L2.len - 1) {
		if (*p1<*p2) {
			*p3 = *p1;
			p1++;
			p3++;
		}
		if (*p1>*p2) {
			*p3 = *p2;
			p2++;
			p3++;
		}			
		if (*p1 == *p2) {
			*p3 = *p1;
			p1++;
			p3++;
		}
	}
	PrintList(L3);
}