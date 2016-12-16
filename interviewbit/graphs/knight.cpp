#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int pos[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
int visited[1000][1000];
class Solution{
public:
  int knight(int N, int M, int x1, int y1, int x2, int y2) {
    int i, j, row, col;
    pair<int, int> p;
    for( i = 1; i <= N; i++) for( j = 1; j <= M; j++) visited[i][j] = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(x1, y1));
    visited[x1][y1] = 1;
    while(!q.empty()){
      p = q.front();
      q.pop();
      if(p.first == x2 && p.second == y2) return (visited[x2][y2]-1);
      for(i = 0; i < 8; i++){
        row = p.first + pos[i][0];
        col = p.second + pos[i][1];
        if(row >= 1 && row <= N && col >=1 && col <= M && !visited[row][col]){
          visited[row][col] = visited[p.first][p.second] + 1;
          q.push(make_pair(row,col));
        }
      }
    }
    return (visited[x2][y2] - 1);
  }
};

int main(){
  Solution s;
  cout << s.knight(8, 8, 1, 1, 8, 8) << endl; // 6
  return 0;
}
