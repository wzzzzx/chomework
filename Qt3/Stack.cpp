#include"Total.h"
Status InitStack(SqStack& S)
{//����һ����ջS
	S.base = (ElemType*)malloc(INIT_SIZE * sizeof(ElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = INIT_SIZE;
	return OK;
}

Status ClearStack(SqStack& S)
{//��S��Ϊ��ջ
	if (!S.base) return ERROR;
	S.top = S.base;
	return OK;
}

Status StackEmpty(SqStack S)
{//��ջSΪ��ջ���򷵻�Ture�����򷵻�FALSE.
	if (!S.base) return ERROR;
	if (S.top == S.base)
		return 1;
	else
		return 0;
}

Status DestroyStack(SqStack& S)
{//�ݻ�һ���Ѵ��ڵ�ջ
	if (!S.base) return ERROR;
	free(S.base);
	S.base = S.top = NULL;
	S.stacksize = 0;
	return OK;
}

Status Push(SqStack& S, ElemType e)
{//����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S.top - S.base >= S.stacksize)
	{//ջ����׷�Ӵ洢�ռ�
		ElemType* newbase;
		newbase = (ElemType*)realloc(S.base, (S.stacksize + INCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);//�洢����ʧ��
		S.base = newbase;
		S.top = S.base + S.stacksize;
		S.stacksize += INCREMENT;
	}
	*(S.top++) = e;
	return OK;
}

Status Pop(SqStack& S, ElemType& e)
{//ɾ��S��ջ��Ԫ��
	if (S.top == S.base) return ERROR;
	e = *(--S.top);
	return OK;
}

Status GetTop(SqStack S, ElemType& e)
{//��e����S��ջ��Ԫ��
	if (!S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}

Status PrintStack(SqStack S)
{//����ջS
	ElemType* i;
	for (i = S.base; i < S.top; i++)
	{
		printf("%d %d ", i->CarNo,i->Time);
	}
	printf("\n");
	return OK;
}