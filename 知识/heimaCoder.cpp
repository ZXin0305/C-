#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<Windows.h>
#include<list>
using namespace std;


// 开闭原则
// 对扩展开放，对修改关闭，增加功能是通过增加代码实现的，而不是去修改源代码

// 写一个抽象类
class AbstractCalculator {
public:
	virtual int getResult() = 0;
	virtual void setOperatorNumber(int a, int b) = 0;
};

// 加法计算器
class PlusCalculator : public AbstractCalculator {
public:
	virtual void setOperatorNumber(int a, int b) {
		this->_a = a;
		this->_b = b;
	}
	virtual int getResult(){
		return this->_a + this->_b;
	}

private:
	int _a;
	int _b;
};

// 减法计算器
class MiuteCalculator : public AbstractCalculator {
public:
	virtual void setOperatorNumber(int a, int b) {
		this->_a = a;
		this->_b = b;
	}
	virtual int getResult() {
		return this->_a - this->_b;
	}

private:
	int _a;
	int _b;
};

// 乘法计算器
class MultiplyCalculator : public AbstractCalculator {
public:
	virtual void setOperatorNumber(int a, int b) {
		this->_a = a;
		this->_b = b;
	}
	virtual int getResult() {
		return this->_a * this->_b;
	}

private:
	int _a;
	int _b;
};


// 迪米特法则： 最少知识原则
class AbstructBuilding {
public:
	virtual void sale() = 0;
	virtual string getQuality() = 0;
};

class BuildingA : public AbstructBuilding {
public:
	BuildingA() {
		this->_Quality = "高品质";
	}
	virtual void sale() {
		cout << "A " << this->_Quality << " 被售卖 .." << endl;
	}

	virtual string getQuality() {
		return _Quality;
	}
public:
	string _Quality;
};

class BuildingB : public AbstructBuilding {
public:
	BuildingB() {
		this->_Quality = "低品质";
	}
	virtual void sale() {
		cout << "B " << this->_Quality << " 被售卖 .." << endl;
	}

	virtual string getQuality()
	{
		return _Quality;
	}
public:
	string _Quality;
};

// 客户端
void test01(){
   BuildingA * ba = new BuildingA;
   if (ba->_Quality == "高品质") {
	   ba->sale();
   }

   BuildingB* bb = new BuildingB;
   if (bb->_Quality == "低品质") {
	   bb->sale();
   }
}

// 中介类
class Mediator {
public:
	Mediator() {
		AbstructBuilding* building = new BuildingA;
		vBuilding.push_back(building);
		building = new BuildingB;
		vBuilding.push_back(building);
	}

	//提供对外接口
	AbstructBuilding* findMyBuilding(string quality) {
		for (auto x : vBuilding) {
			if (x->getQuality() == "高品质") {
				return x;
			}
		}
		return NULL;
	}

	~Mediator() {
		for (auto x : vBuilding) {
			if (x != NULL) {
				delete x;
			}
		}
	}
public:
	vector<AbstructBuilding*> vBuilding;
};

void test02() {
	Mediator* me = new Mediator();
	AbstructBuilding* building = me->findMyBuilding("高品质");
	if (building == NULL) {
		cout << "没有找到" << endl;
	}
	else {
		cout << "找到了" << endl;
	}
}

// 合成复用原则
class AbstructCar {
public:
	virtual void run() = 0;
};

class DaZhong :public AbstructCar {
public:
	virtual void run() {
		cout << "大众车启动 .. " << endl;
	}
};

class TuoLaJi :public AbstructCar {
public:
	virtual void run() {
		cout << "拖拉机启动 .. " << endl;
	}
};

// 这个是复用，不太好
//class Person :public TuoLaJi {
//public:
//	void Doufeng(){
//		run();
//	}
//};

//使用组合
class Person {
public:
	void setCar(AbstructCar* car) {
		this->car = car;
	}

	void Doufeng() {
		this->car->run();
	}

	~Person() {
		if (this->car != NULL) {
			delete this->car;
		}
	}

public:
	AbstructCar* car;
};


// 4.依赖倒转原则

// 具体的类
class BankWorker {
public:
	void saveService(){
		cout << "办理存款业务 .." << endl;
	}
	void payService() {
		cout << "办理支付业务 .." << endl;
	}
	void transferService() {
		cout << "办理转账业务 .." << endl;
	}
};

