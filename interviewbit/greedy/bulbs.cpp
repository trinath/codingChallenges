// author @trinath; src: interviewbit
#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;


class Solution{
public:
  int bulbs(vector<int> &A) {
      int i, len, count=0;
      len = A.size();
      for(i=0; i<len; i++)
      {
          if(A[i] == 1 && count%2 ==0 || A[i] == 0 && count%2 == 1) continue;
          else{
              count++;
          }
      }
      return count;
  }
};

int main(){
  Solution s;
  vector<int> a;
  a.push_back(10);
  a.push_back(2);
  a.push_back(3);
  a.push_back(16);
  cout << s.bulbs(a) << endl;
  return 0;
}
