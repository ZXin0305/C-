#include<iostream>

using namespace std;

const int MAXSIZE = 100;

struct Queue
{
	int data[MAXSIZE];
	int front;
	int rear;
	int q_size = 0;
};

bool InitQueue(Queue& q) {
	q.front = 0;  // ���ݵײ�ʵ�֣�ʹ�ò�ͬ��ָ������
	q.rear = 0;
	cout << "��ʼ���ɹ� .." << endl;
	return true;
}

bool PushQueue(Queue& q, int num) {
	if (q.rear == MAXSIZE+1) {
		cout << "�������� .." << endl;
		return false;
	}

	q.data[q.rear] = num;
	q.rear++;
	q.q_size++;
	return true;
}

int GetQueueSize(Queue& q) {
	return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}

// ����
int PopQueue(Queue& q) {
	if (q.front == q.rear) {
		cout << "����Ϊ�� .." << endl;
		return -INT32_MAX;
	}

	int num = q.data[q.front];
	// ʹ������Ļ���ȡ����������֮��Ҫ������ȫ����ǰ�ƶ�һλ
	for (int i = 0; i < q.q_size; ++i) {
		if (i + 1 == q.q_size) {
			q.data[i] = 0;
			break;
		}
		q.data[i] = q.data[i + 1];
	}
	//for (auto x : q.data)
	//	cout << x << " ";
	//cout << endl;
	q.q_size--;
	q.rear--;
	return num;

}

int main(int argc, char** argv) {

	Queue q;
	InitQueue(q);

	for (int num = 0; num < 100; ++num) {
		if (!PushQueue(q, num)) {
			break;
		}
	}

	//int size = GetQueueSize(q);
	//cout << q.data[99] << endl;

	int num = PopQueue(q);
	cout << num << endl;

	int num_2 = PopQueue(q);
	cout << num_2 << endl;
	cout << q.q_size << endl;

	system("pause");
	return 0;
}