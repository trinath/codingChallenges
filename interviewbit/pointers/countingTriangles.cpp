
// author @trinath; src: interviewbit
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define MOD 1000000007

using namespace std;
class Solution{
public:
  int nTriang(vector<int> &A) {
    int i, j, k, ntriangles = 0, side;
    int prevj, prevk;
    sort(A.begin(), A.end());
    for(i = 0; i < A.size() - 2; i++){
      k = i + 2;
      for(j = i + 1; j < A.size(); j++){
          while(k < A.size() && A[i] + A[j] > A[k]){
              k++;
          }
          ntriangles = (ntriangles + (k - j - 1))%MOD;
      }
    }
    return ntriangles;
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
  cout << sol.nTriang(input) << endl;
  return 0;
}
