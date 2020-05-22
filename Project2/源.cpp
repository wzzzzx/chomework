#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 2 //该停车场内最多的停车数
#define M 10//候车场内对多的停车数
typedef struct {
	int CarNO[N];//车牌号
	int CarTime[N];//进场时间
	int top;//栈指针
}SqStack; //定义顺序栈类型，用于描述停车场
typedef struct {
	int CarNo[M];//车牌号
	int *front, *rear;//队首和队尾指针
}SqQueue;//定义循环队列类型，用于描述候车场
//以下为顺序栈的基本运算算法
void InitStack(SqStack& S) {
	S = (SqStack*)malloc(sizeof(SqStack));
	S->t
}
