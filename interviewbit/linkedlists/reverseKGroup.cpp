// author @trinath; src: interviewbit
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution{
  public:
    ListNode* reverseHelper(ListNode* start, ListNode *dummy, int k){
        if(!start) return NULL;
        ListNode *prev = NULL;
        ListNode *current = start, *next, *temp;
        int count = 0;
        while(current && count < k){
            next = current->next;
            current->next = prev; 
            prev = current;
            current = next;
            count++;
        }
        //printList(prev);
        temp = dummy->next;
        dummy->next = prev;         
        temp->next = current;
        temp->next = reverseHelper(current, temp, k);  
        return dummy->next;
    }

    ListNode *reverseKGroup(ListNode *start, int k){
        if(!start) return NULL;
        if(!start->next || k == 1) return start;
        ListNode *dummy = new ListNode(0);
        dummy->next = start;
        return reverseHelper(start, dummy, k);
    }

    void printList(ListNode *start){
        while(start){
            cout << start->val << " ";
            start = start->next;
        }
        cout << endl;
    }
};

int main(){
    Solution s;
    ListNode *start = new ListNode(1);
    start->next = new ListNode(2);
    start->next->next = new ListNode(3);
    start->next->next->next = new ListNode(4);
    start = s.reverseKGroup(start, 1);
    s.printList(start);
    return 0;
}