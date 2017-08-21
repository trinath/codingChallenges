// Author @trinath
// 21 Aug 2017
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int answer = 0;
    string s;
    cin >> s;
    int sum1 = 0, sum2 = 0;
    vector<int> v1(9, 0), v2(9, 0);
    for(int i = 0; i < 3; i++){
         sum1 += (s[i]-'0');
         v1[s[i]-'0']++;
    }
    for(int i = 3; i < 6; i++) {
         sum2 += (s[i]-'0');
         v2[s[i]-'0']++;
    }
    if(sum1 == sum2){
        cout << answer << endl;
    } else {
    }
    return 0;
}