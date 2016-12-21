// author @trinath; src: interviewbit
#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution{
public:
  string convert(string s, int rows){
    string result("");
    if(rows <= 1) return s;
    int i, j, index;
    bool flag;
    for(i = 0; i < rows; i++){
      if(i ==0 || i == rows - 1) index = 2*rows - 2;
      else index = index - 2;
      flag = false;
      for(j = i; j < s.size();){
        result += s[j];
        if(i == 0 || i == rows-1) j += index;
        else{
          if(!flag){
            j += index;
            flag = true;
          }
          else{
            j += (2*rows - 2 - index);
            flag = false;
          }
        }
      }
    }
    return result;
  }
};

int main(){
  Solution sol;
  string s;
  int rows;
  cin >> s >> rows;
  cout << sol.convert(s, rows) << endl;
  return 0;
}
