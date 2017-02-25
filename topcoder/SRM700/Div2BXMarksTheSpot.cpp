#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

class XMarksTheSpot{
public:
  int countArea(vector<string> board){
    int rows, cols, minrow, maxrow, mincol, maxcol, i, j, index, curminrow, curmincol, curmaxrow, curmaxcol, result;
    vector<int> rowindex, colindex;
    rows = board.size();
    cols = board[0].size();
    minrow = mincol = INT_MAX;
    maxrow = maxcol = INT_MIN;
    index = 0;
    for(i = 0; i < rows; i++){
      for(j = 0; j < cols; j++){
        if(board[i][j] == 'O'){
          minrow = min(minrow,i);
          maxrow = max(maxrow,i);
          mincol = min(mincol,j);
          maxcol = max(maxcol,j);
        }
        else if(board[i][j] == '?'){
          rowindex.push_back(i);
          colindex.push_back(j);
          index++;
        }
      }
    }

    //cout << minrow << " " << maxrow << " " << mincol << " " << maxcol << endl;
    //cout << index << endl;
    
    result = 0;
    for(i = 0; i < (1 << index); i++){
      curminrow = minrow;
      curmincol = mincol;
      curmaxrow = maxrow;
      curmaxcol = maxcol;
      for(j = 0; j < index; j++){
        if( i & ( 1 << j)){
          curminrow = min(curminrow, rowindex[j]);
          curmaxrow = max(curmaxrow, rowindex[j]);
          curmincol = min(curmincol, colindex[j]);
          curmaxcol = max(curmaxcol, colindex[j]);
        }
      }
      result += (curmaxrow - curminrow + 1) * (curmaxcol - curmincol + 1);
    }
    return result;
  }
};

int main(){
  int n;
  string s;
  cin >> n;
  vector<string> v;
  while(n--){
    cin >> s;
    v.push_back(s);
  }
  XMarksTheSpot spot;
  cout << spot.countArea(v) << endl;
  return 0;
}
