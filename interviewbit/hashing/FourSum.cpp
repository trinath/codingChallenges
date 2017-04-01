// author trinath src interviewbit
#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <set>
using namespace std;
class Solution{
    public:
    vector< vector<int> > fourSum(vector<int> &A, int B) {
        set< vector<int> > resultSet;
        vector< vector<int> > resultVector;
        int target, k, l;
        sort(A.begin(), A.end());
        for(int i = 0; i < A.size(); i++) {
            for(int j = i+1; j < A.size(); j++){
                target = B - A[i] - A[j];
                k = j + 1;
                l = A.size() - 1;
                while(k < l){
                    if(A[k] + A[l] < target){
                        k++;
                    } else if(A[k] + A[l] > target){
                        l--;
                    } else {
                        vector<int> v {A[i], A[j], A[k], A[l]};
                        sort(v.begin(), v.end());
                        resultSet.insert(v);
                        k++;
                        l--;
                    } 
                }
            }
        }
        for(const vector<int> &v: resultSet){
            resultVector.push_back(v);
        }
        return resultVector;
    }
};

int main(){
    Solution s;
    int n, target;
    cin >> n;
    vector<int> v(n, 0);
    int i = 0;
    while(n--){
        cin >> v[i];
        i++;
    }
    cin >> target;
    vector< vector<int> > result = s.fourSum(v, target);
    for( vector<int> &w: result){
        for(int &x: w){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}