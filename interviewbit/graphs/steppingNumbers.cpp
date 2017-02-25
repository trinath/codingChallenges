// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:

  void dfs(int number, int A, int B, vector<int> &v){
    if(number == 0 || number > B) return;
    if(number > 9 && number >= A) v.push_back(number);
    int rem = number%10;
    if(rem == 0)
        dfs(number*10 + 1, A, B, v);
    else if(rem == 9)
        dfs(number*10 + 8, A, B, v);
    else{
        dfs(number*10 + rem - 1, A, B, v);
        dfs(number*10 + rem + 1, A, B, v);
    }
  }

  vector<int> stepnum(int A, int B) {
      vector<int> v;
      int i;
      for(i = 0; i <= 9; i++) if(i>=A && i<=B) v.push_back(i);
      for(i = 0; i <= 9; i++) dfs(i, A, B, v);
      sort(v.begin(), v.end());
      return v;
  }
};

int main(){
  int m, n; // 10 20
  cin >> m >> n;
  Solution s;
  vector<int> v = s.stepnum(m, n);
  for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl; // 10 12
  return 0;
}
