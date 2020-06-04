#include"search.h"

int Search_Seq(SSTable ST, KeyType key) {
	//在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为该元素在表中的位置，否则为0
	int i;
	ST.elem[0].Key = key; //哨兵
	i = ST.length;
	while (ST.elem[i].Key != key)
		i--;//从后往前找
	return i;//找不到时，i=0
}

int Search_Bin(SSTable ST, KeyType key,int &h) {
	//用折半法查找
	//若找到，返回元素在表中的位置；否则，返回0
	int low, high, middle;
	low = 1;
	high = ST.length;
	while (low < high) {
		middle = (high + low) / 2;
		h++;
		if (key == ST.elem[middle].Key)
			return middle;//找到待查元素
		else if (key < ST.elem[middle].Key)
			high = middle - 1;
		else
			low = middle + 1;
	}
	return 0;//顺序表中无待测元素
}
void InitList(SSTable& ST,int n) {
	ST.elem = (SElemType*)malloc(n*sizeof(SElemType));
	ST.length = n;
}
void CreatList(SSTable& ST) {
	int i;
	char ch;
	for (i = 1; i <= ST.length; i++) {
		ch = getchar();
		scanf_s("%d %d", &ST.elem[i].Key, &ST.elem[i].m);
	}
}