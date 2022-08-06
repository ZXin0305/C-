#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

typedef int TelemType;

// �������Ľṹ
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr){}  //�޲ι���
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//�������Ĵ��� -- ��ǰ��ģʽ
TreeNode* create_binary_tree(string tree_name) {
	TreeNode* p;
	TelemType ch;
	cout << "������" << tree_name << "��ֵ:";
	cin >> ch;
	if (ch == 0) {
		p = nullptr;   // �����ֵΪ0�Ļ�����ֱ��������ڵ�Ϊ�գ�Ȼ��ֱ�ӷ��أ�����������´��� ����
	}
	else {
		p = new TreeNode(ch);
		p->left = create_binary_tree("left");  // ��������������
		p->right = create_binary_tree("right");  // ��������������
	}
	return p; 
}

// ǰ�����  -- �ݹ��
// ǰ�����˳��Ϊ����-��-�ң� �����ȷ��ʸ��ڵ㣬 Ȼ�������������ǰ������� �ٶ�����������ǰ�������ͬ���������ҵ�˳��
// ���ʵ�ǰ�ڵ��ֵ��������������ȥ������ڵ㣬Ȼ������ҽڵ㣬�ݹ麯�����������ݾ�ȷ����
void helper(TreeNode* root, vector<int>& res) {

	// ����ڵ�Ϊ�գ�ֱ�ӷ���
	if (root == nullptr)
		return;

	// ���ڵ��ֵ��ŵ�������
	res.push_back(root->val);
	
	//// ���ʵ�ǰ�ڵ��ֵ
	//int num = root->val;

	// ǰ�����������
	helper(root->left, res);  // ��������������ӱ�Ϊ��ǰ���ڵ���������ĸ��ڵ㣬�������б���

	// ǰ�����������
	helper(root->right, res);
}

// ���ǵ��ڵ�Ϊ�յ������Ϊ��ʱֱ�ӷ��ؾͿ��ԣ�Ȼ��Ѷ�ȡ�Ľڵ�ֵ�洢��������Ҫһ�������������ֵ�������������
vector<int> preorderTraversal(TreeNode* root) {
	// ������ǰ�����
	vector<int> res;  //��������
	helper(root, res);
	return res;
}

// ������� -- �ݹ��
// ˳���ǣ���-��-�ҡ��ȷ������������������Ȼ����ʸ��ڵ㣬�������������������������Կ�����ǰ�������ȣ�ֻ����ڵ�͸��ڵ㻥����λ�ã���Ȼ�ǵݹ��˼��
// ǰ������������ǰѷ��ʸ��ڵ��ֵ�����˵�һ����䣬��ô�����������ֻ��Ҫ�ѷ��ʸ��ڵ��ֵ��һ���ͱ�����������һ�����л����ͺ�
void helper2(TreeNode* root, vector<int>& res) {

	//����ڵ�Ϊ�գ���ֱ�ӷ���
	if (root == nullptr)
		return;
	
	// �������������
	helper2(root->left, res);

	// ���ڵ��ֵ��ŵ�������
	res.push_back(root->val);

	// �������������
	helper2(root->right, res);
}

vector<int> inorderTraversal(TreeNode* root) {
	//�������������
	vector<int> res;
	helper2(root, res);
	return res;
}

// ������� -- �ݹ��
// �������˳����-��-�С��Ⱥ���������������ٺ�������������������ʸ��ڵ㡣
// �������˳����ǽ����ʸ��ڵ��ֵ�ŵ������������ͱ����������ĺ���

void helper3(TreeNode* root, vector<int>& res) {

	if (root == NULL)
		return;

	helper3(root->left, res);  // ����������
	helper3(root->right, res);  // ����������
	res.push_back(root->val);  // ���߶��������֮���ٷ��ʸ��ڵ��ֵ
}

vector<int> postorderTraversal(TreeNode* root) {

	vector<int> res;
	if (root == nullptr)
		return res;

	helper3(root, res);
	return res;
}

/*     ������      */
//ǰ�����������
//�ڵݹ�汾�У�˼·�Ƿ��ʸ��ڵ��ֵ����ȥ����������������ѭ�����������Ȿ����ά����һ�����ε�ջ
//���������Լ�ά��һ��ջ�����ǵ����İ汾��
//ǰ������ڵ�˳��Ϊ�������ң������ĸ��ڵ㿪ʼ��һֱ����ǰ�����ﵽ����ֵ�������Ľڵ�ͳһ�Ż�ջ�У�ͬʱҲ���԰Ѹýڵ��ֵȡ�����洢
//��Ϊ����һ����������û�п����Һ��ӣ����һ���ڵ��к��ӣ���ô����Ϊ���ڵ��Ȼ���ں��ӷ���֮ǰ�����ʣ�����ýڵ�û�к��ӣ�
//��ô�������ĸ��ڵ�����ӣ���ʱ���ڵ��Ѿ����ʹ�����ʱӦ�÷������ӵ�ֵ��

