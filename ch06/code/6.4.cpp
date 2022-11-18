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