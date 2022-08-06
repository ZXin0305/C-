/*
* 栈的链式存储结构
* 和单链表相似，但是栈只能在栈顶压入和弹出
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
	EleType data;  //结点数据域
	struct StackNode* next; //结点指针域 
} StackNode;

//链栈的数据结构
//这个其实作用相当于头指针,到时候访问这个链栈的时候，要通过这里
typedef struct LinkStack {
	StackNode* top;  //栈顶结点
	int count; //元素个数
} LinkStack;    //这样的LinkStack 是使用 typedef 将 struct LinkStack 令称为 LinkStack，方便建立对象。而不是声明结构体对象

//初始化
Status InitLinkStack(LinkStack* stack ) {
	if (!stack)
		return ERROR;
	stack->top = NULL;
	stack->count = 0;
	return OK;
}

//压栈
//先将压入元素放入到链表表中，然后再将栈顶指向压入的元素，然后count+1
Status push(LinkStack* stack, EleType e) {
	if (!stack)
		return ERROR;

	StackNode* node;
	node = (StackNode*)malloc(sizeof(StackNode));
	node->next = stack->top;  //将元素加入链表中,链表的性质， 
	node->data = e;
	stack->top = node;  //栈顶元素指向压入元素
	stack->count++;  //长度加1
	return OK;
}

//打印链表
void PrintLinkStack(LinkStack* stack) {
	if (!stack && stack->count) {
		return;
	}

	StackNode* node = stack->top;   //找到此时栈顶指向的位置
	cout << "数据为: ";
	//while (node) {   //不为空指针
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
	stack->top = node->next;   //这两行已经把node的元素全部取出
	free(node);
	stack->count--;
	return OK;
}

void GetTop(LinkStack stack) {
	if (stack.count <= 0)
	{
		cout << "空栈.." << endl;;
	}
	else {
		StackNode* node = stack.top;
		cout << "栈顶元素为: " << node->data << endl;
	}
}

int GetLengthLinkStack(LinkStack* stack) {
	if (!stack)
		return ERROR;

	return stack->count;
}

//判断是否为空栈
Status EmptyLinkStack(LinkStack* stack) {
	if (!stack)
		return ERROR;
	return stack->count == 0 ? 1 : 0;
}

//清空数据
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

	//弹出元素
	EleType e1, e2;
	pop(&stack, &e1);
	//pop(&stack, &e2);

	GetTop(stack);
	cout << "stack的长度为: " << GetLengthLinkStack(&stack) << endl;
	cout << "是否为空栈 .." << EmptyLinkStack(&stack) << endl;
	if (ClearLinkStack)
		cout << "清栈成功.." << endl;
	system("pause");
	return 0;
}