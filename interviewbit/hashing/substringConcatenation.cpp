// author trinath src interviewbit
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution{
    public:
    vector<int> findIndices(string &s, vector<string> &v){
        vector<int> result;
        return result;
    }
};

int main(){
    Solution sol;
    string s, input;
    vector<string> v;
    cin >> s;
    int n;
    cin >> n;
    while(n--){
        cin >> input;
        v.push_back(input);
    }
    for(int &x: sol.findIndices(s, v)){
        cout << x << " ";
    }
    cout << endl; 
    return 0;
}