/*
* 链队列
*/

#include<iostream>
#define MAXSIZE 100
#define OK 1
#define FALSE 0
#define ERROR 0
using namespace std;

typedef int QElemType;  //根据实际类型进行设置
typedef int Status;

//链表的主体
//这个其实就是将固定的data[MAXSIZE]给扩展成了链表的形式
typedef struct QNode {  //结点结构
	QElemType data;
	struct QNode* next;
} QNode;

//队列的元素, 主要是掌控队列的头尾元素
typedef struct {
	QNode* front;
	QNode* rear;   //这两个其实是指针哦
} LinkQueue;

Status InitLinkQueue(LinkQueue* Q) {
	if (!Q)
		return ERROR;
	Q->rear = Q->front = (QNode*)malloc(sizeof(QNode));  //初始化的时候使得队头队尾同时指向相同

	cout << "初始化成功" << endl;
	return OK;
}

//插入元素
Status EnQueue(LinkQueue* Q, QElemType e) {
	QNode* s = (QNode*)malloc(sizeof(QNode));
	if (!s)
		return ERROR;
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	cout << "插入成功" << endl;
	return OK;

}
//出队
Status DeQueue(LinkQueue* Q, QElemType* e) {
	QNode* p;
	if (Q->front == Q->rear)
		return ERROR;
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;

	if (Q->rear == p) {  //若队头是队尾，则删除后将rear指向头结点
		Q->rear = Q->front;
	}
	free(p);
	cout << "出队成功" << endl;
	return OK;
}


int main() {
	LinkQueue Q;
	QElemType e;
	InitLinkQueue(&Q);
	EnQueue(&Q, 10);
	EnQueue(&Q, 12);
	DeQueue(&Q, &e);
	system("pause");
	return 0;
}