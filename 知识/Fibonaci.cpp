#include<iostream>
using namespace std;

int Fbi(int i) {
	if (i < 2) {   //结束递归的条件
		return i == 0 ? 0 : 1;
	}
	return Fbi(i - 1) + Fbi(i - 2);  //调用自身
}

int main() {
	int i;
	for (int i = 0; i < 40; i++) {
		cout << Fbi(i) << endl;
	}
	system("pause");
	return 0;
}