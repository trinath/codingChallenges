// author @trinath; src: interviewbit
#include<iostream>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
  int size(ListNode *start){
      int count = 0;
      while(start){
          start = start->next;
          count++;
      }
      return count;
  }
  TreeNode *helper(ListNode* &start, int low, int high){
          if(!start || low > high) return NULL;
          int mid = (low + high)/2;
          TreeNode *lChild = helper(start, low, mid - 1);
          TreeNode *root = new TreeNode(start->val);
          root->left = lChild;
          start = start->next;
          root->right = helper(start, mid+1, high);
          return root;
  }

  TreeNode* sortedListToBST(ListNode* A) {
      return helper(A, 0, size(A)-1);
  }
  void inorder(TreeNode *root){
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
  }
};

int main(){
  Solution s;
  ListNode *start;
  start = new ListNode(1);
  start->next = new ListNode(2);
  start->next->next = new ListNode(3);
  TreeNode *root = s.sortedListToBST(start);
  s.inorder(root);
  cout << endl;
  return 0;
}
