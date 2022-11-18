#include <iostream>

using namespace std;

double add(double val_1, double val_2) {
    double result = val_1 + val_2;
    static unsigned cnt = 0;
    ++cnt;
    cout << "函数执行了" << cnt <<"次." << endl;
    return result;
}

int main() {
    double num1, num2;
    while(cin >> num1 >> num2 ) {
        cout << num1 << " + " << num2 <<" = " <<add(num1, num2) << endl;
    }
    return 0;
}