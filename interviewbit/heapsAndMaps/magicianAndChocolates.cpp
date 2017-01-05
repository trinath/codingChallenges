// author @trinath; src: interviewbit
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define MOD 1000000007
class Solution{
    public:
        int getMax(vector<int> A, int k){
            priority_queue<int, vector<int>, less<int> > q(A.begin(), A.end());
            long sum = 0, front;
            while(k--){
                if(q.empty()) break;
                front = q.top();
                q.pop();
                sum = (sum + (long)front) % MOD;
                front /= 2;
                if(front > 0) q.push(front);
            } 
            return (int)sum;
        }
};

int main(){
    Solution s;
    vector<int> v;
    int n, k, m;
    cin >> k >> n;
    while(n--){
        cin >> m;
        v.push_back(m);
    }
    cout << s.getMax(v, k) << endl;
    return 0;
}
