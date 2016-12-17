// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1} };
class Solution{
public:
  int visited[1000][1000];

  void print(int rows, int cols){
    int i, j;
    for( i = 0; i < rows; i++){
       for( j = 0; j < cols; j++)
          cout << visited[i][j] << " ";
       cout << endl;
    }
  }

  void printVector(int rows, int cols, vector<vector<char> > &A){
    int i, j;
    for( i = 0; i < rows; i++){
       for( j = 0; j < cols; j++)
          cout << A[i][j] << " ";
       cout << endl;
    }
  }

  bool dfs(int i, int j, int rows, int cols, vector<vector<char> > &A, int region){
    if(i < 0 || i >= rows || j < 0 || j >= cols) return false;
    if( A[i][j] == 'X') return true;
    if( visited[i][j] ) return true;

    visited[i][j] = region;

    bool result = true, temp;
    for(int p = 0; p < 4; p++){
        temp = dfs(i + pos[p][0], j + pos[p][1], rows, cols, A, region);
        result &= temp;
    }
    return result;
  }

  void solve(vector<vector<char> > &A) {
    int i, j, rows, cols, region = 1;
    rows = A.size();
    cols = A[0].size();
    for( i = 0; i < rows; i++) for( j = 0; j < cols; j++) visited[i][j] = 0;
    map<int, bool> regionMap;
    for( i = 0; i < rows; i++){
      for( j = 0; j < cols; j++){
        if(A[i][j] == 'O' && !visited[i][j]){
          if(dfs(i, j, rows, cols, A, region)) regionMap[region] = true;
          region++;
        }
      }
    }
    for( i = 0; i < rows; i++)
        for( j = 0; j < cols; j++)
            if(visited[i][j] && regionMap[visited[i][j]]) A[i][j] = 'X';
  }
};

int main(){
  Solution s;
  int i, j, m, n;
  char ch;
  vector<char> c;
  vector< vector< char> > v;
  cin >> m >> n;
  for( i = 0; i < m; i++)
  {
      c.clear();
      for( j = 0; j < n; j++){
          cin >> ch;
          c.push_back(ch);
      }
      v.push_back(c);
  }
  s.solve(v);
  return 0;
}
