#include"Total.h"

int main() {
	char ch,key;
	int num1 = 0, num2 = 0,i,t;
	ElemType e,q;
	SqStack Station, Stemp;
	LinkQueue Wait;
	InitStack(Station);//��ʼ��ͣ����
	InitStack(Stemp);//��ʼ����·����ʱջ
	InitQueue(Wait);//��ʼ�����
	while (1) {
		printf(" A.The Car Arrive D.The Car Leave E.Exit System\n");
		scanf_s("%c", &ch);
		switch (ch)
		{
		case 'A':scanf_s("%d%d", &e.CarNo, &e.Time);
			if (num1 < N) {
				Push(Station, e);
				num1++;
				printf("Parking Location:%d\n", num1);
			}
			else {
				EnQueue(Wait, e);
				num2++;
				printf("Sidewalk Location:%d\n", num2);
			}
			while ((key = getchar()) != EOF && key != '\n') {//�������
				;
			}
			break;//��������
		case 'D':scanf_s("%d%d",&e.CarNo,&e.Time);//�����뿪
			ElemType* b;
			b = Station.base;
			for (i = 0; i <= num1 && b->CarNo!=e.CarNo; i++,b++);
			if (i > num1) {
				DeQueue(Wait, q);
			}
			else {
				ElemType* h;
				h = Station.top;
				while ((--h)->CarNo != e.CarNo) {
					Pop(Station, q);
					Push(Stemp, q);
				}
				Pop(Station, q);
				num1--;
				t = (e.Time - q.Time);
				printf("Time:%d Parking fees:%d\n", t, t);
				while (!StackEmpty(Stemp)) {
					Pop(Stemp, q);
					Push(Station, q);
				}
				if (!QueueEmpty(Wait)) {
					DeQueue(Wait, q);
					q.Time = e.Time;
					Push(Station, q);
					num1++;
				}
			}
			while ((key = getchar()) != EOF && key != '\n') {//�������
				;
			}
			break;
		case 'E':return 0;//�˳�������
		default:
			break;
		}
	}
	PrintStack(Station);
	return 0;
}

