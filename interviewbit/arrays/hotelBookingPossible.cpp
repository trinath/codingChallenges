// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

class Solution{
public:
  bool hotelBookingsPossible(vector<int> &arrive, vector<int> &depart, int k){
    vector< pair<int, int> > result;
    int i;
    for(i = 0; i < arrive.size(); i++) {
        result.push_back(make_pair(arrive[i], 0));
    }
    for(i = 0; i < depart.size(); i++){ 
        result.push_back(make_pair(depart[i], 1));
    }
    sort(result.begin(), result.end());
    int rooms = 0;
    for( i = 0; i < result.size()-1; i++){
        if(result[i].second == 0) rooms++;
        else rooms--;
        if(i != result.size()-1 && result[i].first != result[i+1].first && rooms > k) return false;
    }
    if(rooms > k) return false;
    return true;
  }
};

int main(){
  int k, n, a, b;
  cin >> n;
  vector<int> arrive, depart;
  while(n--){
    cin >> a >> b;
    arrive.push_back(a);
    depart.push_back(b);
  }
  cin >> k;
  Solution s;
  if(s.hotelBookingsPossible(arrive, depart, k))
    cout << "Possible" << endl;
  else 
    cout << "Not Possible" << endl;
  return 0;
}