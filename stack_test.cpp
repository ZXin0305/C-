#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

// 仿函数
class FunctionMode {
public:
	FunctionMode(){}
	bool operator()(int& val1, int& val2) {  //这个也是运算符重载
		return val1 > val2;
	}
};

//运算符重载中，如果要能够连续运算，应当在重载的运算符中返回运算后的类对象
class Test {
private:
	int _num;
public:
	Test(){}
	Test(int num) :_num(num) {}
	Test operator+(const Test& t) const {  // 这里不使用引用也是可以的，但是速度慢，需要先生成一个副本
		Test t_tmp;
		t_tmp._num = this->_num + t._num;
		return t_tmp;   // 不能够返回t_tmp的指针，因为他是一个局部变量，会被销毁，然后返回的指针就变成了野指针
	}
	int getNum() { return this->_num; }
};


// 函数模板，Function f是一个函数指针，指向这个函数
template<typename Function>
void compare(int val1, int val2, Function f) {
	if (f(val1, val2))
		cout << val1 << " 大于 " << val2 << endl;
	else
		cout << val1 << " 小于 " << val2 << endl;
}

int main() {

	// stack容器适配器的模板有两个参数：1.存储对象的类型 2.底层容器的类型
   /*	top()：返回一个栈顶元素的引用，类型为 T& 。如果栈为空，返回值未定义。
		push(const T & obj)：可以将对象副本压入栈顶。这是通过调用底层容器的 push_back() 函数完成的。
		push(T && obj)：以移动对象的方式将对象压入栈顶。这是通过调用底层容器的有右值引用参数的 push_back() 函数完成的。
		pop()：弹出栈顶元素。
		size()：返回栈中元素的个数。
		empty()：在栈中没有元素的情况下返回 true。
		emplace()：用传入的参数调用构造函数，在栈顶生成对象。
		swap(stack<T> & other_stack)：将当前栈中的元素和参数中的元素交换。参数所包含元素的类型必须和当前栈的相同。对于 stack 对象有一个特例化的全局函数 swap() 可以使用。
	*/
	// 定义一个用存放字符串对象的stack容器
	//stack<string> words;

	//words.push("zx1");
	//words.push("zx2");
	//words.emplace("zx3");

	//words.pop();
	//words.pop();
	//words.pop();
	//cout << words.size() << endl;

	//char c1 = '[';
	//char c2 = ']';
	//string s1;
	//s1 = c1;
	//string s2;
	//s2 = c2;
	//
	//cout << s1+s2<< endl;

	//string s = "hello";

	//reverse(s.begin(), s.end());

	//cout << s << endl;
	//string ss = "12";
	//int xx = atoi(ss.c_str());
	//cout << xx << endl;

	FunctionMode f;
	int val1 = 12, val2 = 13;
	cout << f(val1, val2) << endl;  // 运算符重载
	compare(12, 13, f);  // 这个是仿函数的使用，创建一个虚拟对象之后，会调用这个对象中的operator()()
	compare(12, 13, [](int val1, int val2) {return val1 > val2; });  //这个是lambda函数

	Test t1(12), t2(13), t3(14);

	Test t4 = t1 + t2 + t3;  // 重载运算符，若进行连续操作，需要在重载运算中返回生成的对象
	cout << t4.getNum() << endl;

	system("pause");
	return 0;
}