// 中间层模块
void doSaveBussiness(BankWorker* worker) {
	worker->saveService();
}
void doPayBussiness(BankWorker* worker) {
	worker->payService();
}
void doTransBussiness(BankWorker* worker) {
	worker->transferService();
}

// 上述的不太好，太过于依赖中间层
// 单一原则
class AbstractWorker {
public:
	virtual void doBusiness() = 0;
};

// 专门存款
class SaveWorker : public AbstractWorker {
public:
	virtual void doBussiness() {
		cout << "办理存款 .." << endl;
	}
};
class PayWorker : public AbstractWorker {
public:
	virtual void doBussiness() {
		cout << "办理支付 .." << endl;
	}
};
class TransferWorker : public AbstractWorker {
public:
	virtual void doBussiness() {
		cout << "办理转账 .." << endl;
	}
};

// 新的中间层模块
void doNewBussiness(AbstractWorker* worker) {  // 形参的思想就是，这一类人抽象出来后，只使用这个抽象类就好了
	worker->doBusiness();
	delete worker;
}

//void test3() {
//	AbstractWorker* abworker = new SaveWorker();
//	doNewBussiness(abworker);
//}

/*
* 简单工厂模式:就是用一个类隔离用户和类，让创建复杂类的功能由工厂负责.创建过程不用担心
*/

class AbstractFruit {
public:
	virtual void show_name() = 0;
};

class Apple : public AbstractFruit{
public:
	virtual void show_name() {
		cout << "我是苹果" << endl;
	}
};

class Pear : public AbstractFruit {
public:
	virtual void show_name() {
		cout << "我是鸭梨" << endl;
	}
};

//创建一个工厂
class FruitFactory {
public:
	//写成一个静态函数
	static AbstractFruit* create_fruit(string flag) {
		if (flag == "apple") {
			return new Apple();
		}
		else if (flag == "pear"){
			return new Pear();
		}
	}
};

void test03() {
	FruitFactory* fac = new FruitFactory();
	AbstractFruit* apple = fac->create_fruit("apple");
	apple->show_name();
	AbstractFruit* pear = fac->create_fruit("pear");
	pear->show_name();
	delete apple;
	delete pear;
}

/*
* 工厂方法模式
*/
class AbstractFruit1 {
public:
	virtual void show_name() = 0;
};

class Apple1 : public AbstractFruit1 {
public:
	virtual void show_name() {
		cout << "我是苹果" << endl;
	}
};

class Pear1 : public AbstractFruit1 {
public:
	virtual void show_name() {
		cout << "我是鸭梨" << endl;
	}
};

// 把工厂抽象出来
class AbstractFruitFactory {
public:
	virtual AbstractFruit1* create_fruit() = 0;
};

// 苹果工厂
class AppleFactory : public AbstractFruitFactory {
public:
	virtual AbstractFruit1* create_fruit() {
		return new Apple1();
	}
};

// 鸭梨工厂
class PearFactory : public AbstractFruitFactory {
public:
	virtual AbstractFruit1* create_fruit() {
		return new Pear1();
	}
};

void test04() {
	AbstractFruitFactory* fac1 = NULL;
	AbstractFruit1* fruit = NULL;
	//创建苹果工厂
	fac1 = new AppleFactory();
	fruit = fac1->create_fruit();
	fruit->show_name();
	delete fruit;
	delete fac1;
}

/*
* 单例模式:
* 1.私有化构造函数。让new或者直接实例化的功能失效（只给你一个成员函数作为接口进行调用，其它方法不行。。）
* 2.取值成员函数加上static是让该函数可以不用创建对象（通过类名）就能够进行调用（因为此时无法创建对象，不改成静态函数就无法进行调用）
* 3.单例对象的释放：可以不用释放，因为单例只维护一个类对象。
* 4.单例碰上多线程：懒汉式不安全（可能会多个new），饿汉式是安全的（饿汉式是在编译阶段即main函数之前完成的，此时pSingleto已经被创建，多个线程返回的都是同一个内存空间）
*/

class A {
private:
	A(){
		a = new A;   // 饿汉式：直接就进行了创建
	}
private:
	static A* a;  // 静态变量，需要在类外初始化
public:
	static A* getInstance() {
		return a;
	}
};

