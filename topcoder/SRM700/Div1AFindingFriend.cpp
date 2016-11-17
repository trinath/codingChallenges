#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class FindingFriend{
public:
  int find(int roomSize, vector <int> leaders, int friendPlace){
    int rooms = leaders.size();
    sort(leaders.begin(), leaders.end());
    for(int i = 0; i < leaders.size(); i++){
      if(friendPlace == leaders[i]) return 1;
      if(friendPlace < leaders[i] || roomSize == 1) rooms--;
    }
    int cut = 0;
    for(int i = rooms-1; i >= 0; i--){
      if(leaders[i] == i*roomSize + 1){
        cut = i;
        break;
      }
    }
    return (rooms-cut);
  }
};

int main(){
  FindingFriend a;
  int size, n, m, place;
  cin >> size >> n;
  vector<int> v;
  for(int i = 0; i < n; i++){
    cin >> m;
    v.push_back(m);
  }
  cin >> place;
  cout << a.find(n, v, place);
  return 0;
}
