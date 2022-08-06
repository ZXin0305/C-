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
	q.front = 0;  // 根据底层实现，使用不同的指针类型
	q.rear = 0;
	cout << "初始化成功 .." << endl;
	return true;
}

bool PushQueue(Queue& q, int num) {
	if (q.rear == MAXSIZE+1) {
		cout << "队列已满 .." << endl;
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

// 出队
int PopQueue(Queue& q) {
	if (q.front == q.rear) {
		cout << "队列为空 .." << endl;
		return -INT32_MAX;
	}

	int num = q.data[q.front];
	// 使用数组的话，取出队首数据之后还要将数据全部往前移动一位
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