A* A::a = NULL;

// 单例：懒汉式  饿汉式
// 懒汉式
class Singleton_lazy {
private:
	Singleton_lazy(){ cout << "懒汉式构造 .. " << endl; }
private:
	static Singleton_lazy* pSingleton;
public:
	static Singleton_lazy* getInstance() {
		if (pSingleton == NULL) {
			pSingleton = new Singleton_lazy();
		}
		return pSingleton;
	}
	// 这个函数不能直接给一个函数释放，太危险，很容易别人给你释放掉了
	//static void freeSpace() {
	//	if (pSingleton != NULL) {
	//		delete pSingleton;
	//		cout << "单例释放完成 .." << endl;
	//	}
	//}
};
Singleton_lazy* Singleton_lazy::pSingleton = NULL;

// 饿汉式
class Singleton_hungry {
private:
	Singleton_hungry() { cout << "饿汉式构造 .. " << endl; }
private:
	static Singleton_hungry* pSingleton;
public:
	static Singleton_hungry* getInstance() {
		return pSingleton;
	}
};
Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry();  // 这里需要进行一个实例化，才能初始化这个Singleton_hungry类

/* ================================================================================================== */

/*
* 代理模式：为其他对象提供一种代理以控制对这个对象的访问。
            在某些情况下，一个对象不适合或者不能直接引用另一个对象，而代理对象可以在客户端和目标对象之间起到中介的作用。
*/

//提供一种方式，控制对其他对象的访问
class AbstractCommonInterface {
public:
	virtual void run() = 0;
};

class MySystem : public AbstractCommonInterface{
public:
	virtual void run() {
		cout << "系统启动 .." << endl;
	}

};

// 必须要有权限验证，不是所有人都能启动我的系统，提供用户名和密码
// 代理：提供对服务器的访问
class MySystemProxy :public AbstractCommonInterface {
public:
	MySystemProxy(string username, string password) {
		this->user_name = username;
		this->password = password;
		pSystem = new MySystem();
	}

	bool checkUserNameAndPassword() {
		if(this->user_name == "admin" && this->password == "admin") {
			return true;
		}
		return false;
	}

	virtual void run() {
		if (checkUserNameAndPassword()) {
			this->pSystem->run();
		}
		else {
			cout << "cannot run the system .." << endl;
		}
	}

	~MySystemProxy() {
		if (pSystem != NULL) {
			delete pSystem;
		}
	}
public:
	MySystem* pSystem;   // 将自己的系统封装起来，通过代理来访问
	string user_name;
	string password;
};

void test05() {
	MySystemProxy* proxy = new MySystemProxy("root", "root");
	proxy->run();
}

/* ========================================================================= */

/*
* 结构型模式：
*/

/* ========================================================================= */

/*
* 外观模式：将复杂的子类系统抽象到同一个的接口进行管理，外界只需要通过此接口与子类系统进行交互，而不必直接与复杂的子类系统进行交互
* 根据迪米特法则，如果两个类不必彼此直接通信，那么这两个类就不应当发生直接的相互作用
*/
class SubSystem1 {
public:
	void run() {
		cout << "子系统1运行 .." << endl;
	}
};

class SubSystem2 {
public:
	void run() {
		cout << "子系统2运行 .." << endl;
	}
};

class SubSystem3 {
public:
	void run() {
		cout << "子系统3运行 .." << endl;
	}
};

class SubSystem4 {
public:
	void run() {
		cout << "子系统4运行 .." << endl;
	}
};
//外观类
class Facede {
public:
	Facede() {
		pSystem1 = new SubSystem1();
		pSystem2 = new SubSystem2();
		pSystem3 = new SubSystem3();
		pSystem4 = new SubSystem4();
	}

	void runSystem() {
		pSystem1->run();
		pSystem2->run();
		pSystem3->run();
		pSystem4->run();
	}

private:
	SubSystem1* pSystem1;
	SubSystem2* pSystem2;
	SubSystem3* pSystem3;
	SubSystem4* pSystem4;
};

void test06() {
	Facede* facede = new Facede();
	facede->runSystem();
	delete facede;
}

