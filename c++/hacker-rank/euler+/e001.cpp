#include <iostream>
using namespace std;

long summation(int divby, long max){
  long sum;
  // multiply by divby to get numbers divisible
  // by divby. Use max-1 since we are checking numbers
  // below some max number. then summation formula
  sum = divby * ((max-1)/divby * ((max-1)/divby +1))/2;

  return sum;
}
int main() {
  //get number of numbers to check
  int t;
  cin >> t;

  for (long i = 0; i < t; i++){
    long n, tot, sum3, sum5, sum15;
    cin >> n;
    // sum instead of looping. I forgot math was a thing.
    sum3 = summation(3,n);
    sum5 = summation(5,n);
    sum15 = summation(15,n);

    tot = sum3 + sum5 - sum15;
    cout << tot << endl;
  }
  return 0;
}
