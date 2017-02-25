// author @trinath; src: interviewbit
#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
  int candy(vector<int> &ratings) {
      vector<pair<int, int>> v;
      vector<int> candies;
      int i, len = ratings.size();
      for(i=0;i<len;i++)
          candies.push_back(1);
      for(i=1;i<len;i++)
      {
          if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
      }
      for(i=len-2;i>=0;i--)
      {
          if(ratings[i] > ratings[i+1])
            if(candies[i] <= candies[i+1])
              candies[i] = candies[i+1] + 1;
      }
      int result = 0;
      for(i=0;i<candies.size();i++)
          result += candies[i];
      return result;
  }
};

int main(){
  int n;
  Solution s;
  cin >> n;
  vector<int> A;
  while(n--){
    cin >> m;
    A.push_back(m);
  }
  cout << s.candy(A) << endl;
  return 0;
}
