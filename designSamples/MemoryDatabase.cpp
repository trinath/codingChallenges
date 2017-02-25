// author trinath.
// Implementation of In-Memory Database of a relation having five fields. AVL Tree is used for indexing every field.
#include<iostream>
#include<cstdio>
using namespace std;

// helper functions

int max(int a, int b){
  return (a > b) ? a : b;
}

void strcpy(char *first, char *second){
  int i = 0;
  for(i = 0; i < 20 && second[i] != '\0'; i++){
    first[i] = second[i];
  }
  first[i] = '\0';
}

int strcmp(char *first, char *second){
  int i = 0;
  for( i = 0; i < 20 && first[i] != '\0' && second[i]!='\0'; i++)
  {
    if(first[i] < second[i]) return -1;
    else if (first[i] > second[i]) return 1;
  }
  if(second[i] != '\0') return -1;
  else if(first[i] !='\0') return 1;
  return 0;
}

int absolute(int a){
  return (a < 0) ? (-1*a) : a;
}

// global datatypes
enum FIELD{
  NAME,
  NUMBER,
  EMAIL,
  MEMO,
  BIRTHDAY
};

enum COMMAND{
  INIT,
  INSERT,
  UPDATE,
  DELETE,
  SEARCH
};

struct RESULT{
  int count;
  char str[20];
};

// classes

struct record{
  char name[20];
  char number[20];
  char email[20];
  char birthday[20];
  char memo[20];
  record *next, *prev;
  record(char *_name, char *_number, char *_email, char *_birthday, char *_memo){
    strcpy(name, _name);
    strcpy(number, _number);
    strcpy(email, _email);
    strcpy(birthday, _birthday);
    strcpy(memo, _memo);
    next = prev = NULL;
  }
};

char *getFirstRecordField(record *rec, FIELD field){
    if(!rec) return NULL;
    cout << (EMAIL == field) << endl;
    switch(field){
      case NAME: return rec->name;
      case NUMBER: return rec->number;
      case EMAIL: return rec->email;
      case MEMO: return rec->memo;
      case BIRTHDAY: return rec->birthday;
    }
}

void updateRecordField(record *rec, FIELD field, char *updateStr){
    if(!rec) return;
    switch(field){
      case NAME: 
        strcpy(rec->name, updateStr);
        break;
      case NUMBER: 
        strcpy(rec->number, updateStr);
        break;
      case EMAIL: 
        strcpy(rec->email, updateStr);
        break;
      case MEMO:
        strcpy(rec->memo, updateStr);
        break;
      case BIRTHDAY: 
        strcpy(rec->birthday, updateStr);
        break;
    }
}

class DLL{
  private:
    record *head, *tail;
    int size;
    char *getFirstName(){
      if(!head) return NULL;
      return head->name;
    }

    char *getFirstNumber(){
      if(!head) return NULL;
      return head->number; 
    }
    
    char *getFirstEmail(){
      if(!head) return NULL;
      return head->email;
    }

    char *getFirstBirthday(){
      if(!head) return NULL;
      return head->birthday;
    }

    char *getFirstMemo(){
      if(!head) return NULL;
      return head->memo;
    }

    void updateName(record *rec, char *str){
      if(!rec) return;
      strcpy(rec->name, str);
    }

    void updateNumber(record *rec, char *str){
      if(!rec) return;
      strcpy(rec->number, str);
    }

    void updateEmail(record *rec, char *str){
      if(!rec) return;
      strcpy(rec->email, str);
    }

    void updateBirthday(record *rec, char *str){
      if(!rec) return;
      strcpy(rec->birthday, str);
    }

    void updateMemo(record *rec, char *str){
      if(!rec) return;
      strcpy(rec->memo, str);
    }
  public:

    DLL(){
      head = tail = NULL;
      size = 0;
    }
    
    record *addRecord(char *name, char *number, char *birthday, char *email, char *memo){
      record *current = new record(name, number, email, birthday, memo);
      current->next = head;
      head = current;
      if(!head->next) tail = head;
      size++;
      return head;
    }

    void deleteRecord(record *rec){
      if(!rec) return;
      if(rec == head){
        head = head->next;
      } else if (rec == tail){
        tail = tail->prev;
      } else{
        record *prev = rec->prev;
        prev->next = rec->next;
        rec->next->prev = prev;
      }
      if(head == NULL || head->next == NULL) tail = head;
      delete rec;
      size--;
    }

