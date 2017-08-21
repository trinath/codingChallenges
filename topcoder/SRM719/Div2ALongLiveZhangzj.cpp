// Author @avtrinath
// SRM 719 Div-2 250
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class LongLiveZhangzj{
public:
    int donate(vector<string> speech, vector<string> words){
        map<string, bool> wordMap;
        for(int i = 0; i < words.size(); i++){
            if(wordMap.find(words[i]) == wordMap.end()){
                wordMap[words[i]] = true;
            }
        }
        int sum = 0;
        for(int i = 0; i < speech.size(); i++){
            if(wordMap[speech[i]]) sum += 1;
        }
        return sum;
    }
};

int main(){
    vector<string> v1, v2;
    v1.push_back("make");
    v1.push_back("topcoder");
    v1.push_back("great");
    v1.push_back("again");
    v2.push_back("make");
    v2.push_back("america");
    v2.push_back("great");
    v2.push_back("again");
    LongLiveZhangzj llz;
    cout << llz.donate(v1, v2) << endl;
    return 0;
}