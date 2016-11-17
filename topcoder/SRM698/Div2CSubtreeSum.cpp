#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#define MOD 1000000007
using namespace std;


class SubtreeSum{
private:
    vector<int> graph[50], weight;
    int trees[50], zerotrees[50], answer;
public:

    SubtreeSum(){
      answer = 0;
      memset(trees, 1, 50 * sizeof(int));
      memset(zerotrees, 1, 50 * sizeof(int));
      weight.clear();
      for(int i = 0 ; i < 50; i++) graph[i].clear();
    }

    void dfs(int root, int bit){
        int i;
        int ntrees = 1;
        trees[root] = 1;

        for(i = 0; i < graph[root].size(); i++){
        	   dfs(graph[root][i], bit);
			       trees[root] = (1LL * (trees[graph[root][i]] + 1) * trees[root]) % MOD;
             ntrees = (1LL * ntrees * zerotrees[graph[root][i]]) % MOD;
        }
        if(weight[root] & (1 << bit)){
             zerotrees[root] = 1;
        } else {
             zerotrees[root] = ntrees + 1;
        }
        //cout << bit << " " << root << " " <<  zerotrees[root] << " " << trees[root] << endl;
        answer = (answer + ( (1LL << bit) * (trees[root] - zerotrees[root] + 1) % MOD) )%MOD;
    }

    int getSum(vector<int> p, vector<int> x){
    	int i, bit, size = x.size();
        for(i = 0; i < size-1; i++)
        {
            graph[p[i]].push_back(i+1);
            weight.push_back(x[i]);
        }
        weight.push_back(x[i]);
        for(bit = 0; bit < 30; bit++){
            dfs(0, bit);
        }
        return answer;
    }

};

int main(){
  int t, temp;
  cin >> t;
  vector<int> p, x;
  while(t--){
    cin >> n;
    SubtreeSum s;
    for(i = 0; i < n - 1; i++){
      cin >> temp; p.push_back(temp);
    }
    for(i = 0; i < n; i++){
      cin >> temp; x.push_back(temp);
    }
    cout << s.getSum(p, x) << endl;
  }
return 0;
}
