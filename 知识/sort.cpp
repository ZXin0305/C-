#include<iostream>
#include<vector>
using namespace std;

//快排
int AdjustArray(vector<int>& nums, int left, int right);
void quick_sort(vector<int>& nums, int left, int right);

//归并
void MergeSort(vector<int>& nums, int n);
void Merge(vector<int>& nums, vector<int>& left_v, int left_num, vector<int>& right_v, int right_num);

//堆排序
void heap_sort(int arr[], int len);

int main() {
	/*
	插入排序
		最差时间复杂度：O(n^2)
		最优时间复杂度：O(n)
		平均时间复杂度：O(n^2)
		稳定性：稳定

		1.从第一个元素开始，该元素可以认为已被排序
		2.取出下一个元素，在已经排序的元素序列中从后向前扫描
		3.如果该元素（已排序）大于新元素，将该元素移到下一个位置
		4.重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
		5.将新元素插入到该位置后，重复2~5
	*/

	//vector<int> v1{1,10,22,3,4,4,6};
	//int n = v1.size();
	//for (int i = 1; i < n; ++i) {
	//	int key = v1[i];
	//	int search_idx = i - 1;
	//	while (search_idx >= 0 && v1[search_idx] > key) {
	//		v1[search_idx + 1] = v1[search_idx];
	//		search_idx--;   //注意这里是在寻找插入位置的索引，同时也指明了最后这个key的具体插入位置是[search_idx+1]
	//	}
	//	v1[search_idx + 1] = key;
	//}
	//for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
	//	int num = *it;
	//	cout << num << " ";
	//}
	//cout << endl;
	//system("pause");


	/*
	希尔排序
		平均时间复杂度：O(nlogn)
		稳定性：不稳定

		也成为递减增量式排序算法,是插入排序的一种高速而稳定的改进版本
		其是基于插入排序的以下两点性质改进的：
		1.插入排序在对几乎已经排好序的数据进行操作时，效率高，即可以达到线性排序的效率
		2.插入排序一般来说是低效率的，因为插入排序每次只能将数据移动一位

		希尔排序的一般步骤：
		1.先取一个小于n的整数d1作为第一个增量，把文件的全部记录分成d1个组。
		  所有距离为d1的倍数的记录放在同一个组中，在各组内进行直接插入排序。
		2.取第二个增量d2<d1，重复上述的分组和排序，直到所取的增量dt = 1 (dt< d(t-1) < ... < d2 < d1),
		  即所有记录放在同一个组中进行直接插入排序为止。
		步长的选择是希尔排序的重要部分。只要最终步长为1，任何步长都可以工作。
		算法最开始以一定的步长进行排序，然后会继续以一定步长进行排序，最终算法以步长为1进行排序。
		当步长为1时，算法变为插入排序，这就保证了数据一定会被排序。
	*/

	//vector<int> v2{ 40, 30, 60, 80, 70, 10, 20, 40, 50, 5 };
	//int h = 1;
	//int n = v2.size();
	//int stride = 4;
	//while (h < n) {
	//	h = stride * h + 1;   //这个是确定最开始的步长的
	//}
	//while (h > 0) {
	//	for (int i = h; i < n; ++i) {  //起步是h,而简单的插入排序起步是1
	//		int key = v2[i];
	//		int j = i - h;    //一次性移动h个单位
	//		while (j >= 0 && v2[j] > key) {
	//			v2[j + h] = v2[j];
	//			j = j - h;
	//		}
	//		v2[j + h] = key;

	//	}
	//	h = h / 3;   //这个是确定每次的步长的，这个式子可以自己确定，只要最后的步长为1，保证所有的都会被插入排序
	//}
	//for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
	//	int num = *it;
	//	cout << num << " ";
	//}
	//cout << endl;
	//system("pause");


	/*
	选择排序
		简单直观，无论什么数据进去都是O(n^2)的时间复杂度
		数据规模越小越好，不占额外的内存空间

		算法步骤：
		1.首先在未排序的序列中找到最小（大）元素，存放到排序序列的起始位置
		2.再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
		3.重复第二步，直到所有元素均排序完毕。
	*/
	//vector<int> v3{ 40, 30, 2, 80, 70, 10, 20, 40, 50, 5};
	//int n = v3.size();

	//for (int i = 0; i < n; ++i) {
	//	int max_num = v3[i];
	//	int max_idx = i;
	//	for (int j = i + 1; j < n; ++j) {
	//		if (v3[j] > max_num) {
	//			max_num = v3[j];
	//			max_idx = j;
	//		}
	//	}
	//	v3[max_idx] = v3[i];
	//	v3[i] = max_num;
	//}

	//for (vector<int>::iterator it = v3.begin(); it != v3.end(); ++it) {
	//	int num = *it;
	//	cout << num << " ";
	//}
	//cout << endl;
	//system("pause");


	/*
	冒泡排序
		重复的走访过要排序的数列，一次比较两个元素，顺序错误就进行交换
	步骤：
		1.比较相邻的元素。比较大小
		2.对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对
		  此时最后的元素将是最大（小）的数
		3.针对所有的元素重复以上的步骤，除了最后一个
		4.持续每次对越来越小的元素重复上面的步骤，直到没有任何一对数字需要比较
	*/

	//vector<int> v4{ 40, 30, 2, 80, 70, 10, 20, 40, 50, 5 };
	//int n = v4.size();
	//for (int i = 0; i < n; ++i) {
	//	for (int j = 0; j < n - i - 1; ++j) {
	//		if (v4[j] > v4[j + 1]) {  //从小到大
	//			int tmp = v4[j];
	//			v4[j] = v4[j + 1];
	//			v4[j + 1] = tmp;
	//		}
	//	}
	//}
	//for (vector<int>::iterator it = v4.begin(); it != v4.end(); ++it) {
	//	int num = *it;
	//	cout << num << " ";
	//}
	//cout << endl;
	//system("pause");

	/*
	快速排序 --> 划分交换排序 （递归 + 分治）
		基本思想：
		通过一趟排序将待排记录隔成独立的两个部分，其中一部分记录的关键字均比另一部分的关键字小
		则可以分别对这两部分继续进行排序，以达到整个序列有序
		
		实现逻辑：
		快速排序使用分而治之的策略来把一个序列（list）分成两个子序列（sub-lists）
		1.从数列中挑出一个元素，称为“基准”
		2.重新排序数列，所有元素比基准值小的摆放在基准前面，
		  所有元素比基准值大的摆在基准的后面（相同的数可以放在任一边）。
		  在这个分区退出以后，该基准就会处于数列的中间位置 --> 称为分区操作
		3.递归地把小于基准值元素的子数列和大于基准值元素的子数列进行排序

		重点就是这个递归的思想
		递归到最底部的时候，数列的大小是零或者1，也就是已经排序好了，
		这个算法一定会结束，因为在每次的迭代中，它至少会把一个元素摆到它最后的位置去

	时间复杂度：
		平均时间复杂度：O(NlogN)
		最佳时间复杂度：O(NlogN)
		最差时间复杂度：O(N^2)
		空间复杂度：根据实现方式的不同而不同
	*/
//	vector<int> v5{ 40, 30, 2, 80, 70, 10, 20, 40, 50, 5 };
//	int n = v5.size();
//	quick_sort(v5, 0, n - 1);
//	for (vector<int>::iterator it = v5.begin(); it != v5.end(); ++it) {
//		int num = *it;
//		cout << num << " ";
//	}
//	cout << endl;
//	system("pause");

	/*
	归并排序(merge sort):
		 归并排序，是创建在归并操作上的一种有效的排序算法  基于比较的排序算法
		 算法是采用分治法（Divide and Conquer）的一个非常典型的应用，且各层分治递归可以同时进行
		 归并排序思路简单，速度仅次于快速排序，为稳定排序算法，
		 一般用于对总体无序，但是各子项相对有序的数列

		基本思想：
		归并排序是用分治思想，分治模式在每一层递归上有三个步骤
		1.分解（分）：将n个元素分成两个含n/2个元素的子序列（单数的时候，后面的子序列可以只有一个）
		2.解决（治）：用合并排序法（设置两个指针）对两个子序列递归的排序
		3.合并（合）：合并两个已经排序的子序列以得到排序结果 （设置两个指针）

		实现方法：
		1.迭代法
		（1）申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
		（2）设定两个指针，最初位置分别为两个已经排序序列的起始位置
		（3）比较两个指针所指向的元素，选择相对小的元素放到合并空间，并移动指针到下一个位置
		（4）重复步骤（3）直到某一个指针到达序列尾
		（5）将另一序列剩下的所有元素直接复制到合并序列尾

		2.递归法
		（1）将序列中每相邻两个数字进行归并操作，形成floor(n/2)个序列，排序后每个序列包含两个元素
		（2）将上述序列再次归并，形成floor(n/4)个序列，每个序列包含四个元素
		（3）重复步骤（2），直到所有元素排序完毕

		归并排序的时间复杂度总是为 O(nlogn)
		空间复杂度为 O(n)
		归并排序适用于数据量大，并且对稳定性有要求的场景
	*/

	//vector<int> v6{ 40, 30, 2, 80, 70, 10, 20, 40, 50, 5 };
	//int n = v6.size();
	//vector<int> res(n);

	//
	////这个只是测试最后的那个归并环节
	////vector<int> left_v{ 1,3,5 }, right_v{ 2,4,6 }, nums(6);
	////int left_num = 3, right_num = 3;
	////Merge(nums, left_v, left_num, right_v, right_num);
	////for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
	////	int num = *it;
	////	cout << num << " ";
	////}
	////cout << endl;
	////system("pause");

	//MergeSort(v6, v6.size());
	//for (vector<int>::iterator it = v6.begin(); it != v6.end(); ++it) {
	//	int num = *it;
	//	cout << num << " ";
	//}
	//cout << endl;
	//system("pause");

	/*
	堆排序: 堆一般指的是二叉堆，二叉堆是完全二叉树或者近似二叉树

		堆的性质：
		（1）是一棵完全二叉树
		（2）每个节点值都大于或者等于其子节点值，称为最大堆，反之称为最小堆

		堆的存储：
		一般用数组表示堆，下标为i的结点的父结点下标为（i-1）/2；其左右子结点分别为(2i + 1)、(2i + 2)

		堆的操作：
		在堆的数据结构中，堆中的最大值总是位于根节点（在优先队列中使用堆的话，堆中的最小值位于根节点）
		堆中定义以下几种操作：
		（1）最大堆调整：将堆的末端子结点做调整，使得子结点永远小于父结点
		（2）创建最大堆：将堆的所有数据重新排序
		（3）堆排序：移除位在第一个数据的根节点，并作最大堆调整的递归运算

		堆排序(Heapsort)是指利用堆这种数据结构所设计的一种排序算法。堆积是一个近似完全二叉树的结构，并满足堆积的性质
		即：子结点的键值或者索引总是小于（或者大于）它的父结点

		基本思想：
		利用大顶堆（小顶堆）堆顶记录的是最大关键字（最小关键字）这一特性，使得每次从无序中选择最大记录（最小记录）变得简单
		（1）将待排序的序列构造成一个最大堆，此时序列的最大值为根节点
		（2）依次将根节点与待排序序列的最后一个元素交换
		（3）再维护从根节点到该元素的前一个节点为最大堆，如此往复，最终得到一个递增序列

		实现逻辑：
		（1）先将初始的R[0…n-1]建立成最大堆，此时是无序堆，而堆顶是最大元素
		（2）再将堆顶R[0]和无序区的最后一个记录R[n-1]交换，由此得到新的无序区R[0…n-2]和有序区R[n-1]，且满足R[0…n-2].keys ≤ R[n-1].key
		（3）由于交换后新的根R[1]可能违反堆性质，故应将当前无序区R[1..n-1]调整为堆
		     然后再次将R[1..n-1]中关键字最大的记录R[1]和该区间的最后一个记录R[n-1]交换，
		     由此得到新的无序区R[1..n-2]和有序区R[n-1..n]，且仍满足关系R[1..n-2].keys≤R[n-1..n].keys，
			 同样要将R[1..n-2]调整为堆
		（4）直到无序区只有一个元素为止

		平均时间复杂度：O(nlogn)
		最佳时间复杂度：O(nlogn)
		最差时间复杂度：O(nlogn)
		稳定性：不稳定

	*/

	int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
	int len = (int)sizeof(arr) / sizeof(int);
	heap_sort(arr, len);
	system("pause");

}


