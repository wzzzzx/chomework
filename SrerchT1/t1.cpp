#include"search.h"

int main() {
	SSTable s;
	int key,d;
	int n,m;
	int h = 0;
	scanf_s("%d", &d);
	InitList(s, d);
	CreatList(s);
	scanf_s("%d", &key);
	n = Search_Seq(s, key);
	m = Search_Bin(s, key,h);
	if (n)
		printf("Find %d\n", d - n + 1);
	else
		printf("NotFind %d\n", d + 1);
	if (m)
		printf("Find %d\n", h);
	else
		printf("NotFind %d\n", h+1);
	return 0;
}