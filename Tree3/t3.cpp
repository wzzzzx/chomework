#include"tree.h"

int main() {
	int n,i;
	int w[10] = { 0 };
	HuffmanCode HC;
	HuffmanTree HT;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		scanf_s("%d", &w[i]);
	}
	HuffmanCoding(HT, HC, w, n);
	for (i = 1; i <= n; i++) {
		printf("%s\n", HC[i]);
	}
	return 0;
}
