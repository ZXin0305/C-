#include<iostream>

using namespace std;

class A {
public:
	A() {}

	~A() {
		cout << "�ͷŻ��� .." << endl;
	}
};

class B : public A {
public:
	B(){}
	//~B() {
	//	cout << "�ͷ����� .." << endl;
	//}
};

int main(){

	A* test = new B();

	B* test1 = new B();

	delete test;
	test = nullptr;

	delete test1;
	test1 = NULL;

	system("pause");
	return 0;
}