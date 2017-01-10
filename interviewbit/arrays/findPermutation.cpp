#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
  public:
  vector<int> findPerm(const string A, int B) {
    int i, dcount = 0, icount = 0;
    vector<int> result;
    for(i = 0; i < A.size(); i++){
      if(A[i] == 'D') dcount++; 
    }
    icount =  dcount+1;
    result.push_back(icount++);
    for(i = 0; i < A.size(); i++){
      if(A[i] == 'I') result.push_back(icount++);
      else result.push_back(dcount--);
    }
    return result;
  }
};

int main(){
  Solution s;
  int n;
  string input;
  cin >> n >> input;
  vector<int> v = s.findPerm(input, n);
  for_each(v.begin(), v.end(), [] (int &x) {cout << x << " ";});
  cout << endl;
  return 0;
}