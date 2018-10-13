#include <iostream>
using namespace std;

int main() {
  //get number of numbers to check
  int t;
  cin >> t;

  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    // more generic loop from project-euler solution
    int tot = 0;
    for (int j = 0; j<n; j++){
      if (j%3 == 0 || j%5 ==0){
        tot += j;
      }
    }
    cout << tot << endl;
  }
  return 0;
}
