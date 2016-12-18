// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution{
public:
  bool dfs(int row, int col, int maxrows, int maxcols, vector<string> &A, string B){
    int i, newrow, newcol;
    if(B.size() == 0) return true;
    if(B[0] != A[row][col]) return false;
    bool result = false;
    for(i = 0; i < 4; i++){
      newrow = row + pos[i][0];
      newcol = col + pos[i][1];
      if(newrow >= 0 && newrow < maxrows && newcol >=0 && newcol < maxcols){
        result = result || dfs(newrow, newcol, maxrows, maxcols, A, B.substr(1));
      }
    }
    return result;
  }

  int exist(vector<string> &A, string B) {
    int rows, cols, i, j;
    bool possible = false;
    rows = A.size();
    cols = A[0].size();
    for(i = 0; i < rows; i++){
      for(j = 0; j < cols; j++){
        if(A[i][j] == B[0]){
          possible = possible || dfs(i, j, rows, cols, A, B);
        }
      }
    }
    return possible;
  }
};

int main(){
  Solution s;
  vector<string> v;
  v.push_back("ABCE");
  v.push_back("SFCS");
  v.push_back("ADEE");
  string pattern;
  cin >> pattern;
  cout << s.exist(v, pattern) << endl;
  return 0;
}
