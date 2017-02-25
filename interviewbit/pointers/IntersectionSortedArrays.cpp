// author @trinath; src: interviewbit
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class Solution{
public:
  vector<int> intersect(const vector<int> &A, const vector<int> &B) {
      vector<int> result;
      int i, j, as, bs;
      i = 0;
      j = 0;
      as = A.size();
      bs = B.size();
      for(i=0,j=0; i<as || j<bs;)
      {
          if(i<as && j<bs){
              if(A[i] == B[j])
              {
                  result.push_back(A[i]);
                  i++;
                  j++;
              }
              else if(A[i] < B[j]) i++;
              else j++;
          }
          else if(i<as)
          {
              break;
          }
          else if(j<bs){
              break;
          }
      }
      return result;
  }
};

int main(){
  Solution sol;
  vector<int> input1, input2;
  int m, n, t;
  cin >> m;
  while(m--){
    cin >> t;
    input1.push_back(t);
  }
  cin >> n;
  while(n--){
    cin >> t;
    input2.push_back(t);
  }
  vector<int> result = sol.intersect(input1, input2);
  for(int i = 0; i < result.size(); i++){
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}