    record *getHead(){
      return head;
    }

    char *getFirstField(FIELD field){
      switch(field){
        case NAME: return getFirstName();
        case NUMBER: return getFirstNumber();
        case EMAIL: return getFirstEmail();
        case MEMO: return getFirstMemo();
        case BIRTHDAY: return getFirstBirthday();
      }
    }

    void updateField(FIELD field, char *updatestr){
      record *current = head;
      while(current){
        switch(field){
          case NAME: return updateName(current, updatestr);
          case NUMBER: return updateNumber(current, updatestr);
          case EMAIL: return updateEmail(current, updatestr);
          case MEMO: return updateMemo(current, updatestr);
          case BIRTHDAY: return updateBirthday(current, updatestr);
        }
        current = current->next;
      }
    }

    int getSize(){
      return size;
    }

    void reset(){
      record *temp;
      while(head){
        temp = head->next;
        delete head;
        head = temp;
      }
      head = tail = NULL;
      size = 0;
    }

    void print(){
      record *current = head;
      cout << "Print Records: " << endl;
      while(current){
        cout << "Record: " << current->name << " " << current->number << " " << current->email << " " << current->memo << " " << current->birthday << endl;
        current = current->next;
      }
    }


    void deleteField(FIELD field, char *str){
      record *current = head;
      bool breakloop = false;
      while(current){
        switch(field){
          case NAME: 
            if(strcmp(current->name,str) == 0) breakloop = true;
            break; 
          case NUMBER: 
            if(strcmp(current->number,str) == 0) breakloop = true;
            break; 
          case EMAIL: 
            if(strcmp(current->email,str) == 0) breakloop = true;
            break;  
          case MEMO:
            if(strcmp(current->memo,str) == 0) breakloop = true;
            break;  
          case BIRTHDAY: 
            if(strcmp(current->birthday,str) == 0) breakloop = true;
            break; 
        }
        if(breakloop) break;
        current = current->next;
      }
      deleteRecord(current);
      return;
    }

    ~DLL(){
      //reset();
    }

};

struct llnode{
  record *ptr;
  llnode *next;
  llnode(record *rec){
    ptr = rec;
    next = NULL;
  }
};

class LL{
  private:
    llnode *head;
    int size;
  
  public:

    LL(){
      head = NULL;
      size = 0;
    }

    int getSize(){
      return size;
    }

    llnode* getHead(){
      return head;
    }

    llnode* nextRecord(llnode *&rec){
      if(!rec) return NULL;
      llnode *temp = rec;
      rec = rec->next;
      return temp;
    }

    void insert(record *rec){
      llnode *current = new llnode(rec);
      current->next = head;
      head = current;
      size++;
    }

    char *getFirstField(FIELD field){
      cout << "getFirstField: " << field << endl;
      if(head && head->ptr){
        return getFirstRecordField(head->ptr, field);
      }
      return NULL;
    }

    void updateField(FIELD field, char *updatestr){
      llnode *current = head;
      while(current){
        if(current->ptr){
          updateRecordField(current->ptr, field, updatestr);
        }
        current = current->next;
      }
    } 

    void print(){
      llnode *current = head;
      cout << "Print LL" << endl;
      while(current){
        if(current->ptr){
          cout << "Record: " << current->ptr->name << endl;
        }
        current = current->next;
      }
    }


    ~LL(){  
      llnode *temp;
      while(head) {
        temp = head->next;
        delete head; 
        head = temp;
      }
      size = 0;
      head = NULL;
    }
};

struct avlnode{
  int height;
  record *ptr;
  avlnode *left, *right;
  avlnode(record *rec){
    height = 0;
    ptr = rec;
    left = right = NULL;
  }
};

class AVLTree{
  private:
    avlnode *root;
    FIELD field;

    int height(avlnode *t){
      if(!t) return 0;
      else t->height;
    }

    int compare(record *first, record *second){
      switch(field){
        case NAME: return strcmp(first->name, second->name);
        case NUMBER: return strcmp(first->number, second->number);
        case EMAIL: return strcmp(first->email, second->email);
        case MEMO: return strcmp(first->memo, second->memo);
        case BIRTHDAY: return strcmp(first->birthday, second->birthday);
      }
    }

