// author @trinath; src: interviewbit
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
  int getNumber(string s){
    stringstream ss;
    int n;
    ss << s;
    ss >> n;
    return n;
  }

  bool isPossible(int a, int b, int c, string &s, string &final){
    string part1 = s.substr(0, a);
    if(part1.size() > 3 || (part1.size() > 1 && part1[0] == '0')) return false;
    if(getNumber(part1)>255) return false;
    final += part1;

    string part2 = s.substr(a, b - a);
    if(part2.size() > 3 || (part2.size() > 1 && part2[0] == '0')) return false;
    if(getNumber(part2)>255) return false;
    final = final + "." + part2;

    string part3 = s.substr(b, c-b);
    if(part3.size() > 3 || (part3.size() > 1 && part3[0] == '0')) return false;
    if(getNumber(part3)>255) return false;
    final = final + "." + part3;

    string part4 = s.substr(c);
    if(part4.size() > 3 || (part4.size() > 1 && part4[0] == '0')) return false;
    if(getNumber(part4)>255) return false;
    final = final + "."+  part4;

    return true;
  }

  vector<string> restoreIpAddresses(string s){
    vector<string> result;
    string final("");
    int len, i, j, k;
    len = s.size();
    for(i = 1; i < len; i++){
      for(j = i+1; j < len; j++){
        for(k = j+1; k < len; k++){
            final.clear();
            if(isPossible(i, j, k, s, final)){
              result.push_back(final);
            }
        }
      }
    }
    sort(result.begin(), result.end());
    return result;
  }
};

int main(){
  string s;
  Solution sol;
  cin >> s;
  vector<string> v =  sol.restoreIpAddresses(s);
  for( int i =0 ; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}