// case：根据类图，实现家庭影院外观模式应用
// 实现KTV模式：电视打开，灯关掉，音响打开，麦克风打开，dvd打开
// 实现游戏模式：电视打开，音响打开，游戏机打开


// 电视
class Television {
public:
	void On() {
		cout << "open TV .. " << endl;
	}
	void Off() {
		cout << "off TV .. " << endl;
	}
};

//灯
class Light {
public:
	void On() {
		cout << "open Light .. " << endl;
	}
	void Off() {
		cout << "off Light .. " << endl;
	}
};


// 音响
class Audio {
public:
	void On() {
		cout << "open Audio .. " << endl;
	}
	void Off() {
		cout << "off Audio .. " << endl;
	}
};

//麦克风
class MicroPhone {
public:
	void On() {
		cout << "open MicroPhone .. " << endl;
	}
	void Off() {
		cout << "off MicroPhone .. " << endl;
	}
};

//DVD
class DVDPlayer {
public:
	void On() {
		cout << "open DVDPlayer .. " << endl;
	}
	void Off() {
		cout << "off DVDPlayer .. " << endl;
	}
};

//游戏机
class GameMachine {
public:
	void On() {
		cout << "open GameMachine .. " << endl;
	}
	void Off() {
		cout << "off GameMachine .. " << endl;
	}
};

class KTVMode {
public:
	KTVMode() {
		 pTV = new Television();
		 pLight = new Light();
		 pAudio = new Audio();
		 pMicroPhone = new MicroPhone();
		 pDVD = new DVDPlayer();
	}

	~KTVMode() {
		delete pTV;
		delete pLight;
		delete pAudio;
		delete pMicroPhone;
		delete pDVD;
	}

	void onKTV() {
		pTV->On();
		pLight->Off();
		pAudio->On();
		pMicroPhone->On();
		pDVD->On();
	}

	void offKTV() {
		pTV->Off();
		pLight->On();
		pAudio->Off();
		pMicroPhone->Off();
		pDVD->Off();
	}

public:
	Television* pTV;
	Light* pLight;
	Audio* pAudio;
	MicroPhone* pMicroPhone;
	DVDPlayer* pDVD;
};

void test07() {
	KTVMode* ktv = new KTVMode();
	ktv->onKTV();
}

/* ============================================================================= */

/*
* 适配器模式：将一个类的接口转换成客户希望的另外一个接口。使得原本由于接口不兼容而不能一起工作的那些类可以一起工作
* 将写好的接口转换成目标接口
*/
struct MyPrint {
	void operator()(int v1, int v2) {
		cout << v1 + v2 << endl;
	}
};

//定义目标接口，适配成什么样子的
class Target {
public:
	virtual void operator()(int v) = 0;
};

//写适配器
class Adapter :public Target {
public:
	Adapter(int param) { this->param = param; }
	virtual void operator()(int v) {
		my_print(v, param);
	}
public:
	MyPrint my_print;
	int param;
};

// MyBind2nd
Adapter MyBind2nd(int v) {
	return Adapter(v);
}

/* =================================================================================== */

/*
* 行为型模式：用来对类或者对象怎样交互和怎样分配职责进行描述
* 模板方法模式：定义一个操作中算法的框架，而将一些步骤延迟到子类中。模板方法模式使得一些子类可以不改变一个算法的结构即可重新定义该算法的某些特定步骤
*/

class DrinkTemplate {
public:
	virtual void BoildWater() = 0;
	virtual void Brew() = 0;
	virtual void PourInCup() = 0;
	virtual void AddSomething() = 0;

	// 模板方法
	void Make() {
		BoildWater();
		Brew();
		PourInCup();
		AddSomething();
	}
};

class Coffee : public DrinkTemplate {
public:
	virtual void BoildWater() {
		cout << "煮山泉水 .." << endl;
	}
	virtual void Brew() {
		cout << "冲泡咖啡 .." << endl;
	}
	virtual void PourInCup() {
		cout << "咖啡导入杯中 .." << endl;
	}
	virtual void AddSomething() {
		cout << "加糖，加牛奶 .." << endl;
	}
};

class Tea : public DrinkTemplate {
public:
	virtual void BoildWater() {
		cout << "煮山泉水 .." << endl;
	}
	virtual void Brew() {
		cout << "冲泡茶叶 .." << endl;
	}
	virtual void PourInCup() {
		cout << "茶水导入杯中 .." << endl;
	}
	virtual void AddSomething() {
		cout << "加柠檬 .." << endl;
	}
};

