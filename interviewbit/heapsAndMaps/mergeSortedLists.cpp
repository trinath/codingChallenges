#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class ListNodeCompare{
  public:
    bool operator() (ListNode* &lhs, ListNode* &rhs){
      return (lhs->val > rhs->val);
    }
};

class Solution{
  public:
    ListNode* merge(vector<ListNode*> &v) {
      ListNode *dummy = new ListNode(0);
      ListNode *start = dummy;
      priority_queue<ListNode*, vector<ListNode*>, ListNodeCompare> q(v.begin(), v.end());
      while(!q.empty()){
        dummy->next = q.top();
        q.pop();
        if(dummy->next->next){
          q.push(dummy->next->next);
        }
        dummy = dummy->next;
       }
      return start->next;
    }

    void print(ListNode *start){
      while(start){
        cout << start->val << " ";
        start = start->next;
      }
      cout << endl;
    }
};

int main(){
  Solution s;
  vector<ListNode*> v;
  ListNode *temp = new ListNode(1);
  temp->next = new ListNode(10);
  temp->next->next = new ListNode(20);
  v.push_back(temp);
  s.print(temp);

  temp = new ListNode(4);
  temp->next = new ListNode(11);
  temp->next->next = new ListNode(13);
  v.push_back(temp);
  s.print(temp);

  temp = new ListNode(3);
  temp->next = new ListNode(8);
  temp->next->next = new ListNode(9);
  v.push_back(temp);
  s.print(temp);

  ListNode *result = s.merge(v);
  s.print(result);
  return 0;
}