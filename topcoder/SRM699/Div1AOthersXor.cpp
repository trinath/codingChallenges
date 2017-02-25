// Editorial is used as reference
#include<iostream>
#include<vector>
using namespace std;

class OthersXor{
public:
    long minSum(vector<int> x){
        int bit, j, n, zerocount, onecount, anycount, anybits, currentzerocount, currentonecount;
        long result = 0;
        long final, current;
        int xorv = 1;
        n = x.size();
        for (bit = 0; bit < 30; bit++){
            zerocount = 0, onecount = 0, anycount = 0;
            for (j = 0; j < n; j++){
                if (x[j] == -1) anycount++;
                else if (x[j] & (1 << bit)) onecount++;
                else zerocount++;
            }
            final = -1;
            for (anybits = 0; anybits <= anycount; ++anybits){
                currentzerocount = zerocount + anybits;
                currentonecount = onecount + (anycount - anybits);
                if (n % 2 == 1 && currentonecount % 2 == 1) continue;
                for (xorv = 0; xorv <= 1; ++xorv){
                    if (n % 2 == 0 && xorv != currentonecount % 2) continue;
                    current = (xorv == 1) ? currentzerocount : currentonecount;
                    if (final == -1 || current < final) final = current;
                }

            }

            if (final == -1) return -1;
            result += (final << bit);
        }
        return result;
    }
};

int main(){
  int m, n;
  vector<int> v;
  cin >> n;
  while(n--){
    cin >> m;
    v.push_back(m);
  }
  OthersXor oxr;
  cout << oxr.minSum(v) << endl;
  return 0;
}
