// author @trinath; src: interviewbit
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class Solution{
public:
  vector<vector<int> > threeSum(vector<int> &A) {
      sort(A.begin(),A.end());

      int i, start, end, len, target;
      vector<vector<int> > result;
      vector<int> temp(3,0);
      len = A.size();
      if(len>=3){
  		for(i=0; i<len-2 ; i++)
  		{
  			if(i>0 && A[i]==A[i-1]) continue;
  			temp[0] = A[i];
  			target = -A[i];
  			start = i+1;
  			end = len-1;
  			while(start < end)
  			{
  				if(start > i+1 && A[start]==A[start-1])
  				{
  					start++;
  					continue;
  				}
  				if(A[start] + A[end] == target)
  				{
  					temp[1] = A[start++];
  					temp[2] = A[end--];
  					result.push_back(temp);
  				}
  				else if ((A[start] + A[end]) < target) start++;
  				else end--;
  			}
  		}
  		return result;
      }
  }
};

int main(){
  Solution sol;
  vector<int> input;
  int m, t;
  cin >> m;
  while(m--){
    cin >> t;
    input.push_back(t);
  }

  vector< vector<int> > result = sol.threeSum(input);
  for(int i = 0; i < result.size(); i++){
    for(int j = 0; j < result[i].size(); j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
