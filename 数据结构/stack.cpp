/*
* 大话数据结构Chapter 4:栈和队列
*	1.顺序栈
*/
#include<iostream>

using namespace std;

typedef int SElemType;  //根据是实际类型进行定义

void printUI() {
    cout << "*******************************************************" << endl;
    cout << "*********  1.初始化为空栈                     *********" << endl;
    cout << "*********  2.销毁栈                           *********" << endl;
    cout << "*********  3.将栈置空                         *********" << endl;
    cout << "*********  4.判断栈是否为空栈                 *********" << endl;
    cout << "*********  5.返回栈的长度                     *********" << endl;
    cout << "*********  6.求栈顶元素                       *********" << endl;
    cout << "*********  7.插入元素，并使其成为栈顶元素     *********" << endl;
    cout << "*********  8.删除栈顶元素，并返回其值         *********" << endl;
    cout << "*********  9.输出栈内元素                     *********" << endl;
    cout << "*********  10.创建并出入栈元素                *********" << endl;
    cout << "*********  11.数制转换                        *********" << endl;
    cout << "*********  12.退出                            *********" << endl;
    cout << "*******************************************************" << endl;
}

//栈中元素
struct SqStack {
	SElemType *base = nullptr;  //栈底
	SElemType *top = nullptr;  //栈顶, 如果不用这种*top,还可以表示为 SElemType top = -1 (-1表明是在这个列表的最左端)
	int stacksize;             //栈大小
};

/*
* 初始化栈   这是一种动态申请内存的方法
 * @param S
 * @return true
 * @return false
*/
bool InitStack(SqStack& S, int MAXSIZE) {
    S.base = new SElemType[MAXSIZE];   //new出来一个新的地址，里面可以进行 
    S.top = S.base;                   //初始化的时候，栈顶和栈底的位置是在一起的
    S.stacksize = MAXSIZE;
    return true;
}

/*
* 销毁栈
 * @param S
 * @return true
 * @return false
*/
bool DestroyStack(SqStack& S) {
    if (S.base) {
        delete[] S.base;
        S.stacksize = 0;
        S.base = S.top = nullptr;
    }
    //cout << S.top << " " << S.base << endl;   // 00000000 00000000

    return true;
}

/*请空栈
 * @param S
 * @return true
 * @return false
*/
bool ClearStack(SqStack& S) {
    if (S.base)
        S.top = S.base;   //直接让栈顶和栈底相等，但是并没有进行销毁
    /*cout << S.top << " " << S.base << endl;*/
    return true;
}

/*
* 判断栈是否为空
 * @param S
 * @return true
 * @return false
*/
bool StackEmpty(SqStack& S) {
    if (S.top == S.base) {
        return true;
    }
    return false;
}

/*求顺序栈的长度
 * @param S
 * @return int
*/
int StackLength(SqStack& S) {
    cout << "base: " << S.base << "top: " << S.top<< endl;
    return S.top - S.base;
}

/*取栈顶元素
 * @param S
 * @param e
 * @return true
 * @return false
*/
bool GetTop(SqStack S, SElemType& e) {
    if (S.top == S.base)
        return false;
    e = *(S.top - 1);
    //cout << *(S.base) << endl;
    return true;
}

/*
* 插入元素
* @param S
* @param e
* @return true
* @return false
*/
bool Push(SqStack& S, SElemType e) {
    if (S.top - S.base == S.stacksize)
        return false;
    *S.top = e;
    S.top++;   //指针是可以进行自身的加减的，这里加上的其实是一个SElemType类型所占的字节的大小
    return true;
}

/*
* 出栈 （将元素从栈中删除）
 * @param S
 * @param e
 * @return true
 * @return false
*/

bool Pop(SqStack& S, SElemType& e) {
    if (S.top == S.base)
        return false;
    e = *(S.top-1);
    S.top--;
    return true;
}

/*
* 打印元素
 * @param S
 * @return true
 * @return false
*/
bool PrintEle(SqStack S) {
    if (S.top == S.base) {
        return false;
    }
    for (SElemType* p = S.top - 1; p >= S.base; p--) {
        cout << *p;
        if (p == S.base)
            cout << endl;
        else
            cout << " " << endl;
    }
    return true;
}

/*
* 十进制准转二进制
 * @param num
*/
void Dec2Bin(int num) {
    SqStack stack;
    SElemType e;
    InitStack(stack, 100);
    while (num > 0) {
        Push(stack, num % 2);
        num /= 2;
    }
    while (Pop(stack, e))
        cout << e;
    cout << endl;
}

int main() {
	int mode, i;
	SqStack S;     //声明一个结构体对象
	SElemType e;   //声明一个元素
    int len;
    int MAXSIZE = 100;
	printUI();
    cout << "输入你想生成的栈的大小：";
    cin >> MAXSIZE;
    
    while (true) {
        cout << "请根据上面的提示选择模式: " << endl;
        cin >> mode;
        if (mode == 12)
            break;
        else if (mode < 1 || mode>12) {
            cout << "请输入正确范围内的数字   ";
            continue;
        }

        if (!S.base && mode != 1 && mode != 10) {
            cout << "尚未完成初始化" << endl;
            continue;
        }

        switch (mode) {
        case 1:
            if (InitStack(S, MAXSIZE))
                cout << "初始化栈成功" << endl;
            break;
        case 2:
            if (DestroyStack(S))
                cout << "销毁栈成功" << endl;
            break;
        case 3:
            if (ClearStack(S))
                cout << "清空栈成功" << endl;
            break;
        case 4:
            if (StackEmpty(S))
                cout << "栈为空" << endl;
            else
                cout << "栈不为空" << endl;
            break;
        case 5:
            len = StackLength(S);
            cout << "顺序栈的长度为: " << len << endl;
            break;
        case 6:
            if (GetTop(S, e))
                cout << "栈顶元素为：" << e << endl;
            else
                cout << "获取栈顶元素失败" << endl;
            break;
        case 7:
            cout << "请输入将要插入的元素：" << endl;
            cin >> e;
            if (Push(S, e))
                cout << e << "  入栈成功" << endl;
            else
                cout << e << "  入栈失败" << endl;
            break;
        case 8:
            if (Pop(S, e))
                cout << "栈顶元素为：" << e << endl;
            else
                cout << "无栈顶元素" << endl;
            break;
        case 9:
            if (!PrintEle(S))
                cout << "栈中无元素" << endl;
            break;
        case 10:
            int n;
            cout << "请输入要输入的元素个数：" << endl;
            cin >> n;
            if ((n + StackLength(S)) > MAXSIZE) {
                cout << "超出容量" << endl;
                break;
            }

            InitStack(S, MAXSIZE);
            while (n--) {
                cin >> e;
                Push(S, e);
            }
            break;
        case 11:
            int num;
            cout << "请输入你要转换的十进制：" << endl;
            cin >> num;
            Dec2Bin(num);
            break;
        }
    }
	system("pause");
    return 0;
}