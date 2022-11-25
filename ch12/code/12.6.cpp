#include <iostream>
#include <vector>
#include <new>

using namespace std;

vector<int> *new_vector()
{
    return new (nothrow) vector<int>();
}

void read_ints(vector<int> *v)
{
    int num;
    while(cin >> num) {
        v->push_back(num);
    }
}

void print_vector(vector<int> *v) 
{
    for(const auto &num : *v) {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    auto *pv = new_vector();
    if(!pv) {
        cout << "内存不足" << endl;
        return -1;
    }
    read_ints(pv);
    print_vector(pv);

    delete pv;
    pv = nullptr;

    return 0;
}