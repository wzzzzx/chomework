#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 2 //��ͣ����������ͣ����
#define M 10//�򳵳��ڶԶ��ͣ����
typedef struct {
	int CarNO[N];//���ƺ�
	int CarTime[N];//����ʱ��
	int top;//ջָ��
}SqStack; //����˳��ջ���ͣ���������ͣ����
typedef struct {
	int CarNo[M];//���ƺ�
	int *front, *rear;//���׺Ͷ�βָ��
}SqQueue;//����ѭ���������ͣ����������򳵳�
//����Ϊ˳��ջ�Ļ��������㷨
void InitStack(SqStack& S) {
	S = (SqStack*)malloc(sizeof(SqStack));
	S->t
}
