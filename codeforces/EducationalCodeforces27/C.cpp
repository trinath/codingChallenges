// Author @trinath
// 21 Aug 2017
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, i, j;
    bool isPossible = true;
    cin >> n;
    vector< pair<int, int> > v;
    while(n--){
        cin >> i >> j;
        v.push_back(make_pair(i,j));
    }
    sort(v.begin(), v.end());
    pair<int, int> result[2];
    result[0].first = -1, result[0].second = -1;
    result[1].first = -1, result[1].second = -1;
    for(auto t: v) {
        if(t.first > result[0].second){
            result[0].first = t.first, result[0].second = t.second;
        } else if(t.first > result[1].second){
            result[1].first = t.first, result[1].second = t.second;
        } else {
            isPossible = false;
            break;
        }
    }
    if(isPossible) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}