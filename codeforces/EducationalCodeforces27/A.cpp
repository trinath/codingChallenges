// Author @trinath
// 21 Aug 2017
#include <iostream>
using namespace std;

int main() {
    int i, j, m, n;
    cin >> n;
    int a[1001] = {0};
    for(i = 0; i < 2*n; i++){
        cin >> m;
        a[m]++;
    }
    i = 0, j = 1000;
    while(i != j && i < j){
        if(!a[i] || !a[j]){
            if(!a[i]) i++;
            if(!a[j]) j--;
        } else {
            if(a[i] && a[j]){
                a[i]--;
                a[j]--;
            }
        }
    }
    if(a[i] || a[j]) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}