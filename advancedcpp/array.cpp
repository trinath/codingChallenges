// author: trinath
#include <iostream>
#include <array>
using namespace std;

using order = bool(*)(int, int);

bool increasing(int a, int b){
    return a < b;
}

bool decreasing(int a, int b){
    return a > b;
}

void sort(array<int, 5> &arr, order pfn){
    sort(arr.begin(), arr.end(), pfn);
}

int main()
{
    array<int, 5> arr = {4, 2, 5, 3, 1};
    for_each(arr.begin(), arr.end(), [](int &x){cout << x << " ";});
    cout << endl;
    sort(arr, increasing);
    for_each(arr.begin(), arr.end(), [](int &x){cout << x << " ";});
    cout << endl;
    return 0;
}