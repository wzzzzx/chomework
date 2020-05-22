#include"AT2.h"

void InitList(List& L) {
	L.data = (int*)malloc(initsize * sizeof(int));
	if (!L.data)
		exit(-2);
	L.len = 0;
	L.listsize = initsize;
}

void ListInsert(List& L, int i, int e) {
	int* newbase, * q, * p;
	if (i<1 || i>L.len + 1)
	{
		return;
	}
	if (L.len >= L.listsize)
	{
		newbase = (int*)realloc(L.data, (L.listsize + 10) * sizeof(int));
		L.data = newbase;
		L.listsize = L.listsize + 10;
	}
	q = &(L.data[i - 1]);
	for (p = &(L.data[L.len - 1]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	L.len++;
}
void PrintList(List L) {
	int i;
	for (i = 0; i < L.len; i++)
	{
		printf("%d ", L.data[i]);
	}
}