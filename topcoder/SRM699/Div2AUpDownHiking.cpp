#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

class UpDownHiking{
public:
   int maxHeight(int N, int A, int B){
     int x, y;
     x = floor((double)(B*N)/(A+B));
     y = N - x;
     if(x == 0){
         x = 1;
         y--;
	   }
     if(y == 0){
         y = 1;
         x--;
     }
     if(y > 1)
     	return max(max(min(A*x, B*y), min(B*x, A*y)), max(min(A*(x+1), B*(y-1)), min(B*(x+1), A*(y-1))));
     else
        return max(min(A*x, B*y), min(B*x, A*y));
   }
};

int main(){
  UpDownHiking up;
  int t, n, a, b;
  cin >> t;
  while(t--){
      cin >> n >> a >> b;
      std::cout << up.maxHeight(n, a, b) << std::endl;
  }
  return 0;
}
