#include <iostream>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
    public:
        vector<int> equal(vector<int> &A) {
            unordered_map<int, pair<int, int> > umap;
            int sum;
            vector<int> result(4, INT_MAX);
            for(int i = 0; i < A.size(); i++)
            {
                for(int j = i+1; j < A.size(); j++)
                {
                    sum = A[i] + A[j];
                    if(umap.find(sum) != umap.end()){
                        if(i > umap[sum].first && umap[sum].second != i && umap[sum].second != j){
                            if(umap[sum].first < result[0] || 
                                    (umap[sum].first == result[0] && umap[sum].second < result[1]) || 
                                    (umap[sum].first == result[0] && umap[sum].second == result[1] && i < result[2]) || 
                                    (umap[sum].first == result[0] && umap[sum].second < result[1] && 
                                        i == result[2] && j < result[3]) ){
                                result[0] = umap[sum].first;                  
                                result[1] = umap[sum].second;
                                result[2] = i;
                                result[3] = j;
                            }                   
                        }                
                    }
                    else{
                        umap[sum] = make_pair(i, j);
                    }
                }
            }
            return result;
        }
};
int main(){
    int m, n;
    Solution s;
    cin >> n;
    vector<int> v;
    while(n--){
        cin >> m;
        v.push_back(m);
    }
    vector<int> result = s.equal(v);
    for(int &a: result){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}