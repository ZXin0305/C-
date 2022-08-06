#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

typedef int TelemType;

// 二叉树的结构
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr){}  //无参构造
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//二叉树的创建 -- 以前序模式
TreeNode* create_binary_tree(string tree_name) {
	TreeNode* p;
	TelemType ch;
	cout << "请输入" << tree_name << "的值:";
	cin >> ch;
	if (ch == 0) {
		p = nullptr;   // 如果赋值为0的话，会直接让这个节点为空，然后直接返回，不会继续往下创建 。。
	}
	else {
		p = new TreeNode(ch);
		p->left = create_binary_tree("left");  // 继续创建左子树
		p->right = create_binary_tree("right");  // 继续创建右子树
	}
	return p; 
}

// 前序遍历  -- 递归版
// 前序遍历顺序为：左-中-右， 即：先访问根节点， 然后对左子树进行前序遍历， 再对右子树进行前序遍历（同样是中左右的顺序）
// 访问当前节点的值，函数调用自身去访问左节点，然后访问右节点，递归函数的主题内容就确定了
void helper(TreeNode* root, vector<int>& res) {

	// 如果节点为空，直接返回
	if (root == nullptr)
		return;

	// 将节点的值存放到数组中
	res.push_back(root->val);
	
	//// 访问当前节点的值
	//int num = root->val;

	// 前序遍历左子树
	helper(root->left, res);  // 这里调用自身，左孩子变为当前根节点的左子树的根节点，继续进行遍历

	// 前序遍历右子树
	helper(root->right, res);
}

// 考虑到节点为空的情况，为空时直接返回就可以，然后把读取的节点值存储起来，需要一个数组来存放数值。这样就完成了
vector<int> preorderTraversal(TreeNode* root) {
	// 二叉树前序遍历
	vector<int> res;  //定义数组
	helper(root, res);
	return res;
}

// 中序遍历 -- 递归版
// 顺序是：左-中-右。先访问中序遍历左子树，然后访问根节点，最后则是中序遍历右子树，可以看到和前序遍历相比，只是左节点和根节点互换了位置，仍然是递归的思想
// 前序遍历代码中是把访问根节点的值放在了第一条语句，那么在中序遍历中只需要把访问根节点的值这一语句和遍历左子树这一语句进行互换就好
void helper2(TreeNode* root, vector<int>& res) {

	//如果节点为空，则直接返回
	if (root == nullptr)
		return;
	
	// 中序遍历左子树
	helper2(root->left, res);

	// 将节点的值存放到数组中
	res.push_back(root->val);

	// 中序遍历右子树
	helper2(root->right, res);
}

vector<int> inorderTraversal(TreeNode* root) {
	//二叉树中序遍历
	vector<int> res;
	helper2(root, res);
	return res;
}

// 后序遍历 -- 递归版
// 后序遍历顺序：左-右-中。先后序遍历左子树，再后序遍历右子树，最后访问根节点。
// 这个遍历顺序就是将访问根节点的值放到遍历左子树和遍历右子树的后面

void helper3(TreeNode* root, vector<int>& res) {

	if (root == NULL)
		return;

	helper3(root->left, res);  // 遍历左子树
	helper3(root->right, res);  // 遍历右子树
	res.push_back(root->val);  // 两边都遍历完成之后，再访问根节点的值
}

vector<int> postorderTraversal(TreeNode* root) {

	vector<int> res;
	if (root == nullptr)
		return res;

	helper3(root, res);
	return res;
}

/*     迭代版      */
//前序遍历迭代版
//在递归版本中，思路是访问根节点的值，再去遍历左右子树，来循环调用自身，这本身是维护了一个隐形的栈
//现在我们自己维护一个栈，就是迭代的版本了
//前序遍历节点顺序为：中左右，从树的根节点开始，一直向左前进，达到最左值，遇到的节点统一放回栈中，同时也可以把该节点的值取出并存储
//因为在这一过程中我们没有考虑右孩子，如果一个节点有孩子，那么他作为父节点必然是在孩子访问之前被访问，如果该节点没有孩子，
//那么他是他的父节点的左孩子，此时父节点已经访问过，这时应该访问左孩子的值。

