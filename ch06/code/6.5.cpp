#include <iostream>
#include <cmath>

using namespace std;

int myabs(int val) {
    return val < 0 ? -val : val;
}

int main() {
    int num;
    cout << "请输入一个整数：";
    cin >> num;

    cout << num << "的绝对值是" << myabs(num) << endl;
    cout << num << "的绝对值是" << abs(num) << endl;

    return 0;

}