// author @trinath; src: interviewbit
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void addString(vector<string> &v, string &var, string &tabs){
  if(var.size() == 0) return;
  v.push_back(tabs+var);
  var.clear();
}

vector<string> prettyJSON(string &s){
  vector<string> v;
  int i = 0, count = 0;
  string temp(""), brcktopen("{"), brcktclose("}"), squareopen("["), squareclose("]"), tabs("");
  for(i = 0; i < s.size(); i++){
    if(s[i] == '{' || s[i] == '['){ 
      count++;
      addString(v, temp, tabs);
      (s[i] == '{') ? v.push_back(tabs+brcktopen) : v.push_back(tabs+squareopen);
      tabs += '\t';
    }
    else if (s[i] == '}' || s[i] == ']'){
      count--;
      addString(v, temp, tabs);
      if(tabs.size() == 1) tabs.clear();
      else tabs = tabs.substr(1);
      (s[i] == '}') ? v.push_back(tabs+brcktclose) : v.push_back(tabs+squareclose);
    }
    else{
      if (s[i] == ','){
        if(s[i-1] == '}' || s[i-1] == ']') v.back() = v.back() + ',';
        else{
          temp += ',';
          addString(v, temp, tabs);
        }
      }
      else{
        temp += s[i];
      }
    }
  }
  return v;
}

int main(){
  string s;
  cin >> s;
  vector<string> v = prettyJSON(s);
  for_each(v.begin(), v.end(), [](string &t) {cout << t << endl;});
  cout << v.size() << endl; 
  return 0;
}