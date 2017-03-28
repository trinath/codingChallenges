// Author @avtrinath
// SRM 711 Div-2 250
#include <iostream>
#include <algorithm>
using namespace std;

class SquareMaking{
    public:
        int getMinimalPrice(int a, int b, int c, int d){
            int row[4];
            row[0] = a;
            row[1] = b;
            row[2] = c;
            row[3] = d;
            sort(row, row+4);
            return (row[3] + row[2] - row[1] - row[0]);
        }
};

int main(){
    SquareMaking sm;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << sm.getMinimalPrice(a, b, c, d) << endl;
    return 0;
}