//快速排序
int AdjustArray(vector<int>& nums, int left, int right) {
	int i = left, j = right;
	int X = nums[left];  //nums[left]就是s[i],就是第一个坑,基准

	while (i < j) {
		// 从右向左找小于X的数来填充nums[i]
		while (i < j && nums[j] >= X) {
			j--;  //从后往前找，找到了以后，就退出这个循环
		}
		if (i < j) {
			nums[i] = nums[j];  //将nums[j]填到nums[i]中，nums[j]就成了一个新的坑（实际上这个值没有改变）
			i++;                //左边的指针往后进一位
		}

		//从左向右找大于或者等于X的数来填充nums[j]
		while (i < j && nums[i] < X) {
			i++;
		}
		if (i < j) {
			nums[j] = nums[i]; //将nums[i]填充到nums[j]中，此时nums[i]又成了一个新的坑
			j--;               //此时再继续从后往前找比基准小的数值
		}
	}
	//退出外面这个大循环的时候，必然是 i == j, 这个是最后的一个坑，再不能往前或者往后找了，
	//但是我们最开始挖出来的那个基准，刚好用来填充这个坑
	nums[i] = X;
	return i;    //这个返回的是在本次排序后基准最终的索引位置
}

void quick_sort(vector<int>& nums, int left, int right) {

	if (left < right) {
		int i = AdjustArray(nums, left, right);   //这里的left是用来选取每次的基准值的
		//递归，左右边区
		quick_sort(nums, left, i - 1);   //新的左边的分区 [left, i-1]
		quick_sort(nums, i + 1, right);  //新的右边的分区 [i+1, right]
	}
}


