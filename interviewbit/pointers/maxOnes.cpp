// author @trinath; src: interviewbit
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class Solution{
public:
  vector<int> maxOnes(vector<int> &input, int n){
    int left, right, maxLeft, maxWindow, zeroCount, i, j;
    left = 0, right = 0;
    maxLeft = 0, maxWindow = 0;
    zeroCount = 0;
    while(right < input.size()){
      if(zeroCount <= n){
        if(input[right] == 0) zeroCount++;
        right++;
      }
      else if(zeroCount > n){
        if(input[left] == 0) zeroCount--;
        left++;
      }
      if(zeroCount <= n){
        if(right - left > maxWindow || ((right - left) == maxWindow && left < maxLeft)){
          maxWindow = (right - left);
          maxLeft = left;
        }
      }
    }
    // preparing result
    vector<int> result;
    i = maxLeft - 1; j = maxLeft + maxWindow;
    while(i >=0 && input[i] == 1){
      result.push_back(i);
      i--;
    }
    reverse(result.begin(), result.end());
    i = maxLeft;
    while( i < j || (i < input.size() && input[i] == 1)){
      result.push_back(i);
      i++;
    }
    return result;
  }
};

int main(){
  Solution sol;
  vector<int> input;
  int m, n, t;
  cin >> n;
  cin >> m;
  while(m--){
    cin >> t;
    input.push_back(t);
  }
  vector<int> result = sol.maxOnes(input, n);
  for(int i = 0; i < result.size(); i++){
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}
