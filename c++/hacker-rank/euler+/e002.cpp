#include <iostream>
using namespace std;

long fib(long max){
  // calculate sum of even fibonacci numbers
  // initialize starting conditions
  long sum;
  int e[3] = {1,2,3};
  int p = 2;

  while (e[2] <= max){
    if (e[2]%2 == 0){
      p += e[2];
    }
    //shift numbers and sum
    e[0] = e[1];
    e[1] = e[2];
    e[2] = e[0] + e[1];
  }
  return p;
}

int main() {
  int t;
  cin >> t;

  for (int i=0; i<t; i++){
    long n, p;
    cin >> n;
    p = fib(n);
  
    cout << p << endl;
  }
  return 0;
}