//归并排序

//用for实现  // 把两个数组按照顺序合并在一起
void Merge(vector<int>& nums, vector<int>& left_v, int left_num, vector<int>& right_v, int right_num) {
	
	int count = 0;
	int i, j;
	for (i = 0, j = 0; i < left_num && j < right_num; ) {
		if (left_v[i] < right_v[j])
			nums[count++] = left_v[i++];
		else
			nums[count++] = right_v[j++];
	}

	if (i != left_num) {
		for (int k = i; k < left_num; ++k) {
			nums[count++] = left_v[k];
		}
	}
	else if (j != right_num) {
		for (int k = j; k < right_num; ++k) {
			nums[count++] = right_v[k];
		}
	}
}

//用while实现
//void Merge(vector<int>& nums, vector<int>& left_v, int left_num, vector<int>& right_v, int right_num) {
//	int i, j, k;
//
//	// i - to mark the index of left aubarray (L)
//	// j - to mark the index of right sub-raay (R)
//	// k - to mark the index of merged subarray (A)
//	i = 0; j = 0; k = 0;
//
//	while (i < left_num && j < right_num) {
//		if (left_v[i] < right_v[j]) nums[k++] = left_v[i++];
//		else nums[k++] = right_v[j++];
//	}
//	while (i < left_num) nums[k++] = left_v[i++];
//	while (j < right_num) nums[k++] = right_v[j++];
//}

