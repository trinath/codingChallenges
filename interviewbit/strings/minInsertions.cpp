#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
    public:
    int lcs(string s, string t){
        int result = 0;
        int n = s.size();
        int dp[n+1][n+1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if( (i==0) || (j==0)) dp[i][j] = 0;
                else if( s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s){
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        return (n - lcs(s, t));
    }
};

int main(){
    string s;
    cin >> s;
    Solution sol;
    cout << sol.minInsertions(s) << endl;
    return 0;
}