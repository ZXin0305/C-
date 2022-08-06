/*
* 代码随想录中的链表
*/
#include<iostream>
#include<time.h>
using namespace std;

// 单链表的定义
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL){}  //节点的构造函数  不定义也是可以的，C++默认生成一个构造函数
										   // 但是默认的构造函数不会初始化任何成员变量
	ListNode(){}   //这个就相当于默认构造函数
};

// 头插法，最先添加的在最后
void create_list_head(ListNode* L, int num) {
	ListNode* add_node;
	srand(time(0));
	L->next = NULL;
	L->val = num;  // 表明的是这个链表中具有的长度
	for (int i = 0; i < num; ++i) {
		add_node = new ListNode();
		/*add_node->val = rand() % 100 + 1;*/
		add_node->val = i;
		add_node->next = L->next;
		L->next = add_node;
	}
}

// 尾插法,最先添加的在最前面
void create_list_tail(ListNode* L, int num) {
	ListNode* p, *r;
	r = L;  // r为指向尾部的结点
	L->val = num;
	for (int i = 0; i < num; ++i) {
		p = new ListNode();
		p->val = i;
		r->next = p;
		r = p;      // 主要是这一点，尾插法需要将r用p替换，从而使结点依次进行添加
	}
	r->next = NULL;

}

void show_node(ListNode* L){
	int list_length = L->val;
	cout << "这个链表的长度是: " << list_length << endl;
	ListNode* p;
	p = L->next;  //初始化一个链表结点并指向第一个结点，从而用这个来进行依次遍历

	while (p) {
		cout << "当前的值：" << p->val << endl;
		p = p->next;
	}
	cout << "展示结束 .." << endl;
	
}

//单链表的读取
int get_elem(ListNode* L, int i) {
	int j;
	ListNode* p;
	p = L->next;
	j = 1;  // j是一个计数器，使其为1使跳过了头结点（索引相当于0）

	while (p && j < i) {
		p = p->next;   //指向下一个结点
		++j;
	}

	if (!p || j > i)
		return -1;

	return p->val;

}

//单链表的插入
void insert_node(ListNode* L, int posi) {
	int j;
	ListNode* p, * s;
	p = L;
	j = 1;

	while (p && j < posi) {   //寻找第i-1个结点
		p = p->next;
		++j;
	}

	if (!p || j > posi)
		cout << "插入失败" << endl;
	else {
		// 生成一个新的结点进行插入
		s = new ListNode();
		s->val = 35;
		s->next = p->next;
		p->next = s;
		L->val++;
		cout << "插入成功 .." << endl;
	}
}

// 单链表的删除
void list_delete(ListNode* L, int posi) {
	int j;
	ListNode* p, * q;
	p = L;
	j = 1;

	while (p->next && j < posi) {  //这里使用p->next是为了防止L中只有头结点，并没有其他的结点
		p = p->next;
		++j;
	}

	if (!(p->next) || j > posi)
		cout << "删除失败 .." << endl;
	else {
		q = p->next;
		p->next = p->next->next;  // 或者 q->next
		int ee = q->val;
		delete q;  // 系统回收结点，释放内存
		L->val--;
		cout << "删除成功 .." << endl;
	}
}

// 单链表的清空
void clear_list(ListNode* L) {

	ListNode* p, * q;
	p = L->next;
	while (p) {
		q = p->next;
		delete p;
		p = q;
	}

	L->next = NULL;  //已经全部删除完毕
	cout << "链表删除完成 .." << endl;

}

int main() {
	ListNode* head = new ListNode();   // 自定义的构造函数
	ListNode* head1 = new ListNode();   // 默认构造函数在初始化的时候不能直接给变量赋值
	//head1->val = 10;
	//cout << head->val << endl;

	//链表的创建
	//头插法
	create_list_head(head, 10);
	show_node(head);

	//尾插法
	create_list_tail(head1, 10);
	//show_node(head1);

	//int i = 8;
	//cout << "获取得到的结点的元素为: " << get_elem(head, i) << endl;

	insert_node(head, 5);
	show_node(head);

	list_delete(head, 5);
	show_node(head);

	clear_list(head);

	system("pause");
	return 0;
}