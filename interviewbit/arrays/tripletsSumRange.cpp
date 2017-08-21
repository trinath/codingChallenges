#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solve(vector<string> &u){
    vector<double> v(u.size(), 0);
    int i, j;
    double minValue, sumValue;
    for(i = 0; i < u.size(); i++){
        v[i] = stod(u[i]);
    }
    for(i = 0; i < 3; i++){
        minValue = v[i];
        for(j = i+1; j < v.size(); j++){
            if(v[j] < v[i]) swap(v[i], v[j]);
        }
    }
    for_each(v.begin(), v.end(), [](double &x) {cout << x << " ";});
    cout << endl;    
    sumValue = v[0] + v[1] + v[2];
    if(sumValue > 1 && sumValue < 2) return 1;
    else return 0;
}

int main(){
    int n;
    string s;
    cin >> n;
    vector<string> v;
    while(n--){
        cin >> s;
        v.push_back(s);
    }
    // for_each(v.begin(), v.end(), [](string &x) {cout << x << " ";});
    // cout << endl;
    cout << solve(v) << endl;
    return 0;
}