// author @trinath; src: interviewbit
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class Solution{
public:
  int maxArea(vector<int> &A) {
          int maxarea=0;
          int i = 0;
          int n = A.size() - 1;
          while(i<n)
          {
              int sheight = A[i];
              int eheight = A[n];
              int area = min(sheight, eheight) * (n - i);
              if(area > maxarea)  maxarea = area;
              if(sheight < eheight) i++;
              else n--;
          }

          return maxarea;
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
  cout << sol.maxArea(input) << endl;
  return 0;
}
