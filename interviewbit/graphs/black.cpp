// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[1000][1000];

void dfs(vector<string> &A, int i, int j, int rows, int cols){
    if(i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j] || A[i][j] == 'O') return;
    visited[i][j] = true;
    for(int p = 0; p < 4; p++){
        dfs(A, i + pos[p][0], j + pos[p][1], rows, cols);
    }
}

int black(vector<string> &A) {
    int i, j, rows, cols;
    rows = A.size();
    cols = A[0].size();
    for( i = 0; i < rows; i++) for( j = 0; j < cols; j++) visited[i][j] = false;
    int result = 0;
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            if(A[i][j] == 'X' && !visited[i][j]){
                dfs(A, i, j, rows, cols);
                result++;
            }
        }
    }
    return result;
}

int main(){
  vector<string> A;
  A.push_back("OOOXOOO");
  A.push_back("OOXXOXO");
  A.push_back("OXOOOXO");
  cout << black(A) << endl; // 3
}
