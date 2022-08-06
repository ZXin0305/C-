#include<iostream>

using namespace std;

// ˫����Ķ���
struct DoubleListNode
{
	int data;                //������
	DoubleListNode* next;    //��һ������ָ����
	DoubleListNode* pre;     //��һ������ָ����
};


// ˫����ĳ�ʼ��
bool DoubleListNodeInit(DoubleListNode* L) {
	if (!L) {
		cout << "˫�����ʼ��ʧ�� .." << endl;
		return false;
	}  

	L->next = NULL;  
	L->pre = NULL;         //��ʼ��������ָ��
	L->data = INT32_MAX;
	return true;
}

// ˫�����ͷ�巨
// ͷ�巨��Ҫʹ��һ��if����Ϊ��Ҫ�ı�pre���ָ����
void create_doubleList_head(DoubleListNode* L, int num) {
	DoubleListNode* add_node;

	if (!L) {
		cout << "��������ʧ�� .." << endl;
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
			L->next->pre = add_node;  //���ǰ��ָ��Ҳ����ı�
			add_node->next = L->next;
			add_node->pre = L;
			L->next = add_node;
		}
	}
	cout << "ͷ�巨����˫����ɹ� .." << endl;
}

// β�巨
// ���������ʱ��Ͳ���if�ˣ���Ϊ���øı�pre���ָ����
void create_doubleList_tail(DoubleListNode* L, int num) {
	DoubleListNode* add_node;
	DoubleListNode* add_node_2;
	add_node = L;
	if (!L) {
		cout << "��������ʧ�� .." << endl;
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
	cout << "β�巨����˫����ɹ� .." << endl;
}

// ˫����Ĳ���
void insert_doubleList(DoubleListNode* L, int posi) {
	DoubleListNode* add_node;

	DoubleListNode* p = L;
	int j = 1;

	while (p && j < posi) {  //�ҵ���(posi-1)��λ��
		p = p->next;
		j++;
	}

	if (!p || j > posi) {
		cout << "����ʧ�� .." << endl;
	}
	else {
		add_node = new DoubleListNode();
		add_node->data = 35;
		add_node->pre = p;
		add_node->next = p->next;
		p->next->pre = add_node;
		p->next = add_node;
		L->data++;
		cout << "����ɹ� .." << endl;
	}
}

// ˫�����ɾ��
void delete_doubleList(DoubleListNode* L, int posi) {
	DoubleListNode* p, * q;
	p = L;
	int j = 1;

	while (p && j < posi) {
		p = p->next;
		j++;
	}

	if (!p || j > posi) {
		cout << "ɾ��ʧ�� .." << endl;
	}
	else {
		q = p->next;
		p->next = q->next;
		q->next->pre = p;
		delete q;
		L->data--;
		cout << "ɾ���ɹ� .." << endl;
	}
}

void show_doubleList(DoubleListNode* L) {
	int doubleList_length = L->data;
	cout << "˫����ĳ���Ϊ: " << doubleList_length << endl;

	DoubleListNode* p;
	p = L->next;   //��ʼ��һ�������㲢ָ���һ����㣬�Ӷ���������������α���

	while (p) {
		cout <<"��ǰ��ֵ��"<< p->data << endl;
		p = p->next;
	}
	cout << "˫����չʾ��� .." << endl;
}

void inverse_show_doubleList(DoubleListNode* L) {
	int doubleList_length = L->data;
	cout << "˫����ĳ���Ϊ: " << doubleList_length << endl;

	DoubleListNode* p;
	p = L;

	while (p->next) {
		p = p->next;
	}

	while (p) {
		if (p->pre == NULL) {  //˵���ﵽ��head
			break;
		}
		cout << "��ǰ��ֵ��" << p->data << endl;
		p = p->pre;
	}
	cout << "˫������չʾ��� .." << endl;
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
	cout << "˫�������ٳɹ� .." << endl;
}


int main() {
	DoubleListNode* head = new DoubleListNode();  //����һ���½ڵ���Ϊͷ��㣬��ͷָ��Lָ���½ڵ�
	DoubleListNodeInit(head);   //������head����Ļ���headû�ж��壬��Ҫ���������ô���ȥ
	//create_doubleList_head(head, 5); //˫����ͷ�巨

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