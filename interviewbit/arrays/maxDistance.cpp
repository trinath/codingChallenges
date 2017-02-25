// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
  public:
    int maxDistance(vector<int> &v){
      int i, j, result = 0, size = v.size();
      vector<int> minLeft(size, 0);
      vector<int> maxRight(size, 0);
      minLeft[0] = v[0]; maxRight[size-1] = v[size-1];
      for(i = 1; i < size; i++) minLeft[i] = min(v[i], minLeft[i-1]);
      for(i = size-2 ; i >= 0; i--) maxRight[i] = max(v[i], maxRight[i+1]);
      i = 0, j = 0;
      while(i < size && j < size){
        if(minLeft[i] <= maxRight[j]){
          result = max(result, j - i);
          j++;
        }
        else i++;
      }
      return result;
    }

};

int main(){
  int m, n;
  vector<int> v;
  cin >> n;
  while(n--){
    cin >> m;
    v.push_back(m);
  }
  Solution s;
  cout << s.maxDistance(v) << endl;
  return 0;
}