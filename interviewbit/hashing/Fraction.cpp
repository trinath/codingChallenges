// author trinath src interviewbit
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution{
    public:
    string fractionToDecimal(int num, int dnum){
        bool isNegative = (num < 0) ^ (dnum < 0);
        long long int numerator, denominator, reminder;
        numerator = abs(num);
        denominator = abs(dnum);
        if(numerator == 0) return "0";
        if(denominator == 1) return ((isNegative == true) ? to_string(numerator) : to_string(numerator).substr(1));

        string decimalresult("");
        bool isExact = true;
        unordered_map< long long int, int > umap;
        int index;
        
        decimalresult = to_string(numerator/denominator);
        reminder = numerator%denominator;
        if(isNegative) decimalresult = '-' + decimalresult;
        if(reminder) decimalresult += '.';
        
        while(reminder != 0 && isExact == true){
            reminder *= 10;
            if(umap.find(reminder) != umap.end()){
                isExact = false;
                index = umap[reminder];
                break;
            } else{
                umap[reminder] = decimalresult.size();
            }
            int temp = reminder/denominator;
            decimalresult += to_string(abs(temp));
            reminder = reminder % denominator;
        }
        if(!isExact){
            decimalresult += ")";
            decimalresult.insert(index, "(");
        }
        return decimalresult;
    }
};

int main(){
    int m, n;
    cin >> m >> n;
    Solution s;
    cout << s.fractionToDecimal(m, n) << endl;
    return 0;
}