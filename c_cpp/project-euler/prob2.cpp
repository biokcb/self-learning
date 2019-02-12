#include <iostream>
using namespace std;

int main() {
  int e[3] = {1,2,3};
  int p = 2;

  while (e[2] <= 4000000){
    if (e[2]%2 == 0) {
      p += e[2];
    }
      e[0] = e[1];
      e[1] = e[2];
      e[2] = e[0] + e[1];
  }
  
  cout << p << endl;

  return 0;
}
