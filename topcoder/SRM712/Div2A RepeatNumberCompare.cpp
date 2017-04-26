// Author @avtrinath
// SRM 712 Div-2 250
#include <iostream>
#include <string>

using namespace std;

class RepeatNumberCompare{
    public:
        string compare(int x1, int k1, int x2, int k2){
            string a = to_string(x1);   
            string b = to_string(x2);
            int i, asize = a.size(), bsize = b.size();
            if(k1*asize > k2*bsize) return "Greater";
            else if(k1*asize < k2*bsize) return "Less";
            for(i = 0; i < k1*asize; i++){
                if(a[i%asize] < b[i%bsize]) return "Less";
                else if(a[i%asize] > b[i%bsize]) return "Greater";
            }
            return "Equal";   
        }
};

int main(){
    RepeatNumberCompare rnc;
    int x1, x2, k1, k2;
    cin >> x1 >> k1 >> x2 >> k2;
    cout << rnc.compare(x1, k1, x2, k2) << endl;
    return 0;
}