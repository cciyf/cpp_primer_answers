#include <iostream>

using namespace std;

int test() {
    static unsigned int cnt = 0;
    ++cnt;
    return cnt;
}

int main() {
    cout << test() << endl;
    cout << test() << endl;
    cout << test() << endl;
    return 0;
}