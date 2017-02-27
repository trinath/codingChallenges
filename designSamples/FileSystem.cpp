// author trinath
// Simple File & Directory Management System
#include <iostream>
using namespace std;

enum command{
    INIT,
    ADD,
    MOVE,
    INFECT,
    RECOVER,
    REMOVE
};

struct node{
    int pid;
    int actualSize;
    int infectSize;
    int nFiles;
    bool isFile;
    node *child;
    node *parent;
    node *next;
    node(){
        child = parent = next = NULL;
    }
    node(int _pid, int _aSize, int _iSize, bool _isFile, node* _parent){
        pid = _pid;
        actualSize = _aSize;
        infectSize = _iSize;
        isFile = _isFile;
        nFiles = (isFile == true) ? 1 : 0;
        parent = _parent;
        child = next = NULL;
    }
};

// Used chained hashing when collisions are occurred.
class Cache{
    public:
        struct hashNode{
            int key;
            node *value;
            hashNode *next;
            hashNode(){
                key = -1;
                value = NULL;
                next = NULL;
            }
            hashNode(int _pid, node* _value){
                key = _pid;
                value = _value;
                next = NULL;
            }
        };
    private:
        int hashSize;
        hashNode *table;
    public:
        Cache(int size){
            hashSize = size;
            table = new hashNode[size]; 
        }
        
        ~Cache(){
            delete table;
        }

        void add(int pid, node *pNode){
            int hashKey = pid%hashSize;
            hashNode *current = new hashNode(pid, pNode);
            current->next = table[hashKey].next;
            table[hashKey].next = current;
        }
        
        node *search(int pid){
            int hashKey = pid%hashSize;
            hashNode *first = table[hashKey].next;
            while(first){
                if(first->key == pid) return first->value;
                first = first->next;
            }
            return NULL;
        }
        
        void remove(int pid){
            int hashKey = pid%hashSize;
            hashNode *first = table[hashKey].next;
            hashNode *prev = &(table[hashKey]);
            while(first && first->key != pid){
                prev = first;
                first = first->next;
            }
            if(first){
                prev->next = first->next;
                delete first;
            }
        }
        
        void reset(){
            hashNode *first, *temp;
            for(int i = 0; i < hashSize; i++){
                if(table[i].next){
                    first = table[i].next;
                    while(first){
                        temp = first;
                        first = first->next;
                        delete temp;
                    }
                }
            }
        }
};
// writing unit tests for functions
// global
class Tree{
    private:
        node *root;
    public:
        Tree(){
            root = new node(10000, 0, 0, 0, 0);
        }
        
        node *getRoot(){
            return root;
        }
        
        void addChildToParent(node *child, node *parent){
            child->next = parent->child;
            parent->child = child;
            return;
        }

        void removeChildFromParent(node *child, node *parent){
            node *prev = NULL;
            node *first = parent->child;
            while(first != child){
                prev = first;
                first = first->next;
            }
            if(first){
                if(prev == NULL){
                    parent->child = parent->child->next;
                } else {
                    prev->next = first->next;
                }
            }
            return;
        }

        void updateAncestors(node *parent, int actualDiff, int infectDiff, int filesDiff){
            while(parent){
                parent->actualSize += actualDiff;
                parent->infectSize += infectDiff;
                parent->nFiles += filesDiff;
                parent = parent->parent;
            }
        }

        void updateSubTree(node *current, int size){
            if(!current) return;
            current->infectSize += size * current->nFiles;
            node *first = current->child;
            while(first){
                updateSubTree(first, size);
                first = first->next;
            }
        }

        void resetSubTree(node *current){
            if(!current) return;
            current->infectSize = current->actualSize;
            node *first = current->child;
            while(first){
                resetSubTree(first);
                first = first->next;
            }
        }
        
        void deleteSubTree(node *current){
            if(!current) return;
            node *first = current->child;
            node *temp;
            while(first){
                temp = first;
                first = first->next;
                deleteSubTree(temp);
            }
            delete current;
        }
        
        void reset(){
            node *first = root->child;
            node *temp;
            while(first){
                temp = first;
                first = first->next;
                deleteSubTree(temp);
            }
            root->next = root->child = NULL;
            root->nFiles = root->actualSize = root->infectSize = 0;
        }
};

Cache dataCache(10000);
Tree dataTree;

void init(){
    dataCache.reset();
    dataTree.reset();
    dataCache.add(10000, dataTree.getRoot());
}

int add(int id, int pid, int size){
    node *parent = dataCache.search(pid);
    if(!parent) return 0;
    node *current = new node(id, size, size, size, parent);
    dataTree.addChildToParent(current, parent);
    dataTree.updateAncestors(parent, current->actualSize, current->infectSize, current->nFiles);
    dataCache.add(id, current);
    return parent->infectSize;
}

int move(int id, int pid){
    node *current = dataCache.search(id);
    node *newParent = dataCache.search(pid);
    if(!current || !newParent) return 0;
    node *oldParent = current->parent;
    dataTree.removeChildFromParent(current, oldParent);
    dataTree.updateAncestors(oldParent, -1 * current->actualSize, -1 * current->infectSize, -1 * current->nFiles);
    dataTree.addChildToParent(current, newParent);
    dataTree.updateAncestors(newParent, current->actualSize,  current->infectSize,  current->nFiles);
    return newParent->infectSize;
}

int infect(int pid){
    node *current = dataCache.search(pid);
    if(!current) return 0;
    node *root = dataTree.getRoot();
    int infectSize = (root->nFiles == 0) ? 0 : (root->infectSize/root->nFiles);
    dataTree.updateSubTree(current, infectSize);
    dataTree.updateAncestors(current->parent, 0, current->nFiles * infectSize, 0);
    return current->infectSize;
}

int recover(int pid){
    node *current = dataCache.search(pid);
    if(!current) return 0;
    int updatedSize = (current->infectSize - current->actualSize);
    dataTree.resetSubTree(current);
    dataTree.updateAncestors(current->parent, 0, -1 * updatedSize, 0);
    return current->infectSize;
}

int remove(int pid){
    node *current = dataCache.search(pid);
    if(!current) return 0;
    node *parent = current->parent;
    dataTree.removeChildFromParent(current, parent);
    dataTree.updateAncestors(parent, -1 * current->actualSize, -1 * current->infectSize, -1 * current->nFiles);
    dataCache.remove(current->pid);
    dataTree.deleteSubTree(current);
    return parent->infectSize;
}

int main(){
    int testCases, id, pid, fileSize;
    int cmd;
    cin >> testCases;
    while(testCases--){
        cin >> cmd;
        switch(cmd){
            case INIT: // 0
                init();
                break;
            case ADD: // 1
                cin >> id >> pid >> fileSize;
                cout << add(id, pid, fileSize) << endl;
                break;
            case MOVE: // 2
                cin >> id >> pid;
                cout << move(id, pid) << endl;
                break;
            case INFECT: // 3
                cin >> id;
                cout << infect(id) << endl;
                break;
            case RECOVER: // 4
                cin >> id;
                cout << recover(id) << endl;
                break;
            case REMOVE: // 5
                cin >> id;
                cout << remove(id) << endl;
                break;
        }
    }
    return 0;
}