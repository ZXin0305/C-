#include<iostream>
#include<vector>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

int fun(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
void swap(int* a, int* b) {
	int* tmp;
	tmp = a;
	a = b;
	b = tmp;
}

struct A {
	char a1;
	short a2;
	int a4;
	char* p1;
};

int main() {

	//char a[1024];
	//gets(a);
	//cout << a << endl;
	
	//int a, b;
	//a = 32;
	//b = 16;
	//swap(&a, &b);
	//cout << a << " " << b << endl;

	//A a;
	//cout << sizeof(a) << endl;
	//cout << sizeof(short) << endl;

	//char b[30];
	//cout << sizeof(b[3]) << endl;

	//char* c = (char*)malloc(sizeof(char) * 10);
	//cout << sizeof(*(c+3)) << endl;

	//int te[5] = { 1,2,3,4,5 };
	//int* p = te;
	//cout << *p++ << endl;
	//cout << (*p)++ << endl;
	//cout << *++p << endl;
	//cout << ++ * p << endl;

	//cout << te[1] << endl;

	vector<int> v{ 1,10,3,4,2,1 };
	auto it = max_element(v.begin(), v.end());
	if(it != v.end())
		cout << *it << endl;


	system("pause");
	return 0;
}