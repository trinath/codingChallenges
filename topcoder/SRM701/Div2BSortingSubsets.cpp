#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

class SortingSubsets{
public:
    int getMinimalSize(vector <int> a){
        vector<int> b(a.begin(), a.end());
        sort(b.begin(), b.end());
        int count = 0;
        for (int i = 0; i < a.size(); i++){
            if (a[i] != b[i]){
                count++;
            }
        }
        return count;
    }
};

int main(){
  int n, temp;
  SortingSubsets s;
  cin >> n;
  vector<int> v;
  while(n--){
    cin >> temp;
    v.push_back(temp);
  }
  cout << s.getMinimalSize(v) << endl;
  return 0;
}
