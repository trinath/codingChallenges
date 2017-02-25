// author @trinath; src: interviewbit
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class Solution{
public:
  int removeDuplicates(vector<int> &A) {
      int i = 0;
      int k=0;
      int check = 0;
      for(i=1,k=1; i<A.size(); i++){
          if(A[i] == A[i-1] && check==0)
          {
              check = 1;
              A[k++] = A[i];
          }
          else if(A[i] == A[i-1] && check==1)
              continue;
          else{
              A[k++] = A[i];
              check = 0;
          }
      }
      if(k>0){
          for(i=0;i<A.size()-k;i++)
              A.pop_back();
      }
      return k;
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
  cout << sol.removeDuplicates(input) << endl;
  return 0;
}
