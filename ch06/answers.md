# 章节6参考答案
## 6.1 实参和形参的区别是什么？
- 形参是函数定义时的参数，形参列表可包含多个形参，参数之间逗号间隔，规定了一个函数所接受的数据的类型和数量。
- 实参是函数调用时给定的参数，实参与形参一一对应，数量类型一一匹配。

## 6.2 指出下列函数的错误，并且指出如何修改。
1. 
```
int f() {
	string s;
	// ...
	return s;
} 
```
解答：错误，返回返回值类型为int，函数体中却返回了string，应当根据函数功能修改函数返回值类型或者修改函数体内返回值的类型。
2. 
```
f2(int i) { /* ...*/ }
```
解答：错误，缺少返回值类型，若函数无返回值，应当定义返回值为void。

3. 
```
int calc(int v1, int v1) /* ... */ }
```
解答：错误，函数形参不可重名，并且缺失一个左花括号，应当修改为
```
int calc(int v1, int v2) { /* ... */ }
```

4. 
```
double square(double x) return x * x;
```
解答：错误，函数体需要在一对花括号内。

## 6.3 编写自己的fact函数，

```
int fact(int val) {
	int ret = 1;
	for(int i = 1; i <= val; ++i) {
		ret *= i;
	}
	return ret;
}
```

## 6.4 编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。
```
#include <iostream>

using namespace std;

int fact(int val) {
    if(val < 0) return -1;
    int ret = 1;
    for(int i = 1; i <=val; ++i) {
        ret *= i;
    }
    return ret;
}

int main()
{
    int num;
    cout << "输入一个正整数：";
    cin >> num;

    cout << num <<"! 是：" << fact(num) << endl;
    return 0;
}
```
## 6.5 编写一个函数输出其实参的绝对值
```
int myabs(int val) {
    return val < 0 ? -val : val;
}
```

## 6.6 说明形参、局部变量和局部静态变量的区别。编写一个函数，同时用到这三种形式。
形参和函数体内部的变量均称为局部变量，仅仅在函数的作用域内可见。函数体内的局部变量又分为普通局部变量和静态局部变量，普通局部变量会在局部块结束后销毁，静态局部变量的生命周期会到程序结束终止。
```double add(double val_1, double val_2) {
    double result = val_1 + val_2;
    static unsigned cnt = 0;
    ++cnt;
    cout << "函数执行了" << cnt <<"次." << endl;
    return result;
}
```

## 6.7 编写一个函数，当它第一次被调用时返回0，以后每次调用返回加1.
```
int test() {
    static unsigned int cnt = 0;
    ++cnt;
    return cnt;
}
```

## 6.8 编写一个名为chapter6.h的头文件，令其包含6.1节中的函数声明。
```
#ifndef CHAPTER6_H_INCLUDED
#define CHAPTER6_H_INCLUDED

int fact(int );
double myABS(double );
double myABS2(double );

#endif
```

## 6.9 编写自己的fact.cc和factMain.cc，这两个文件都应该导入上一小节的练习中编写的Chapter6.h头文件。通过这些文件，理解编译器是如何支持分离式编译的。