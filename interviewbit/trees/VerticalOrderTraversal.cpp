// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution{
    public:
    vector<vector<int> > verticalOrderTraversal(TreeNode* A) {
        map<int, vector<int>> mp; 
        queue< pair<TreeNode*, int> > q;
        vector< vector<int> > result;
        int index = 0;
        TreeNode *curnode = NULL;
        
        q.push(make_pair(A, index));
        while(!q.empty()){
            pair<TreeNode*, int> node = q.front();
            q.pop();
            index = node.second;
            curnode = node.first;
            if(curnode == NULL) continue;
            
            mp[index].push_back(curnode->val);
            if(curnode->left != NULL) q.push(make_pair(curnode->left, index-1));
            if(curnode->right != NULL) q.push(make_pair(curnode->right, index+1));
        }
        
        for(auto &x: mp){
            result.push_back(x.second);
        }
        return result;
    }
};

int main(){
    return 0;
}