/*
* ջ����ʽ�洢�ṹ
* �͵��������ƣ�����ջֻ����ջ��ѹ��͵���
*/
#include<iostream>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int EleType;

using namespace std;

typedef struct StackNode {
	EleType data;  //���������
	struct StackNode* next; //���ָ���� 
} StackNode;

//��ջ�����ݽṹ
//�����ʵ�����൱��ͷָ��,��ʱ����������ջ��ʱ��Ҫͨ������
typedef struct LinkStack {
	StackNode* top;  //ջ�����
	int count; //Ԫ�ظ���
} LinkStack;    //������LinkStack ��ʹ�� typedef �� struct LinkStack ���Ϊ LinkStack�����㽨�����󡣶����������ṹ�����

//��ʼ��
Status InitLinkStack(LinkStack* stack ) {
	if (!stack)
		return ERROR;
	stack->top = NULL;
	stack->count = 0;
	return OK;
}

//ѹջ
//�Ƚ�ѹ��Ԫ�ط��뵽������У�Ȼ���ٽ�ջ��ָ��ѹ���Ԫ�أ�Ȼ��count+1
Status push(LinkStack* stack, EleType e) {
	if (!stack)
		return ERROR;

	StackNode* node;
	node = (StackNode*)malloc(sizeof(StackNode));
	node->next = stack->top;  //��Ԫ�ؼ���������,��������ʣ� 
	node->data = e;
	stack->top = node;  //ջ��Ԫ��ָ��ѹ��Ԫ��
	stack->count++;  //���ȼ�1
	return OK;
}

//��ӡ����
void PrintLinkStack(LinkStack* stack) {
	if (!stack && stack->count) {
		return;
	}

	StackNode* node = stack->top;   //�ҵ���ʱջ��ָ���λ��
	cout << "����Ϊ: ";
	//while (node) {   //��Ϊ��ָ��
	//	cout << node->data << " ";
	//	node = node->next;
	//}
	for (int i = 0; i < stack->count; ++i) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
	return;
}

Status pop(LinkStack* stack, EleType* e) {
	if (!stack && stack->count)
		return ERROR;
	StackNode* node = stack->top;

	*e = node->data;
	stack->top = node->next;   //�������Ѿ���node��Ԫ��ȫ��ȡ��
	free(node);
	stack->count--;
	return OK;
}

void GetTop(LinkStack stack) {
	if (stack.count <= 0)
	{
		cout << "��ջ.." << endl;;
	}
	else {
		StackNode* node = stack.top;
		cout << "ջ��Ԫ��Ϊ: " << node->data << endl;
	}
}

int GetLengthLinkStack(LinkStack* stack) {
	if (!stack)
		return ERROR;

	return stack->count;
}

//�ж��Ƿ�Ϊ��ջ
Status EmptyLinkStack(LinkStack* stack) {
	if (!stack)
		return ERROR;
	return stack->count == 0 ? 1 : 0;
}

//�������
Status ClearLinkStack(LinkStack* stack) {
	if (!stack || stack->count) {
		return ERROR;
	}

	while (stack->count) {
		StackNode* node = stack->top;
		stack->top = node->next;
		free(node);
		stack->count--;
	}
	return OK;
}


int main() {
	LinkStack stack;
	InitLinkStack(&stack);

	push(&stack, 100);
	push(&stack, 200);
	PrintLinkStack(&stack);

	//����Ԫ��
	EleType e1, e2;
	pop(&stack, &e1);
	//pop(&stack, &e2);

	GetTop(stack);
	cout << "stack�ĳ���Ϊ: " << GetLengthLinkStack(&stack) << endl;
	cout << "�Ƿ�Ϊ��ջ .." << EmptyLinkStack(&stack) << endl;
	if (ClearLinkStack)
		cout << "��ջ�ɹ�.." << endl;
	system("pause");
	return 0;
}