#include<iostream>

using namespace std;

// 双链表的定义
struct DoubleListNode
{
	int data;                //数据域
	DoubleListNode* next;    //下一个结点的指针域
	DoubleListNode* pre;     //上一个结点的指针域
};


// 双链表的初始化
bool DoubleListNodeInit(DoubleListNode* L) {
	if (!L) {
		cout << "双链表初始化失败 .." << endl;
		return false;
	}  

	L->next = NULL;  
	L->pre = NULL;         //初始化两个空指针
	L->data = INT32_MAX;
	return true;
}

// 双链表的头插法
// 头插法需要使用一个if，因为需要改变pre这个指针域
void create_doubleList_head(DoubleListNode* L, int num) {
	DoubleListNode* add_node;

	if (!L) {
		cout << "创建链表失败 .." << endl;
		return;
	}
	L->data = num;
	for (int i = 0; i < num; ++i) {
		add_node = new DoubleListNode();
		add_node->data = i;
		if (L->next == NULL) {
			add_node->next = NULL;
			add_node->pre = L;
			L->next = add_node;
		}
		else {
			L->next->pre = add_node;  //这个前向指针也必须改变
			add_node->next = L->next;
			add_node->pre = L;
			L->next = add_node;
		}
	}
	cout << "头插法创建双链表成功 .." << endl;
}

// 尾插法
// 这个创建的时候就不用if了，因为不用改变pre这个指针域
void create_doubleList_tail(DoubleListNode* L, int num) {
	DoubleListNode* add_node;
	DoubleListNode* add_node_2;
	add_node = L;
	if (!L) {
		cout << "创建链表失败 .." << endl;
		return;
	}
	L->data = num;

	for (int i = 0; i < num; ++i) {
		add_node_2 = new DoubleListNode();
		add_node_2->data = i;
		add_node_2->pre = add_node;
		add_node->next = add_node_2;
		add_node = add_node_2;
	}
	add_node->next = NULL;
	cout << "尾插法创建双链表成功 .." << endl;
}

// 双链表的插入
void insert_doubleList(DoubleListNode* L, int posi) {
	DoubleListNode* add_node;

	DoubleListNode* p = L;
	int j = 1;

	while (p && j < posi) {  //找到第(posi-1)的位置
		p = p->next;
		j++;
	}

	if (!p || j > posi) {
		cout << "插入失败 .." << endl;
	}
	else {
		add_node = new DoubleListNode();
		add_node->data = 35;
		add_node->pre = p;
		add_node->next = p->next;
		p->next->pre = add_node;
		p->next = add_node;
		L->data++;
		cout << "插入成功 .." << endl;
	}
}

// 双链表的删除
void delete_doubleList(DoubleListNode* L, int posi) {
	DoubleListNode* p, * q;
	p = L;
	int j = 1;

	while (p && j < posi) {
		p = p->next;
		j++;
	}

	if (!p || j > posi) {
		cout << "删除失败 .." << endl;
	}
	else {
		q = p->next;
		p->next = q->next;
		q->next->pre = p;
		delete q;
		L->data--;
		cout << "删除成功 .." << endl;
	}
}

void show_doubleList(DoubleListNode* L) {
	int doubleList_length = L->data;
	cout << "双链表的长度为: " << doubleList_length << endl;

	DoubleListNode* p;
	p = L->next;   //初始化一个链表结点并指向第一个结点，从而用这个来进行依次遍历

	while (p) {
		cout <<"当前的值："<< p->data << endl;
		p = p->next;
	}
	cout << "双链表展示完毕 .." << endl;
}

void inverse_show_doubleList(DoubleListNode* L) {
	int doubleList_length = L->data;
	cout << "双链表的长度为: " << doubleList_length << endl;

	DoubleListNode* p;
	p = L;

	while (p->next) {
		p = p->next;
	}

	while (p) {
		if (p->pre == NULL) {  //说明达到了head
			break;
		}
		cout << "当前的值：" << p->data << endl;
		p = p->pre;
	}
	cout << "双链表反向展示完毕 .." << endl;
}

void clear_doubleList(DoubleListNode* L) {
	DoubleListNode* p, * q;
	p = L->next;

	while (p) {
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
	cout << "双链表销毁成功 .." << endl;
}


int main() {
	DoubleListNode* head = new DoubleListNode();  //生成一个新节点作为头结点，用头指针L指向新节点
	DoubleListNodeInit(head);   //这样将head传入的话，head没有定义，需要把他的引用传进去
	//create_doubleList_head(head, 5); //双链表头插法

	create_doubleList_tail(head, 5);
	insert_doubleList(head, 2);

	show_doubleList(head);

	delete_doubleList(head, 2);
	show_doubleList(head);
	inverse_show_doubleList(head);

	clear_doubleList(head);

	system("pause");
	return 0;
}