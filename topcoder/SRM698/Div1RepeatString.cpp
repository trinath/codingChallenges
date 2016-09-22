// Author: @avtrinath
#include<string>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

class RepeatString{
private:
  int editdistance(string s1,string s2){
  	int dp[51][51];
  	int i,j,l,m;
    l = s1.size();
    m = s2.size();
  	for(i=0;i<=l;i++)
  	{
  		for(j=0;j<=m;j++)
  		{
  			if(i==0) dp[i][j] = j;
        else if(j==0) dp[i][j] = i;
  			else if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
  			else{
  				dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
  			}
  		}
  	}
    //cout << s1 << " " << s2 << " " << dp[l][m] << endl;
  	return dp[l][m];
  }
public:
  int minimalModify(string s){
    int i, result = INT_MAX;
    for(i = 1; i <= s.size(); i++)
    {
        result = min(result, editdistance(s.substr(0,i), s.substr(i)));
    }
    return result;
  }
};


int main(){
  int t;
  string s;
  cin >> t;
  RepeatString result;
  while(t--){
    cin >> s;
    cout << result.minimalModify(s) << endl;
  }
  return 0;
}
