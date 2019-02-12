#include <iostream>
using namespace std;

long fib(long max){
  /* calculate sum of even fibonacci numbers assuming every 3rd number is even
  fibonacci sum proof as practice (obvious could just copy the solution, 
  but good to understand the math.

  if fib(max) is even, then fib(max-1) & fib(max-2) are odd & fib(max-3) and fib(max-6) are even
  fib(max) = fib(max-1) + fib(max-2)
           = fib(max-1-1) + fib(max-1-2) + fib(max-2-1) + fib(max-2-2)
           = 2*fib(max-3) + fib(max-2) + fib(max-4)
           = 2*fib(max-3) + fib(max-2-1)+fib(max-2-2) + fib(max-4-1)+fib(max-4-2)
           = 3*fib(max-3) + fib(max-4) + fib(max-5) + fib(max-6)
           = 3*fib(max-3) + [ fib(max-3-1) + fib(max-3-2) = fib(max-3) ] + fib(max-6)
           = 4*fib(max-3) + fib(max-6)
  fib(21) = 4*5 + 1 = 21, fib(34) = 4*8+2 =34 which can also be evenfib(34)=evenfib(34-1)+evenfib(34-2)
  */
  long currmax = 8;
  long priormax = 2;
  long sum = 2;
  long newmax;

  while (currmax <= max){
      sum += currmax;
      newmax = 4*(currmax) + priormax;
      priormax = currmax;
      currmax = newmax;
  }
  return sum;
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
