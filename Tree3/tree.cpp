#include"tree.h"
void HuffmanCoding(HuffmanTree& HT, HuffmanCode& HC, int* w, int n) {
	//w存放n个字符的权值，构造赫夫曼树HT并求出n个字符的赫夫曼编码HC
	int m,i,start,c,f;
	int exchange;
	int s1, s2;
	char* cd;
	HuffmanTree p;
	if (n <= 1)
		return;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));//0号单元未用
	for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w) {//初始化前n个单元
		(*p).weight = *w;
		(*p).parent = 0;
		(*p).lchild = 0;
		(*p).rchild = 0;
	}
	for (; i <= m; ++i, ++p) {//对叶子之后的存储单元清零
		(*p).parent = 0;
	}
	for (i = n + 1; i <= m; ++i) {
		//构建霍夫曼树
		//在HT[1..i-1]选择parent为0且weight最小的两个结点，其序号分别为s1，s2。
		Select(HT, i - 1, s1, s2);
		if (s1 > s2) {
			exchange = s1;
			s1 = s2;
			s2 = exchange;
		}
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	//-----从叶子到根逆向求每个字符的赫夫曼编码-----//
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));//分配n个字符编码的头指针向量
	cd = (char*)malloc(n * sizeof(char));//分配求编码的工作空间
	cd[n - 1] = '\0';
	for (i = 1; i <= n; i++) {
		//逐个字符求赫夫曼编码
		start = n - 1;//编码结束符位置
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent) {
			if (HT[f].lchild == c) cd[--start] = '0';
			else cd[--start] = '1';
		}
		HC[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(HC[i], &cd[start]); 
	}
	free(cd);
}

void Select(HuffmanTree HT, int n, int& s1, int& s2){
	int i,w1=0,w2=0;
	s1 = 0;
	s2 = 0;
	for (i = 1; i <= n; i++) {
		if (HT[i].parent == 0) {
			if (s1 == 0) {
				s1 = i;
				w1 = HT[i].weight;
				continue;
			}
			if (s2 == 0) {
				s2 = i;
				w2 = HT[i].weight;
				continue;
			}
			if (w1 > w2 && w1 > HT[i].weight) {
				w1 = HT[i].weight;
				s1 = i;
				continue;
			}
			if (w2 > w1 && w2 > HT[i].weight) {
				w2 = HT[i].weight;
				s2 = i;
				continue;
			}
		}
	}
}