vector<int> preorderTraversal_1(TreeNode* root) {
	// 二叉树前序遍历迭代版
	vector<int> res;  //定义数组
	if (root == nullptr)
		return res;

	stack<TreeNode*> stk;  // 自己维护一个栈,根据栈的先进后出的性质，在每次迭代时，依次取出栈顶元素，去遍历得到右孩子
	while (!stk.empty() || root != nullptr) {
		while (root != nullptr) {
			res.push_back(root->val);  // 存储节点的值
			stk.push(root);            //当前节点入栈
			root = root->left;         //寻找左节点
		}
		//上述while循环结束，此时到达二叉树的最左端

		root = stk.top();              // 取栈顶元素，便于后续取该节点的右孩子
		stk.pop();                     // 出栈
		root = root->right;           //  准备遍历右节点
	}
	return res;
}

// 中序遍历迭代版：左-中-右
// 在递归版本中，中序遍历相对于前序遍历仅仅调换了一句语句的位置，那么在非递归中序遍历中，依然可以按照前序遍历的思想，
// 但是有一点细节要调整一下，前序遍历的节点顺序为根左右，中序遍历的节点顺序为左根右，在前序遍历向左走的过程中，
// 遇到一个节点都可以直接访问存储，但是在这里就不能了，因为你无法确定当前节点是否还有左孩子，
// 如果没有左孩子，该节点可以直接访问，但是若有左孩子，则左孩子应该先于该节点被访问，
// 所以我们的任务是首先找到树的最左侧，将中途遇到的节点全部入栈，栈顶元素必然是最左侧的节点，此时可以正常访问。
// 所以中序遍历的非递归版本中，相比于前序遍历，也仅仅是改动语句的位置即可。

vector<int> inorderTraversal_1(TreeNode* root) {
	// 二叉树迭代版中序遍历
	vector<int> res;
	if (root == nullptr)
		return res;

	stack<TreeNode*> stk;  // 自己维护的一个栈
	while (!stk.empty() || root != nullptr) {
		while (root != nullptr) {
			stk.push(root);  // 将当前节点入栈，此时先不能访问根节点的值，要先判定没有左孩子了
			root = root->left;  // 寻找左节点
		}
		//上述while循环结束，表示已经走到二叉树的最左侧
		//中序遍历，先访问左节点，此时就可以取出栈顶元素进行访问了

		root = stk.top();  //取出栈顶元素。该元素必定是最左侧的节点。记住，这里遍历时取出来就要出栈，这样才能得到下一个孩子的位置
		stk.pop();  //出栈
		res.push_back(root->val);  //存储值！！！
		root = root->right;  // 转向访问右节点
	}

	return res;
}

// 后序遍历迭代版
// 顺序：左-右-中
// 后序遍历的节点顺序为左右根，和前面两种遍历方式相比，这三种方式都有一个共同点，那就是左节点都是在右节点之前被访问，而且左节点在根节点之前，这和中序遍历很相似，只是根节点和右节点的顺序不同，那么按照前两种方式，
// 所以后序遍历的非递归算法的大致轮廓仍然是向左走到尽头，然后访问节点的值

vector<int> postorderTraversal_1(TreeNode* root) {
	// 后序遍历迭代版
	vector<int> res;  
	if (root == nullptr)
		return res;

	stack<TreeNode*> stk;
	TreeNode* flag = nullptr;  // 访问标识
	while (!stk.empty() || root != nullptr) {
		while (root != nullptr) {
			stk.push(root);     // 将当前节点入栈
			root = root->left;  // 寻找左节点
		}

		root = stk.top();   //取出栈顶元素，该元素必然是最左侧的节点
		stk.pop();          // 出栈

		//如果右孩子为空，或者右孩子已被访问过，则访问当前节点
		if (root->right == nullptr || root->right == flag) {
			res.push_back(root->val);  
			flag = root;    //当前节点被访问后，将flag指向该节点，
			root = nullptr;
		}
		else {
			//右孩子不为空，或者右孩子未被访问过，则该节点不能访问
			//需要将其入栈，待右孩子访问过后才能重新出栈访问
			stk.push(root);
			root = root->right;  // 访问右节点
		}
	}
	return res;

}

