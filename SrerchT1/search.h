#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int KeyType;
typedef struct {
	KeyType Key;//�ؼ��֣�Ϊ���㣬�ǹؼ��ּ��費���ڣ�
	int m;//������
}SElemType;
typedef struct {
	SElemType* elem;//����Ԫ�ش洢�ռ��ַ������ʱ��ʵ�ʳ��ȷ��䣬0�ŵ�Ԫ����
	int length;//��ĳ���
}SSTable;

int Search_Seq(SSTable ST, KeyType key);
int Search_Bin(SSTable ST, KeyType key,int &h);
void CreatList(SSTable& ST);
void InitList(SSTable& ST,int n);