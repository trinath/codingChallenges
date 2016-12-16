#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

struct UndirectedGraphNode {
   int label;
   vector<UndirectedGraphNode *> neighbors;
   UndirectedGraphNode(int x) : label(x) {};
};

class Solution{
public:
 UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
   map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
      queue<UndirectedGraphNode*> q;
      q.push(node);
      mp[node] = new UndirectedGraphNode(node->label);

      while(!q.empty()){
        UndirectedGraphNode* temp = q.front();
        q.pop();
        for(int i = 0; i < temp->neighbors.size(); i++){
          if(mp.find(temp->neighbors[i]) == mp.end()){
            mp[temp->neighbors[i]] = new UndirectedGraphNode(temp->neighbors[i]->label);
            mp[temp]->neighbors.push_back(mp[temp->neighbors[i]]);
            q.push(temp->neighbors[i]);
          }
          else{
            mp[temp]->neighbors.push_back(mp[temp->neighbors[i]]);
          }
        }
      }
      return mp[node];
 }
};

int main(){
  Solution s;
  UndirectedGraphNode *root = new UndirectedGraphNode(1);
  UndirectedGraphNode *clone = s.cloneGraph(root);
  return 0;
}
