// Author @avtrinath
// SRM 712 Div-2 250
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Robofactory {
    public:
    int reveal(vector <int> query, vector <string> answer) {
        bool isNotEven = 1;
    	for(int i = 1; i < query.size(); i++) {
            if (query[i - 1] % 2 == 0) isNotEven = 0;
        }
        for(int i = 0; i < query.size(); i++){
            if(query[i] % 2 == 0 && answer[i] != "Even"){
                return i;
            }
            else if(query[i] % 2 == 1 && answer[i] != "Odd"){
                return i;
            }
        }
		if(isNotEven) return 0;
        return -1;
    }
};

int main(){
    Robofactory rf;
    int n;
    cin >> n;
    vector<int> query;
    vector<string> answer;
    query.resize(n); answer.resize(n);
    for(int i = 0; i < n; i++) cin >> query[i];
    for(int i = 0; i < n; i++) cin >> answer[i];
    cout << rf.reveal(query, answer) << endl;
    return 0;
}