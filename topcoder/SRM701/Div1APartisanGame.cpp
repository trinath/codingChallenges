#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

class PartisanGame{
public:
    string getWinner(int n, vector<int> a, vector<int> b){
        bool *alice = new bool[n+1];
        bool *bob = new bool[n+1];
        int i, j;
        memset(alice, false, n+1);
        memset(bob, false, n+1);
        for (i = 0; i < a.size(); i++){
            alice[a[i]] = true;
        }
        for (i = 0; i < b.size(); i++){
            bob[b[i]] = true;
        }

        for (i = 1; i <= n; i++){
            if (!alice[i]){
                for (j = 0; j < a.size(); j++){
                    if (i >= a[j])
                        alice[i] |= !bob[i - a[j]];
                }
            }
            if (!bob[i]){
                for (j = 0; j < b.size(); j++){
                    if (i >= b[j])
                        bob[i] |= !alice[i - b[j]];
                }
            }
        }
        return (alice[n]) ? "Alice" : "Bob";
    }
};
