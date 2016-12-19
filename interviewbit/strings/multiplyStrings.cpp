// author @trinath; src: interviewbit
#include<iostream>
#include<string>

using namespace std;
class Solution{
public:
    string addStrings(string s1, string s2){
      int i, j, m, n, sum = 0;
      string result("");
      m = s1.size();
      n = s2.size();
      int carry = 0;
      i = m - 1; j = n - 1;
      while(i >= 0 || j >= 0 || carry){
        sum = 0;
        if(i >= 0) sum += (s1[i] - '0');
        if(j >= 0) sum += (s2[j] - '0');
        if(carry) sum += carry;
        carry = sum/10;
        result = char(sum%10 + '0') + result;
        i--;
        j--;
      }
      if(carry) result = char(carry + '0') + result;
      return result;
    }

    string multiplyNumber(int m, string s){
      string result("");
      int carry = 0, value;
      for(int i = s.size() - 1; i >= 0; i--){
        value = (m*(s[i]-'0') + carry);
        carry = value/10;
        value = value%10;
        result = char(value + '0') + result;
      }
      if(carry) result = char(carry + '0') + result;
      return result;
    }

    string multiply(string s1, string s2){
      int i, j, l1, l2;
      l1 = s1.size();
      l2 = s2.size();
      if(l1 > l2)  {
        swap(l1, l2);
        swap(s1, s2);
      }
      string temp(""), result("");
      for(i = l1-1; i >= 0; i--){
        temp.clear();
        for(j = 0; j < l1-i-1; j ++) temp = '0' + temp;
        result = addStrings(result, multiplyNumber(s1[i]-'0', s2) + temp);
      }
      for(i = 0; i < result.size(); i++) if(result[i] != '0') break;
      if( i == result.size()) return "0";
      else return result.substr(i);
    }
};

int main(){
  Solution sol;
  string s1, s2;
  cin >> s1 >> s2;
  cout << sol.multiply(s1, s2) << endl;
  return 0;
}
