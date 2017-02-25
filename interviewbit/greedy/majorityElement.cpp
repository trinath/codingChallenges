// author @trinath; src: interviewbit
#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
int majorityElement(const vector<int> &A) {
    int index = 0;
    int count = 1;
    int i = 1;
    for(i=1;i<A.size();i++)
    {
        if(A[i] == A[index]) count++;
        else count--;
        if(count == 0){
            index = i;
            count = 1;
        }
    }
    count = 0;
    for(i=0;i<A.size();i++)
    {
        if(A[i] == A[index]) count++;
    }
    if(count > A.size()/2) return A[index];
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
  cout << s.majorityElement(A) << endl;
  return 0;
}
