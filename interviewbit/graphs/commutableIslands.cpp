// author trinath src interviewbit
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution{
    public:
    static bool compare(const vector<int> &a, const vector<int> &b){
        return (a[2] < b[2]);
    }

    int getParent(int root, vector<int> &parentSet){
        while(parentSet[root] != root){
            root = parentSet[root];
        }
        return root;
    }

    int solve(int n, vector<vector<int> > &edges) {
        vector<int> parentSet(n+1, 0);
        vector<int> countSet(n+1, 0);
        int u, v, uroot, vroot, weight, minCost = 0, count = 0;
        sort(edges.begin(), edges.end(), compare);
        for(int i = 1; i <= n; i++){
            parentSet[i] = i;
            countSet[i] = 1;
        }
        for(int i = 0; i < edges.size() && count < n-1; i++){
            weight = edges[i][2];
            u = edges[i][0];
            v = edges[i][1];
            uroot = getParent(u, parentSet);
            vroot = getParent(v, parentSet);

            if(uroot == vroot) continue;
            minCost += weight;

            if(countSet[uroot] > countSet[vroot]){
                swap(uroot, vroot);
            }
            parentSet[uroot] = vroot;
            countSet[vroot] += countSet[uroot];
            count++;
        }
        return minCost;
    }
};

int main(){
    int m, n, to, from, dis;
    cin >> n;
    cin >> m;
    vector< vector<int> > edges;
    while(m--){
        cin >> from >> to >> dis;
        vector<int> v{from, to, dis};
        edges.push_back(v);
    }
    Solution sol;
    cout << sol.solve(n, edges) << endl;
    return 0;
}