    int compareValue(record *first, char *str){
      switch(field){
        case NAME: return strcmp(first->name, str);
        case NUMBER: return strcmp(first->number, str);
        case EMAIL: return strcmp(first->email, str);
        case MEMO: return strcmp(first->memo, str);
        case BIRTHDAY: return strcmp(first->birthday, str);
      }
    }

    avlnode *minValueNode(avlnode *start){
      if(!start) return NULL;
      while(!start->left){
        start = start->left;
      }
      return start;
    }

    void singleRotateLeft(avlnode *&start){
      avlnode *temp = start->left;
      start->left = temp->right;
      temp->right = start;
      start->height = max(height(start->left),height(start->right)) + 1;
      temp->height = max(start->height,height(temp->left)) + 1;
      start = temp;
    }

    void *singleRotateRight(avlnode *&start){
      avlnode *temp = start->right;
      start->right = temp->left;
      temp->left = start;
      start->height = max(height(start->left),height(start->right)) + 1;
      temp->height = max(start->height,height(temp->right)) + 1;
      start = temp;
    }

    void *doubleRotateLeft(avlnode *&start){
      singleRotateRight(start->left);
      singleRotateLeft(start);
    }

    void *doubleRotateRight(avlnode *&start){
      singleRotateLeft(start->right);
      singleRotateRight(start);
    }

    void insertAVLNode(avlnode *&start, record *rec){
      if(!start)
      {
        avlnode *temp = new avlnode(rec);
        start = temp;
        return;
      }
      int value = compare(rec, start->ptr);
      if( value <= 0){
        insertAVLNode(start->left, rec);
        if (absolute(height(start->right) - height(start->left)) == 2)
        {
          if( compare(rec, start->left->ptr) <= 0)
            singleRotateLeft(start);
          else
            doubleRotateLeft(start);
        }
      }
      else if ( value > 0){
        insertAVLNode(start->right, rec);
        if (absolute(height(start->right) - height(start->left)) == 2)
        {
          if(compare(rec, start->right->ptr) > 0)
            singleRotateRight(start);
          else
            doubleRotateRight(start);
        }
      }
      start->height = max(height(start->left),height(start->right))+1;
    }

    void searchAVLNode(avlnode *start, char *str, LL& reclist){
        if(!start){
          return;
        }
        int value = compareValue(start->ptr, str);
        if(value  == 0){
          reclist.insert(start->ptr);
          searchAVLNode(start->left, str, reclist);
        }
        else if( value < 0){
          searchAVLNode(start->right, str, reclist);
        } else {
          searchAVLNode(start->left, str, reclist);
        }
    }
    
    void deleteAVLNode(avlnode *&start, record *rec){
        if (!start)  return;
        int value = compare(rec, start->ptr);
        if ( value < 0 || (value == 0 && rec != start->ptr) ){
            deleteAVLNode(start->left, rec);
            if (absolute(height(start->right) - height(start->left)) == 2)
            {
              if(compare(rec, start->left->ptr) < 0)
                singleRotateLeft(start);
              else
                doubleRotateLeft(start);
            }
        }
        else if( value > 0 ){
            deleteAVLNode(start->right, rec);
            if (absolute(height(start->right) - height(start->left)) == 2)
            {
              if(compare(rec, start->right->ptr) > 0)
                singleRotateRight(start);
              else
                doubleRotateRight(start);
            }
        }
        else
        {
            avlnode *temp1, *temp;
            temp = temp1 = NULL;
            if( (start->left == NULL) || (start->right == NULL) )
            {
                temp = start->left ? start->left : start->right;
                if(temp == NULL)
                {
                    temp = start;
                    start = NULL;
                }
                else{
                  temp1 = start;
                  start = temp;
                  temp = temp1;
                }
            }
            else
            {
                temp1 = start;
                temp = minValueNode(start->right);
                start = temp;
                temp = temp1;
            }
            if(temp)
              delete temp;
        }

        if (start != NULL) start->height = max(height(start->left), height(start->right)) + 1;

        return;
    }

