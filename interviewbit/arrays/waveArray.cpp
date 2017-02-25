// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
  vector<int> waveArray(vector<int> &A){
    sort(A.begin(), A.end());
    vector<int> result;
    int i, j, size;
    size = A.size();
    if(size%2){ 
      for(i = 1, j = 0; i < size-1; i+=2, j+=2){
          result.push_back(A[i]);
          result.push_back(A[j]);
      }
      result.push_back(A[size-1]);
    }
    else{
      for(i = 1, j = 0; i < size; i+=2, j+=2){
          result.push_back(A[i]);
          result.push_back(A[j]);
      }
    }
    return result;
  }
};

int main(){
  int m, n;
  cin >> n;
  vector<int> v, result;
  while(n--){
    cin >> m;
    v.push_back(m);
  }
  Solution s;
  result = s.waveArray(v);
  for_each(result.begin(), result.end(), [] (int &x) {cout << x << " ";});
  cout << endl;
  return 0;
}