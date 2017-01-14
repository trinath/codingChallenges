// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution{
  public:
    vector<int> subUnsort(vector<int> &v) {
          int size = v.size();
          vector<int> result;
          int firstIndex = -1 , lastIndex = -1, i, minValue = INT_MAX, maxValue = INT_MIN;
          for(i = 0; i < size-1; i++){
            if(v[i] > v[i+1]){
              firstIndex = i;
              break;
            }
          }
          if(firstIndex == -1) return vector<int>(1, -1);
          for( i = size - 1; i > 0; i--){
            if(v[i] < v[i-1]){
              lastIndex = i;
              break;
            }
          }
          //cout << firstIndex << " " << lastIndex << endl;
          for( i = firstIndex; i <= lastIndex; i++){
            minValue = min(v[i], minValue);
            maxValue = max(v[i], maxValue);
          }
          //cout << minValue << " " << maxValue << endl;
          for( i = 0 ; i < firstIndex; i++){
            if(v[i] > minValue){
              firstIndex = i;
              break;
            }
          }

          for( i = size-1 ; i > lastIndex; i--){
            if(v[i] < maxValue){
              lastIndex = i;
              break;
            }
          }
          result.push_back(firstIndex);
          result.push_back(lastIndex);
          return result;
    }
};

int main(){
  int m, n;
  vector<int> v;
  cin >> n;
  while(n--){
    cin >> m;
    v.push_back(m);
  }
  Solution s;
  vector<int> result =  s.subUnsort(v);
  for_each(result.begin(), result.end(), [](int &x) {cout << x << " ";});
  cout << endl;
  return 0;
}