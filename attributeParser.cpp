/*=============================================================================
 * Author: A. V. TRINATH   
 * Problem: Parsing Attributes      
 *=============================================================================
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <sstream>
using namespace std;


struct tag{
    tag *parent;
    string name;
    vector<tag*> child;
    map<string, string> attr;
    tag(string _name){
        parent = NULL;
        name = _name;
    }
};

string strip(string t){
    int start = 0, end = t.size() - 1;
    while (start<end && (t[start] == ' ' || t[start] == '"' || t[start] == '<')) start++;
    while (end>0 && (t[end] == ' ' || t[end] == '"' || t[end] == '>')) end--;
    return t.substr(start, end-start+1);
}

string getFirstTag(string keytag){
    int found = keytag.find(".");
    if (found != string::npos)
        return keytag.substr(0, found);
    else
        return keytag;
}

void getTagValue(string keytag, string value, tag* gtag, string &result){
    int i;
    int found = keytag.find(".");
    if (gtag == NULL || keytag.size() == 0){
        return;
    }
    else if (found == string::npos){
        int index = -1; 
        for (i = 0; i < gtag->child.size(); i++){
            if (gtag->child[i]->name == keytag){
                index = i;
                break;
            }
        }
        if (index != -1){
            gtag = gtag->child[i];
            if (gtag->name == keytag){
                if (gtag->attr.find(value) != gtag->attr.end()){
                    result = gtag->attr[value];
                }
            }
        }
    }
    else{
        for (i = 0; i < gtag->child.size(); i++){
            if (gtag->child[i]->name == keytag.substr(0,found)){
                getTagValue(keytag.substr(found+1), value, gtag->child[i], result);
                if (result.compare("Not Found!") == 0) break;
            }
        }
    }
}

int main() {
    int n, q; 
    string input, constant("</"), result = "Not Found!";
    tag *gtag = new tag("root");
    tag *current = gtag;

    getline(cin, input);
    stringstream ss(input);
    ss >> n >> q;

    while (n--){
        getline(cin, input);
        if (input.find(constant) != string::npos){
            if (!(current->name == "root")){
                current = current->parent;
            }
            else{
                cout << result << endl;
            }
        }
        else {
            string t, key, value;
            int found, found1;
            found = input.find("<");
            if (found != string::npos){
                found1 = input.find(" ", found + 1);
                if (found != string::npos){
                    t = input.substr(found + 1, found1 - found);
                    t = strip(t);
                }
                
                // add to tree
                tag *newtag = new tag(t);
                newtag->parent = current;
                current->child.push_back(newtag);
                current = newtag;
                input = input.substr(found1 + 1);

                while (input.size() > 0){
                    found = input.find("=");
                    if (found != string::npos){
                        key = strip(input.substr(0, found));
                        found = input.find("\"");
                        found1 = input.find("\"", found + 1);
                        value = strip(input.substr(found + 1, found1 - found));
			
                        current->attr[key] = value;
                        input = input.substr(found1 + 1);
                    }
                    else{
                        if (input.find(">") != string::npos) break;
                    }
                }
            }
            else{
                cout << result << endl;
            }
        }
    }

    while (q--){
        getline(cin, input);
        result = "Not Found!";
        int found = input.find("~");
        if (found != string::npos){
            getTagValue(input.substr(0, found), input.substr(found + 1), gtag, result);        
        }
        cout << result << endl;

    }
    return 0;
}

