/*
* ����ָ�룺shared_ptr �ܹ����C++����Աδ��ʱ�ͷ��ڴ�ռ䵼�µ��ڴ�й©����
* ʵ�ֺ����Ǹı����е����ü���ֵ
*/

#include<iostream>
using namespace std;

template <typename T>
class myshared_ptr {
public:
	myshared_ptr(T* value) {   // �вι���
		ptr = value;
		count = new int(1);    // ��ʼ��һ�����ô���
	} 
	myshared_ptr(const myshared_ptr& m) {   // ���ƹ���
		ptr = m.ptr;
		count = m.count;
		(*count)++;           // ��ʱʹ��������ƹ��죬�Ὣ�����count��1
	}
	myshared_ptr& operator=(const myshared_ptr& m) {   // ���������ʱҲ��ʹ��count����
		if (this != &m) {   // ��ֹ���Լ���������
			ptr = m.ptr;
			count = m.count;
			(*count)++;
		}
		return *this;
	}
	// ��������
	~myshared_ptr() {
		(*count)--;
		cout << "��������ִ�� .." << endl;
		if (*(this->count) == 0) {
			delete ptr;
			delete count;
			cout << "�����ͷ��ڴ�ռ� .." << endl;
		}
	}

public:
	T* ptr;     //��¼ԭʼָ��
	int* count; // ��¼���ô���
};

void test_myshared_ptr() {
	myshared_ptr<int> res(new int(1));   // �вι���
	cout << *(res.count) << endl;

	myshared_ptr<int> res2(res);         // ���ƹ���
	cout << *(res.count) << endl;

	myshared_ptr<int> res3 = res;
	cout << *(res.count) << endl;
	cout << *(res2.count) << endl;
	cout << *(res3.count) << endl;

	// shou dong shi fang nei cun
	res.~myshared_ptr();
	res2.~myshared_ptr();
	res3.~myshared_ptr();
}

int main() {

	test_myshared_ptr();

	system("pause");
	return 0;
}