vector<int> preorderTraversal_1(TreeNode* root) {
	// ������ǰ�����������
	vector<int> res;  //��������
	if (root == nullptr)
		return res;

	stack<TreeNode*> stk;  // �Լ�ά��һ��ջ,����ջ���Ƚ���������ʣ���ÿ�ε���ʱ������ȡ��ջ��Ԫ�أ�ȥ�����õ��Һ���
	while (!stk.empty() || root != nullptr) {
		while (root != nullptr) {
			res.push_back(root->val);  // �洢�ڵ��ֵ
			stk.push(root);            //��ǰ�ڵ���ջ
			root = root->left;         //Ѱ����ڵ�
		}
		//����whileѭ����������ʱ����������������

		root = stk.top();              // ȡջ��Ԫ�أ����ں���ȡ�ýڵ���Һ���
		stk.pop();                     // ��ջ
		root = root->right;           //  ׼�������ҽڵ�
	}
	return res;
}

// ������������棺��-��-��
// �ڵݹ�汾�У�������������ǰ���������������һ������λ�ã���ô�ڷǵݹ���������У���Ȼ���԰���ǰ�������˼�룬
// ������һ��ϸ��Ҫ����һ�£�ǰ������Ľڵ�˳��Ϊ�����ң���������Ľڵ�˳��Ϊ����ң���ǰ����������ߵĹ����У�
// ����һ���ڵ㶼����ֱ�ӷ��ʴ洢������������Ͳ����ˣ���Ϊ���޷�ȷ����ǰ�ڵ��Ƿ������ӣ�
// ���û�����ӣ��ýڵ����ֱ�ӷ��ʣ������������ӣ�������Ӧ�����ڸýڵ㱻���ʣ�
// �������ǵ������������ҵ���������࣬����;�����Ľڵ�ȫ����ջ��ջ��Ԫ�ر�Ȼ�������Ľڵ㣬��ʱ�����������ʡ�
// ������������ķǵݹ�汾�У������ǰ�������Ҳ�����ǸĶ�����λ�ü��ɡ�

vector<int> inorderTraversal_1(TreeNode* root) {
	// �������������������
	vector<int> res;
	if (root == nullptr)
		return res;

	stack<TreeNode*> stk;  // �Լ�ά����һ��ջ
	while (!stk.empty() || root != nullptr) {
		while (root != nullptr) {
			stk.push(root);  // ����ǰ�ڵ���ջ����ʱ�Ȳ��ܷ��ʸ��ڵ��ֵ��Ҫ���ж�û��������
			root = root->left;  // Ѱ����ڵ�
		}
		//����whileѭ����������ʾ�Ѿ��ߵ��������������
		//����������ȷ�����ڵ㣬��ʱ�Ϳ���ȡ��ջ��Ԫ�ؽ��з�����

		root = stk.top();  //ȡ��ջ��Ԫ�ء���Ԫ�رض��������Ľڵ㡣��ס���������ʱȡ������Ҫ��ջ���������ܵõ���һ�����ӵ�λ��
		stk.pop();  //��ջ
		res.push_back(root->val);  //�洢ֵ������
		root = root->right;  // ת������ҽڵ�
	}

	return res;
}

// �������������
// ˳����-��-��
// ��������Ľڵ�˳��Ϊ���Ҹ�����ǰ�����ֱ�����ʽ��ȣ������ַ�ʽ����һ����ͬ�㣬�Ǿ�����ڵ㶼�����ҽڵ�֮ǰ�����ʣ�������ڵ��ڸ��ڵ�֮ǰ�����������������ƣ�ֻ�Ǹ��ڵ���ҽڵ��˳��ͬ����ô����ǰ���ַ�ʽ��
// ���Ժ�������ķǵݹ��㷨�Ĵ���������Ȼ�������ߵ���ͷ��Ȼ����ʽڵ��ֵ

