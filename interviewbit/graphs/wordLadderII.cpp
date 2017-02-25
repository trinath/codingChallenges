// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
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

  bool equal(vector<string> &v1, vector<string> &v2){
      for(int i =0 ; i < v1.size(); i++){
          if(v1[i] != v2[i]) return false;
      }
      return true;
  }

  void dfs(int startword, int endword, int shortestPath, vector<int> &visited,
    vector<int> *graph, vector<string> &current, vector< vector<string> > &path,  vector<string> &dict){
      if(startword == endword && shortestPath == 1){
        path.push_back(current);
        return;
      }
      if(shortestPath == 1) return;
      for(int i = 0; i < graph[startword].size(); i++){
        if(!visited[graph[startword][i]]){
          visited[graph[startword][i]] = true;
          current.push_back(dict[graph[startword][i]]);
          dfs(graph[startword][i], endword, shortestPath-1, visited, graph, current, path, dict);
          current.pop_back();
          visited[graph[startword][i]] = false;
        }
      }
  }

  vector< vector<string> > findLadders(string start, string end, vector<string> &dict) {
      vector< vector<string> > path, outpath;
      int i, j, words, startword = -1, endword = -1, frontword, neighbor, shortestPath;
      if(start == end){
        path.push_back(vector<string>(1,start));
        return path;
      }
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
      shortestPath = visited[endword];
      if(shortestPath == 0) return path;
      // find all paths with shortest path using dfs
      visited.assign(words, 0);
      vector<string> current;
      visited[startword] = true;
      current.push_back(dict[startword]);
      dfs(startword, endword, shortestPath, visited, graph, current, path, dict);
      sort(path.begin(), path.end());
      outpath.push_back(path[0]);
      for(i = 1; i < path.size(); i++){
          if(!equal(path[i], path[i-1])) outpath.push_back(path[i]);
      }
      return outpath;
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
  vector< vector< string > > result = s.findLadders(start, end, dict);
  for(int i = 0; i < result.size(); i++){
    for(int j = 0; j < result[i].size(); j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
