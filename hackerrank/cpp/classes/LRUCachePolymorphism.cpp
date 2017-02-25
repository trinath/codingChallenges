// @author trinath source hackerank
// url: https://www.hackerrank.com/challenges/abstract-classes-polymorphism
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
    private:
        int currentSize;
        Node *insert(int key, int value){
            if(currentSize == 0){
                head = new Node(key, value);
                tail = head;
            }
            else{
                Node *it = new Node(key,value);
                it->prev = NULL;
                it->next = head;
                head->prev = it;
                head = it;
            }
            currentSize++;
            return head;
        }
        void deleteLast(){
            if(currentSize == cp){
                mp.erase(tail->key);
                Node *temp = tail;
                tail = tail->prev;
                currentSize--;
                if(currentSize <= 1) head = tail;
                delete temp;
            }
        }
        void move(Node *mNode){
            if(mNode == head) return;
            mNode->prev->next = mNode->next;
            if(mNode->next == NULL) tail = mNode->prev;
            mNode->prev = NULL;
            mNode->next = head;
            head->prev = mNode;
            head = mNode;  
        }
    public:
         LRUCache(int n){
            cp = n;
            currentSize = 0;
            head = tail = NULL;
        }
        void set(int key, int value){
            if(mp.find(key) == mp.end()){
                mp[key] = insert(key, value);
            }
            else{
                mp[key]->value = value;
                move(mp[key]); // to head;
            }
            return;            
        }
        int get(int key){
            if(mp.find(key) != mp.end()){
                move(mp[key]);
                return mp[key]->value;
            }
            else{
                deleteLast();
                mp[key] = insert(key, -1);
                return -1;
            }
        }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
