// author trinath
// In-memory Employee Table with insert, udpate, delete and search operations.
#include <iostream>
#include <list>
#include <algorithm>
#include <unordered_map>

using namespace std;

enum FIELD{
  ID,
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

class Record{
public:
    int id;
    string name;
    string number;
    string birthday;
    string email;
    string memo;
    Record(){

    }
    Record(int _id, string _name, string _number, string _email, string _memo, string _birthday){
        id = _id;
        name = _name;
        number = _number;
        birthday = _birthday;
        email = _email;
        memo = _memo;
    }
    void printRecord() {
        cout << "Record:" << id << "|" << name << "|" << number <<  "|" <<  birthday << "|" << email << "|" << memo << endl;
    }
    bool isMatch(FIELD field, string source){
        switch(field){
            case ID: return (to_string(id) == source);
            case NAME: return (name == source);
            case NUMBER: return (number == source);
            case EMAIL: return (email == source);
            case MEMO: return (memo == source);
            case BIRTHDAY: return (birthday == source);
        }   
        return false;
    }
    void update(FIELD field, string target){
        switch(field){
            case NAME: 
                name = target;
                return;
            case NUMBER:
                number = target; 
                return;
            case EMAIL:  
                email = target;
                return;
            case MEMO:  
                memo = target;
                return;
            case BIRTHDAY: 
                birthday = target;
                return;
            case ID:
                return;
        }   
    }   
};  

class Database{
   private:
        list<Record> records;
        unordered_map<int, list<Record>::iterator> umap;
   public:
        void init(){
            records.clear();
            umap.clear();
        }
        Database(){
            init();
        }
        void insertRecord(int id, string name, string number, string email, string memo, string birthday){
            Record record(id, name, number, email, memo, birthday);
            records.push_front(record);
            umap[id] = records.begin();
        }
        int updateRecord(FIELD sourceField, FIELD targetField, string source, string target){
            int result = 0;
            for(auto it = records.begin(); it != records.end(); it++){
                if(it->isMatch(sourceField, source)){
                    it->update(targetField, target);
                    result++;   
                }
            }
            return result;
        }
        int deleteRecord(FIELD sourceField, string source){
            int result = 0;
            for(auto it = records.begin(); it != records.end(); it++){
                if(it->isMatch(sourceField, source)){
                    if(umap.find(it->id) != umap.end()){
                        umap.erase(umap.find(it->id));
                    }
                    records.erase(it);
                    result++;
                }
            }
            return result;
        }
        int searchRecord(int start, int end){
            int result = 0;
            for(int i = start; i < end; i++){
                if(umap.find(i) != umap.end()){
                    umap[i]->printRecord();
                    result++;
                }
            }
            return result;
        }
};
int main(){
    int sourceField, targetField, testCases, id, n, result; 
    Database db;
    cin >> testCases;
    COMMAND cmd;
    string name, number, email, memo, birthday, source, target;
    id = 0;
    while(testCases--){
        cin >> n;
        cmd = (COMMAND)n;
        switch (cmd)
        {
            case INIT:
                db.init();
                break;
            case INSERT:
                id++;
                cout << "Insert" << endl;
                cin >> name >> number >> email >> memo >> birthday; 
                db.insertRecord(id, name, number, email, memo, birthday);
                break;
            case UPDATE:
                cout << "Update" << endl;
                cin >> sourceField >> targetField;
                cin >> source >> target;
                result = db.updateRecord((FIELD)sourceField, (FIELD)targetField, source, target);
                cout << result << " records updated" << endl;
                break;
            case DELETE:
                cout << "Delete" << endl;
                cin >> sourceField >> source;
                result = db.deleteRecord((FIELD)sourceField, source);
                cout << result << " records deleted" << endl;
                break;
            case SEARCH:
                cout << "Search" << endl;
                int start, end;
                cin >> start >> end;
                result = db.searchRecord(start, end);
                cout << result << " records found" << endl;
                break;
        }
    } 
}