void test08() {
	Tea* tea = new Tea();
	tea->Make();
}

/* ======================================================================= */

/*
* 策略模式
* 
*/

// 抽象武器 武器策略
class WeaponStrategy {
public:
	virtual void UseWeapon() = 0;
};

class Knife :public WeaponStrategy {
public:
	virtual void UseWeapon() {
		cout << "使用匕首!" << endl;
	}
};

class AK47 :public WeaponStrategy {
public:
	virtual void UseWeapon() {
		cout << "使用AK 47!" << endl;
	}
};

class Character {
public:
	void setWeapon(WeaponStrategy* weapon) {
		this->pWeapon = weapon;
	}

	void ThrowWeapon() {
		this->pWeapon->UseWeapon();
	}
public:
	WeaponStrategy* pWeapon;
};

void test09() {
	Character* ch = new Character();
	WeaponStrategy* knife = new Knife();
	ch->setWeapon(knife);
	ch->ThrowWeapon();
}

/* ======================================================================== */

/*
* 命令模式: 将一个请求封装为一个对象，从而让我们可用不同的请求对客户进行参数化；对请求排队或者记录请求日志，以及支持可撤销的操作
* 命令模式是一种对象型模式，其别名为动作（Action）模式或者事务（Transaction）模式。
* 命令模式可以将请求发送者和接收者完全解耦，发送者与接收者之间没有直接引用关系，发送请求的对象只需要知道如何发送请求，而不必知道如何完成请求。
*/

// 协议处理类
class HandleClientProtocol {
public:
	//处理增加金币
	void AddMoney() {
		cout << "给玩家增加金币 .." << endl;
	}

	//处理增加钻石
	void AddDiamond() {
		cout << "给玩家增加钻石 .." << endl;
	}

	//处理玩家装备
	void AddEquipment() {
		cout << "给玩家穿设备 .." << endl;
	}

	//处理玩家升级
	void AddLevel() {
		cout << "给玩家升级 .." << endl;
	}
};

// 协议命令接口
class AbstractCommand {
public:
	virtual void handle() = 0;  // 处理客户端请求的接口
};

class AddMoneyCommand :public AbstractCommand {
public:
	AddMoneyCommand(HandleClientProtocol* protocol) {
		this->mProtocol = protocol;
	}
	virtual void handle() {
		this->mProtocol->AddMoney();
	}
public:
	HandleClientProtocol* mProtocol;
};

class AddDiamondCommand :public AbstractCommand {
public:
	AddDiamondCommand(HandleClientProtocol* protocol) {
		this->mProtocol = protocol;
	}
	virtual void handle() {
		this->mProtocol->AddDiamond();
	}
public:
	HandleClientProtocol* mProtocol;
};

class AddEquipmentCommand :public AbstractCommand {
public:
	AddEquipmentCommand(HandleClientProtocol* protocol) {
		this->mProtocol = protocol;
	}
	virtual void handle() {
		this->mProtocol->AddEquipment();
	}
public:
	HandleClientProtocol* mProtocol;
};

class AddLevelCommand :public AbstractCommand {
public:
	AddLevelCommand(HandleClientProtocol* protocol) {
		this->mProtocol = protocol;
	}
	virtual void handle() {
		this->mProtocol->AddLevel();
	}
public:
	HandleClientProtocol* mProtocol;
};

// 服务器程序
class Serser {
public:
	void addRequest(AbstractCommand* command) {
		mCommands.push(command);
	}

	void startHandle() {
		while (!mCommands.empty()) {
			Sleep(200);
			AbstractCommand* command = mCommands.front();
			command->handle();
			mCommands.pop();
		}
	}
public:
	queue<AbstractCommand*> mCommands;  // 协议放在队列中，逐个处理
};

void test10() {
	HandleClientProtocol* protocol = new HandleClientProtocol();

	// 增加钻石
	AbstractCommand* addMoney = new AddMoneyCommand(protocol);

	// 增加钻石
	AddDiamondCommand* addDiamond = new AddDiamondCommand(protocol);

	// 增加装备
	AddEquipmentCommand* addEquipment = new AddEquipmentCommand(protocol);

	// 升级
	AddLevelCommand* addLevel = new AddLevelCommand(protocol);

	Serser* server = new Serser();
	server->addRequest(addMoney);
	server->addRequest(addDiamond);
	server->addRequest(addEquipment);
	server->addRequest(addLevel);

	server->startHandle();  // 开始处理

}

