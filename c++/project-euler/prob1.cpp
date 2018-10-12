#include <iostream>
using namespace std;

int main() {
  int tot = 0;
  for (int i=0; i<1000; i++) {
    if (i%3 == 0 || i%5 == 0){
      tot += i;
    }
  }
    
  cout << tot << endl;

  return 0;
}
