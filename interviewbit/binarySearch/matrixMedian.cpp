// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution{
  public:
  int median(vector< vector<int> > &v){
    int i, count, l, r, mid, rows, cols, total;
    l = 0, r = INT_MAX;
    rows = v.size();
    cols = v[0].size();
    total = rows * cols;
    while(r - l > 1){
      mid = l + (r-l)/2;
      count = 0;
      for( i = 0; i < rows; i++){
        count += upper_bound(v[i].begin(), v[i].end(), mid) - v[i].begin();
      }
      //cout << "first:" << l << " " << r << " " << mid << endl;
      if(count >= ((total+1)/2) ) r = mid;
      else l = mid;
      //cout << count << " " << l  << " " << r << endl;
    }
    return r;
  }
};


int main(){
  int m, n, i, j;
  Solution s;
  cin >> m >> n;
  vector< vector<int> > v(m, vector<int>(n, 0));
  for(i = 0; i < m ; i++){
    for(j = 0; j < n; j++){
      cin >> v[i][j];
    }
  }
  //cout << "Median" << endl;
  cout << s.median(v) << endl;
  return 0;
}