// author @trinath; src: interviewbit
#include<iostream>
#include<string>

using namespace std;
class Solution{
public:
  bool parseNumber(string s){
    if(s.size() == 0) return true;
    int i = 0;
    if(s[i] == '+' || s[i] == '-') i++;
    if(i == s.size()) return false;
    while(i < s.size()){
      if(!(s[i] >= '0' && s[i] <= '9')) return false;
      i++;
    }
    return true;
  }

  bool parseDecimal(string s){
    int i, count = 0, index;
    if(s.size() == 0) return false;
    for(i = 0; i < s.size(); i++){
      if(s[i] == '.'){
        count++;
        index = i;
      }
    }
    if(count > 1) return false;
    if(count == 0){
      return parseNumber(s);
    }
    if(index + 1 == s.size()) return false;
    else return parseNumber(s.substr(0,index)) && parseNumber(s.substr(index+1));
  }

  int isNumber(const string &input){
    int i, j, len, count, index;
    string newinput;
    len = input.size();
    bool isnumeric = true;
    for(i = 0; i < input.size(); i++){ // leading space
      if(input[i] == ' ') continue;
      else break;
    }
    for(j = input.size()-1; j >= 0; j--){ // trailing space
      if(input[j] == ' ') continue;
      else break;
    }
    newinput = input.substr(i, j-i+1); // remove leading and trailing spaces
    count = 0;
    // parse exponent
    for(i = 0; i < newinput.size(); i++){
      if(newinput[i] == 'e'){
        count++;
        index = i;
      }
      else if(!(newinput[i] == '.' || newinput[i] == '+' || newinput[i] == '-'
      ||(newinput[i] >= '0' && newinput[i] <= '9')) ){
        isnumeric = false;
      }
    }
    if(count > 1 || !isnumeric) return false;
    if(count == 0) return parseDecimal(newinput);
    return parseDecimal(newinput.substr(0,index)) && parseNumber(newinput.substr(index+1));
  }
};
int main(){
  Solution s;
  string input;
  cin >> input;
  cout << s.isNumber(input) << endl;
  return 0;
}
