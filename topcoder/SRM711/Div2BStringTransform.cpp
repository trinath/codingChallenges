// Author @avtrinath
// SRM 711 Div-2 500
#include <iostream>
#include <string>
using namespace std;

class StringTransform{
    public:
        string isPossible(string s, string t){
            string possible = "Possible";
            string impossible = "Impossible";
            bool found[26] = {false};
            for(int i = 0; i < s.size(); i++){
                if(s[i] != t[i] && !found[t[i]-'a']){
                    return impossible;
                }
                found[s[i]-'a'] = true;
            }
            return possible;
        }
};

int main(){
    StringTransform st;
    string a, b;
    cin >> a >> b;
    cout << st.isPossible(a, b) << endl;
    return 0;
}
