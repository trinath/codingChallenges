// author trinath src interviewbit
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution{
    public:
        RandomListNode* copyRandomList(RandomListNode* A) {
            if(!A) return NULL;
            RandomListNode *start = A;
            RandomListNode *clone, *cloneStart;
            unordered_map<RandomListNode *, RandomListNode *> umap;
            while(start){
                RandomListNode *copy = new RandomListNode(start->label);
                umap[start] = copy;
                start = start->next;
            }
            clone = umap[A];
            start = A;
            cloneStart = clone;
            while(start){
                cloneStart->next = umap[start->next];
                if(start->random) cloneStart->random = umap[start->random];
                cloneStart = cloneStart->next;
                start = start->next;
            }
            return clone;
        }
};

int main(){
    Solution s;
    RandomListNode *node = NULL;
    RandomListNode *copy = s.copyRandomList(node);
    return 0;
}