//对整数数组进行排序的递归函数
void MergeSort(vector<int>& nums, int n) {
	int mid;
	if (n < 2)      //递归结束判断
		return;

	mid = n / 2;  //找到中间的索引，进行分割

	//声明左右两个分区的子序列
	//左边的区间应该是(0,mid)  --> 长度：mid
	//右边的区间应该是(mid,n)  --> 长度：n-mid
	vector<int> left_v(mid), right_v(n - mid);

	//将左右子序列从原始的序列中分出来
	for (int i = 0; i < mid; ++i)
		left_v[i] = nums[i];
	for (int i = mid; i < n; ++i)
		right_v[i - mid] = nums[i];

	//两边同时进行排序 --> 递归
	MergeSort(left_v, mid);
	MergeSort(right_v, n - mid);

	//上面两个递归会一直进行，然后在每一层上，达到了递归结束的条件后，
	//就会一直在反着在每一层进行归并操作
	Merge(nums, left_v, mid, right_v, n-mid);   // 合并

}


//堆排序

void max_heapify(int arr[], int start, int end) {
	//建立父结点指标和子结点指标
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) {  //若子结点指标在范围内才做比较
		if (son + 1 <= end && arr[son] < arr[son + 1])  //先比较两个子结点大小，选择最大的
			son++;
		if (arr[dad] > arr[son])   //如果父结点大于子结点代表调整完毕，直接跳出函数
			return;
		else {                    //否则交换父子内容，再继续子结点和孙结点进行比较
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int len) {
	//初始化，i从最后一个父结点开始调整
	// 先进行第一次的大顶堆构造
	for (int i = len / 2 - 1; i >= 0; i--) {
		max_heapify(arr, i, len - 1);
	}

	//先将第一个元素和已经排好的元素前一位做交换，再重新调整（刚调整的元素之前的元素），直到排序完毕
	for (int i = len - 1; i > 0; i--) {
		std::swap(arr[0], arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}

