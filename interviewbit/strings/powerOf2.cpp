#include<iostream>
#include<string>
#include<sstream>
using namespace std;
// 2 4 8 16 32 64 128 256
class Solution{
public:
  bool helper(string &A, int size){
      if(A == "1") return true;
      if((A[size-1]-'0')%2) return false;
      string result("");
      int carry = 0, current;
      for(int i = 0; i < size; i++){
        current = A[i] - '0';
        if(carry) current += carry*10;
        if(current != 1)
          result = result + char(current/2 + '0');
        else if(result.size())
          result = result + '0';
        carry = current%2;
      }
      return helper(result, result.size());
  }

  int ispower(string A) {
     if( A == "0" || A == "1") return false;
     return helper(A, A.size());
  }
};

int main(){
  Solution sol;
  string s;
  cin >> s;
  cout << sol.ispower(s) << endl;
  return 0;
}
