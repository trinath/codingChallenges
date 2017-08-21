// Author @avtrinath
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    int loop = 1, i, j, t, k, count;
    string s;
    bool isPossible;
    cin >> t;
    while(loop <= t){
        cin >> s >> k;
        isPossible = true;
        count = 0;
        for(i = 0; i < s.size(); i++){
            if(s[i] == '-' && i + k - 1 < s.size()){
                for(j = i; j < i+k; j++){
                    if(s[j] == '-') s[j] = '+';
                    else s[j] = '-';   
                }
                count++;
            }
            if(s[i] == '-'){
                isPossible = false;
            }
        }
        cout << "Case #" << loop << ": "; 
        if(!isPossible) cout << "IMPOSSIBLE" << endl;
        else cout << count << endl;
        loop++;
    }
    return 0;
}