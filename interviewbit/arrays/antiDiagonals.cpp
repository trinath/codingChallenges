// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
  public:
    vector<vector<int> > antiDiagonals(vector<vector<int> > &v){
      int i, j, n = v.size();
      vector< vector<int> > result(2*n-1, vector<int>());
      for( i = 0; i < n; i++){
        for( j = 0; j < n; j++){
          result[i+j].push_back(v[i][j]);
        }
      }
      return result;
    }
};

int main(){
  int n, i ,j;
  Solution s;
  cin >> n;
  vector< vector<int> > v(n, vector<int>(n, 0));
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      cin >> v[i][j];
  vector< vector<int> > result = s.antiDiagonals(v);
  for_each(result.begin(), result.end(), 
            [] (vector<int> &x) { for_each(x.begin(), x.end(), [] (int &y) {cout << y << " ";} ); cout << endl; });
  return 0;
}