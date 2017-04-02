// author trinath src interviewbit
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution{
    public:
    int largestDistance(int root, vector<int> &height, vector<int> &distance, vector<int> *neighbours){
        int size = height.size();
        int maxDistance = 0;
        vector<int> maxHeight;
        for(int i = 0; i < neighbours[root].size(); i++){
            maxDistance = max(maxDistance, largestDistance(neighbours[root][i], height, distance, neighbours)); 
            maxHeight.push_back(height[neighbours[root][i]]);
        }
        sort(maxHeight.begin(), maxHeight.end());
        height[root] = ( (maxHeight.size() == 0)? 0 : maxHeight.back() ) + 1;
        if(maxHeight.size() == 0)
            return maxDistance;
        else if (maxHeight.size() == 1)
            return max(maxDistance, maxHeight.back());
        else 
            return max(maxDistance, maxHeight.back() + maxHeight[maxHeight.size()-2]);
    }

    int solve(vector<int> &A) {
        int size = A.size();
        int root;
        if(size <= 1) return 0;
        vector<int> height(size, 0);
        vector<int> distance(size, 0);
        vector<int> neighbours[size];
        for(int i = 0; i < size; i++){
            if(A[i] == -1) root = i;
            else{
                neighbours[A[i]].push_back(i);
            }
        }
        return largestDistance(root, height, distance, neighbours);
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << s.solve(v) << endl;
    return 0;
}