// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Solution{
public:
  bool isEdge(string &s1, string &s2){
    int count = 0;
    for(int i = 0; i < s1.size(); i++){
      if(s1[i] != s2[i]) count++;
    }
    return (count == 1) ? true : false;
  }
  int ladderLength(string start, string end, vector<string> &dict) {
      int i, j, words, startword = -1, endword = -1, frontword, neighbor;
      if(start == end) return 1;

      for(i = 0; i < dict.size(); i++){
        if(start == dict[i]) startword = i;
        else if(end == dict[i]) endword = i;
      }
      if(startword == -1){ // add word to dict
          startword = dict.size();
          dict.push_back(start);
      }
      if(endword == -1){ // add word to dict
          endword = dict.size();
          dict.push_back(end);
      }
      words = dict.size();
      vector<int> graph[words];
      vector<int> visited(words, 0);
      // prepare graph
      for(i = 0; i < words; i++){
        for(j = i+1; j < words; j++){
          if(isEdge(dict[i], dict[j])){
            graph[i].push_back(j);
            graph[j].push_back(i);
          }
        }
      }
      // shortest path
      queue<int> q;
      q.push(startword);
      visited[startword] = 1;
      while(!q.empty()){
        frontword = q.front();
        q.pop();
        if(frontword == endword){
          break;
        }
        for(i = 0; i < graph[frontword].size(); i++){
          neighbor = graph[frontword][i];
          if(!visited[neighbor]){
            visited[neighbor] = visited[frontword] + 1;
            q.push(neighbor);
          }
        }
      }
      return visited[endword];
  }
};


int main(){
  string temp, start, end;
  Solution s;
  vector<string> dict;
  cin >> start >> end;
  int n;
  cin >> n;
  while(n--){
    cin >> temp;
    dict.push_back(temp);
  }
  cout << s.ladderLength(start, end, dict) << endl;
  return 0;
}
