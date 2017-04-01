// author trinath src interviewbit
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
    public:
        int longestSubstring(string &s){
            int result = 1;
            unordered_map<char, bool> smap;
            int i, j = 0;
            for(i = 0; i < s.size(); i++){
                if(smap.find(s[i]) == smap.end()){
                    smap[s[i]] = true;
                } 
                else
                {
                    result = max(result, i - j);
                    while(j < i && s[j] != s[i]){
                        smap.erase(s[j]);
                        j++;
                    }
                    if(j != i && s[j] == s[i]) j++;    
                }
            }
            if(i != j) result = max(result, i - j);
            return result;
        }
};
int main(){
    string s;
    Solution sol;
    cin >> s;
    cout << sol.longestSubstring(s) << endl;
    return 0;
}