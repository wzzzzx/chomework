#include"Total.h"
Status InitStack(SqStack& S)
{//构造一个空栈S
	S.base = (ElemType*)malloc(INIT_SIZE * sizeof(ElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = INIT_SIZE;
	return OK;
}

Status ClearStack(SqStack& S)
{//将S清为空栈
	if (!S.base) return ERROR;
	S.top = S.base;
	return OK;
}

Status StackEmpty(SqStack S)
{//若栈S为空栈，则返回Ture，否则返回FALSE.
	if (!S.base) return ERROR;
	if (S.top == S.base)
		return 1;
	else
		return 0;
}

Status DestroyStack(SqStack& S)
{//摧毁一个已存在的栈
	if (!S.base) return ERROR;
	free(S.base);
	S.base = S.top = NULL;
	S.stacksize = 0;
	return OK;
}

Status Push(SqStack& S, ElemType e)
{//插入元素e为新的栈顶元素
	if (S.top - S.base >= S.stacksize)
	{//栈满，追加存储空间
		ElemType* newbase;
		newbase = (ElemType*)realloc(S.base, (S.stacksize + INCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);//存储分配失败
		S.base = newbase;
		S.top = S.base + S.stacksize;
		S.stacksize += INCREMENT;
	}
	*(S.top++) = e;
	return OK;
}

Status Pop(SqStack& S, ElemType& e)
{//删除S的栈顶元素
	if (S.top == S.base) return ERROR;
	e = *(--S.top);
	return OK;
}

Status GetTop(SqStack S, ElemType& e)
{//用e返回S的栈顶元素
	if (!S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}

Status PrintStack(SqStack S)
{//遍历栈S
	ElemType* i;
	for (i = S.base; i < S.top; i++)
	{
		printf("%d %d ", i->CarNo,i->Time);
	}
	printf("\n");
	return OK;
}