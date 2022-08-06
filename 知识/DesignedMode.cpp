/*
* 代码随想录中的设计模式
*/

#include<iostream>

/*
单例模式：某一个类，只允许实例化出一个对象存在
实现方法：懒汉式、饿汉式
饿汉式：在创建类时就初始化好对象
懒汉式：在需要使用到对象实例时，才进行初始化对象
*/

// ---------------------------------
// 懒汉式：第一次用到类实例的时候才会去实例化
// 这个代码只适合在单线程中，多线程时将是不安全的。
//       比如：两个线程同时首次调用instance方法且同时检测到p是nullptr,则两个线程会同时构造一个实例给p，违反了单例的准则
//       给线程加锁，当线程A在执行p = new Singleton()的时候，线程Ｂ如果调用了instance(),一定会被阻塞在加锁处，等待线程A执行结束后释放这个锁。
//       从而保证线程是安全的。

class Singleton {
private:
	Singleton() {};   // 让构造方法private, 这就堵死了外界利用new来创建此类的可能
	static Singleton* p;
public:
	static Singleton* initstance();
};

Singleton* Singleton::p = nullptr;     // 初始化的时候是一个空指针，需要进行被动实例化
Singleton* Singleton::initstance() {
	if (p == nullptr) {
		p = new Singleton();
	}
	return p;
}

// 饿汉式：单例类在定义的时候就进行了实例化

class Singleton1 {
private:
	Singleton1(){}
	static Singleton1* p;
public:
	static Singleton1* instance();
};

Singleton1* Singleton1::p = new Singleton1();  // 就是在这里直接初始化了一个实例
Singleton1* Singleton1::instance() {
	return p;
}

using namespace std;

int main(int argc, char** argv) {

	// 1.单例模式：保证⼀个类仅有⼀个实例，并提供⼀个访问它的全局访问点


	system("pause");
	return 0;
}