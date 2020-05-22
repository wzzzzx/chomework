#pragma once
#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode,*HuffmanTree;//��̬��������洢�շ�����
typedef char** HuffmanCode;//��̬��������洢�շ��������

void HuffmanCoding(HuffmanTree& HT, HuffmanCode& HC, int* w, int n);
void Select(HuffmanTree HT, int n, int& s1, int& s2);