/* =============================================================== */

/*
* 观察者模式：用于建立一种对象与对象之间的依赖关系，一个对象发生改变时将自动通知其他对象，其他对象将相应作出反应
* 在观察者模式中，发生改变的对象称为观察目标，而被通知的对象称为观察者
*/

// 先抽象出来一个接口
class AbstractHero {
public:
	virtual void Update() = 0;
};

class HeroA :public AbstractHero {
public:
	HeroA() {
		cout << "英雄A正在撸Boss ... " << endl;
	}

	virtual void Update() {
		cout << "英雄A停止撸Boss, 待机状态  .." << endl;
	}
};

class HeroB :public AbstractHero {
public:
	HeroB() {
		cout << "英雄B正在撸Boss ... " << endl;
	}
	virtual void Update() {
		cout << "英雄B停止撸Boss, 待机状态  .." << endl;
	}
};

class HeroC :public AbstractHero {
public:
	HeroC() {
		cout << "英雄C正在撸Boss ... " << endl;
	}
	virtual void Update() {
		cout << "英雄C停止撸Boss, 待机状态  .." << endl;
	}
};

class HeroD :public AbstractHero {
public:
	HeroD() {
		cout << "英雄D正在撸Boss ... " << endl;
	}
	virtual void Update() {
		cout << "英雄D停止撸Boss, 待机状态  .." << endl;
	}
};

class HeroE :public AbstractHero {
public:
	HeroE() {
		cout << "英雄E正在撸Boss ... " << endl;
	}

	virtual void Update() {
		cout << "英雄E停止撸Boss, 待机状态  .." << endl;
	}
};

//观察目标抽象
class AbstractBoss {
public:
	//添加观察者
	virtual void addHero(AbstractHero* hero) = 0;
	//删除观察者
	virtual void deleteHero(AbstractHero* hero) = 0;
	//通知所有观察者
	virtual void notify() = 0;
};

//具体的观察目标 BOSSA
class BOSSA :public AbstractBoss {
public:
	virtual void addHero(AbstractHero* hero) {
		pHeroList.push_back(hero);
	}

	virtual void deleteHero(AbstractHero* hero) {
		pHeroList.remove(hero);
	}

	virtual void notify() {
		for (list<AbstractHero*>::iterator it = pHeroList.begin(); it != pHeroList.end(); it++) {
			(*it)->Update();
		}
	}

public:
	list<AbstractHero*> pHeroList;
};

void test11() {
	//创建观察者
	AbstractHero* heroA = new HeroA;
	AbstractHero* heroB = new HeroB;
	AbstractHero* heroC = new HeroC;
	AbstractHero* heroD = new HeroD;
	AbstractHero* heroE = new HeroE;

	//创建观察目标
	AbstractBoss* bossA = new BOSSA();
	bossA->addHero(heroA);
	bossA->addHero(heroB);
	bossA->addHero(heroC);
	bossA->addHero(heroD);
	bossA->addHero(heroE);


	cout << "hero C 阵亡 .." << endl;
	bossA->deleteHero(heroC);

	cout << "Boss 没了， 通知其他英雄停止攻击，抢装备 .." << endl;
	bossA->notify();

}

/* ============================================================================= */

/*
* 装饰模式:又叫包装模式，通过一种对客户端透明的方式来扩展对象功能，是继承关系的一种替代
* 装饰模式就是把要附加的功能分别放在单独的类中，并让这个类包含它要装饰的对象，当需要执行时，客户端就可以有选择地、按顺序的使用装饰功能进行包装
*/

//一般情况下，继承实现类的功能扩展
//装饰模式  可以动态给一个类增加功能


//抽象出来一个英雄的类
class AbstractHero1 {
public:
	virtual void ShowStatus() = 0;
public:
	int mHp;
	int mMp;
	int mAt;
	int mDf;
};

