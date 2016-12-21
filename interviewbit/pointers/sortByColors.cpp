// author @trinath; src: interviewbit
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class Solution{
public:
  void sortColors(vector<int> &A) {
      int i, c1, c2, c3;
      c1 = c2 = c3 = 0;
      for(i=0;i<A.size();i++){
          if(A[i]==0) c1++;
          else if(A[i]==1) c2++;
          else c3++;
      }
      for(i=0;i<c1;i++){
          A[i] = 0;
      }
      for(i=c1;i<c1+c2;i++){
          A[i] = 1;
      }
      for(i=c1+c2;i<A.size();i++){
          A[i] = 2;
      }
  }
};

int main(){
  Solution sol;
  vector<int> input;
  int m, t;
  cin >> m;
  while(m--){
    cin >> t;
    input.push_back(t);
  }
  sol.sortColors(input);
  for(int i = 0; i < input.size(); i++){
    cout << input[i] << " ";
  }
  cout << endl;
  return 0;
}
