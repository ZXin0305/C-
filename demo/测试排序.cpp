#include<iostream>
#include<vector>
using namespace std;
// 堆排序

// 堆排序的逻辑
void max_heapify(int arr[], int start, int end) {
	int dad = start;
	int son = 2 * dad + 1;
	while (son <= end) {
		if (son + 1 <= end && arr[son] < arr[son + 1]) {
			son++;
		}

		if (arr[dad] > arr[son]) {
			return;
		}
		else {
			swap(arr[dad], arr[son]);
			dad = son;
			son = 2 * dad + 1;
		}
	}
}

// 堆排序的函数体
void heap_sort(int arr[], int len) {
	for (int i = len / 2 - 1; i >= 0; --i) {
		max_heapify(arr, i, len - 1);
	}

	for (int i = len - 1; i > 0; --i) {
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}

// 快排(递归)

// 快排的逻辑(萝卜填坑)
// 每次给定一个区间，在这个区间中选择一个基准值（通常是区间的开头）
// 经过排序逻辑，让大于和小于这个基准值的数据，排布在这个基准值的两边
int AdjustArray(vector<int>& nums, int left, int right) {
	int i = left, j = right;
	int X = nums[left];    // 基准值

	while (i < j) {
		while (i < j && nums[j] >= X) {
			j--;
		}
		if (i < j) {
			nums[i] = nums[j];
			i++; 
		}

		while (i < j && nums[i] < X) {
			i++;
		}
		if (i < j) {
			nums[j] = nums[i];
			j--;
		}
	}

	nums[i] = X;
	return i;
}

// 快排的函数体
void quick_sort(vector<int>& nums, int left, int right) {

	if (left < right) {  // 递归的终止条件
		int i = AdjustArray(nums, left, right);
		quick_sort(nums, left, i - 1);  
		quick_sort(nums, i + 1, right);
	}
}

// 归并排序(递归)

// 归并排序的逻辑
void Merge(vector<int>& nums, vector<int>& left_v, int left_num, vector<int>& right_v, int right_num) {
	int count = 0;
	int i, j;

	for (i = 0, j = 0; i < left_num && j < right_num;) {
		if (left_v[i] < right_v[j])
			nums[count++] = left_v[i++];
		else
			nums[count++] = right_v[j++];
	}

	if (i != left_num) {
		for (int k = i; k < left_num; ++k)
			nums[count++] = left_v[k];
	}
	else if (j != right_num) {
		for (int k = j; k < right_num; ++k)
			nums[count++] = right_v[k];
	}
}


// 归并排序的函数体
void MergeSort(vector<int>& nums, int n) {
	int mid;
	if (n < 2)   // 递归的终止条件
		return;

	mid = n / 2;

	vector<int> left_v(mid), right_v(n - mid);

	//left_v.assign(nums.begin(), nums.begin() + mid);
	//right_v.assign(nums.begin() + mid, nums.end());

	for (int i = 0; i < mid; ++i)
		left_v[i] = nums[i];

	for (int j = mid; j < n; ++j)
		right_v[j - mid] = nums[j];

	MergeSort(left_v, mid);
	MergeSort(right_v, n - mid);

	Merge(nums, left_v, mid, right_v, n - mid);

}


int main() {

	vector<int> nums{ 10,2,3,4,1,5,6,1 };

	MergeSort(nums, nums.size());

	for (auto xx : nums)
		cout << xx << " ";
	cout << endl;

	system("pause");
	return 0;
}


//if (root == nullptr) return 0;
//
//if (root->left && !root->left && !root->right)
//sum += root->val;
//int sum_left = sumOfLeftLeaves(root->left);
//int sum_right = sumOfLeftLeaves(root->right);
//
//return sum_left + sum_right;