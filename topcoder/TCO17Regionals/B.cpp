// Author @avtrinath
// TCO Regionals 
// 20 Aug 2017
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class EllysAnagrams{
    public:
        int getCount(string A, string B){
            int answer = 0;
            int answer1 = 0;            
            int acount[26] = {0}, bcount[26] = {0};
            string Atrans("");
            string Btrans("");

            for(int i = 0; i < A.size(); i++) {
                acount[A[i]-'A']++; 
                bcount[B[i]-'A']++; 
            }
            for(int i = 0; i < B.size(); i++){
                if(acount[B[i] - 'A'] > 0){
                    acount[B[i] - 'A']--;
                    bcount[B[i] - 'A']--;
                }
            }
            int i, j;
            bool flag;
            for(i = 0; i < 26; i++){
                while(acount[i] > 0){
                    flag = false;
                    for(j = i; j < 26; j++){
                        if(bcount[j] != 0){
                            answer += (j-i);
                            acount[i]--;
                            bcount[j]--;
                            flag = true;
                            break;
                        }
                    }
                    if(!flag){
                        for(j = 0; j < i; j++){
                            if(bcount[j] != 0){
                                answer += (26 - i + j);
                                acount[i]--;
                                bcount[j]--;
                                break;
                            }
                        }   
                    }
                }
            }
            return answer;
        }
};

int main() {
    int t;
    cin >> t;
    EllysAnagrams ea;
    string A, B;
    while(t--){
        cin >> A >> B;
        cout << ea.getCount(A, B) << endl;
    }
    return 0;
}