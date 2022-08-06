/*
* ����: queue���ײ�����������ʵ�֣�, ���˶��У� �Ƚ��ȳ���ֻ�ܷ��ʶ�β���޷�����
*/
#include<iostream>
#define MAXSIZE 100
#define OK 1
#define FALSE 0
#define ERROR 0
using namespace std;

typedef int QElemType;  //����ʵ�����ͽ�������
typedef int Status;

struct SqQueue{
	QElemType data[MAXSIZE];
	int front;   //ͷָ��
	int rear;    //βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
};

typedef struct SqQueue SqQueue;

Status InitQueue(SqQueue* Q) {
	Q->front = 0;
	Q->rear = 0;
	cout << "��ʼ���ɹ�" << endl;
	return OK;
}

//���ض��еĳ���
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//ѭ������δ��ʱ�����
Status EnQueue(SqQueue* Q, QElemType e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front)  //Q->front ��һ��int ��
	{
		cout << "�������� .." << endl;
		return ERROR;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	cout << "��ӳɹ�" << endl;
	return OK;
}

//ѭ�����еĳ��Ӳ���
Status DeQueue(SqQueue* Q, QElemType* e) {
	if (Q->front == Q->rear) {  //����Ϊ��
		cout << "����Ϊ��" << endl;
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
	cout<<"���г���Ϊ��"<< QueueLength(Q) << endl;
	DeQueue(&Q, &e);
	cout << "���г���Ϊ��" << QueueLength(Q) << endl;
	system("pause");
	return 0;
}