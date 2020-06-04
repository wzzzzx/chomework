#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int KeyType;
typedef struct {
	KeyType Key;//关键字（为方便，非关键字假设不存在）
	int m;//其他域
}SElemType;
typedef struct {
	SElemType* elem;//数据元素存储空间基址，建表时按实际长度分配，0号单元留空
	int length;//表的长度
}SSTable;

int Search_Seq(SSTable ST, KeyType key);
int Search_Bin(SSTable ST, KeyType key,int &h);
void CreatList(SSTable& ST);
void InitList(SSTable& ST,int n);