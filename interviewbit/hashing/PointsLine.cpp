// author trinath src interviewbit
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
    public:
        int maxPointsInLine(vector<int> x, vector<int> y){
            int result = 1;

            return result;
        }
};

int main(){
    Solution s;
    int i, n;
    cin >> n;
    vector<int> x(n, 0);
    vector<int> y(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    cout << s.maxPointsInLine(x, y) << endl;
    return 0;
}