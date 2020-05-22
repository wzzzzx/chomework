#include"AT3.h"

void MergeList(Sqlist La, Sqlist Lb, Sqlist& Lc)
{
	int* pa = La.data;
	int* pb = Lb.data;
	Lc.len = La.len + Lb.len;
	Lc.listsize = Lc.len;
	Lc.data = (int*)malloc(Lc.listsize * sizeof(int));
	int* pc = Lc.data;
	if (!Lc.data)
		exit(OVERFLOW);
	int* pa_last = La.data + La.len - 1;
	int* pb_last = Lb.data + Lb.len - 1;
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb)
		{
			*pc++ = *pa++;
		}
		else {
			*pc++ = *pb++;
		}
	}
	while (pa <= pa_last) {
		*pc++ = *pa++;
	}
	while (pb <= pb_last) {
		*pc++ = *pb++;
	}
}
void InitList(Sqlist& L)
{
	L.data = (int*)malloc((initsize) * sizeof(int));
	if (!L.data) exit(OVERFLOW);
	L.len = 0;
	L.listsize = initsize;
}

void ListInsert(Sqlist& L, int i, ElemType e)
{
	int* newbase, * q, * p;
	if (i<1 || i>L.len + 1)
	{
		printf("Insertion Location Error"); return;
	}
	if (L.len >= L.listsize)
	{
		newbase = (int*)realloc(L.data, (L.listsize + LISTINCREMENT) * sizeof(int));
		if (!newbase) exit(OVERFLOW);
		L.data = newbase;
		L.listsize = L.listsize + LISTINCREMENT;
	}
	q = &(L.data[i - 1]);
	p = &(L.data[L.len - 1]);
	for (; p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	L.len++;
}
void PrintList(Sqlist L)
{
	int i;
	for (i = 0; i < L.len; i++)
	{
		if (i == L.len - 1) printf("%d\n", L.data[i]);
		else printf("%d ", L.data[i]);
	}
}