#include"tree.h"
void HuffmanCoding(HuffmanTree& HT, HuffmanCode& HC, int* w, int n) {
	//w���n���ַ���Ȩֵ������շ�����HT�����n���ַ��ĺշ�������HC
	int m,i,start,c,f;
	int exchange;
	int s1, s2;
	char* cd;
	HuffmanTree p;
	if (n <= 1)
		return;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));//0�ŵ�Ԫδ��
	for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w) {//��ʼ��ǰn����Ԫ
		(*p).weight = *w;
		(*p).parent = 0;
		(*p).lchild = 0;
		(*p).rchild = 0;
	}
	for (; i <= m; ++i, ++p) {//��Ҷ��֮��Ĵ洢��Ԫ����
		(*p).parent = 0;
	}
	for (i = n + 1; i <= m; ++i) {
		//������������
		//��HT[1..i-1]ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1��s2��
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
	//-----��Ҷ�ӵ���������ÿ���ַ��ĺշ�������-----//
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));//����n���ַ������ͷָ������
	cd = (char*)malloc(n * sizeof(char));//���������Ĺ����ռ�
	cd[n - 1] = '\0';
	for (i = 1; i <= n; i++) {
		//����ַ���շ�������
		start = n - 1;//���������λ��
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