// 层序遍历，顾名思义就是一层一层的去遍历
// 实现层序遍历，要用到队列
//基本思想：
//1.先将根节点放到队列中
//2.根节点弹出队列，然后将根节点的左、右儿子入队
//3.弹出左儿子，放入左儿子的左右儿子
//4.弹出右儿子，放入右儿子的左右儿子
//5.重复3、4步
vector<int> levelorderTraversal(TreeNode* root) {
	queue<TreeNode*> q;
	vector<int> res;
	TreeNode* tmp;
	if (root == nullptr)
		return res;
	
	q.push(root);           // 先把最上面的root入栈
	while (!q.empty()) {
		tmp = q.front();    // 第一个循环，先取出root,并在下一步弹出
		q.pop();            // 弹出
		res.push_back(tmp->val);  // 取出元素值

		// 压入左右孩子
		if (tmp->left != nullptr)
			q.push(tmp->left);
		if (tmp->right != nullptr)
			q.push(tmp->right);
		
	}
	return res;
}

// 代码随想录中的，更加好的层序遍历，可以将每一层的分隔开，主要是利用了队列的大小是在不断变化的这个原理！！！
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<vector<int>> result;
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
			// 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
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

	/*  测试：
	*   请输入root的值:1
		请输入left的值:2
		请输入left的值:3
		请输入left的值:0
		请输入right的值:0
		请输入right的值:4
		请输入left的值:0
		请输入right的值:0
		请输入right的值:5
		请输入left的值:6
		请输入left的值:0
		请输入right的值:0
		请输入right的值:7
		请输入left的值:0
		请输入right的值:0
		创建成功 ..
		前序遍历：
		1 2 3 4 5 6 7
		中序遍历：
		3 2 4 1 6 5 7
		后序遍历：
		3 4 2 6 7 5 1
	*/

	TreeNode* root = nullptr;
	root = create_binary_tree("root");
	cout << "创建成功 .." << endl;

	vector<TelemType> res;
	// 前序遍历
	res = preorderTraversal(root);
	cout << "前序遍历递归版：" << endl;
	for (auto xx : res)
		cout << xx << " ";
	cout << endl;

	vector<TelemType> res1;
	//中序遍历
	cout << "中序遍历递归版：" << endl;
	res1 = inorderTraversal(root);
	for (auto xx : res1)
		cout << xx << " ";
	cout << endl;

	vector<TelemType> res2;
	//后序遍历
	cout << "后序遍历递归版：" << endl;
	res2 = postorderTraversal(root);
	for (auto xx : res2)
		cout << xx << " ";
	cout << endl;

	// 迭代版
	vector<TelemType> res3;
	cout << "前序遍历迭代版：" << endl;
	res3 = preorderTraversal_1(root);
	for (auto xx : res3)
		cout << xx << " ";
	cout << endl;

	vector<TelemType> res4;
	cout << "中序遍历迭代版：" << endl;
	res4 = inorderTraversal_1(root);
	for (auto xx : res4)
		cout << xx << " ";
	cout << endl;

	vector<TelemType> res5;
	cout << "后序遍历迭代版：" << endl;
	res5 = postorderTraversal_1(root);
	for (auto xx : res5)
		cout << xx << " ";
	cout << endl;

	vector<TelemType> res6;
	cout << "层序遍历：" << endl;
	res6 = levelorderTraversal(root);
	for (auto xx : res6)
		cout << xx << " ";
	cout << endl;

	system("pause");
	return 0;
}