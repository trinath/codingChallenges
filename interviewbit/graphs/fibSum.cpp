// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
  void fibo(int N, vector<int> &fiboList){
    fiboList.push_back(1);
    fiboList.push_back(1);
    for(int i = 2; fiboList.back() <= N; i++){
      fiboList.push_back(fiboList[i-1] + fiboList[i-2]);
    }
  }
  int fibsum(int A) {
    vector<int> fiboList;
    int count = 0;
    fibo(A, fiboList);
    for(int i = fiboList.size()-1; i >= 0; i--){
      if(A <= 0) break;
      if(A >= fiboList[i]){
        A -= fiboList[i];
        count++;

      }
    }
    if(A == 0) return count;
    return 0;
  }
};

int main(){
  Solution s;
  int n; // 7
  cin >> n;
  cout << s.fibsum(n) << endl; // 2
  return 0;
}
