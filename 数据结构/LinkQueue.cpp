/*
* ������
*/

#include<iostream>
#define MAXSIZE 100
#define OK 1
#define FALSE 0
#define ERROR 0
using namespace std;

typedef int QElemType;  //����ʵ�����ͽ�������
typedef int Status;

//���������
//�����ʵ���ǽ��̶���data[MAXSIZE]����չ�����������ʽ
typedef struct QNode {  //���ṹ
	QElemType data;
	struct QNode* next;
} QNode;

//���е�Ԫ��, ��Ҫ���ƿض��е�ͷβԪ��
typedef struct {
	QNode* front;
	QNode* rear;   //��������ʵ��ָ��Ŷ
} LinkQueue;

Status InitLinkQueue(LinkQueue* Q) {
	if (!Q)
		return ERROR;
	Q->rear = Q->front = (QNode*)malloc(sizeof(QNode));  //��ʼ����ʱ��ʹ�ö�ͷ��βͬʱָ����ͬ

	cout << "��ʼ���ɹ�" << endl;
	return OK;
}

//����Ԫ��
Status EnQueue(LinkQueue* Q, QElemType e) {
	QNode* s = (QNode*)malloc(sizeof(QNode));
	if (!s)
		return ERROR;
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	cout << "����ɹ�" << endl;
	return OK;

}
//����
Status DeQueue(LinkQueue* Q, QElemType* e) {
	QNode* p;
	if (Q->front == Q->rear)
		return ERROR;
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;

	if (Q->rear == p) {  //����ͷ�Ƕ�β����ɾ����rearָ��ͷ���
		Q->rear = Q->front;
	}
	free(p);
	cout << "���ӳɹ�" << endl;
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