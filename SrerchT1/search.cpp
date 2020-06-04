#include"search.h"

int Search_Seq(SSTable ST, KeyType key) {
	//��˳���ST��˳�������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0
	int i;
	ST.elem[0].Key = key; //�ڱ�
	i = ST.length;
	while (ST.elem[i].Key != key)
		i--;//�Ӻ���ǰ��
	return i;//�Ҳ���ʱ��i=0
}

int Search_Bin(SSTable ST, KeyType key,int &h) {
	//���۰뷨����
	//���ҵ�������Ԫ���ڱ��е�λ�ã����򣬷���0
	int low, high, middle;
	low = 1;
	high = ST.length;
	while (low < high) {
		middle = (high + low) / 2;
		h++;
		if (key == ST.elem[middle].Key)
			return middle;//�ҵ�����Ԫ��
		else if (key < ST.elem[middle].Key)
			high = middle - 1;
		else
			low = middle + 1;
	}
	return 0;//˳������޴���Ԫ��
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