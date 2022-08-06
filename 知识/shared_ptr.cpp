/*
* 智能指针：shared_ptr 能够解决C++程序员未及时释放内存空间导致的内存泄漏问题
* 实现核心是改变其中的引用计数值
*/

#include<iostream>
using namespace std;

template <typename T>
class myshared_ptr {
public:
	myshared_ptr(T* value) {   // 有参构造
		ptr = value;
		count = new int(1);    // 初始化一个引用次数
	} 
	myshared_ptr(const myshared_ptr& m) {   // 复制构造
		ptr = m.ptr;
		count = m.count;
		(*count)++;           // 此时使用这个复制构造，会将共享的count加1
	}
	myshared_ptr& operator=(const myshared_ptr& m) {   // 运算符重载时也会使得count增加
		if (this != &m) {   // 防止将自己传进来了
			ptr = m.ptr;
			count = m.count;
			(*count)++;
		}
		return *this;
	}
	// 析构函数
	~myshared_ptr() {
		(*count)--;
		cout << "析构函数执行 .." << endl;
		if (*(this->count) == 0) {
			delete ptr;
			delete count;
			cout << "最终释放内存空间 .." << endl;
		}
	}

public:
	T* ptr;     //记录原始指针
	int* count; // 记录引用次数
};

void test_myshared_ptr() {
	myshared_ptr<int> res(new int(1));   // 有参构造
	cout << *(res.count) << endl;

	myshared_ptr<int> res2(res);         // 复制构造
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