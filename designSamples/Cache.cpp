// author trinath
// implementation of LRUCache and LFUCache 
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

struct node{
  int key;
  int priority;
  node(int _key, int _priority){
    key = _key;
    priority = _priority;
  }
};

class Cache{
  protected:
    int capacity;
  public:
    Cache(int c):capacity(c){};
    virtual void set(int key, int value) = 0;
    virtual int get(int key) = 0;
    ~Cache();
};

class LRUCache: public Cache{
  private:
    typedef pair<int, list<int>::iterator> PIL; 
    typedef unordered_map<int, PIL> LRUMap; // key, value, reference
    LRUMap umap;
    list<int> memoryList;
    void moveToFront(LRUMap::iterator it){
      int key = it->first;
      memoryList.erase(it->second.second);
      memoryList.push_front(key);
      it->second.second = memoryList.begin();
    }
  public:
    LRUCache(int c):Cache(c){

    }
    void set(int key, int value){
      LRUMap::iterator it = umap.find(key);
      if(it != umap.end()){
        moveToFront(it);        
      } else {
        if(capacity == umap.size()){
          umap.erase(memoryList.back());
          memoryList.pop_back();
        }
        memoryList.push_front(key);
      }
      umap[key] = make_pair(value, memoryList.begin());
    }
    int get(int key){
      LRUMap::iterator it = umap.find(key);
      if(it == umap.end()){
        return -1;  
      }
      moveToFront(it);
      return it->second.first; // value
    }
};


class LFUCache: public Cache{
  private:
    typedef pair<int, list<node>::iterator> PIQ;
    typedef unordered_map<int, PIQ> LFUMap;  // key, value, reference
    LFUMap umap;
    list<node> memoryList;
    void increaseCount(LFUMap::iterator &it){
      bool found = false;
      list<node>::iterator itlist;
      node keynode(it->first, (it->second.second)->priority + 1);
      memoryList.erase(it->second.second);
      for(itlist = memoryList.begin(); itlist != memoryList.end() && itlist->priority <= keynode.priority; itlist++)
      memoryList.insert(itlist, keynode);      
      for(itlist = memoryList.begin(); itlist != memoryList.end(); itlist++){
        if(itlist->key == keynode.key){
          it->second.second = itlist;
          break;
        }
      }
    }
  public:
    LFUCache(int c):Cache(c){
    }
    void set(int key, int value){
      LFUMap::iterator it = umap.find(key);
      if(it != umap.end()){
        increaseCount(it);
        umap[key].first = value;
        return;
      } else {
        if(umap.size() == capacity){
          umap.erase(memoryList.front().key);
          memoryList.pop_front();
        }
        memoryList.push_front(*new node(key, 1));
        umap[key] = make_pair(value, memoryList.begin());
      }
    }

    int get(int key){
      LFUMap::iterator it = umap.find(key);
      if(it == umap.end()) return -1;
      increaseCount(it);
      return it->second.first; // value
    }
};

int main(){
  int t, key, value, capacity;
  string command;
  cout << "Input Capcity: " << endl;
  cin >> capacity;
  Cache *itemCache = new LFUCache(capacity);
  cout << "Input Number of Commands: " << endl;
  cin >> t;
  while(t--){
    cin >> command;
    if(command == "get"){
      cin >> key;
      cout << itemCache->get(key) << endl;
    }
    else if(command == "set"){
      cin >> key >> value;
      itemCache->set(key, value);
    }
  }
  return 0;
}