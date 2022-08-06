/*
* 一些C++基本知识的测试
* 20220703
*/

//#pragma pack(push)
//#pragma pack(4)
#include<iostream>
#include<assert.h>
#include <utility>

using namespace std;


class Base {
public:
	Base() {}
	virtual void print() { cout << "Base 对象 .." << endl; }
	virtual ~Base() { cout << "父类的析构函数 .." << endl; }
};

class Child : public Base {
	friend void print_age(Child cc);
private:
	int* age = new int(10);
public:
	Child() {}
	void print() { cout << "child 对象 .." << endl; }
	~Child() { 
		cout << "子类的析构函数 .." << endl; 
		if (this->age != nullptr)
		{
			delete age;
			age = nullptr;
		}
	};    //如果在子类中使用了动态内存分配，需要在子类中写一个析构函数，用来释放内存。因为Base中没办法知道需要释放什么内存
};


void print_age(Child cc) {
	cout << "children's age is: " << cc.age << endl;
}

//联合
union UnionTest   // UnionTest 联合
{
	UnionTest() :i(10) {}
	int i;
	double d;
};

static union   // 全局静态匿名联合
{
	int i;
	double d;
};

//枚举
enum Color
{
	red, yellow, green
};

enum class Test_enum
{
	input, optput, append
};

struct MyClass
{
	std::string s;
	MyClass(const char* sz) : s(sz)
	{
		std::cout << "MyClass sz:" << sz << std::endl;
	}
	MyClass(const MyClass& o) : s(o.s)
	{
		std::cout << "copy construct!\n";
	}

	MyClass(MyClass&& o) noexcept : s(std::move(o.s))
	{
		std::cout << "move construct!\n";
	}

	MyClass& operator=(const MyClass& other) { // copy assign
		std::cout << "copy assign!\n";
		s = other.s;
		return *this;
	}
	MyClass& operator=(MyClass&& other) noexcept { // move assign
		std::cout << "move assign!\n";
		s = std::move(other.s);
		return *this;
	}

	static MyClass GetMyClassGo(const char* sz)
	{
		MyClass o(sz); // 注意：可能会被NRVO优化掉
		return o;
	}
};

void func0(MyClass o)
{
	std::cout << o.s.c_str() << std::endl;
}

void func1(MyClass& o)
{
	std::cout << o.s.c_str() << std::endl;
}

void func2(const MyClass& o)
{
	std::cout << o.s.c_str() << std::endl;
}

void func3(MyClass&& o)
{
	std::cout << o.s.c_str() << std::endl;
}

// 虚基类
class VirtualBase {
public:
	VirtualBase(){}
	virtual void print() = 0;
};

class VirtualChild: public VirtualBase{
public:
	VirtualChild(){}
	void print();
};

void VirtualChild::print() {
	cout << "纯虚函数的子类 .." << endl;
}


int main() {

	/*
	* 继承和多态
	*/
	Base b;
	b.print();
	Base* b1 = new Child();  //父类引用指向子类对象，然后子类中会覆盖父类中的虚函数
							 // 而fu类中的非静态方法（被zi类覆盖）发生了变化，
	                         // 在编译阶段看fu类的（看fu类有没有，有的话编译通过），运行的时候运行的是zi类的代码。
	b1->print();             //此时这个已经被重写了
	delete b1;   //在类外删除这个new对象的时候，会先调用子类的析构函数，再调用父类的析构函数
	//int i = 10;
	//assert(i == 9);   //断言

	cout << sizeof(b1) << endl;   //指针的内存大小


	/*
	* 联合
	*/
	// 
	//UnionTest u;
	//union 
	//{
	//	int i;
	//	double d;
	//};

	//u.d = 13.0;           // union就像一个开关一样，每个时刻只有一个状态是激活的
	//cout << u.i << endl;  // 输出 UnionTest 联合的 10
	//cout << u.d << endl;

	//::i = 20;
	//cout << ::i << endl;  // 输出全局静态匿名联合的 20

	//i = 30;
	//cout << i << endl;    // 输出局部匿名联合的 30


	/*
	* 友元函数
	*/
	//Child cc;
	//print_age(cc);

	/*
	* 枚举
	*/
	//cout << green << endl;

	//auto c = Test_enum::append;

	/*
	* 左值引用和右值引用
	*/
	//int num = 10;
	//const int& a = num;
	//const int& a = 19;  //这种是常量右值引用是可以的
	//int& b = 10;  //错误，左值引用只能够左值进行初始化
	//cout << a << endl;

	//int&& b = 10;
	//b = 100;
	//cout << b << endl;

	//MyClass a1("how");
	//MyClass a2("are");

	//a2 = a1; // copy assign  注：a1是一个左值

	//a2 = MyClass("you"); // move assign  注：MyClass("you")是一个右值

	//MyClass a3(a1); // copy construct  注：a1是一个左值
	//MyClass&& a4 = MyClass::GetMyClassGo("go"); // move construct  注：发生在MyClass::GetMyClassGo()内部
	//MyClass a5 = MyClass::GetMyClassGo("china"); // move construct两次  注：一次发生在MyClass::GetMyClassGo()内部；另一次发生在将返回值赋值给a5

	//MyClass a6("let");
	//MyClass a7("it");
	//MyClass a8("go");
	//MyClass a9("!");

	//func0(a6);  // copy construct
	//func1(a7);
	//func2(a8);
	//func3(a9); // 编译error: 不能把一个左值赋值给右值

	//func0(MyClass::GetMyClassGo("god")); // move construct两次  注：一次发生在MyClass::GetMyClassGo()内部；另一次发生在将返回值赋值给foo0参数时
	//func1(MyClass::GetMyClassGo("is")); // 编译error: 不能把一个右值赋值给左值
	//func2(MyClass::GetMyClassGo("girl")); // move construct  注：发生在MyClass::GetMyClassGo()内部
	//func3(MyClass::GetMyClassGo("!"));  // move construct  注：发生在MyClass::GetMyClassGo()内部

	/*
	* 带有纯虚函数的类叫做虚基类，不能直接实例化对象，且纯虚函数需要在子类中重写
	* 这样子类才能实例化
	*/
	//VirtualChild vc;
	//vc.print();

	/*
	* 强制类型转换运算符
	*/
	//float test_num = 9.9;
	//int test_num2 = static_cast<int>(test_num);
	//cout << test_num2 << endl;

	//Child* ch = new Child;
	//Base* ba = dynamic_cast<Base*>(ch);
	//ba->print();
	//delete ch;

	int n;
	int* pt = new int;
	const int bb = 101;
	int& rn = n;
	int& rt = *pt;
	//const int& rb = bb;
	//cout << "bb: " << bb << endl;
	//const int& rb = 10;

	int&& rb = 10;   // 右值引用
	rb = 12;
	cout << "rb: " << rb << endl;

	system("pause");
	return 0;
}