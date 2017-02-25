// author trinath
// 7 50 to 8 05
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

struct record{
  string firstName;
  string lastName;
  string number;
};

struct node{
  char data;
  bool isEnd;
  list<record>::iterator recordptr;
  struct node *less, *eq, *great;
  node(char _ch){
    ch = _ch;
    isEnd = 0;
    recordId = -1;
    recordptr = less = eq = great = NULL;
  }
};

class tst{
  private:
    node *root;
    list<record>;
  public:
    tst(){
      root = NULL;
    }
    
    void addRecord(string name, list<record>::iterator recorditer){
      
    }

    list<record>::iterator searchRecord(string name){

    }
    
    void listRecords(string prefix){

    }
};


int main(){
  return 0;
}