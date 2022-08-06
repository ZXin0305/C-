#include<iostream>

using namespace std;


class Test {
private:
	int num;
public:
	Test() {
		cout << "���캯�� .." << endl;
	}
	Test(int num) :num(num) {
		cout << "�вι��� .." << endl;
	}

	Test(const Test& t) {
		this->num = t.num;
		cout << "�������� .." << endl;
	}

	Test& operator=(const Test& t) {
		if (this == &t) return *this;  // ��ֹ�Լ������Լ�
		cout << "��ֵ����� .." << endl;
		this->num = t.num;
		return *this;
	}

	void show_num() {
		cout << this->num << endl;
	}

	virtual ~Test(){}
};

int main() {

	Test t1(10);
	Test t2(t1);  // �����Ĭ�ϵĿ�������
	t2.show_num();
	Test t3;
	t3 = t2;
	t3.show_num();

	system("pause");
	return 0;
}