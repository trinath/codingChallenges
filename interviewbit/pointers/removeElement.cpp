// author @trinath; src: interviewbit
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class Solution{
public:
  int removeElement(vector<int> &A, int B) {
      int k , i;
      for(i=0, k=0; i<A.size(); i++)
      {
          if(A[i] != B) A[k++] = A[i];
      }
      for(i=0; i<A.size()-k; i++)
          A.pop_back();
      return k;
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
  cout << sol.removeElement(input, n) << endl;
  return 0;
}
