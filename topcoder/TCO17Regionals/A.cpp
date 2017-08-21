// Author @avtrinath
// TCO Regionals 
// 20 Aug 2017
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class EllysSquareWords{
    public:
         int getScore(string s){
             int prefix[26] = {0};
             for(int i=0; i < s.size(); i++) prefix[s[i]-'A']++;
             int answer = 0;
             sort(prefix, prefix+26);
             for(int i = 0; i < 24; i++){
                 answer += (prefix[i] * prefix[i]);
             }
             int value = (prefix[24] + prefix[25]);
             answer += value * value;
             return answer;
         }
};

int main(){
    string s;
    EllysSquareWords es;
    cin >> s;
    cout << es.getScore(s) << endl;
    return 0;
}