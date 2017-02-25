// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
  public:

    void add(int key, unordered_map<int, int> &unmp){
        if(unmp.find(key) == unmp.end()) unmp.insert(make_pair(key, 1));
        else unmp[key]++;
    }

    void remove(int key, unordered_map<int, int> &unmp){
        if(unmp.find(key) != unmp.end()){
          if(unmp[key] == 1){
            unmp.erase(key);
          }
          else{
            unmp[key]--;
          }
        }
    }

    vector<int> dNums(vector<int> &v, int k) {
          unordered_map<int, int> unmp;
          vector<int> result;
          int i;
          for(i = 0; i < k ; i++){
            add(v[i], unmp);
          }
          result.push_back(unmp.size());
          for(i = k; i < v.size(); i++){
            // remove i - k
            remove(v[i-k], unmp);
            // add i
            add(v[i], unmp);
            // add to window
            result.push_back(unmp.size());
          }
          return result;    
    }
};


int main(){
  Solution s;
  int n, m, windowSize;
  vector<int> v, result;
  cin >> n >> windowSize;
  while(n--){
    cin >> m;
    v.push_back(m);
  }
  result = s.dNums(v, windowSize);
  for_each(v.begin(), v.end(), [] (int &x) { cout << x << " ";});
  cout << endl;
  return 0;
}