/*
* 两个栈共享空间
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

//两栈共享空间
struct SeqDoubleStack {
	EleType data[MAXSIZE];  //用数组是静态分配内存的
	int top1;
	int top2;
};

//初始化
Status initSeqDoubleStack(SeqDoubleStack* stack) {
	if (!stack)
		return ERROR;
	stack->top1 = -1;
	stack->top2 = MAXSIZE;
	return OK;
}

//压栈
Status push(SeqDoubleStack* stack, EleType e, int stackNum) {
	if (!stack)  //空指针,未进行初始化
		return ERROR;
	
	//栈没有满的情况,根据栈的编号，push相应的栈的元素
	//栈未满的条件都是stack->top+1 < stack->top2
	//理解上是两个分开了，但是这个里面写的还是关于顺序表的方式，即地址是连续的，只不过是有两个top指针来分隔成了两个栈
	if (stackNum == 1 && stack->top1 + 1 < stack->top2) {  //两个栈都未满，选择往1栈中存放
		stack->top1++;
		stack->data[stack->top1] = e;
		return OK;
	}
	else if (stackNum == 2 && stack->top1 < stack->top2) {
		stack->top2--;
		stack->data[stack->top2] = e;
		return OK;
	}

	//栈满或者编号不对
	return ERROR;
}

//打印两个栈中的元素
void showStack(SeqDoubleStack* stack) {
	cout << "栈1中的元素为：";
	for (int i = 0; i <= stack->top1; ++i) {
		cout << stack->data[i] << " ";
	}
	cout << endl << "栈2中的元素为: ";
	for (int i = stack->top2; i < MAXSIZE; ++i) {
		cout << stack->data[i] << " ";
	}
	cout << endl << "打印完毕" << endl;
}

//弹栈
Status pop(SeqDoubleStack* stack, EleType* e, int stackNum) {
	if (!stack || !e) {
		return ERROR;
	}

	//栈1不为空的情况下，根据栈编号，pop相应的栈的元素
	//栈1为空:stack->top1 != -1  ; 栈2空栈判断  stack->top2 != MAXSIZE
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
	//初始化
	initSeqDoubleStack(&stack);

	//压栈
	push(&stack, 100, 1);
	push(&stack, 20, 2);

	//打印元素
	showStack(&stack);
	EleType e;
	//弹栈
	pop(&stack, &e, 2);
	showStack(&stack);
	system("pause");
	return 0;
}