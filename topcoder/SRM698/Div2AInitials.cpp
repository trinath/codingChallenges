// Author: @avtrinath
#include<string>
#include<iostream>
using namespace std;
class Initials{
    public:
    string getInitials(string s){
            int i, len;
            bool state;
            string result("");
            state = 1;
            len = s.size();
            for(i = 0; i < len; i++){
               if(state == 1 && s[i]!=' ')
               {
                  result += s[i];
                  state = 0;
               }
               if(s[i] == ' ') state = 1;
            }
            return result;
      }
};

int main(){
   Initials ob;
   string s = "looks good to me";
   cout << ob.getInitials(s) << endl;
   return 0;
}
