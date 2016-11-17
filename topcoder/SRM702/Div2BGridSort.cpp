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

    }
};

int main(){
  GridSort g;

  return 0;
}
