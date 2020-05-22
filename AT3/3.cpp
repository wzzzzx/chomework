#include"AT3.h"
void main()
{
	int i, n, m, x;
	Sqlist La, Lb, Lc;
	InitList(La);
	InitList(Lb);
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &x);
		ListInsert(La, La.len + 1, x);
	}
	scanf_s("%d", &m);
	for (i = 1; i <= m; i++)
	{
		scanf_s("%d", &x);
		ListInsert(Lb, Lb.len + 1, x);
	}
	MergeList(La, Lb, Lc);
	PrintList(Lc);
}
