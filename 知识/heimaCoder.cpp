#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<Windows.h>
#include<list>
using namespace std;


// ����ԭ��
// ����չ���ţ����޸Ĺرգ����ӹ�����ͨ�����Ӵ���ʵ�ֵģ�������ȥ�޸�Դ����

// дһ��������
class AbstractCalculator {
public:
	virtual int getResult() = 0;
	virtual void setOperatorNumber(int a, int b) = 0;
};

// �ӷ�������
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

// ����������
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

// �˷�������
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


// �����ط��� ����֪ʶԭ��
class AbstructBuilding {
public:
	virtual void sale() = 0;
	virtual string getQuality() = 0;
};

class BuildingA : public AbstructBuilding {
public:
	BuildingA() {
		this->_Quality = "��Ʒ��";
	}
	virtual void sale() {
		cout << "A " << this->_Quality << " ������ .." << endl;
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
		this->_Quality = "��Ʒ��";
	}
	virtual void sale() {
		cout << "B " << this->_Quality << " ������ .." << endl;
	}

	virtual string getQuality()
	{
		return _Quality;
	}
public:
	string _Quality;
};

// �ͻ���
void test01(){
   BuildingA * ba = new BuildingA;
   if (ba->_Quality == "��Ʒ��") {
	   ba->sale();
   }

   BuildingB* bb = new BuildingB;
   if (bb->_Quality == "��Ʒ��") {
	   bb->sale();
   }
}

// �н���
class Mediator {
public:
	Mediator() {
		AbstructBuilding* building = new BuildingA;
		vBuilding.push_back(building);
		building = new BuildingB;
		vBuilding.push_back(building);
	}

