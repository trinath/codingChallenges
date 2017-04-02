// author trinath src interviewbit
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
struct node{
    int n;
    struct node *left;
    struct node *right;
    node(int _val){
        n = _val;
        left = right = NULL;
    }
};

class Solution{
    public:
    int helper(node *root, int &height){
        if(!root){
            height = 0;
            return 0;
        }
        int ldis, rdis, lheight, rheight;
        ldis = helper(root->left, lheight);
        rdis = helper(root->right, rheight);
        height = max(lheight, rheight) + 1;
        return max(ldis, max(rdis, lheight + rheight + 1));
    }
    int largestDistance(node *root){
        int height = 0;
        return helper(root, height);
    }
};

int main(){
    Solution sol;
    node *root = new node(1);
    root->left        = new node(2);
    root->right       = new node(3);
    root->left->left  = new node(4);
    root->left->right = new node(5);
    cout << sol.largestDistance(root) << endl;
    return 0;
}