    void printAVLTree(avlnode *start){
      if(!start) return;
      printAVLTree(start->left);
      cout << start->ptr->name << " ";
      printAVLTree(start->right);
    }

  public:
    AVLTree(){
      root = NULL;
    }

    void insertRecord(record *rec){
       insertAVLNode(root, rec);
    }

    void deleteRecord(record *rec){
       deleteAVLNode(root, rec);
    }

    void getRecordList(char *str, LL &reclist){
      searchAVLNode(root, str, reclist);
    }

    void deleteAVLTree(avlnode *root){
      if(!root) return;
      deleteAVLTree(root->left);
      deleteAVLTree(root->right);
      delete root;
      root = NULL;
    }

    void setField(FIELD fd){
      field = fd;
    }

    void reset(){
      deleteAVLTree(root);
      root = NULL;
    }

    void print(){
      cout << "Print AVL: " << field << endl;
      printAVLTree(root);
      cout << endl;
    }

    ~AVLTree(){
      //reset();
    }
};


DLL list;
AVLTree Tree[5];
void initDB(){
  list.reset();
  for(int i = 0; i < 5; i++){
    Tree[i].reset();
  }
}

void insert(char* name , char* number , char* birthday , char* email , char* memo){
  record *rec = list.addRecord(name, number, birthday, email, memo);
  list.print();
  // for(int i = 0; i < 5; i++){
  //   Tree[i].setField((FIELD)i);
  //   Tree[i].insertRecord(rec);
  //   Tree[i].print();
  // } 
}

int update(FIELD field, char *str, FIELD ret_field, char *updatestr){
  LL reclist;
  Tree[field].getRecordList(str, reclist);
  reclist.updateField(ret_field, updatestr);
  list.print();
  return reclist.getSize();
}

int deleteRec(FIELD field, char *str){
  // LL reclist;
  // Tree[field].getRecordList(str, reclist);
  // llnode *it = reclist.getHead();
  // while(it){
  //   for(int i = 0; i < 5; i++)
  //     Tree[i].deleteRecord(it->ptr);
  //   list.deleteRecord(it->ptr);
  //   it = it->next;
  // }
  list.deleteField(field, str);
  list.print();
  // return reclist.getSize();
  return list.getSize();
}

RESULT search(FIELD field, char *str, FIELD ret_field){
  RESULT res;
  LL reclist;
  Tree[field].getRecordList(str, reclist);
  reclist.print();
  res.count = reclist.getSize();
  if(res.count > 0)
    strcpy(res.str, reclist.getFirstField(ret_field));
  return res;
}

int main(){
  COMMAND cmd;
  int n;
  int testCases;
  char name[20], number[20], birthday[20], email[20], memo[20], str[20], str1[20];
  RESULT res;
  int records;
  int field, ret_field;
  scanf("%d", &testCases);
  while(testCases--){
      printf("Input Command: (0) INIT (1) INSERT (2) UPDATE (3) DELETE (4) SEARCH \n");
      scanf("%d", &n);
      cmd = (COMMAND)n;
      switch(cmd){
        case INIT:
          initDB();
          break;
        case INSERT:
          scanf("%s %s %s %s %s", name, number, birthday, email, memo);
          insert(name, number, birthday, email, memo);
          break;
        case SEARCH:
          printf("Input Field: (0) NAME (1) NUMBER (2) EMAIL (3) MEMO (4) BIRTHDAY \n");
          scanf("%d %d %s", &field, &ret_field, str);
          res = search((FIELD)field, str, (FIELD)ret_field);
          printf("Count: %d First Record: %s\n", res.count, res.str);
          break;
        case UPDATE:
          printf("Input Field: (0) NAME (1) NUMBER (2) EMAIL (3) MEMO (4) BIRTHDAY and field value to be updated \n");
          scanf("%d %d %s %s", &field,  &ret_field, str, str1);
          records = update((FIELD)field, str, (FIELD)ret_field, str1);
          printf("%d records updated\n", records);
          break;
        case DELETE:
          printf("Input Field: (0) NAME (1) NUMBER (2) EMAIL (3) MEMO (4) BIRTHDAY and field value to be deleted \n");
          scanf("%d %s", &field, str);
          records = deleteRec((FIELD)field, str);
          printf("%d records deleted\n", records);
          break;
      }
  }
  return 0;
}