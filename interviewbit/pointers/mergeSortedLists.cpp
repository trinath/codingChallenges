// author @trinath; src: interviewbit
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class Solution{
public:
  void merge(vector<int> &A, vector<int> &B) {
      int as = A.size();
      int bs = B.size();
      vector<int> result;
      int i, j, k;
      for(i=0;i<B.size();i++)
          A.push_back(0);
      for(i=0,j=0; i<as || j<bs;)
      {
          if(i<as && j<bs){
              if(A[i] <= B[j]){
                  result.push_back(A[i]);
                  i++;
              }
              else{
                  result.push_back(B[j]);
                  j++;
              }
          }
          else if(i<as){
              result.push_back(A[i]);
              i++;
          }
          else if(j<bs){
              result.push_back(B[j]);
              j++;
          }
      }
      for(k=0;k<as+bs;k++)
          A[k] = result[k];
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
  sol.merge(input1, input2);
  for(int i = 0; i < input1.size(); i++){
    cout << input1[i] << " ";
  }
  cout << endl;
  return 0;
}
