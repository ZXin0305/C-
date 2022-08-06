#include<iostream>

using namespace std;


class Test {
private:
	int num;
public:
	Test() {
		cout << "构造函数 .." << endl;
	}
	Test(int num) :num(num) {
		cout << "有参构造 .." << endl;
	}

	Test(const Test& t) {
		this->num = t.num;
		cout << "拷贝构造 .." << endl;
	}

	Test& operator=(const Test& t) {
		if (this == &t) return *this;  // 防止自己构造自己
		cout << "赋值运算符 .." << endl;
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
	Test t2(t1);  // 会调用默认的拷贝构造
	t2.show_num();
	Test t3;
	t3 = t2;
	t3.show_num();

	system("pause");
	return 0;
}