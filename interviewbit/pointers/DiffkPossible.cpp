// author @trinath; src: interviewbit
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class Solution{
public:
  int diffPossible(vector<int> &A, int B) {
      int i,j,len;
      i = 0;
      j = 1;
      len = A.size();
      while(i<len && j<len)
      {
         if(i!=j && A[j]-A[i] == B) return 1;
         else if(A[j]-A[i] < B) j++;
         else i++;
      }
      return 0;
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
  cout << sol.diffPossible(input, n) << endl;
  return 0;
}