	//�ṩ����ӿ�
	AbstructBuilding* findMyBuilding(string quality) {
		for (auto x : vBuilding) {
			if (x->getQuality() == "��Ʒ��") {
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
	AbstructBuilding* building = me->findMyBuilding("��Ʒ��");
	if (building == NULL) {
		cout << "û���ҵ�" << endl;
	}
	else {
		cout << "�ҵ���" << endl;
	}
}

// �ϳɸ���ԭ��
class AbstructCar {
public:
	virtual void run() = 0;
};

class DaZhong :public AbstructCar {
public:
	virtual void run() {
		cout << "���ڳ����� .. " << endl;
	}
};

class TuoLaJi :public AbstructCar {
public:
	virtual void run() {
		cout << "���������� .. " << endl;
	}
};

// ����Ǹ��ã���̫��
//class Person :public TuoLaJi {
//public:
//	void Doufeng(){
//		run();
//	}
//};

//ʹ�����
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


// 4.������תԭ��

// �������
class BankWorker {
public:
	void saveService(){
		cout << "������ҵ�� .." << endl;
	}
	void payService() {
		cout << "����֧��ҵ�� .." << endl;
	}
	void transferService() {
		cout << "����ת��ҵ�� .." << endl;
	}
};

// �м��ģ��
void doSaveBussiness(BankWorker* worker) {
	worker->saveService();
}
void doPayBussiness(BankWorker* worker) {
	worker->payService();
}
void doTransBussiness(BankWorker* worker) {
	worker->transferService();
}

// �����Ĳ�̫�ã�̫���������м��
// ��һԭ��
class AbstractWorker {
public:
	virtual void doBusiness() = 0;
};

// ר�Ŵ��
class SaveWorker : public AbstractWorker {
public:
	virtual void doBussiness() {
		cout << "������ .." << endl;
	}
};
class PayWorker : public AbstractWorker {
public:
	virtual void doBussiness() {
		cout << "����֧�� .." << endl;
	}
};
class TransferWorker : public AbstractWorker {
public:
	virtual void doBussiness() {
		cout << "����ת�� .." << endl;
	}
};

// �µ��м��ģ��
void doNewBussiness(AbstractWorker* worker) {  // �βε�˼����ǣ���һ���˳��������ֻʹ�����������ͺ���
	worker->doBusiness();
	delete worker;
}

//void test3() {
//	AbstractWorker* abworker = new SaveWorker();
//	doNewBussiness(abworker);
//}

/*
* �򵥹���ģʽ:������һ��������û����࣬�ô���������Ĺ����ɹ�������.�������̲��õ���
*/

class AbstractFruit {
public:
	virtual void show_name() = 0;
};

class Apple : public AbstractFruit{
public:
	virtual void show_name() {
		cout << "����ƻ��" << endl;
	}
};

class Pear : public AbstractFruit {
public:
	virtual void show_name() {
		cout << "����Ѽ��" << endl;
	}
};

//����һ������
class FruitFactory {
public:
	//д��һ����̬����
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
* ��������ģʽ
*/
class AbstractFruit1 {
public:
	virtual void show_name() = 0;
};

class Apple1 : public AbstractFruit1 {
public:
	virtual void show_name() {
		cout << "����ƻ��" << endl;
	}
};

class Pear1 : public AbstractFruit1 {
public:
	virtual void show_name() {
		cout << "����Ѽ��" << endl;
	}
};

// �ѹ����������
class AbstractFruitFactory {
public:
	virtual AbstractFruit1* create_fruit() = 0;
};

// ƻ������
class AppleFactory : public AbstractFruitFactory {
public:
	virtual AbstractFruit1* create_fruit() {
		return new Apple1();
	}
};

// Ѽ�湤��
class PearFactory : public AbstractFruitFactory {
public:
	virtual AbstractFruit1* create_fruit() {
		return new Pear1();
	}
};

void test04() {
	AbstractFruitFactory* fac1 = NULL;
	AbstractFruit1* fruit = NULL;
	//����ƻ������
	fac1 = new AppleFactory();
	fruit = fac1->create_fruit();
	fruit->show_name();
	delete fruit;
	delete fac1;
}

/*
* ����ģʽ:
* 1.˽�л����캯������new����ֱ��ʵ�����Ĺ���ʧЧ��ֻ����һ����Ա������Ϊ�ӿڽ��е��ã������������С�����
* 2.ȡֵ��Ա��������static���øú������Բ��ô�������ͨ�����������ܹ����е��ã���Ϊ��ʱ�޷��������󣬲��ĳɾ�̬�������޷����е��ã�
* 3.����������ͷţ����Բ����ͷţ���Ϊ����ֻά��һ�������
* 4.�������϶��̣߳�����ʽ����ȫ�����ܻ���new��������ʽ�ǰ�ȫ�ģ�����ʽ���ڱ���׶μ�main����֮ǰ��ɵģ���ʱpSingleto�Ѿ�������������̷߳��صĶ���ͬһ���ڴ�ռ䣩
*/

class A {
private:
	A(){
		a = new A;   // ����ʽ��ֱ�Ӿͽ����˴���
	}
private:
	static A* a;  // ��̬��������Ҫ�������ʼ��
public:
	static A* getInstance() {
		return a;
	}
};

A* A::a = NULL;

// ����������ʽ  ����ʽ
// ����ʽ
class Singleton_lazy {
private:
	Singleton_lazy(){ cout << "����ʽ���� .. " << endl; }
private:
	static Singleton_lazy* pSingleton;
public:
	static Singleton_lazy* getInstance() {
		if (pSingleton == NULL) {
			pSingleton = new Singleton_lazy();
		}
		return pSingleton;
	}
	// �����������ֱ�Ӹ�һ�������ͷţ�̫Σ�գ������ױ��˸����ͷŵ���
	//static void freeSpace() {
	//	if (pSingleton != NULL) {
	//		delete pSingleton;
	//		cout << "�����ͷ���� .." << endl;
	//	}
	//}
};
Singleton_lazy* Singleton_lazy::pSingleton = NULL;

// ����ʽ
class Singleton_hungry {
private:
	Singleton_hungry() { cout << "����ʽ���� .. " << endl; }
private:
	static Singleton_hungry* pSingleton;
public:
	static Singleton_hungry* getInstance() {
		return pSingleton;
	}
};
Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry();  // ������Ҫ����һ��ʵ���������ܳ�ʼ�����Singleton_hungry��

/* ================================================================================================== */

/*
* ����ģʽ��Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ��ʡ�
            ��ĳЩ����£�һ�������ʺϻ��߲���ֱ��������һ�����󣬶������������ڿͻ��˺�Ŀ�����֮�����н�����á�
*/

//�ṩһ�ַ�ʽ�����ƶ���������ķ���
class AbstractCommonInterface {
public:
	virtual void run() = 0;
};

class MySystem : public AbstractCommonInterface{
public:
	virtual void run() {
		cout << "ϵͳ���� .." << endl;
	}

};

// ����Ҫ��Ȩ����֤�����������˶��������ҵ�ϵͳ���ṩ�û���������
// �����ṩ�Է������ķ���
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
	MySystem* pSystem;   // ���Լ���ϵͳ��װ������ͨ������������
	string user_name;
	string password;
};

void test05() {
	MySystemProxy* proxy = new MySystemProxy("root", "root");
	proxy->run();
}

/* ========================================================================= */

/*
* �ṹ��ģʽ��
*/

/* ========================================================================= */

/*
* ���ģʽ�������ӵ�����ϵͳ����ͬһ���Ľӿڽ��й������ֻ��Ҫͨ���˽ӿ�������ϵͳ���н�����������ֱ���븴�ӵ�����ϵͳ���н���
* ���ݵ����ط�����������಻�ر˴�ֱ��ͨ�ţ���ô��������Ͳ�Ӧ������ֱ�ӵ��໥����
*/
class SubSystem1 {
public:
	void run() {
		cout << "��ϵͳ1���� .." << endl;
	}
};

class SubSystem2 {
public:
	void run() {
		cout << "��ϵͳ2���� .." << endl;
	}
};

class SubSystem3 {
public:
	void run() {
		cout << "��ϵͳ3���� .." << endl;
	}
};

class SubSystem4 {
public:
	void run() {
		cout << "��ϵͳ4���� .." << endl;
	}
};
//�����
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

// case��������ͼ��ʵ�ּ�ͥӰԺ���ģʽӦ��
// ʵ��KTVģʽ�����Ӵ򿪣��ƹص�������򿪣���˷�򿪣�dvd��
// ʵ����Ϸģʽ�����Ӵ򿪣�����򿪣���Ϸ����


// ����
class Television {
public:
	void On() {
		cout << "open TV .. " << endl;
	}
	void Off() {
		cout << "off TV .. " << endl;
	}
};

//��
class Light {
public:
	void On() {
		cout << "open Light .. " << endl;
	}
	void Off() {
		cout << "off Light .. " << endl;
	}
};


// ����
class Audio {
public:
	void On() {
		cout << "open Audio .. " << endl;
	}
	void Off() {
		cout << "off Audio .. " << endl;
	}
};

//��˷�
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

//��Ϸ��
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
* ������ģʽ����һ����Ľӿ�ת���ɿͻ�ϣ��������һ���ӿڡ�ʹ��ԭ�����ڽӿڲ����ݶ�����һ��������Щ�����һ����
* ��д�õĽӿ�ת����Ŀ��ӿ�
*/
struct MyPrint {
	void operator()(int v1, int v2) {
		cout << v1 + v2 << endl;
	}
};

//����Ŀ��ӿڣ������ʲô���ӵ�
class Target {
public:
	virtual void operator()(int v) = 0;
};

//д������
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
* ��Ϊ��ģʽ������������߶���������������������ְ���������
* ģ�巽��ģʽ������һ���������㷨�Ŀ�ܣ�����һЩ�����ӳٵ������С�ģ�巽��ģʽʹ��һЩ������Բ��ı�һ���㷨�Ľṹ�������¶�����㷨��ĳЩ�ض�����
*/

class DrinkTemplate {
public:
	virtual void BoildWater() = 0;
	virtual void Brew() = 0;
	virtual void PourInCup() = 0;
	virtual void AddSomething() = 0;

	// ģ�巽��
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
		cout << "��ɽȪˮ .." << endl;
	}
	virtual void Brew() {
		cout << "���ݿ��� .." << endl;
	}
	virtual void PourInCup() {
		cout << "���ȵ��뱭�� .." << endl;
	}
	virtual void AddSomething() {
		cout << "���ǣ���ţ�� .." << endl;
	}
};

class Tea : public DrinkTemplate {
public:
	virtual void BoildWater() {
		cout << "��ɽȪˮ .." << endl;
	}
	virtual void Brew() {
		cout << "���ݲ�Ҷ .." << endl;
	}
	virtual void PourInCup() {
		cout << "��ˮ���뱭�� .." << endl;
	}
	virtual void AddSomething() {
		cout << "������ .." << endl;
	}
};

void test08() {
	Tea* tea = new Tea();
	tea->Make();
}

/* ======================================================================= */

/*
* ����ģʽ
* 
*/

// �������� ��������
class WeaponStrategy {
public:
	virtual void UseWeapon() = 0;
};

class Knife :public WeaponStrategy {
public:
	virtual void UseWeapon() {
		cout << "ʹ��ذ��!" << endl;
	}
};

class AK47 :public WeaponStrategy {
public:
	virtual void UseWeapon() {
		cout << "ʹ��AK 47!" << endl;
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
* ����ģʽ: ��һ�������װΪһ�����󣬴Ӷ������ǿ��ò�ͬ������Կͻ����в��������������Ŷӻ��߼�¼������־���Լ�֧�ֿɳ����Ĳ���
* ����ģʽ��һ�ֶ�����ģʽ�������Ϊ������Action��ģʽ��������Transaction��ģʽ��
* ����ģʽ���Խ��������ߺͽ�������ȫ����������������֮��û��ֱ�����ù�ϵ����������Ķ���ֻ��Ҫ֪����η������󣬶�����֪������������
*/

// Э�鴦����
class HandleClientProtocol {
public:
	//�������ӽ��
	void AddMoney() {
		cout << "��������ӽ�� .." << endl;
	}

	//����������ʯ
	void AddDiamond() {
		cout << "�����������ʯ .." << endl;
	}

	//�������װ��
	void AddEquipment() {
		cout << "����Ҵ��豸 .." << endl;
	}

	//�����������
	void AddLevel() {
		cout << "��������� .." << endl;
	}
};

// Э������ӿ�
class AbstractCommand {
public:
	virtual void handle() = 0;  // ����ͻ�������Ľӿ�
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

// ����������
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
	queue<AbstractCommand*> mCommands;  // Э����ڶ����У��������
};

void test10() {
	HandleClientProtocol* protocol = new HandleClientProtocol();

	// ������ʯ
	AbstractCommand* addMoney = new AddMoneyCommand(protocol);

	// ������ʯ
	AddDiamondCommand* addDiamond = new AddDiamondCommand(protocol);

	// ����װ��
	AddEquipmentCommand* addEquipment = new AddEquipmentCommand(protocol);

	// ����
	AddLevelCommand* addLevel = new AddLevelCommand(protocol);

	Serser* server = new Serser();
	server->addRequest(addMoney);
	server->addRequest(addDiamond);
	server->addRequest(addEquipment);
	server->addRequest(addLevel);

	server->startHandle();  // ��ʼ����

}

/* =============================================================== */

/*
* �۲���ģʽ�����ڽ���һ�ֶ��������֮���������ϵ��һ���������ı�ʱ���Զ�֪ͨ������������������Ӧ������Ӧ
* �ڹ۲���ģʽ�У������ı�Ķ����Ϊ�۲�Ŀ�꣬����֪ͨ�Ķ����Ϊ�۲���
*/

// �ȳ������һ���ӿ�
class AbstractHero {
public:
	virtual void Update() = 0;
};

class HeroA :public AbstractHero {
public:
	HeroA() {
		cout << "Ӣ��A����ߣBoss ... " << endl;
	}

	virtual void Update() {
		cout << "Ӣ��AֹͣߣBoss, ����״̬  .." << endl;
	}
};

class HeroB :public AbstractHero {
public:
	HeroB() {
		cout << "Ӣ��B����ߣBoss ... " << endl;
	}
	virtual void Update() {
		cout << "Ӣ��BֹͣߣBoss, ����״̬  .." << endl;
	}
};

class HeroC :public AbstractHero {
public:
	HeroC() {
		cout << "Ӣ��C����ߣBoss ... " << endl;
	}
	virtual void Update() {
		cout << "Ӣ��CֹͣߣBoss, ����״̬  .." << endl;
	}
};

class HeroD :public AbstractHero {
public:
	HeroD() {
		cout << "Ӣ��D����ߣBoss ... " << endl;
	}
	virtual void Update() {
		cout << "Ӣ��DֹͣߣBoss, ����״̬  .." << endl;
	}
};

class HeroE :public AbstractHero {
public:
	HeroE() {
		cout << "Ӣ��E����ߣBoss ... " << endl;
	}

	virtual void Update() {
		cout << "Ӣ��EֹͣߣBoss, ����״̬  .." << endl;
	}
};

//�۲�Ŀ�����
class AbstractBoss {
public:
	//��ӹ۲���
	virtual void addHero(AbstractHero* hero) = 0;
	//ɾ���۲���
	virtual void deleteHero(AbstractHero* hero) = 0;
	//֪ͨ���й۲���
	virtual void notify() = 0;
};

//����Ĺ۲�Ŀ�� BOSSA
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
	//�����۲���
	AbstractHero* heroA = new HeroA;
	AbstractHero* heroB = new HeroB;
	AbstractHero* heroC = new HeroC;
	AbstractHero* heroD = new HeroD;
	AbstractHero* heroE = new HeroE;

	//�����۲�Ŀ��
	AbstractBoss* bossA = new BOSSA();
	bossA->addHero(heroA);
	bossA->addHero(heroB);
	bossA->addHero(heroC);
	bossA->addHero(heroD);
	bossA->addHero(heroE);


	cout << "hero C ���� .." << endl;
	bossA->deleteHero(heroC);

	cout << "Boss û�ˣ� ֪ͨ����Ӣ��ֹͣ��������װ�� .." << endl;
	bossA->notify();

}

/* ============================================================================= */

/*
* װ��ģʽ:�ֽа�װģʽ��ͨ��һ�ֶԿͻ���͸���ķ�ʽ����չ�����ܣ��Ǽ̳й�ϵ��һ�����
* װ��ģʽ���ǰ�Ҫ���ӵĹ��ֱܷ���ڵ��������У���������������Ҫװ�εĶ��󣬵���Ҫִ��ʱ���ͻ��˾Ϳ�����ѡ��ء���˳���ʹ��װ�ι��ܽ��а�װ
*/

//һ������£��̳�ʵ����Ĺ�����չ
//װ��ģʽ  ���Զ�̬��һ�������ӹ���


//�������һ��Ӣ�۵���
class AbstractHero1 {
public:
	virtual void ShowStatus() = 0;
public:
	int mHp;
	int mMp;
	int mAt;
	int mDf;
};

// ����Ӣ��
class HeroA1 : public AbstractHero1 {
public:
	HeroA1() {
		mHp = 0;
		mMp = 0;
		mAt = 0;
		mDf = 0;
	}

	virtual void ShowStatus() {
		cout << "Ѫ����" << mHp << endl;
		cout << "ħ����" << mMp << endl;
		cout << "������" << mAt << endl;
		cout << "������" << mDf << endl;
	}
};

//Ӣ�۴���ĳ��װ��� ��ô������һ��Ӣ��
//����д����һ����������
//Ϊʲô��������Ļ����̳�Ӣ�۵Ļ��࣬����Ϊ����װ��֮����Ȼ��һ��Ӣ�ۣ�����Ӣ�۸þ��е�����
class AbstractEquipment :public AbstractHero1 {
public:
	AbstractEquipment(AbstractHero1* hero) {
		this->pHero = hero;
	}

	virtual void ShowStatus(){}

public:
	AbstractHero1* pHero;
};

//��ͽ
class KuangTuEquipment :public AbstractEquipment {
public:
	KuangTuEquipment(AbstractHero1* hero):AbstractEquipment(hero){}
	//���Ӷ��⹦��
	void AddKunagTu() {
		cout << "���Ͽ�ͽ .." << endl;
		this->mHp = this->pHero->mHp;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt;
		this->mDf = this->pHero->mDf + 30;
		delete this->pHero;
	}
	virtual void ShowStatus() {
		AddKunagTu();
		cout << "Ѫ����" << mHp << endl;
		cout << "ħ����" << mMp << endl;
		cout << "������" << mAt << endl;
		cout << "������" << mDf << endl;
	}
};

//�޾�֮��
class WuJinEquipment :public AbstractEquipment {
public:
	WuJinEquipment(AbstractHero1* hero) :AbstractEquipment(hero) {}
	//���Ӷ��⹦��
	void AddWuJin() {
		cout << "�����޾� .." << endl;
		this->mHp = this->pHero->mHp;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt + 100;
		this->mDf = this->pHero->mDf;
		delete this->pHero;
	}
	virtual void ShowStatus() {
		AddWuJin();
		cout << "Ѫ����" << mHp << endl;
		cout << "ħ����" << mMp << endl;
		cout << "������" << mAt << endl;
		cout << "������" << mDf << endl;
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
	// 1.����ԭ��
	//AbstractCalculator* ab = new PlusCalculator();
	//ab->setOperatorNumber(10, 10);
	//auto res = ab->getResult();
	//cout << res << endl;

	// 2.�����ط��� ����֪ʶԭ��
	//test01();
	//test02();

	// 3.�ϳɸ���ԭ��
	//Person* p1 = new Person();
	//p1->setCar(new DaZhong());
	//p1->Doufeng();

	// 4.������תԭ��
	//test3();

	// �򵥹���ģʽ
	//test03();

	// ��������ģʽ
	//test04();

	// ����ģʽ
	//A::getInstance();

	//Singleton_lazy* p1 =  Singleton_lazy::getInstance();
	//Singleton_lazy* p2 = Singleton_lazy::getInstance();
	//if (p1 == p2) {
	//	cout << "����ָ��ָ��ͬһ���ڴ�ռ䣬�ǵ��� ��" << endl;
	//}
	//else {
	//	cout << "���ǵ�����" << endl;
	//}

	//Singleton_hungry* p3 = Singleton_hungry::getInstance();
	//Singleton_hungry* p4 = Singleton_hungry::getInstance();
	//if (p3 == p4) {
	//	cout << "����ָ��ָ��ͬһ���ڴ�ռ䣬�ǵ��� ��" << endl;
	//}
	//else {
	//	cout << "���ǵ�����" << endl;
	//}

	// ����ģʽ
	// test05();

	// ���ģʽ
	//test06();
	//test07();

	//������ģʽ

	//vector<int> v;
	//for (int i = 0; i < 10; ++i) {
	//	v.push_back(i);
	//}
	//for_each(v.begin(), v.end(), MyBind2nd(10));

	//ģ�巽��ģʽ
	//test08();

	// ����ģʽ
	//test09();


	// ����ģʽ
	//test10();

	//�۲���ģʽ
	//test11();


	//װ��ģʽ
	test12();

	system("pause");
	return 0;
}