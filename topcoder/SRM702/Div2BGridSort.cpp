// Author @avtrinath
// Div2 500
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class GridSort{
public:
    string sort(int n, int m, vector <int> grid){
      string possible("Possible"), impossible("Impossible");
      int i, j, row, col, arow, acol;
      string s("");
      bool rowblock[52] = {false}, colblock[52] = {false};
      vector<int> index;
      index.resize(n*m+1);

      if(n == 1 || m == 1){
        return possible;
      }

      for(i = 0; i < m*n; i++){
         index[grid[i]] = i;
      }

      for(i = 1; i <= n*m; i++){
        arow = (i-1)/m; acol = (i-1)%m;
        if(index[i] != i-1){
           row = index[i]/m;
           col = index[i]%m;
           // row, actualrow, col and actualcol should be free to swap
           if( (arow == row || (rowblock[arow] == false && rowblock[row] == false)) && (acol == col || (colblock[acol] == false && colblock[col] == false)) ) {
             // swap row and actualrow
             for(j = 0; j < m; j++)
             {
               swap(index[grid[row*m + j]], index[grid[arow*m + j]]);
               swap(grid[row*m + j], grid[arow*m + j]);
             }
             // swap col and actualcol
             for(j = 0; j < n; j++)
             {
               swap(index[grid[j*m + col]], index[grid[j*m + acol]]);
               swap(grid[j*m + col], grid[j*m + acol]);
             }
             rowblock[arow] = true;
             colblock[acol] = true;
           }
        } else {
          rowblock[arow] = true;
          colblock[acol] = true;
        }
      }

      for(i = 0; i < m*n; i++){
        if(grid[i] != i+1) return impossible;
      }
      return possible;

    }
};

int main(){
  int n, m, temp;
  GridSort s;
  cin >> n >> m;
  vector<int> v;
  for(int i = 0 ; i < n *m ; i++){
    cin >> temp;
    v.push_back(temp);
  }
  cout << s.sort(n, m, v) << endl;
  return 0;
}
