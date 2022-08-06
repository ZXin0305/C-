/*
* һЩC++����֪ʶ�Ĳ���
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
	virtual void print() { cout << "Base ���� .." << endl; }
	virtual ~Base() { cout << "������������� .." << endl; }
};

class Child : public Base {
	friend void print_age(Child cc);
private:
	int* age = new int(10);
public:
	Child() {}
	void print() { cout << "child ���� .." << endl; }
	~Child() { 
		cout << "������������� .." << endl; 
		if (this->age != nullptr)
		{
			delete age;
			age = nullptr;
		}
	};    //�����������ʹ���˶�̬�ڴ���䣬��Ҫ��������дһ�����������������ͷ��ڴ档��ΪBase��û�취֪����Ҫ�ͷ�ʲô�ڴ�
};


void print_age(Child cc) {
	cout << "children's age is: " << cc.age << endl;
}

//����
union UnionTest   // UnionTest ����
{
	UnionTest() :i(10) {}
	int i;
	double d;
};

static union   // ȫ�־�̬��������
{
	int i;
	double d;
};

//ö��
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
		MyClass o(sz); // ע�⣺���ܻᱻNRVO�Ż���
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

// �����
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
	cout << "���麯�������� .." << endl;
}


int main() {

	/*
	* �̳кͶ�̬
	*/
	Base b;
	b.print();
	Base* b1 = new Child();  //��������ָ���������Ȼ�������лḲ�Ǹ����е��麯��
							 // ��fu���еķǾ�̬��������zi�า�ǣ������˱仯��
	                         // �ڱ���׶ο�fu��ģ���fu����û�У��еĻ�����ͨ���������е�ʱ�����е���zi��Ĵ��롣
	b1->print();             //��ʱ����Ѿ�����д��
	delete b1;   //������ɾ�����new�����ʱ�򣬻��ȵ�������������������ٵ��ø������������
	//int i = 10;
	//assert(i == 9);   //����

	cout << sizeof(b1) << endl;   //ָ����ڴ��С


	/*
	* ����
	*/
	// 
	//UnionTest u;
	//union 
	//{
	//	int i;
	//	double d;
	//};

	//u.d = 13.0;           // union����һ������һ����ÿ��ʱ��ֻ��һ��״̬�Ǽ����
	//cout << u.i << endl;  // ��� UnionTest ���ϵ� 10
	//cout << u.d << endl;

	//::i = 20;
	//cout << ::i << endl;  // ���ȫ�־�̬�������ϵ� 20

	//i = 30;
	//cout << i << endl;    // ����ֲ��������ϵ� 30


	/*
	* ��Ԫ����
	*/
	//Child cc;
	//print_age(cc);

	/*
	* ö��
	*/
	//cout << green << endl;

	//auto c = Test_enum::append;

	/*
	* ��ֵ���ú���ֵ����
	*/
	//int num = 10;
	//const int& a = num;
	//const int& a = 19;  //�����ǳ�����ֵ�����ǿ��Ե�
	//int& b = 10;  //������ֵ����ֻ�ܹ���ֵ���г�ʼ��
	//cout << a << endl;

	//int&& b = 10;
	//b = 100;
	//cout << b << endl;

	//MyClass a1("how");
	//MyClass a2("are");

	//a2 = a1; // copy assign  ע��a1��һ����ֵ

	//a2 = MyClass("you"); // move assign  ע��MyClass("you")��һ����ֵ

	//MyClass a3(a1); // copy construct  ע��a1��һ����ֵ
	//MyClass&& a4 = MyClass::GetMyClassGo("go"); // move construct  ע��������MyClass::GetMyClassGo()�ڲ�
	//MyClass a5 = MyClass::GetMyClassGo("china"); // move construct����  ע��һ�η�����MyClass::GetMyClassGo()�ڲ�����һ�η����ڽ�����ֵ��ֵ��a5

	//MyClass a6("let");
	//MyClass a7("it");
	//MyClass a8("go");
	//MyClass a9("!");

	//func0(a6);  // copy construct
	//func1(a7);
	//func2(a8);
	//func3(a9); // ����error: ���ܰ�һ����ֵ��ֵ����ֵ

	//func0(MyClass::GetMyClassGo("god")); // move construct����  ע��һ�η�����MyClass::GetMyClassGo()�ڲ�����һ�η����ڽ�����ֵ��ֵ��foo0����ʱ
	//func1(MyClass::GetMyClassGo("is")); // ����error: ���ܰ�һ����ֵ��ֵ����ֵ
	//func2(MyClass::GetMyClassGo("girl")); // move construct  ע��������MyClass::GetMyClassGo()�ڲ�
	//func3(MyClass::GetMyClassGo("!"));  // move construct  ע��������MyClass::GetMyClassGo()�ڲ�

	/*
	* ���д��麯�������������࣬����ֱ��ʵ���������Ҵ��麯����Ҫ����������д
	* �����������ʵ����
	*/
	//VirtualChild vc;
	//vc.print();

	/*
	* ǿ������ת�������
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

	int&& rb = 10;   // ��ֵ����
	rb = 12;
	cout << "rb: " << rb << endl;

	system("pause");
	return 0;
}