vector<int> postorderTraversal_1(TreeNode* root) {
	// �������������
	vector<int> res;  
	if (root == nullptr)
		return res;

	stack<TreeNode*> stk;
	TreeNode* flag = nullptr;  // ���ʱ�ʶ
	while (!stk.empty() || root != nullptr) {
		while (root != nullptr) {
			stk.push(root);     // ����ǰ�ڵ���ջ
			root = root->left;  // Ѱ����ڵ�
		}

		root = stk.top();   //ȡ��ջ��Ԫ�أ���Ԫ�ر�Ȼ�������Ľڵ�
		stk.pop();          // ��ջ

		//����Һ���Ϊ�գ������Һ����ѱ����ʹ�������ʵ�ǰ�ڵ�
		if (root->right == nullptr || root->right == flag) {
			res.push_back(root->val);  
			flag = root;    //��ǰ�ڵ㱻���ʺ󣬽�flagָ��ýڵ㣬
			root = nullptr;
		}
		else {
			//�Һ��Ӳ�Ϊ�գ������Һ���δ�����ʹ�����ýڵ㲻�ܷ���
			//��Ҫ������ջ�����Һ��ӷ��ʹ���������³�ջ����
			stk.push(root);
			root = root->right;  // �����ҽڵ�
		}
	}
	return res;

}

// �������������˼�����һ��һ���ȥ����
// ʵ�ֲ��������Ҫ�õ�����
//����˼�룺
//1.�Ƚ����ڵ�ŵ�������
//2.���ڵ㵯�����У�Ȼ�󽫸��ڵ�����Ҷ������
//3.��������ӣ���������ӵ����Ҷ���
//4.�����Ҷ��ӣ������Ҷ��ӵ����Ҷ���
//5.�ظ�3��4��
vector<int> levelorderTraversal(TreeNode* root) {
	queue<TreeNode*> q;
	vector<int> res;
	TreeNode* tmp;
	if (root == nullptr)
		return res;
	
	q.push(root);           // �Ȱ��������root��ջ
	while (!q.empty()) {
		tmp = q.front();    // ��һ��ѭ������ȡ��root,������һ������
		q.pop();            // ����
		res.push_back(tmp->val);  // ȡ��Ԫ��ֵ

		// ѹ�����Һ���
		if (tmp->left != nullptr)
			q.push(tmp->left);
		if (tmp->right != nullptr)
			q.push(tmp->right);
		
	}
	return res;
}

// ��������¼�еģ����ӺõĲ�����������Խ�ÿһ��ķָ�������Ҫ�������˶��еĴ�С���ڲ��ϱ仯�����ԭ������
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<vector<int>> result;
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
			// ����һ��Ҫʹ�ù̶���Сsize����Ҫʹ��que.size()����Ϊque.size�ǲ��ϱ仯��
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				vec.push_back(node->val);
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
			result.push_back(vec);
		}
		return result;
	}
};


int main() {

	/*  ���ԣ�
	*   ������root��ֵ:1
		������left��ֵ:2
		������left��ֵ:3
		������left��ֵ:0
		������right��ֵ:0
		������right��ֵ:4
		������left��ֵ:0
		������right��ֵ:0
		������right��ֵ:5
		������left��ֵ:6
		������left��ֵ:0
		������right��ֵ:0
		������right��ֵ:7
		������left��ֵ:0
		������right��ֵ:0
		�����ɹ� ..
		ǰ�������
		1 2 3 4 5 6 7
		���������
		3 2 4 1 6 5 7
		���������
		3 4 2 6 7 5 1
	*/

	TreeNode* root = nullptr;
	root = create_binary_tree("root");
	cout << "�����ɹ� .." << endl;

	vector<TelemType> res;
	// ǰ�����
	res = preorderTraversal(root);
	cout << "ǰ������ݹ�棺" << endl;
	for (auto xx : res)
		cout << xx << " ";
	cout << endl;

	vector<TelemType> res1;
	//�������
	cout << "��������ݹ�棺" << endl;
	res1 = inorderTraversal(root);
	for (auto xx : res1)
		cout << xx << " ";
	cout << endl;

	vector<TelemType> res2;
	//�������
	cout << "��������ݹ�棺" << endl;
	res2 = postorderTraversal(root);
	for (auto xx : res2)
		cout << xx << " ";
	cout << endl;

	// ������
	vector<TelemType> res3;
	cout << "ǰ����������棺" << endl;
	res3 = preorderTraversal_1(root);
	for (auto xx : res3)
		cout << xx << " ";
	cout << endl;

	vector<TelemType> res4;
	cout << "������������棺" << endl;
	res4 = inorderTraversal_1(root);
	for (auto xx : res4)
		cout << xx << " ";
	cout << endl;

	vector<TelemType> res5;
	cout << "������������棺" << endl;
	res5 = postorderTraversal_1(root);
	for (auto xx : res5)
		cout << xx << " ";
	cout << endl;

	vector<TelemType> res6;
	cout << "���������" << endl;
	res6 = levelorderTraversal(root);
	for (auto xx : res6)
		cout << xx << " ";
	cout << endl;

	system("pause");
	return 0;
}