// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

class Solution{
public:
  string multiple(int n) {
    if(n == 1) return "1";
    queue<int> q;
    int parent[n],state, childState, value; // number%n
    string result("");
    bool isfirst, number[n], visited[n];

    //init
    for(int i = 0; i<n; i++){
        parent[i] = 0;
        visited[i] = false;
        number[i] = 0;
    }

    q.push(1);
    number[1] = 1;
    visited[1] = true;
    while(!q.empty()){
      state = q.front();
      q.pop();
      if(state == 0) // answer
      {
        isfirst = true;
        while(isfirst || state != 0){
          result = char(number[state] + '0') + result;
          state = parent[state];
          isfirst = false;
        }
        break;
      }

      for(value = 0, childState = state*10; value<=1 ; value++,childState++){
        childState = childState%n;
        if(!visited[childState]){
          q.push(childState);
          number[childState] = value;
          parent[childState] = state;
          visited[childState] = true;
        }
      }

    }
    return result;
  }
};

int main(){
  int n;
  Solution s;
  cin >> n;
  cout << s.multiple(n) << endl;
  return 0;
}
