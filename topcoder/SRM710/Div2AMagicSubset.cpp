// Author @avtrinath
// SRM 710 Div-2 250
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MagicSubset{
    public:
    int findBest(vector<int> &values){
        int result, size = values.size();
        int negativeSum = 0, positiveSum = 0;
        for(int i = 0; i < size; i++){
            if(i==0 || values[i] < 0) negativeSum += values[i];
            else positiveSum += values[i];
        }
        return max(positiveSum, max(-1 * negativeSum, 0));
    }
};

int main(){
    MagicSubset ms;
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << ms.findBest(v) << endl;
    return 0;
}