// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:

  void helper(TreeNode *A, int level, vector<vector<int> > &v){
    if(!A) return;
    if(v.size() == level) v.push_back(vector<int>());
    v[level].push_back(A->val);
    helper(A->left, level+1, v);
    helper(A->right, level+1, v);
  }
  // dfs
  vector<vector<int> > levelOrderSimple(TreeNode* A){
    vector<vector<int> > v;
    helper(A, 0, v);
  }
  // bfs
  vector<vector<int> > levelOrder(TreeNode* A) {
      vector< vector<int> > result;
      vector<int> level;
      queue<TreeNode*> q;
      TreeNode* temp;
      if(A == NULL) return result;
      q.push(A);
      q.push(NULL);
      while(!q.empty()){
          temp = q.front();
          q.pop();
          if(temp == NULL){
              if(!q.empty()) q.push(NULL);
              result.push_back(level);
              level.clear();
          }
          else{
              level.push_back(temp->val);
              if(temp->left) q.push(temp->left);
              if(temp->right) q.push(temp->right);
          }
      }
      return result;
  }
};

int main(){
  Solution s;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  vector< vector<int> > v = s.levelOrder(root);
  for(int i = 0; i < v.size(); i++){
    for(int j = 0;j < v[i].size(); j++){
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
