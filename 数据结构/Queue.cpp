/*
* 队列: queue（底层可以用数组等实现）, 单端队列， 先进先出，只能访问队尾但无法处理
*/
#include<iostream>
#define MAXSIZE 100
#define OK 1
#define FALSE 0
#define ERROR 0
using namespace std;

typedef int QElemType;  //根据实际类型进行设置
typedef int Status;

struct SqQueue{
	QElemType data[MAXSIZE];
	int front;   //头指针
	int rear;    //尾指针，若队列不空，指向队列尾元素的下一个位置
};

typedef struct SqQueue SqQueue;

Status InitQueue(SqQueue* Q) {
	Q->front = 0;
	Q->rear = 0;
	cout << "初始化成功" << endl;
	return OK;
}

//返回队列的长度
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//循环队列未满时，入队
Status EnQueue(SqQueue* Q, QElemType e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front)  //Q->front 是一个int 数
	{
		cout << "队列已满 .." << endl;
		return ERROR;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	cout << "入队成功" << endl;
	return OK;
}

//循环队列的出队操作
Status DeQueue(SqQueue* Q, QElemType* e) {
	if (Q->front == Q->rear) {  //队列为空
		cout << "队列为空" << endl;
		return ERROR;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}

int main() {
	QElemType e;
	SqQueue Q;
	InitQueue(&Q);
	EnQueue(&Q, 10);
	cout<<"队列长度为："<< QueueLength(Q) << endl;
	DeQueue(&Q, &e);
	cout << "队列长度为：" << QueueLength(Q) << endl;
	system("pause");
	return 0;
}