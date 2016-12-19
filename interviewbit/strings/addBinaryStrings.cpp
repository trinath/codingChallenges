// author @trinath; src: interviewbit
#include<iostream>
#include<string>

using namespace std;
class Solution{
public:
 string addBinary(string s1, string s2){
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
     carry = sum/2;
     if(sum%2) result = '1' + result;
     else result = '0' + result;
     i--;
     j--;
   }
   if(carry) result = '1' + result;
   return result;
 }

};

int main(){
  string s1, s2;
  Solution s;
  cin >> s1 >> s2;
  cout << s.addBinary(s1, s2) << endl;
  return 0;
}
