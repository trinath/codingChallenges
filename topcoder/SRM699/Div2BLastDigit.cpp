// Reference: Editorial
#include<iostream>
using namespace std;

class LastDigit{
public:
    long long getVal(long long val){
        long long result = 0;
        while (val > 0){
            result += val;
            val /= 10;
        }
        return result;
    }
    long long findX(long long S){
        long long low, high, mid;
        low = 1LL, high = 1000000000LL * 1000000000;
        while (low < high){
            mid = (high + low) / 2;
            if (getVal(mid) < S) low = mid + 1;
            else if (getVal(mid) > S)  high = mid - 1;
            else return mid;
        }
        if (getVal(low) == S) return low;
        else return -1;
    }
};

int main(){
  LastDigit ld;
  int n;
  long long s;
  cin >> n;
  while(n--){
    cin >> s;
    cout << ld.findX(s) << endl;
  }
  return 0;
}
