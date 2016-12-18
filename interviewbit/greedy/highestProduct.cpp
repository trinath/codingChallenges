// author @trinath; src: interviewbit
#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
  int maxp3(vector<int> &A) {
      int i, len, maxV, maxI, j, prod1, prod2;
      len = A.size();

      for(j=0; j<3; j++){
          maxV = j;
          for(i=j+1;i<len;i++){
              if(A[i] > A[maxV]) maxV = i;
          }
          swap(A[j],A[maxV]);
      }
      // two highest absolute value
      for(j=0;j<2;j++)
      {
          maxV = INT_MIN;
          maxI = 0;
          for(i = 3; i < len - j; i++)
          {
              if(A[i] < 0 && abs(A[i]) > maxV){
                  maxV = abs(A[i]);
                  maxI = i;
              }
          }
          if(maxI)
          swap(A[len-j-1], A[maxI]);
      }
      prod1 = A[0] * A[1] * A[2];
      prod2 = A[0] * A[len-2] * A[len-1];
      return  max(prod1, prod2);
  }
};

int main(){
  int n;
  Solution s;
  cin >> n;
  vector<int> A;
  while(n--){
    cin >> m;
    A.push_back(m);
  }
  cout << s.maxp3(A) << endl;
  return 0;
}
