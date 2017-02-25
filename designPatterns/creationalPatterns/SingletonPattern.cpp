/*
@Author @Source: https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns

Creational Patterns are design patterns that deal with the object creation mechanisms,
trying to create objects in a manner suitable to the situation.

Problem:
The Singleton pattern ensures that a class has only one instance and provides a global
point of access to that instance.
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
#include <mutex>
using namespace std;


class StringSingleton
{
public:
    std::string GetString() const
    {
      return mString;
    }
    void SetString(const std::string &newStr)
    {
      mString = newStr;
    }


    static StringSingleton &Instance()
    {
        lock_guard<mutex> lock(mMutex);
        static StringSingleton *instance = new StringSingleton;
        return *instance; 
    }

private:
    StringSingleton(){} 
    StringSingleton(const StringSingleton &old); // disallow copy constructor
    const StringSingleton &operator=(const StringSingleton &old); //disallow assignment operator
    ~StringSingleton(){}
private:
    std::string mString;
    static mutex mMutex;
};

mutex StringSingleton::mMutex;

int main(){
    StringSingleton &ss = StringSingleton::Instance();
    string input;
    cin >> input;
    ss.SetString(input);
    cout << ss.GetString() << endl;
    return 0;
}