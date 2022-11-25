#include <iostream>
#include <cstdio>
#include <memory>
#include <vector>
#include <new>


using namespace std;

shared_ptr< vector<int>> new_vector() 
{
    return make_shared<vector<int>>();
}

void read_ints(shared_ptr<vector<int>> spv) 
{
    int num;
    while(cin >> num) {
        spv->push_back(num);
    }    
}

void print_vector(shared_ptr<vector<int>> spv) 
{
    for(const auto &num : *spv) {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    auto spv = new_vector();
    read_ints(spv);
    print_vector(spv);
    return 0;
}