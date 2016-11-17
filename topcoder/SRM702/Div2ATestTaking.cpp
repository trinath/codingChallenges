// Author @avtrinath
// Div2 250
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class TestTaking{
public:
   int findMax(int questions, int guessed, int actual){
     if(guessed == actual) return questions;
     if(!guessed) return (questions - actual);
     if(!actual) return (questions - guessed);
     return abs(guessed-actual) + abs(actual - guessed);
   }
};

int main(){
  TestTaking t;
  cout << t.findMax(3, 2, 1) << endl;
  cout << t.findMax(5, 5, 0) << endl;
  cout << t.findMax(10, 8, 8) << endl;
  cout << t.findMax(7, 0, 2) << endl;
  return 0;
}
