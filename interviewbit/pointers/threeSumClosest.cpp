// author @trinath; src: interviewbit
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class Solution{
public:
  int threeSumClosest(vector<int> &A, int B) {
      sort(A.begin(),A.end());
      int i, start, end, len, diff, closesum, sum;
      len = A.size();
      if(len>=3){
      closesum = A[0] + A[1] + A[2];
      diff = abs(closesum - B);
      for(i=0; i < len-2; i++){
          start = i+1;
          end = len-1;
          while(start<end)
          {
              sum = A[i] + A[start] + A[end];
              if(abs(sum - B) < diff){
                  diff = abs(sum-B);
                  closesum = sum;
              }
              if(sum < B) start++;
              else end--;
          }
      }
      return closesum;
      }
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
  cout << sol.threeSumClosest(input, n) << endl;
  return 0;
}
