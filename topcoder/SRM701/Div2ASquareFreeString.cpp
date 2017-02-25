#include <iostream>
#include <string>
using namespace std;

class SquareFreeString{
public:
    string isSquareFree(string s){
        int i, j, subStringSize;
        int len = s.size();
        string free("square-free"), nofree("not square-free");
        for (i = 0; i < len; i++)
        {
            for (j = i + 1; j < len; j++){
                subStringSize = j - i + 1;
                if ((subStringSize) % 2 == 0 && (s.substr(i, subStringSize / 2) == s.substr(i + subStringSize/2, subStringSize/2) ))
                    return nofree;
            }
        }
        return free;
    }
};

int main(){
  string s;
  cin >> s;
  SquareFreeString sfs;
  cout << sfs.isSquareFree(s) << endl;
  return 0;
}
