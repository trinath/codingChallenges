#include<string>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

class RepeatStringEasy{
private:
  int lcs(string s1,string s2){
  	int dp[50][50];
  	int i,j,l,m;
    l = s1.size();
    m = s2.size();
  	for(i=0;i<=l;i++)
  	{
  		for(j=0;j<=m;j++)
  		{
  			if(i==0 || j==0) dp[i][j] = 0;
  			else if(s1[i-1]==s2[j-1])
  			{
  				dp[i][j] = 1 + dp[i-1][j-1];
  			}
  			else{
  				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
  			}
  		}
  	}
  	return dp[l][m];
  }
public:
  int maximalLength(string s){
    int count[26] = {0};
    int i, result = INT_MIN;
    string reduced("");
    bool isPossible = false;
    for(i = 0; i < s.size(); i++){
       count[s[i]-'a']++;
    }
    for(i = 0; i < 26; i++){
       if(count[i] > 1){
         isPossible = true;
         break;
       }
    }
    if(!isPossible) return 0;
    for(i = 0; i < s.size(); i++){
       if(count[s[i]-'a'] > 1) reduced += s[i];
    }
    //cout << reduced << endl;
    for(i = 1; i <= reduced.size(); i++)
    {
        result = max(result, 2 * lcs(reduced.substr(0,i), reduced.substr(i)));
    }
    return result;
  }
};


int main(){
  int t;
  string s;
  cin >> t;
  RepeatStringEasy result;
  while(t--){
    cin >> s;
    cout << result.maximalLength(s) << endl;
  }
  return 0;
}

// test cases
// frankfurt, single, singing