// 具体英雄
class HeroA1 : public AbstractHero1 {
public:
	HeroA1() {
		mHp = 0;
		mMp = 0;
		mAt = 0;
		mDf = 0;
	}

	virtual void ShowStatus() {
		cout << "血量：" << mHp << endl;
		cout << "魔法：" << mMp << endl;
		cout << "攻击：" << mAt << endl;
		cout << "防御：" << mDf << endl;
	}
};

//英雄穿上某个装饰物， 那么他还是一个英雄
//这里写的是一个武器基类
//为什么这个武器的基类会继承英雄的基类，是因为穿上装备之后仍然是一个英雄，具有英雄该具有的属性
class AbstractEquipment :public AbstractHero1 {
public:
	AbstractEquipment(AbstractHero1* hero) {
		this->pHero = hero;
	}

	virtual void ShowStatus(){}

public:
	AbstractHero1* pHero;
};

//狂徒
class KuangTuEquipment :public AbstractEquipment {
public:
	KuangTuEquipment(AbstractHero1* hero):AbstractEquipment(hero){}
	//增加额外功能
	void AddKunagTu() {
		cout << "穿上狂徒 .." << endl;
		this->mHp = this->pHero->mHp;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt;
		this->mDf = this->pHero->mDf + 30;
		delete this->pHero;
	}
	virtual void ShowStatus() {
		AddKunagTu();
		cout << "血量：" << mHp << endl;
		cout << "魔法：" << mMp << endl;
		cout << "攻击：" << mAt << endl;
		cout << "防御：" << mDf << endl;
	}
};

//无尽之刃
class WuJinEquipment :public AbstractEquipment {
public:
	WuJinEquipment(AbstractHero1* hero) :AbstractEquipment(hero) {}
	//增加额外功能
	void AddWuJin() {
		cout << "穿上无尽 .." << endl;
		this->mHp = this->pHero->mHp;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt + 100;
		this->mDf = this->pHero->mDf;
		delete this->pHero;
	}
	virtual void ShowStatus() {
		AddWuJin();
		cout << "血量：" << mHp << endl;
		cout << "魔法：" << mMp << endl;
		cout << "攻击：" << mAt << endl;
		cout << "防御：" << mDf << endl;
	}
};


void test12() {
	AbstractHero1* hero = new HeroA1();
	hero->ShowStatus();

	cout << " -------------------------- " << endl;

	hero = new KuangTuEquipment(hero);
	hero->ShowStatus();

	hero = new WuJinEquipment(hero);
	hero->ShowStatus();
}

int main() {
	// 1.开闭原则
	//AbstractCalculator* ab = new PlusCalculator();
	//ab->setOperatorNumber(10, 10);
	//auto res = ab->getResult();
	//cout << res << endl;

	// 2.迪米特法则： 最少知识原则
	//test01();
	//test02();

	// 3.合成复用原则
	//Person* p1 = new Person();
	//p1->setCar(new DaZhong());
	//p1->Doufeng();

	// 4.依赖倒转原则
	//test3();

	// 简单工厂模式
	//test03();

	// 工厂方法模式
	//test04();

	// 单例模式
	//A::getInstance();

	//Singleton_lazy* p1 =  Singleton_lazy::getInstance();
	//Singleton_lazy* p2 = Singleton_lazy::getInstance();
	//if (p1 == p2) {
	//	cout << "两个指针指向同一个内存空间，是单例 ！" << endl;
	//}
	//else {
	//	cout << "不是单例！" << endl;
	//}

	//Singleton_hungry* p3 = Singleton_hungry::getInstance();
	//Singleton_hungry* p4 = Singleton_hungry::getInstance();
	//if (p3 == p4) {
	//	cout << "两个指针指向同一个内存空间，是单例 ！" << endl;
	//}
	//else {
	//	cout << "不是单例！" << endl;
	//}

	// 代理模式
	// test05();

	// 外观模式
	//test06();
	//test07();

	//适配器模式

	//vector<int> v;
	//for (int i = 0; i < 10; ++i) {
	//	v.push_back(i);
	//}
	//for_each(v.begin(), v.end(), MyBind2nd(10));

	//模板方法模式
	//test08();

	// 策略模式
	//test09();


	// 命令模式
	//test10();

	//观察者模式
	//test11();


	//装饰模式
	test12();

	system("pause");
	return 0;
}