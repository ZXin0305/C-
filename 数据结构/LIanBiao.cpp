/*
* ��������¼�е�����
*/
#include<iostream>
#include<time.h>
using namespace std;

// ������Ķ���
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL){}  //�ڵ�Ĺ��캯��  ������Ҳ�ǿ��Եģ�C++Ĭ������һ�����캯��
										   // ����Ĭ�ϵĹ��캯�������ʼ���κγ�Ա����
	ListNode(){}   //������൱��Ĭ�Ϲ��캯��
};

// ͷ�巨��������ӵ������
void create_list_head(ListNode* L, int num) {
	ListNode* add_node;
	srand(time(0));
	L->next = NULL;
	L->val = num;  // ����������������о��еĳ���
	for (int i = 0; i < num; ++i) {
		add_node = new ListNode();
		/*add_node->val = rand() % 100 + 1;*/
		add_node->val = i;
		add_node->next = L->next;
		L->next = add_node;
	}
}

// β�巨,������ӵ�����ǰ��
void create_list_tail(ListNode* L, int num) {
	ListNode* p, *r;
	r = L;  // rΪָ��β���Ľ��
	L->val = num;
	for (int i = 0; i < num; ++i) {
		p = new ListNode();
		p->val = i;
		r->next = p;
		r = p;      // ��Ҫ����һ�㣬β�巨��Ҫ��r��p�滻���Ӷ�ʹ������ν������
	}
	r->next = NULL;

}

void show_node(ListNode* L){
	int list_length = L->val;
	cout << "�������ĳ�����: " << list_length << endl;
	ListNode* p;
	p = L->next;  //��ʼ��һ�������㲢ָ���һ����㣬�Ӷ���������������α���

	while (p) {
		cout << "��ǰ��ֵ��" << p->val << endl;
		p = p->next;
	}
	cout << "չʾ���� .." << endl;
	
}

//������Ķ�ȡ
int get_elem(ListNode* L, int i) {
	int j;
	ListNode* p;
	p = L->next;
	j = 1;  // j��һ����������ʹ��Ϊ1ʹ������ͷ��㣨�����൱��0��

	while (p && j < i) {
		p = p->next;   //ָ����һ�����
		++j;
	}

	if (!p || j > i)
		return -1;

	return p->val;

}

//������Ĳ���
void insert_node(ListNode* L, int posi) {
	int j;
	ListNode* p, * s;
	p = L;
	j = 1;

	while (p && j < posi) {   //Ѱ�ҵ�i-1�����
		p = p->next;
		++j;
	}

	if (!p || j > posi)
		cout << "����ʧ��" << endl;
	else {
		// ����һ���µĽ����в���
		s = new ListNode();
		s->val = 35;
		s->next = p->next;
		p->next = s;
		L->val++;
		cout << "����ɹ� .." << endl;
	}
}

// �������ɾ��
void list_delete(ListNode* L, int posi) {
	int j;
	ListNode* p, * q;
	p = L;
	j = 1;

	while (p->next && j < posi) {  //����ʹ��p->next��Ϊ�˷�ֹL��ֻ��ͷ��㣬��û�������Ľ��
		p = p->next;
		++j;
	}

	if (!(p->next) || j > posi)
		cout << "ɾ��ʧ�� .." << endl;
	else {
		q = p->next;
		p->next = p->next->next;  // ���� q->next
		int ee = q->val;
		delete q;  // ϵͳ���ս�㣬�ͷ��ڴ�
		L->val--;
		cout << "ɾ���ɹ� .." << endl;
	}
}

// ����������
void clear_list(ListNode* L) {

	ListNode* p, * q;
	p = L->next;
	while (p) {
		q = p->next;
		delete p;
		p = q;
	}

	L->next = NULL;  //�Ѿ�ȫ��ɾ�����
	cout << "����ɾ����� .." << endl;

}

int main() {
	ListNode* head = new ListNode();   // �Զ���Ĺ��캯��
	ListNode* head1 = new ListNode();   // Ĭ�Ϲ��캯���ڳ�ʼ����ʱ����ֱ�Ӹ�������ֵ
	//head1->val = 10;
	//cout << head->val << endl;

	//����Ĵ���
	//ͷ�巨
	create_list_head(head, 10);
	show_node(head);

	//β�巨
	create_list_tail(head1, 10);
	//show_node(head1);

	//int i = 8;
	//cout << "��ȡ�õ��Ľ���Ԫ��Ϊ: " << get_elem(head, i) << endl;

	insert_node(head, 5);
	show_node(head);

	list_delete(head, 5);
	show_node(head);

	clear_list(head);

	system("pause");
	return 0;
}