/*
* ����ջ����ռ�
*/

#include<iostream>
using namespace std;

#define MAXSIZE 100
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int EleType;
typedef int Status;

//��ջ����ռ�
struct SeqDoubleStack {
	EleType data[MAXSIZE];  //�������Ǿ�̬�����ڴ��
	int top1;
	int top2;
};

//��ʼ��
Status initSeqDoubleStack(SeqDoubleStack* stack) {
	if (!stack)
		return ERROR;
	stack->top1 = -1;
	stack->top2 = MAXSIZE;
	return OK;
}

//ѹջ
Status push(SeqDoubleStack* stack, EleType e, int stackNum) {
	if (!stack)  //��ָ��,δ���г�ʼ��
		return ERROR;
	
	//ջû���������,����ջ�ı�ţ�push��Ӧ��ջ��Ԫ��
	//ջδ������������stack->top+1 < stack->top2
	//������������ֿ��ˣ������������д�Ļ��ǹ���˳���ķ�ʽ������ַ�������ģ�ֻ������������topָ�����ָ���������ջ
	if (stackNum == 1 && stack->top1 + 1 < stack->top2) {  //����ջ��δ����ѡ����1ջ�д��
		stack->top1++;
		stack->data[stack->top1] = e;
		return OK;
	}
	else if (stackNum == 2 && stack->top1 < stack->top2) {
		stack->top2--;
		stack->data[stack->top2] = e;
		return OK;
	}

	//ջ�����߱�Ų���
	return ERROR;
}

//��ӡ����ջ�е�Ԫ��
void showStack(SeqDoubleStack* stack) {
	cout << "ջ1�е�Ԫ��Ϊ��";
	for (int i = 0; i <= stack->top1; ++i) {
		cout << stack->data[i] << " ";
	}
	cout << endl << "ջ2�е�Ԫ��Ϊ: ";
	for (int i = stack->top2; i < MAXSIZE; ++i) {
		cout << stack->data[i] << " ";
	}
	cout << endl << "��ӡ���" << endl;
}

//��ջ
Status pop(SeqDoubleStack* stack, EleType* e, int stackNum) {
	if (!stack || !e) {
		return ERROR;
	}

	//ջ1��Ϊ�յ�����£�����ջ��ţ�pop��Ӧ��ջ��Ԫ��
	//ջ1Ϊ��:stack->top1 != -1  ; ջ2��ջ�ж�  stack->top2 != MAXSIZE
	if (stackNum == 1 && stack->top1 != -1) {
		*e = stack->data[stack->top1];
		stack->top1--;
		return OK;
	}
	else if (stackNum == 2 && stack->top2 != MAXSIZE) {
		*e = stack->data[stack->top2];
		stack->top2++;
		return OK;
	}

	return ERROR;
}

int main() {

	SeqDoubleStack stack;
	//��ʼ��
	initSeqDoubleStack(&stack);

	//ѹջ
	push(&stack, 100, 1);
	push(&stack, 20, 2);

	//��ӡԪ��
	showStack(&stack);
	EleType e;
	//��ջ
	pop(&stack, &e, 2);
	showStack(&stack);
	system("pause");
	return 0;
}