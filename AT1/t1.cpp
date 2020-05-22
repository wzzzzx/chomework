#include"AT1.h"
void InitList(pLink& L) {
	L = (pLink)malloc(sizeof(LNode));
	L->pnext = NULL;
}

void CreatList(pLink& L, int n) {
	int i;
	pLink r, p;
	InitList(L);
	r = L;
	for (i = 0; i < n; i++) {
		p = (pLink)malloc(sizeof(LNode));
		scanf_s("%d", &p->data);
		p->pnext = NULL;
		r->pnext = p;
		r = p;
	}
}

void ListPrint(pLink L) {
	pLink r;
	r = L;
	do {
		r = r->pnext;
		printf("%d ", r->data);
	} while (r->pnext != NULL);
	printf("\n");
}

void DeleteList(pLink& L, int n, int m) {
	int i;
	pLink r,p;
	r = L;
	p = L;
	for (i = 1;; i++) {
		r = r->pnext;
		if (r->data >= m)
			break;
		if (r->data > n) {
			p->pnext = r->pnext;
		}
		else {
			p = p->pnext;
		}
	}
}