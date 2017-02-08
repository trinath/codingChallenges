// author @trinath; src: interviewbit
#include<iostream>
#include<string>
#include<climits>
using namespace std;

class Solution{
  public:
    string minWindow(string &s, string &t){
      string result;
      int i, head, tail, start, end, len, minSize, state, p;
      int present[256] = {0};
      int required[256] = {0};
      for(i = 0; i < t.size(); i++) required[t[i]]++;
      len = t.size();
      minSize = INT_MAX;
      start = 0, end = -1;
      for(head = 0, tail = 0; tail < s.size(); tail++){
        if(required[s[tail]] == 0) continue;
        present[s[tail]]++;
        if(required[s[tail]] >= present[s[tail]]){
          len--; 
        }
        if(len == 0){
          while(!required[s[head]] || present[s[head]] > required[s[head]]){
            if(present[s[head]] > required[s[head]]){ 
              present[s[head]]--;
            }
            head++;
          }
          if(minSize > (tail - head + 1) || (minSize == (tail - head + 1) && head < start )){
            minSize = tail - head + 1;
            end = tail;
            start = head;
          }
        }
      }
      return s.substr(start, end - start + 1);
    }
  
};


int main(){
  Solution sol;
  string s, t;
  cin >> s >> t;
  cout << sol.minWindow(s, t) << endl;
  return 0;
}