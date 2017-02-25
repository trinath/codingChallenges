#include<iostream>
using namespace std;

void strcpy(char *first, char *second){
  int i = 0;
  for(i = 0; i < 20 && second[i] != '\0'; i++){
    first[i] = second[i];
  }
  first[i] = '\0';
}

int strcmp(char *first, char *second){
  while(first != '\0' && second!= '\0'){
    if(first < second) return -1;
    else if( second < first) return 1;
    first++;
    second++;
  }
  if(second != '\0') return -1;
  else if(first !='\0') return 1;
  return 0;
}

int main()
{
  char s[] = "ab";
  char s1[] = "xyz";
  char a[20];
  cout << strcmp(s, s1) << endl;
  strcpy(a, s);
  cout << a << endl; 
  return 0;
}