#include<iostream>
#include<vector>
using namespace std;

class Xylophone{
public:
   int countKeys(vector <int> v){
     bool a[7] = {false};
     int count = 0;
     vector<int>::iterator it;

     for(it = v.begin(); it!= v.end(); it++){
       if(!a[(*it)%7]) a[(*it)%7] = true;
     }

     for(int i = 0; i < 7; i++){
       if(a[i]) count++;
     }
     return count;
   }
};

int main(){
  int n, temp;
  Xylophone s;
  cin >> n;
  vector<int> v;
  while(n--){
    cin >> temp;
    v.push_back(temp);
  }
  cout << s.countKeys(v) << endl;
  return 0;
}
